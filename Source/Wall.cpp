#include "Wall.h"

Wall::Wall()
{
    this->initRenderDate();
    //this->loadTextures("Resources/Textures/Wall/wall_4.png");
    this->loadTextures("Resources/Textures/QBM_5.png");
}

Wall::~Wall()
{
}

void Wall::initRenderDate()
{
    float y1 = -9.0f;
    
    float wallVertices[] = {
        // left                          
        -125.0f,  2.0f, -75.0f,  50.0f, 3.0f, // top right     
        -125.0f, y1, -75.0f,  50.0f, 0.0f, // bottom right
        -125.0f, y1,  75.0f,  0.0f,  0.0f, // bottom left
        -125.0f,  2.0f,  75.0f,  0.0f,  3.0f, // top left
        -125.0f, y1,  75.0f,  0.0f,  0.0f, // bottom left
        -125.0f,  2.0f, -75.0f,  50.0f, 3.0f, // top right

        // right
        -124.5f,  2.0f, -75.0f,  50.0f, 3.0f, // top right   
        -124.5f, y1, -75.0f,  50.0f, 0.0f, // bottom right
        -124.5f, y1,  75.0f,  0.0f,  0.0f, // bottom left
        -124.5f,  2.0f,  75.0f,  0.0f,  3.0f, // top left
        -124.5f, y1,  75.0f,  0.0f,  0.0f, // bottom left
        -124.5f,  2.0f, -75.0f,  50.0f, 3.0f, // top right

        // top
        -125.0f,  2.0f, -75.0f,  80.0f, 3.0f, // top right
        -124.5f,  2.0f, -75.0f,  80.0f, 0.0f, // bottom right
        -124.5f,  2.0f,  75.0f,  0.0f,  0.0f, // bottom left
        -125.0f,  2.0f,  75.0f,  0.0f,  3.0f, // top left
        -124.5f,  2.0f,  75.0f,  0.0f,  0.0f, // bottom left
        -125.0f,  2.0f, -75.0f,  80.0f, 3.0f, // top right

        // side_1
        -124.5f,  2.0f, -75.0f,  1.0f, 4.0f, // top right
        -124.5f, y1, -75.0f,  1.0f, 0.0f, // bottom right
        -125.0f, y1, -75.0f,  0.0f, 0.0f, // bottom left
        -125.0f,  2.0f, -75.0f,  0.0f, 4.0f, // top left
        -125.0f, y1, -75.0f,  0.0f, 0.0f, // bottom left
        -124.5f,  2.0f, -75.0f,  1.0f, 4.0f, // top right

        // side_2
        -124.5f,  2.0f, 75.0f,  1.0f, 4.0f, // top right
        -124.5f, y1, 75.0f,  1.0f, 0.0f, // bottom right
        -125.0f, y1, 75.0f,  0.0f, 0.0f, // bottom left
        -125.0f,  2.0f, 75.0f,  0.0f, 4.0f, // top left
        -125.0f, y1, 75.0f,  0.0f, 0.0f, // bottom left
        -124.5f,  2.0f, 75.0f,  1.0f, 4.0f, // top right
    };

    float wallVertices_2[] = {
        // left                          
         124.5f,  2.0f, 75.0f,  80.0f, 3.0f, // top right     
         124.5f, y1, 75.0f,  80.0f, 0.0f, // bottom right
        -124.5f, y1, 75.0f,  0.0f,  0.0f, // bottom left
        -124.5f,  2.0f, 75.0f,  0.0f,  3.0f, // top left
        -124.5f, y1, 75.0f,  0.0f,  0.0f, // bottom left
         124.5f,  2.0f, 75.0f,  80.0f, 3.0f, // top right

        // right
         124.5f,  2.0f, 74.5f,  80.0f, 3.0f, // top right   
         124.5f, y1, 74.5f,  80.0f, 0.0f, // bottom right
        -124.5f, y1, 74.5f,  0.0f,  0.0f, // bottom left
        -124.5f,  2.0f, 74.5f,  0.0f,  3.0f, // top left
        -124.5f, y1, 74.5f,  0.0f,  0.0f, // bottom left
         124.5f,  2.0f, 74.5f,  80.0f, 3.0f, // top right

        // top
         124.5f,  2.0f, 75.0f,  100.0f, 1.0f, // top right
         124.5f,  2.0f, 74.5f,  100.0f, 0.0f, // bottom right
        -124.5f,  2.0f, 74.5f,  0.0f,  0.0f, // bottom left
        -124.5f,  2.0f, 75.0f,  0.0f,  1.0f, // top left
        -124.5f,  2.0f, 74.5f,  0.0f,  0.0f, // bottom left
         124.5f,  2.0f, 75.0f,  100.0f, 1.0f, // top right

        //// side_1
        // 124.5f,  2.0f, 74.5f,  1.0f, 4.0f, // top right
        // 124.5f, -2.0f, 74.5f,  1.0f, 0.0f, // bottom right
        // 124.5f, -2.0f, 75.0f,  0.0f, 0.0f, // bottom left
        // 124.5f,  2.0f, 75.0f,  0.0f, 4.0f, // top left
        // 124.5f, -2.0f, 75.0f,  0.0f, 0.0f, // bottom left
        // 124.5f,  2.0f, 74.5f,  1.0f, 4.0f, // top right
        //
        //// side_2
        //-124.5f,  2.0f, 74.5f,  1.0f, 4.0f, // top right
        //-124.5f, -2.0f, 74.5f,  1.0f, 0.0f, // bottom right
        //-124.5f, -2.0f, 75.0f,  0.0f, 0.0f, // bottom left
        //-124.5f,  2.0f, 75.0f,  0.0f, 4.0f, // top left
        //-124.5f, -2.0f, 75.0f,  0.0f, 0.0f, // bottom left
        //-124.5f,  2.0f, 74.5f,  1.0f, 4.0f, // top right
    };

    float cubeVertices[] = {
        // left                          
        -125.0f,  3.0f, -73.0f,  2.0f, 1.0f, // top right     
        -125.0f,  2.0f, -73.0f,  2.0f, 0.0f, // bottom right
        -125.0f,  2.0f, -75.0f,  0.0f, 0.0f, // bottom left
        -125.0f,  3.0f, -75.0f,  0.0f, 1.0f, // top left
        -125.0f,  2.0f, -75.0f,  0.0f, 0.0f, // bottom left
        -125.0f,  3.0f, -73.0f,  2.0f, 1.0f, // top right

        // right                         
        -124.5f,  3.0f, -73.0f,  2.0f, 1.0f, // top right   
        -124.5f,  2.0f, -73.0f,  2.0f, 0.0f, // bottom right
        -124.5f,  2.0f, -75.0f,  0.0f, 0.0f, // bottom left
        -124.5f,  3.0f, -75.0f,  0.0f, 1.0f, // top left
        -124.5f,  2.0f, -75.0f,  0.0f, 0.0f, // bottom left
        -124.5f,  3.0f, -73.0f,  2.0f, 1.0f, // top right

        // top                         
        -125.0f,  3.0f, -75.0f,  2.0f, 1.0f, // top right   
        -124.5f,  3.0f, -75.0f,  2.0f, 0.0f, // bottom right
        -124.5f,  3.0f, -73.0f,  0.0f, 0.0f, // bottom left
        -125.0f,  3.0f, -73.0f,  0.0f, 1.0f, // top left
        -124.5f,  3.0f, -73.0f,  0.0f, 0.0f, // bottom left
        -125.0f,  3.0f, -75.0f,  2.0f, 1.0f, // top right

        // side_1                         
        -125.0f,  3.0f, -75.0f,  2.0f, 1.0f, // top right   
        -125.0f,  2.0f, -75.0f,  2.0f, 0.0f, // bottom right
        -124.5f,  2.0f, -75.0f,  0.0f, 0.0f, // bottom left
        -124.5f,  3.0f, -75.0f,  0.0f, 1.0f, // top left
        -124.5f,  2.0f, -75.0f,  0.0f, 0.0f, // bottom left
        -125.0f,  3.0f, -75.0f,  2.0f, 1.0f, // top right

        // side_2                         
        -125.0f,  3.0f, -73.0f,  2.0f, 1.0f, // top right   
        -125.0f,  2.0f, -73.0f,  2.0f, 0.0f, // bottom right
        -124.5f,  2.0f, -73.0f,  0.0f, 0.0f, // bottom left
        -124.5f,  3.0f, -73.0f,  0.0f, 1.0f, // top left
        -124.5f,  2.0f, -73.0f,  0.0f, 0.0f, // bottom left
        -125.0f,  3.0f, -73.0f,  2.0f, 1.0f, // top right

        


    };

    // setup ground VAO
    glGenVertexArrays(1, &this->wallVAO);
    glGenBuffers(1,      &this->wallVBO);
    glBindVertexArray(    this->wallVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->wallVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(wallVertices), wallVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // setup ground VAO
    glGenVertexArrays(1, &this->wallVAO_2);
    glGenBuffers(1, &this->wallVBO_2);
    glBindVertexArray(this->wallVAO_2);
    glBindBuffer(GL_ARRAY_BUFFER, this->wallVBO_2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(wallVertices_2), wallVertices_2, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // setup ground VAO
    glGenVertexArrays(1, &this->cubeVAO);
    glGenBuffers(1, &this->cubeVBO);
    glBindVertexArray(this->cubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    float z = 2.5;
    for (int i = 0; i < std::size(cubePositions_1); i++)
    {
        cubePositions_1[i] = glm::vec3(0.0f, 0.0f, z);
        z = z + 2.5;
    }

    z = z - 2.5;
    for (int i = 0; i < std::size(cubePositions_2); i++)
    {
        cubePositions_2[i] = glm::vec3(249.5f, 0.0f, z);
        z = z - 2.5;
    }

    for (unsigned int i = 0; i < std::size(cubePositions_3); i++)
    {   
        float z2 = 2.5;
        cubePositions_3[i] = glm::vec3(0.0f, 0.0f, z2);
    }

    for (unsigned int i = 0; i < std::size(cubePositions_4); i++)
    {
        float z3 = -2.5;
        cubePositions_4[i] = glm::vec3(0.0f, 0.0f, z3);
    }
    
}

void Wall::loadTextures(const char* path)
{
    glGenTextures(1, &wallTexture);

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

        glBindTexture(GL_TEXTURE_2D, wallTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
}

void Wall::renderWall()
{   
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(12.5f, 2.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.1f, 1.0f, 1.0f));
    shader->setMat4("model", model);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, wallTexture);

    glBindVertexArray(this->wallVAO);
    glDrawArrays(GL_TRIANGLES, 0, 30);

    glBindVertexArray(this->wallVAO_2);
    glDrawArrays(GL_TRIANGLES, 0, 30);

    glBindVertexArray(this->cubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    for (unsigned int i = 0; i < std::size(cubePositions_1); i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions_1[i]);
        model = glm::translate(model, glm::vec3(0.0f, 2.0f, 0.0f));
        shader->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    
    glBindVertexArray(this->wallVAO);
    model = glm::mat4(1.0f);
    //model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::translate(model, glm::vec3(249.5f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    model = glm::translate(model, glm::vec3(25.0f, 2.0f, 0.0f));
    shader->setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(this->wallVAO_2);
    model = glm::mat4(1.0f);
    //model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -149.5f));
    model = glm::translate(model, glm::vec3(12.5f, 2.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.1f, 1.0f, 1.0f));
    
    shader->setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(this->cubeVAO);
    for (unsigned int i = 0; i < std::size(cubePositions_2); i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions_2[i]);
        model = glm::translate(model, glm::vec3(25.0f, 2.0f, 0.0f));
        shader->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

        glBindVertexArray(this->cubeVAO);
        model = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::translate(model, glm::vec3(50.0f, 0.0f, -48.5f));
        model = glm::translate(model, glm::vec3(0.0f, 2.0f, 0.0f));

        shader->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);

    for (unsigned int i = 0; i < std::size(cubePositions_3); i++)
    {
        model = glm::translate(model, cubePositions_3[i]);
        shader->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }


    model = glm::translate(model, glm::vec3(149.5f, 0.0f, 0.0f));
    //model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    //model = glm::translate(model, glm::vec3(0.0f, 2.0f, 0.0f));
    shader->setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    for (unsigned int i = 0; i < std::size(cubePositions_4); i++)
    {
        model = glm::translate(model, cubePositions_4[i]);
        
        shader->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    

}

void Wall::renderEnd()
{
    glDeleteVertexArrays(1, &wallVAO);
    glDeleteBuffers(1,      &wallVBO);

    glDeleteVertexArrays(1, &wallVAO_2);
    glDeleteBuffers(1, &wallVBO_2);

    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteBuffers(1, &cubeVBO);
}
