#include "Cylinders.h"

Cylinders::Cylinders(float radius, float height, unsigned int segments)
{
    //this->cylinderTexture = texture;
    this->initCylinder(radius, height, segments);
}

Cylinders::Cylinders(float radius, float height, unsigned int segments, bool semi)
{
    //this->cylinderTexture = texture;
    this->initSemiCylinder(radius, height, segments);
}
void Cylinders::initCylinder(float radius, float height, unsigned int segments)
{
    
    std::vector<glm::vec2> texCoords;
    // Generate vertices for the sides of the cylinder
    for (unsigned int i = 0; i <= segments; ++i) {
        float theta = static_cast<float>(i) / segments * glm::two_pi<float>();
        float x = radius * cos(theta);
        float z = radius * sin(theta);
        cylinderPositions.emplace_back(x, -height * 0.5f, z);
        cylinderPositions.emplace_back(x, height * 0.5f, z);

        float texCoordX = static_cast<float>(i) / segments;
        texCoords.emplace_back(texCoordX, 0.0f);
        texCoords.emplace_back(texCoordX, 1.0f);
    }

    glGenVertexArrays(1, &cylinderVAO);
    glGenBuffers(1, &cylinderVBO);

    glBindVertexArray(cylinderVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cylinderVBO);
    glBufferData(GL_ARRAY_BUFFER, cylinderPositions.size() * sizeof(glm::vec3), cylinderPositions.data(), GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);

    unsigned int VBO_texCoords;
    glGenBuffers(1, &VBO_texCoords);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_texCoords);
    glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(glm::vec2), texCoords.data(), GL_STATIC_DRAW);

    // Set vertex attribute pointers for texture coordinates
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
    glEnableVertexAttribArray(1);

}

void Cylinders::initSemiCylinder(float radius, float height, unsigned int segments)
{

    std::vector<glm::vec2> texCoords;
    // Generate vertices for the sides of the cylinder
    for (unsigned int i = 0; i <= segments/2; ++i) {
        float theta = static_cast<float>(i) / segments * glm::two_pi<float>();
        float x = radius * cos(theta);
        float z = radius * sin(theta);
        cylinderPositions.emplace_back(x, -height * 0.5f, z);
        cylinderPositions.emplace_back(x, height * 0.5f, z);

        float texCoordX = static_cast<float>(i) / segments;
        texCoords.emplace_back(texCoordX, 0.0f);
        texCoords.emplace_back(texCoordX, 1.0f);
    }

    glGenVertexArrays(1, &cylinderVAO);
    glGenBuffers(1, &cylinderVBO);

    glBindVertexArray(cylinderVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cylinderVBO);
    glBufferData(GL_ARRAY_BUFFER, cylinderPositions.size() * sizeof(glm::vec3), cylinderPositions.data(), GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);

    unsigned int VBO_texCoords;
    glGenBuffers(1, &VBO_texCoords);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_texCoords);
    glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(glm::vec2), texCoords.data(), GL_STATIC_DRAW);

    // Set vertex attribute pointers for texture coordinates
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
    glEnableVertexAttribArray(1);

}

void Cylinders::renderCylinder(unsigned int texture)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(cylinderVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, cylinderPositions.size());
}
