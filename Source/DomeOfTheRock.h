#pragma once

#include <learnopengl/shader.h>

#include <GLFW/glfw3.h>
#include <stb_image.h>


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<vector>

class DomeOfTheRock
{
public:
	DomeOfTheRock();

	~DomeOfTheRock();

	void initRenderDate();
	unsigned int loadTexture(const char* path);
	void renderDomeOfTheRock();
	void renderEnd();

	Shader* shader = new Shader("6.1.coordinate_systems.vs", "6.1.coordinate_systems.fs");

private:
	unsigned int baseVAO, baseVBO, baseTexture, base2Texture;

	unsigned int firstVAO, firstVBO, firstTexture;

	unsigned int secondVAO, secondVBO, secondTexture;

	unsigned int thirdVAO, thirdVBO, thirdTexture;

	unsigned int forthVAO, forthVBO, forthTexture;

	unsigned int  mocketVBO, mocketVAO, mocketEBO, mocketTexture, mocket_2Texture, groundTexture;

	unsigned int  aroundDomeVBO, aroundDomeVAO, aroundDomeTexture, domeTexture, topTexture; 

	unsigned int cylinderTexture, cylinder2Texture;

	unsigned int GardenVBO, GardenVAO, GardenTexture;
};

