#include "Al_Qibli_Mosque.h"
#include"Cylinders.h"
#include"Dome.h"
#include"circle.h"

Cylinders* Cyl3;
Cylinders* Cyl4;
Dome* dome2;
Circle* circle2;

Al_Qibli_Mosque::Al_Qibli_Mosque()
{
    this->initRenderDate();
    QBMTexture    = this->loadTextures("Resources/Textures/QBM_1.png");
    QBM2Texture   = this->loadTextures("Resources/Textures/QBM_3.png");
    QBM3Texture   = this->loadTextures("Resources/Textures/QBM_2.png");
    QBM4Texture   = this->loadTextures("Resources/Textures/QBM_4.png");
    QBM5Texture   = this->loadTextures("Resources/Textures/QBM_5.png");
    mocketTexture = this->loadTextures("Resources/Textures/mocket_8.png");
    QBMdome       = this->loadTextures("Resources/Textures/QBM_Dome_1.png");
    QBMdome_2     = this->loadTextures("Resources/Textures/QBM_Dome_2.png");
    QBMdome_3     = this->loadTextures("Resources/Textures/testing_6.png");
}

Al_Qibli_Mosque::~Al_Qibli_Mosque()
{
}
void Al_Qibli_Mosque::initRenderDate() {

    Cyl3 = new Cylinders(0.5, 0.25, 128);
    Cyl4 = new Cylinders(0.55, 0.02, 128);

    dome2 = new Dome(128, 128);
    circle2 = new Circle(0.55, 128);

    float QBMVertices[] = {
       // side_1                                               
       -69.0f,   10.0f,  -25.0f,  6.0f, 1.0f, // top right    
       -69.0f,   -2.0f,  -25.0f,  6.0f, 0.0f, // bottom right 
      -124.4f,   -2.0f,  -25.0f,  0.0f, 0.0f, // bottom left  
      -124.4f,   10.0f,  -25.0f,  0.0f, 1.0f, // top left     
      -124.4f,   -2.0f,  -25.0f,  0.0f, 0.0f, // bottom left  
       -69.0f,   10.0f,  -25.0f,  6.0f, 1.0f, // top right   

        // side_2                                               
        -69.0f,   10.0f,  5.0f,  6.0f, 1.0f, // top right    
        -69.0f,   -2.0f,  5.0f,  6.0f, 0.0f, // bottom right 
       -124.4f,   -2.0f,  5.0f,  0.0f, 0.0f, // bottom left  
       -124.4f,   10.0f,  5.0f,  0.0f, 1.0f, // top left     
       -124.4f,   -2.0f,  5.0f,  0.0f, 0.0f, // bottom left  
        -69.0f,   10.0f,  5.0f,  6.0f, 1.0f, // top right     

        // right                          
        -75.0f,  10.0f, -25.0f, 4.0f, 1.0f, // top right     
        -75.0f,  -2.0f, -25.0f, 4.0f, 0.0f, // bottom right
        -75.0f,  -2.0f,  5.0f, 0.0f, 0.0f, // bottom left
        -75.0f,  10.0f,  5.0f, 0.0f, 1.0f, // top left
        -75.0f,  -2.0f,  5.0f, 0.0f, 0.0f, // bottom left
        -75.0f,  10.0f, -25.0f, 4.0f, 1.0f, // top right
        
        // left                          
       -124.4f,  10.0f, -25.0f, 6.0f, 1.0f, // top right     
       -124.4f,  -2.0f, -25.0f, 6.0f, 0.0f, // bottom right
       -124.4f,  -2.0f,  5.0f, 0.0f, 0.0f, // bottom left
       -124.4f,  10.0f,  5.0f, 0.0f, 1.0f, // top left
       -124.4f,  -2.0f,  5.0f, 0.0f, 0.0f, // bottom left
       -124.4f,  10.0f, -25.0f, 6.0f, 1.0f, // top right

       //  Roof                                               
        -69.0f,   10.0f, -25.0f,  10.0f, 8.0f, // top right    
        -69.0f,   10.0f,  5.0f,  10.0f, 0.0f, // bottom right 
       -125.1f,   10.0f,  5.0f,   0.0f, 0.0f, // bottom left  
       -125.1f,   10.0f, -25.0f,   0.0f, 8.0f, // top left     
       -125.1f,   10.0f,  5.0f,   0.0f, 0.0f, // bottom left  
        -69.0f,   10.0f, -25.0f,  10.0f, 8.0f, // top right 


        //  Mocket                                               
        -75.0f,  -1.95f, -25.0f,  15.0f, 5.0f, // top right    
        -75.0f,  -1.95f,  5.0f,  15.0f, 0.0f, // bottom right 
       -124.4f,  -1.95f,  5.0f,   0.0f, 0.0f, // bottom left  
       -124.4f,  -1.95f, -25.0f,   0.0f, 5.0f, // top left     
       -124.4f,  -1.95f,  5.0f,   0.0f, 0.0f, // bottom left  
        -75.0f,  -1.95f, -25.0f,  15.0f, 5.0f, // top right

        // external side
        // left_1                          
      -125.1f,  10.0f, -25.0f, 6.0f, 1.0f, // top right     
      -125.1f,  3.0f, -25.0f, 6.0f, 0.0f, // bottom right
      -125.1f,  3.0f,  5.0f, 0.0f, 0.0f, // bottom left
      -125.1f,  10.0f,  5.0f, 0.0f, 1.0f, // top left
      -125.1f,  3.0f,  5.0f, 0.0f, 0.0f, // bottom left
      -125.1f,  10.0f, -25.0f, 6.0f, 1.0f, // top right

      // right_1                          
      -124.47f,  10.0f, -25.0f, 6.0f, 1.0f, // top right   
      -124.47f,  3.0f, -25.0f, 6.0f, 0.0f, // bottom right
      -124.47f,  3.0f,  5.0f, 0.0f, 0.0f, // bottom left
      -124.47f,  10.0f,  5.0f, 0.0f, 1.0f, // top left
      -124.47f,  3.0f,  5.0f, 0.0f, 0.0f, // bottom left
      -124.47f,  10.0f, -25.0f, 6.0f, 1.0f, // top right

      // side_1                                               
      -124.47f,  10.0f,  -25.0f,  1.0f, 3.0f, // top right    
      -124.47f,  3.0f,  -25.0f,  1.0f, 0.0f, // bottom right 
      -125.1f,   3.0f,  -25.0f,  0.0f, 0.0f, // bottom left  
      -125.1f,   10.0f,  -25.0f,  0.0f, 3.0f, // top left     
      -125.1f,   3.0f,  -25.0f,  0.0f, 0.0f, // bottom left  
      -124.47f,  10.0f,  -25.0f,  1.0f, 3.0f, // top right   

       // side_2                                               
     -124.47f,   10.0f,  5.0f,  1.0f, 3.0f, // top right    
     -124.47f,   3.0f,  5.0f,  1.0f, 0.0f, // bottom right 
      -125.1f,   3.0f,  5.0f,  0.0f, 0.0f, // bottom left  
      -125.1f,   10.0f,  5.0f,  0.0f, 3.0f, // top left     
      -125.1f,   3.0f,  5.0f,  0.0f, 0.0f, // bottom left  
     -124.47f,   10.0f,  5.0f,  1.0f, 3.0f, // top right   

     // left_2                          
   -125.1f,  3.0f, -25.0f, 9.0f, 2.5f, // top right    
   -125.1f,  -4.0f, -25.0f, 9.0f, 0.0f, // bottom right
   -125.1f,  -4.0f,  5.0f, 0.0f, 0.0f, // bottom left
   -125.1f,  3.0f,  5.0f, 0.0f, 2.5f, // top left
   -125.1f,  -4.0f,  5.0f, 0.0f, 0.0f, // bottom left
   -125.1f,  3.0f, -25.0f, 9.0f, 2.5f, // top right

   // right_2                          
   -124.47f,  3.0f, -25.0f, 9.0f, 2.5f, // top right   
   -124.47f,  -4.0f, -25.0f, 9.0f, 0.0f, // bottom right
   -124.47f,  -4.0f,  5.0f, 0.0f, 0.0f, // bottom left
   -124.47f,  3.0f,  5.0f, 0.0f, 2.5f, // top left
   -124.47f,  -4.0f,  5.0f, 0.0f, 0.0f, // bottom left
   -124.47f,  3.0f, -25.0f, 9.0f, 2.5f, // top right

    };
    float QBMVertices_2[] = {

       // side_1                                               
       -112.0f,   12.0f,  -13.0f,  4.0f, 1.0f, // top right    
       -112.0f,   10.0f,  -13.0f,  4.0f, 0.0f, // bottom right 
        -80.0f,   10.0f,  -13.0f,  0.0f, 0.0f, // bottom left  
        -80.0f,   12.0f,  -13.0f,  0.0f, 1.0f, // top left     
        -80.0f,   10.0f,  -13.0f,  0.0f, 0.0f, // bottom left  
       -112.0f,   12.0f,  -13.0f,  4.0f, 1.0f, // top right   

       // side_2                                               
        -80.0f,    12.0f,  -2.0f,  4.0f, 1.0f, // top right    
        -80.0f,    10.0f,  -2.0f,  4.0f, 0.0f, // bottom right 
       -112.0f,    10.0f,  -2.0f,  0.0f, 0.0f, // bottom left  
       -112.0f,    12.0f,  -2.0f,  0.0f, 1.0f, // top left     
       -112.0f,    10.0f,  -2.0f,  0.0f, 0.0f, // bottom left  
        -80.0f,    12.0f,  -2.0f,  4.0f, 1.0f, // top right     

        // right                          
        -80.0f,   12.0f,  -2.0f, 4.0f, 1.0f, // top right     
        -80.0f,   10.0f,  -2.0f, 4.0f, 0.0f, // bottom right
        -80.0f,   10.0f, -13.0f, 0.0f, 0.0f, // bottom left
        -80.0f,   12.0f, -13.0f, 0.0f, 1.0f, // top left
        -80.0f,   10.0f, -13.0f, 0.0f, 0.0f, // bottom left
        -80.0f,   12.0f,  -2.0f, 4.0f, 1.0f, // top right

        // left                          
       -112.0f,   12.0f,  -2.0f, 4.0f, 1.0f, // top right     
       -112.0f,   10.0f,  -2.0f, 4.0f, 0.0f, // bottom right
       -112.0f,   10.0f, -13.0f, 0.0f, 0.0f, // bottom left
       -112.0f,   12.0f, -13.0f, 0.0f, 1.0f, // top left
       -112.0f,   10.0f, -13.0f, 0.0f, 0.0f, // bottom left
       -112.0f,   12.0f,  -2.0f, 4.0f, 1.0f, // top right

         // roof                                               
        -80.0f,   12.0f,   -2.0f,  6.0f, 3.0f, // top right    
        -80.0f,   12.0f,  -13.0f,  6.0f, 0.0f, // bottom right 
       -112.0f,   12.0f,  -13.0f,  0.0f, 0.0f, // bottom left  
       -112.0f,   12.0f,   -2.0f,  0.0f, 3.0f, // top left     
       -112.0f,   12.0f,  -13.0f,  0.0f, 0.0f, // bottom left  
        -80.0f,   12.0f,   -2.0f,  6.0f, 3.0f, // top right 


          -79.5f,   12.5f,   -7.5f,  4.0f, 2.0f, // top right
          -79.5f,   12.0f,  -13.5f,  4.0f, 0.0f, // bottom right 
         -112.5f,   12.0f,  -13.5f,  0.0f, 0.0f, // bottom left 

         -112.5f,   12.5f,   -7.5f,  0.0f, 2.0f, // top left
         -112.5f,   12.0f,  -13.5f,  0.0f, 0.0f, // bottom left
          -79.5f,   12.5f,   -7.5f,  4.0f, 2.0f, // top right

          -79.5f,    12.5f,  -7.5f,  4.0f, 2.0f, // top right
          -79.5f,    12.0f,  -1.5f,  4.0f, 0.0f, // bottom right 
          -112.5f,   12.0f,  -1.5f,  0.0f, 0.0f, // bottom left

          -112.5f,   12.5f,  -7.5f,  0.0f, 2.0f, // top left
          -112.5f,   12.0f,  -1.5f,  0.0f, 0.0f, // bottom left
          -79.5f,    12.5f,  -7.5f,  4.0f, 2.0f, // top right

    };

    // setup ground VAO
    glGenVertexArrays(1, &this->Al_Qibli_MosqueVAO);
    glGenBuffers(1, &this->Al_Qibli_MosqueVBO);
    glBindVertexArray(this->Al_Qibli_MosqueVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->Al_Qibli_MosqueVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(QBMVertices), QBMVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // setup ground VAO_2
    glGenVertexArrays(1, &this->Al_Qibli_Mosque_2VAO);
    glGenBuffers(1, &this->Al_Qibli_Mosque_2VBO);
    glBindVertexArray(this->Al_Qibli_Mosque_2VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->Al_Qibli_Mosque_2VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(QBMVertices_2), QBMVertices_2, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

}
unsigned int Al_Qibli_Mosque::loadTextures(const char* path)
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

void Al_Qibli_Mosque::renderAl_Qibli_Mosque() {

    //glm::mat4 model = glm::mat4(1.0f);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,QBMTexture);
    glBindVertexArray(this->Al_Qibli_MosqueVAO);

    // top
    glDrawArrays(GL_TRIANGLES, 0, 6);
    // bottom
    glDrawArrays(GL_TRIANGLES, 6, 6);
    // left
    glDrawArrays(GL_TRIANGLES, 12, 6);
    // right
    glDrawArrays(GL_TRIANGLES, 18, 6);


    // roof
    glBindTexture(GL_TEXTURE_2D, QBM2Texture);
    glDrawArrays(GL_TRIANGLES, 24, 6);

    // mocket
    glBindTexture(GL_TEXTURE_2D, mocketTexture);
    glDrawArrays(GL_TRIANGLES, 30, 6);

    // external side
    glBindTexture(GL_TEXTURE_2D, QBM4Texture);
    glDrawArrays(GL_TRIANGLES, 36, 12);

    glBindTexture(GL_TEXTURE_2D, QBM5Texture);
    glDrawArrays(GL_TRIANGLES, 48, 12);


    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -6.0f));
    shader->setMat4("model", model);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, QBM3Texture);
    glBindVertexArray(this->Al_Qibli_Mosque_2VAO);
    glDrawArrays(GL_TRIANGLES, 0, 30);

    glBindTexture(GL_TEXTURE_2D, QBM2Texture);
    glDrawArrays(GL_TRIANGLES, 30, 12);

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-119.0f, 11.15f, -13.5f));
    model = glm::scale(model, glm::vec3(9.0f, 9.0f, 9.0f));
    shader->setMat4("model", model);
    Cyl3->renderCylinder(QBMdome_2);

    model = glm::translate(model, glm::vec3(0.0f, 0.125f, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader->setMat4("model", model);
    circle2->renderCircle(QBM2Texture);

     model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
     model = glm::translate(model, glm::vec3(0.0f, 0.01f, 0.0f));
   //model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    shader->setMat4("model", model);
    Cyl4->renderCylinder(QBMdome_3);

    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -0.01f));
    //model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    shader->setMat4("model", model);
    circle2->renderCircle(QBM2Texture);

    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -0.01f));
    model = glm::scale(model, glm::vec3(0.52f, 0.52f, 0.6f));
    model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader->setMat4("model", model);
    dome2->renderDome(QBMdome);


    //for (int i = 0; i < 2; i++)
    //{
    //    float z = i * -100;
    //    model = glm::mat4(1.0f);
    //    model = glm::translate(model, glm::vec3(-190.0f, 0.01f, 60.0f + z));
    //    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    //    shader->setMat4("model", model);
    //    glActiveTexture(GL_TEXTURE0);
    //    glBindTexture(GL_TEXTURE_2D, GardenTexture);
    //    glBindVertexArray(this->GardenVAO);
    //    glDrawArrays(GL_TRIANGLES, 0, 30);
    //}
    
    
}
