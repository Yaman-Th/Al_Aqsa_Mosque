#ifndef SKYBOX_H
#define SKYBOX_H


#include<learnopengl/shader_m.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class skybox
{
public:
    // Constructor (inits shaders/shapes)
    skybox();

    // Destructor
    ~skybox();

    // Renders a defined quad textured with given sprite
    void Drawskybox(unsigned int texture);
    void renderEnd();

    Shader *shader = new Shader("6.2.skybox.vs", "6.2.skybox.fs") ;
private:
    // Render state
    unsigned int skyboxVAO, skyboxVBO;
    // Initializes and configures the quad's buffer and vertex attributes
    void initRenderData();
    
};

#endif

