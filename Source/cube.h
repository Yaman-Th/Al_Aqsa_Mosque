#ifndef CUBE_H
#define CUBE_H


#include<learnopengl/shader_m.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class cube
{
public:
    Shader *shader = new Shader("6.2.cubemaps.vs", "6.2.cubemaps.fs");

    // Constructor (inits shaders/shapes)
    cube();

    // Destructor
    ~cube();

    // Renders a defined quad textured with given sprite
    void Drawcube(unsigned int texture);
    void renderEnd();

private:
    // Render state
    unsigned int cubeVAO, cubeVBO;
    // Initializes and configures the quad's buffer and vertex attributes
    void initRenderData();
};
#endif