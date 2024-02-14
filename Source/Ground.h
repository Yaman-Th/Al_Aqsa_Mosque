#ifndef GROUND_H
#define GROUND_H

#include <learnopengl/shader.h>

#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <random>

class Ground
{
public:

	Ground();
	~Ground();

	void renderGround();
	void renderEnd();

	std::vector<glm::mat4> getLightSpaceMatrices();
	std::vector<glm::vec4> getFrustumCornersWorldSpace(const glm::mat4& projview);
	void drawCascadeVolumeVisualizers(const std::vector<glm::mat4>& lightMatrices, Shader* shader);

	float cameraNearPlane = 0.1f;
	float cameraFarPlane = 500.0f;

	Shader* shader = new Shader("10.shadow_mapping.vs", "10.shadow_mapping.fs");
	Shader *simpleDepthShader = new Shader("10.shadow_mapping_depth.vs", "10.shadow_mapping_depth.fs", "10.shadow_mapping_depth.gs");
	Shader *debugDepthQuad = new Shader("10.debug_quad.vs", "10.debug_quad_depth.fs");
	Shader *debugCascadeShader = new Shader("10.debug_cascade.vs", "10.debug_cascade.fs");

	std::vector<float> shadowCascadeLevels{ cameraFarPlane / 50.0f, cameraFarPlane / 25.0f, cameraFarPlane / 10.0f, cameraFarPlane / 2.0f };
	int debugLayer = 0;
	unsigned int groundTexture;

	const glm::vec3 lightDir = glm::normalize(glm::vec3(20.0f, 50, 20.0f));
	unsigned int lightFBO;
	unsigned int lightDepthMaps;
	unsigned int depthMapResolution = 4096;

	unsigned int matricesUBO;

	bool showQuad = false;

	std::random_device device;
	std::mt19937 generator = std::mt19937(device());

	std::vector<glm::mat4> lightMatricesCache;

	void renderAssis(const Shader shader);
	void renderQuad();
private:
	unsigned int groundVBO, groundVAO;

	void initRenderData();
	void loadTexture(char const* path);
	void initLight();
	//Shader shader("10.shadow_mapping.vs", "10.shadow_mapping.fs");
	//Shader simpleDepthShader("10.shadow_mapping_depth.vs", "10.shadow_mapping_depth.fs", "10.shadow_mapping_depth.gs");
	//Shader debugDepthQuad("10.debug_quad.vs", "10.debug_quad_depth.fs");
	//Shader debugCascadeShader("10.debug_cascade.vs", "10.debug_cascade.fs");

};

#endif 



