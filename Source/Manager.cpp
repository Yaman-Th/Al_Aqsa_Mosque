#include "Manager.h"

#include"cube.h"
#include"skybox.h"
#include"Ground.h"
#include"Wall.h"
#include"DomeOfTheRock.h"
#include "Al_Qibli_Mosque.h"
#include"Environment.h"
#include"model.h"

skybox *firstSkybox;
cube *firstCube;
Ground *ground;
Wall* wall;
DomeOfTheRock* dom;
Al_Qibli_Mosque* QM;
model* models;
Environment* env;



Manager::Manager(unsigned int width, unsigned int height)
	:Width(width),Height(height)
{

}

Manager::~Manager()
{
}

void Manager::createWindow()
{
	this->window = glfwCreateWindow(Width, Height, "AQSA_PROJECT", nullptr, nullptr);
	glfwMakeContextCurrent(window);

    return ;
}
void Manager::InitProject()
{
}

void Manager::InitResources()
{
    
	//ResourceManager::LoadShader("6.2.cubemaps.vs", "6.2.cubemaps.fs",nullptr,"programShader");
	//ResourceManager::LoadShader("6.2.skybox.vs", "6.2.skybox.fs", nullptr, "skyboxShader");

     this->cubemaptextures = loadCubemap(this->faces);


     firstSkybox = new skybox();
	 firstCube = new cube();
     ground = new Ground();
     wall = new Wall();
     dom = new DomeOfTheRock();
     models = new model();
     QM = new Al_Qibli_Mosque();
     //env = new Environment();

}



unsigned int Manager::loadCubemap(vector<std::string> faces)
{
    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->textureID);

    int width, height, nrComponents;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrComponents, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}

void Manager::ProcessInput(float dt)
{
}

void Manager::Update(float dt)
{
}

void Manager::RenderSkybox()
{
    firstSkybox->Drawskybox(this->cubemaptextures);
}

void Manager::RenderCubes()
{
    firstCube->Drawcube(this->cubemaptextures);

}

void Manager::End()
{
    firstCube->renderEnd();
    firstSkybox->renderEnd();
    ground->renderEnd();
    wall->renderEnd();
    dom->renderEnd();
}

void Manager::renderScene(Camera camera)
{
    glm::mat4 model = glm::mat4(1.0f); 
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    ground->shader->use();
    ground->shader->setInt("diffuseTexture", 0);
    ground->shader->setInt("shadowMap", 1);
    ground->debugDepthQuad->use();
    ground->debugDepthQuad->setInt("depthMap", 0);

    ground->simpleDepthShader->use();

    glBindFramebuffer(GL_FRAMEBUFFER, ground->lightFBO);
    glViewport(0, 0, ground->depthMapResolution, ground->depthMapResolution);
    glClear(GL_DEPTH_BUFFER_BIT);
    glCullFace(GL_FRONT);  // peter panning
    ground->renderAssis(*ground->simpleDepthShader);
    glCullFace(GL_BACK);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // reset viewport
    glViewport(0, 0, 1920, 1080);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, 1920, 1080);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ground->shader->use();
    projection = glm::perspective(glm::radians(camera.Zoom), (float)1920 / (float)1080, ground->cameraNearPlane, ground->cameraFarPlane);
    view = camera.GetViewMatrix();
    ground->shader->setMat4("projection", projection);
    ground->shader->setMat4("view", view);
    // set light uniforms
    ground->shader->setVec3("viewPos", camera.Position);
    ground->shader->setVec3("lightDir", ground->lightDir);
    ground->shader->setFloat("farPlane", ground->cameraFarPlane);
    ground->shader->setInt("cascadeCount", ground->shadowCascadeLevels.size());
    for (size_t i = 0; i < ground->shadowCascadeLevels.size(); ++i)
    {
        ground->shader->setFloat("cascadePlaneDistances[" + std::to_string(i) + "]", ground->shadowCascadeLevels[i]);
    }
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, ground->groundTexture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D_ARRAY, ground->lightDepthMaps);
    ground->renderAssis(*ground->shader);

    if (ground->lightMatricesCache.size() != 0)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        ground->debugCascadeShader->use();
        ground->debugCascadeShader->setMat4("projection", projection);
        ground->debugCascadeShader->setMat4("view", view);
        glDisable(GL_BLEND);
    }

    model = glm::scale(model,glm::vec3(1.5f,1.0f,1.5f));
    // render Depth map to quad for visual debugging
    // ---------------------------------------------
    ground->debugDepthQuad->use();
    ground->debugDepthQuad->setInt("layer", ground->debugLayer);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D_ARRAY, ground->lightDepthMaps);
    if (ground->showQuad)
    {
        ground->renderQuad();
    }

    // Wall
    model = glm::mat4(1.0f);
    wall->shader->use();
    wall->shader->setMat4("model", model);
    wall->shader->setMat4("view", view);
    wall->shader->setMat4("projection", projection);
    wall->renderWall();

    // DomeOfTheRock
    model = glm::mat4(1.0f);
    dom->shader->use();
    dom->shader->setMat4("model", model);
    dom->shader->setMat4("view", view);
    dom->shader->setMat4("projection", projection);
    dom->renderDomeOfTheRock();

    // AlQibliMosque
    model = glm::mat4(1.0f);
    QM->shader->use();
    QM->shader->setMat4("model", model);
    QM->shader->setMat4("view", view);
    QM->shader->setMat4("projection", projection);
    QM->renderAl_Qibli_Mosque();


    // RENDER MODELS
    model = glm::mat4(1.0f);
    models->shader->use();
    models->shader->setMat4("model", model);
    models->shader->setMat4("view", view);
    models->shader->setMat4("projection", projection);
    models->modelsRender();

    // draw skybox as last
    glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
    firstSkybox->shader->use();
    view = glm::mat4(glm::mat3(camera.GetViewMatrix())); // remove translation from the view matrix
    firstSkybox->shader->setMat4("view", view);
    firstSkybox->shader->setMat4("projection", projection);
    // skybox cube
    RenderSkybox();
}
