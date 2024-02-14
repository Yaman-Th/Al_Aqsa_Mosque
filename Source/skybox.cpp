#include "skybox.h"

skybox::skybox()
{

    this->initRenderData();

}

skybox::~skybox()
{
}

void skybox::Drawskybox(unsigned int texture)
{
    glBindVertexArray(skyboxVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS); // set depth function back to default
}

void skybox::renderEnd()
{
    glDeleteVertexArrays(1, &skyboxVAO);
    glDeleteBuffers(1, &skyboxVBO);
}

void skybox::initRenderData()
{
    float x = 1.0f, y = 1.0f, z = 1.0f;
    float skyboxVertices[] = {
        // positions          
        -x,  y, -z,
        -x, -y, -z,
         x, -y, -z,
         x, -y, -z,
         x,  y, -z,
        -x,  y, -z,
                 
        -x, -y,  z,
        -x, -y, -z,
        -x,  y, -z,
        -x,  y, -z,
        -x,  y,  z,
        -x, -y,  z,
                 
         x, -y, -z,
         x, -y,  z,
         x,  y,  z,
         x,  y,  z,
         x,  y, -z,
         x, -y, -z,
                 
        -x, -y,  z,
        -x,  y,  z,
         x,  y,  z,
         x,  y,  z,
         x, -y,  z,
        -x, -y,  z,
                 
        -x,  y, -z,
         x,  y, -z,
         x,  y,  z,
         x,  y,  z,
        -x,  y,  z,
        -x,  y, -z,
                 
        -x, -y, -z,
        -x, -y,  z,
         x, -y, -z,
         x, -y, -z,
        -x, -y,  z,
         x, -y,  z
    };

    glGenVertexArrays(1, &this->skyboxVAO);
    glGenBuffers(1, &this->skyboxVBO);
    glBindVertexArray(this->skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

}


