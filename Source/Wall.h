#pragma once

#include <learnopengl/shader.h>

#include <GLFW/glfw3.h>
#include <stb_image.h>


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Wall
{
public:
	Wall();
	~Wall();

	void initRenderDate();
	void loadTextures(const char* path);
	void renderWall();
	void renderEnd();

	Shader *shader = new Shader("6.1.coordinate_systems.vs", "6.1.coordinate_systems.fs");

private:

	unsigned int wallVAO, wallVBO, wallVBO_2, wallVAO_2, wallTexture, cubeVAO, cubeVBO;


   glm::vec3 cubePositions_1[59];

   glm::vec3 cubePositions_2[60];

   glm::vec3 cubePositions_3[108];

   glm::vec3 cubePositions_4[108];

};

