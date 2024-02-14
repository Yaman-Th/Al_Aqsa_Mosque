#pragma once

#include <learnopengl/shader.h>

#include <GLFW/glfw3.h>
#include <stb_image.h>


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

class Cylinders
{
public:
	Cylinders(float radius, float height, unsigned int segments);
	Cylinders(float radius, float height, unsigned int segments, bool semi);
	void renderCylinder(unsigned int texture);



private:

	unsigned int cylinderVAO, cylinderVBO, cylinderTexture;
	std::vector<glm::vec3> cylinderPositions;

	void initCylinder(float radius, float height, unsigned int segments);
	void initSemiCylinder(float radius, float height, unsigned int segments);
};

