#ifndef MANAGER_H
#define MANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include"texture.h"

//#include <learnopengl/model.h>
#include <learnopengl/mesh.h>
#include <learnopengl/camera.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>


class Manager
{
private:
	const unsigned int Width;
	const unsigned int Height;

	vector<std::string> faces
	{
		"Resources/Skyboxes/Ground/right.jpg" ,
		"Resources/Skyboxes/Ground/left.jpg"  ,
		"Resources/Skyboxes/Ground/top.jpg"   ,
		"Resources/Skyboxes/Ground/down.jpg",
		"Resources/Skyboxes/Ground/front.jpg" ,
		"Resources/Skyboxes/Ground/back.jpg"  ,
	};

	vector<std::string> faces_2
	{
		"Resources/Skyboxes/Palastine/right.jpg" ,
		"Resources/Skyboxes/Palastine/left.jpg"  ,
		"Resources/Skyboxes/Palastine/top.jpg"   ,
		"Resources/Skyboxes/Palastine/down.jpg",
		"Resources/Skyboxes/Palastine/front.jpg" ,
		"Resources/Skyboxes/Palastine/back.jpg"  ,
	};

	vector<std::string> faces_3
	{
		"Resources/Skyboxes/Mountain/right.jpg" ,
		"Resources/Skyboxes/Mountain/left.jpg"  ,
		"Resources/Skyboxes/Mountain/top.jpg"   ,
		"Resources/Skyboxes/Mountain/down.jpg",
		"Resources/Skyboxes/Mountain/front.jpg" ,
		"Resources/Skyboxes/Mountain/back.jpg"  ,
	};

	unsigned int cubemaptextures;
	unsigned int textureID;

	unsigned int loadCubemap(vector<std::string> faces);

	void RenderCubes();
	void RenderSkybox();

public:

	GLFWwindow* window;
	// constructor && destructor
	Manager(unsigned int width, unsigned int height);
	~Manager();

	void createWindow();
	void InitProject();
	void InitResources();
	void ProcessInput(float dt);
	void Update(float dt);
	void renderScene(Camera camera);
	void End();
	glm::mat4 getLightSpaceMatrix(const float nearPlane, const float farPlane);
};

#endif

