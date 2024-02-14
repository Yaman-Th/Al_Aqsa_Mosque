#pragma once

#include <learnopengl/shader.h>

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <assimp/scene.h>

class model {
public:
    model();

    void modelsRender();

    Shader* shader = new Shader("1.model_loading.vs","1.model_loading.fs");

private:
    
    void initRenderData();
    unsigned int loadTexture(char const* path);
    void loadGLTF();

    unsigned int topTexture, minrateTexture, topTexture_2, columns_2Texture,
                 oldBuildTexture, columnsTexture, holiTexture, doorTexture;
};


