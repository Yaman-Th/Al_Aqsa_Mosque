#include "Circle.h"


Circle::Circle(float radius, int segments)
{
    this->initRenderDate(radius, segments);
}

void Circle::initRenderDate(float radius, int segments)
{
    std::vector<glm::vec2> texCoords;

    // Center vertex
    circleVertices.emplace_back(0.0f, 0.0f, 0.0f);
    texCoords.emplace_back(0.5f, 0.5f); // Center texture coordinate

    // Generate vertices for the circle with texture coordinates
    for (unsigned int i = 0; i <= segments; ++i) {
        float theta = static_cast<float>(i) / segments * glm::two_pi<float>();
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        circleVertices.emplace_back(x, y, 0.0f);

        float texCoordX = 0.5f + 0.5f * cos(theta); // Map [-1, 1] to [0, 1]
        float texCoordY = 0.5f + 0.5f * sin(theta); // Map [-1, 1] to [0, 1]
        texCoords.emplace_back(texCoordX, texCoordY);

    }

    // setup ground VAO
    glGenVertexArrays(1, &this->circleVAO);
    glGenBuffers(1, &this->circleVBO);

    glBindVertexArray(this->circleVAO);
    glBindBuffer(GL_ARRAY_BUFFER, circleVBO);
    glBufferData(GL_ARRAY_BUFFER, circleVertices.size() * sizeof(glm::vec3), circleVertices.data(), GL_STATIC_DRAW);

    // Set vertex attribute pointers for positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);

    // Create and bind VBO for texture coordinates
    unsigned int VBO_texCoords;
    glGenBuffers(1, &VBO_texCoords);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_texCoords);
    glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(glm::vec2), texCoords.data(), GL_STATIC_DRAW);

    // Set vertex attribute pointers for texture coordinates
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
    glEnableVertexAttribArray(1);
}

void Circle::renderCircle(unsigned int texture)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(this->circleVAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, circleVertices.size());
}
