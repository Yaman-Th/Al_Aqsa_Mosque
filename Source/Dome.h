#pragma once

#include <learnopengl/shader.h>

#include <GLFW/glfw3.h>
#include <stb_image.h>


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<vector>
class Dome
{
public:
	Dome(unsigned int X_SEGMENTS, unsigned int Y_SEGMENTS);

	void renderDome(unsigned int texture);

private:
	unsigned int domeVAO, domeVBO, domeEBO, indexCount;

	std::vector<glm::vec3> positions;
	void initDome(unsigned int X_SEGMENTS, unsigned int Y_SEGMENTS);
};

