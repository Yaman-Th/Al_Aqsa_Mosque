#include "Ground.h"


Ground::Ground()
{
	this->initRenderData();
    this->loadTexture("Resources/Textures/Ground/ground_1.png");
    this->initLight();

}

void Ground::renderGround()
{
    

    
}

void Ground::renderEnd()
{
    glDeleteVertexArrays(1, &groundVAO);
    glDeleteBuffers(1, &groundVBO);
}

void Ground::initRenderData()
{
    float groundVertices[] = {
        // positions            // normals         // texcoords
         125.0f, -7.0f,  75.0f,  0.0f, 1.0f, 0.0f,  30.0f,  0.0f,
        -125.0f, -7.0f,  75.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
        -125.0f, -7.0f, -75.0f,  0.0f, 1.0f, 0.0f,   0.0f, 20.0f,
         125.0f, -7.0f,  75.0f,  0.0f, 1.0f, 0.0f,  30.0f,  0.0f,
        -125.0f, -7.0f, -75.0f,  0.0f, 1.0f, 0.0f,   0.0f, 20.0f,
         125.0f, -7.0f, -75.0f,  0.0f, 1.0f, 0.0f,  30.0f, 20.0f,

    };
    // setup ground VAO
    glGenVertexArrays(1, &this->groundVAO);
    glGenBuffers(1, &this->groundVBO);
    glBindVertexArray(this->groundVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->groundVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(groundVertices), groundVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glBindVertexArray(0);


}

void Ground::initLight()
{
    // lighting info
    // -------------
    

    // configure light FBO
    // -----------------------
    glGenFramebuffers(1, &lightFBO);

    glGenTextures(1, &lightDepthMaps);
    glBindTexture(GL_TEXTURE_2D_ARRAY, lightDepthMaps);
    glTexImage3D(
        GL_TEXTURE_2D_ARRAY, 0, GL_DEPTH_COMPONENT32F, depthMapResolution, depthMapResolution, int(shadowCascadeLevels.size()) + 1,
        0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    constexpr float bordercolor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_BORDER_COLOR, bordercolor);

    glBindFramebuffer(GL_FRAMEBUFFER, lightFBO);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, lightDepthMaps, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);

    int status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (status != GL_FRAMEBUFFER_COMPLETE)
    {
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!";
        throw 0;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // configure UBO
    // --------------------
    glGenBuffers(1, &matricesUBO);
    glBindBuffer(GL_UNIFORM_BUFFER, matricesUBO);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::mat4x4) * 16, nullptr, GL_STATIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, matricesUBO);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void Ground::loadTexture(char const* path)
{
    
    glGenTextures(1, &groundTexture);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, groundTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }

}

void Ground::renderAssis(const Shader shader)
{
    // floor
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(5.0f, 1.0f, 5.0f));
    shader.setMat4("model", model);
    glBindVertexArray(this->groundVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawArrays(GL_TRIANGLES, 6, 3);

    static std::vector<glm::mat4> modelMatrices;
    if (modelMatrices.size() == 0)
    {
        for (int i = 0; i < 10; ++i)
        {
            static std::uniform_real_distribution<float> offsetDistribution = std::uniform_real_distribution<float>(-10, 10);
            static std::uniform_real_distribution<float> scaleDistribution = std::uniform_real_distribution<float>(1.0, 2.0);
            static std::uniform_real_distribution<float> rotationDistribution = std::uniform_real_distribution<float>(0, 180);

            auto model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(offsetDistribution(generator), offsetDistribution(generator) + 10.0f, offsetDistribution(generator)));
            model = glm::rotate(model, glm::radians(rotationDistribution(generator)), glm::normalize(glm::vec3(1.0, 0.0, 1.0)));
            model = glm::scale(model, glm::vec3(scaleDistribution(generator)));
            modelMatrices.push_back(model);
        }
    }
}

    // renderQuad() renders a 1x1 XY quad in NDC
    // -----------------------------------------
    void Ground::renderQuad()
    {
    unsigned int quadVAO = 0;
    unsigned int quadVBO;
        if (quadVAO == 0)
        {
            float quadVertices[] = {
                // positions        // texture Coords
                -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
                -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
                 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
                 1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
            };
            // setup plane VAO
            glGenVertexArrays(1, &quadVAO);
            glGenBuffers(1, &quadVBO);
            glBindVertexArray(quadVAO);
            glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        }
        glBindVertexArray(quadVAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glBindVertexArray(0);
    }
