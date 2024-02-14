#pragma once

#include <learnopengl/shader.h>
#include <stb_image.h>

#include <string>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>

class Environment
{
public:
	Environment();
	void renderEnv();

	Shader* shader = new Shader("1.model_loading.vs", "1.model_loading.fs");
private:

	void InitRenderData();

	unsigned int loadTextures(const char* path);

	

};

