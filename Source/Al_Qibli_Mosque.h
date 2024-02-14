#pragma once

#include <learnopengl/shader.h>

#include <GLFW/glfw3.h>
#include <stb_image.h>


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Al_Qibli_Mosque
{
public:
	Al_Qibli_Mosque();
	~Al_Qibli_Mosque();

	void initRenderDate();
	unsigned int loadTextures(const char* path);
	void renderAl_Qibli_Mosque();
	void renderEnd();

	Shader* shader = new Shader("6.1.coordinate_systems.vs", "6.1.coordinate_systems.fs");

private:

	unsigned int Al_Qibli_MosqueVAO, Al_Qibli_MosqueVBO,        
		         Al_Qibli_Mosque_2VBO, Al_Qibli_Mosque_2VAO,    
				 QBMTexture, QBM2Texture, QBM3Texture, QBMdome, 
				 QBMdome_2, QBMdome_3, mocketTexture, QBM4Texture,
		         QBM5Texture;

};