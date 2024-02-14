#pragma once
#include <learnopengl/shader.h>

#include <GLFW/glfw3.h>
#include <stb_image.h>


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

class Circle
{
public:
	Circle(float radius, int segments);
	void renderCircle(unsigned int texture);

private:
	void initRenderDate(float radius, int segments);

	std::vector<glm::vec3> circleVertices;
	unsigned int  circleVBO, circleVAO, circleTexture;
};

