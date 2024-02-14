#include"model.h"
#include <learnopengl/model.h>

Model* topMosque;
Model* oldBuild;
Model* column;
Model* column_2;
Model* tree_1;
Model* tree_2;
Model* holi;
Model* arch;
Model* oldArch;
Model* oldArch_2;
Model* door;

model::model() 
{
	this->initRenderData();

    this->topTexture = this->loadTexture("Resources/Textures/dome_2.png");
    this->minrateTexture = this->loadTexture("Resources/Textures/rock.png");
    this->topTexture_2 = this->loadTexture("Resources/Textures/silver.png");
    this->oldBuildTexture = this->loadTexture("Resources/Textures/ground_2.png");
    this->columnsTexture = this->loadTexture("Resources/Textures/columns_1.png");
    this->holiTexture = this->loadTexture("Resources/Textures/testing.png");
    this->columns_2Texture = this->loadTexture("Resources/Textures/columns_2.png");
    this->doorTexture = this->loadTexture("Resources/Textures/door.png");
    
}

void model::modelsRender()
{   
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(45.5f, 17.3f, -9.3f));
    model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));
    model = glm::rotate(model,glm::radians(90.0f), glm::vec3(0.0f,1.0f,0.0f));
    this->shader->setMat4("model", model);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, topTexture);
    topMosque->Draw(*this->shader);

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-119.0f, 17.9f, -16.2f));
    model = glm::scale(model, glm::vec3(0.03f, 0.03f, 0.03f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader->setMat4("model", model);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, topTexture_2);
    topMosque->Draw(*this->shader);

    // Render Houses
    for (int i = 0; i < 6; i++) 
        {
            for (int j = 0; j < 6; j++) 
            {
                float x = i * -50.0;
                float z = j * -30.0;
        
                model = glm::mat4(1.0f);
                model = glm::translate(model, glm::vec3(x + 130.0f, -6.0f,260.0 + z));
                model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
     
                this->shader->setMat4("model", model);
                
                glBindTexture(GL_TEXTURE_2D, minrateTexture);
                oldBuild->Draw(*this->shader);
            }
        
        }
        
    // Render Columns
    for (int i = 0; i < 6; i++)
    {
        
            float x = i * 10.0;

            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(-115 + x, -2.0f, 20.0));
            model = glm::scale(model, glm::vec3(1.4f, 1.4f, 1.4f));
            this->shader->setMat4("model", model);
            glBindTexture(GL_TEXTURE_2D, columnsTexture);
            column->Draw(*this->shader);
    }

    for (int i = 0; i < 6; i++)
    {

        float x = i * 10.0;

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-115 + x, -2.0f, -38.0));
        model = glm::scale(model, glm::vec3(1.4f, 1.4f, 1.4f));
        this->shader->setMat4("model", model);
        glBindTexture(GL_TEXTURE_2D, columnsTexture);
        column->Draw(*this->shader);
    }

    // Render Trees
    for (int i = 0; i < 3; i++) 
    {
        float z1 = i * -50;
        for (int j = 0; j < 4; j++) 
        {
            float x = j * -12;
            for (int k = 0; k < 3; k++) 
            {
                float z2 = k * 10;
                model = glm::mat4(1.0f);
                model = glm::translate(model, glm::vec3(140.0f+x, -2.0f, 40.0f+z1+z2));
                model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
                //model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader->setMat4("model", model);
                tree_1->Draw(*this->shader);

            }
        }

    }

    //Render Column_2
    for(int k=0;k<2;k++)
    {
        float n = k * 6.0f;
        for (int i = 0; i < 2; i++) 
        {
            float x = i * 2.0f;
            for (int j = 0; j < 2; j++)
            {
                float z = j * 0.8f;
                model = glm::mat4(1.0f);
                model = glm::translate(model, glm::vec3(27.0f, -2.0f, -0.3f - (z+x+n)));
                model = glm::scale(model, glm::vec3(0.35f, 0.405f, 0.35f));
                //model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader->setMat4("model", model);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, columns_2Texture);
                column_2->Draw(*this->shader);

            }


        }
    }

    //Render Archs
    for (int i = 0; i < 4; i++) {

       float z = i * 7.3;
    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-69.9f, -2.0f, 4.0f - z));
    model = glm::scale(model, glm::vec3(0.03f, 0.039f, 0.032f));
    model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    shader->setMat4("model", model);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, columnsTexture);
    arch->Draw(*this->shader);

    }


    // Render big arch
    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.015f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    //model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader->setMat4("model", model);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, oldBuildTexture);
    //oldArch->Draw(*this->shader);

    // Render doorArch
    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(27.0f, 0.89f, -4.70f));
    model = glm::scale(model, glm::vec3(0.58f, 0.6f, 0.82f)); 
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    //model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader->setMat4("model", model);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, holiTexture);
    oldArch_2->Draw(*this->shader);

    // Render door
    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(29.5f, -1.68f, -4.592f));
    model = glm::scale(model, glm::vec3(0.02f, 0.0137f, 0.02f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    shader->setMat4("model", model);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, doorTexture);
    door->Draw(*this->shader);

}

void model::initRenderData()
{
    topMosque = new Model("Resources/Models/HILAL ALEM PASABAHCE/model.obj");
    column = new Model("Resources/Models/Column/uploads_files_2681501_Column.obj");
    tree_1 = new Model("Resources/Models/Trees/Tree 02/Tree.obj");
    tree_2 = new Model("Resources/Models/Trees/Tree_1/model.obj");
    //holi = new Model("Resources/Models/Holicapter/helipainter.obj");
    column_2 = new Model("Resources/Models/Column_3/columns_001.obj");
    oldBuild = new Model("Resources/Models/oldBuild/model.obj");
    arch = new Model("Resources/Models/Arch/arch.FBX");
    oldArch = new Model("Resources/Models/OldArch/model.obj");
    oldArch_2 = new Model("Resources/Models/OldArch_2/P_DoorArch_4096.obj");
    door = new Model("Resources/Models/door/door.obj");

}

unsigned int model::loadTexture(char const* path)
{
    stbi_set_flip_vertically_on_load(true);

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

void model::loadGLTF()
{
    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile("Resources/Models/birds/scene.gltf",
        aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "Assimp error: " << importer.GetErrorString() << std::endl;
        
    }
    
}

