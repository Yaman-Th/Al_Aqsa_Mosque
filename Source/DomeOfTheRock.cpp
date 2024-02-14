#include "DomeOfTheRock.h"
#include"Cylinders.h"
#include"Dome.h"
#include"Circle.h"

Cylinders* Cyl1;
Cylinders* Cyl2;
Cylinders* semiCyl;

Dome* dome;

Circle* circle;

DomeOfTheRock::DomeOfTheRock()
{
    this->initRenderDate();
    this->baseTexture = this->loadTexture("Resources/Textures/DOM_2.png");
    this->firstTexture = this->loadTexture("Resources/Textures/DOM.png");
    this->aroundDomeTexture = this->loadTexture("Resources/Textures/aroundDome.png");
    this->mocketTexture = this->loadTexture("Resources/Textures/mocket_4.png");
    this->mocket_2Texture = this->loadTexture("Resources/Textures/mocket_5.png");
    this->groundTexture = this->loadTexture("Resources/Textures/Ground/ground_1.png");
    this->thirdTexture = this->loadTexture("Resources/Textures/DOM_3.png");
    this->forthTexture = this->loadTexture("Resources/Textures/top_3.png");
    this->domeTexture = this->loadTexture("Resources/Textures/dome_7.png");
    this->cylinderTexture = this->loadTexture("Resources/Textures/testing_4.png");
    this->cylinder2Texture = this->loadTexture("Resources/Textures/testing_5.png");
    this->base2Texture = this->loadTexture("Resources/Textures/DOM_4.png");
    this->GardenTexture = this->loadTexture("Resources/Textures/soil_2.png");
    
}

DomeOfTheRock::~DomeOfTheRock()
{
}

void DomeOfTheRock::initRenderDate()
{
    // base vertices
    float baseVertices[] = {

        // side_1                          
        60.0f,   1.0f,   1.5f,  3.0f, 1.0f, // top right   
        60.0f,  -2.0f,   1.5f,  3.0f, 0.0f, // bottom right
        51.5f,  -2.0f,  10.0f,  0.0f, 0.0f, // bottom left 
        51.5f,   1.0f,  10.0f,  0.0f, 1.0f, // top left    
        51.5f,  -2.0f,  10.0f,  0.0f, 0.0f, // bottom left 
        60.0f,   1.0f,   1.5f,  3.0f, 1.0f, // top right   

        // side_2                                         
        51.5f,   1.0f,  10.0f,  3.0f, 1.0f, // top right   
        51.5f,  -2.0f,  10.0f,  3.0f, 0.0f, // bottom right
        38.5f,  -2.0f,  10.0f,  0.0f, 0.0f, // bottom left 
        38.5f,   1.0f,  10.0f,  0.0f, 1.0f, // top left    
        38.5f,  -2.0f,  10.0f,  0.0f, 0.0f, // bottom left 
        51.5f,   1.0f,  10.0f,  3.0f, 1.0f, // top right   

        // side_3                                         
        38.5f,   1.0f,  10.0f,  3.0f, 1.0f, // top right   
        38.5f,  -2.0f,  10.0f,  3.0f, 0.0f, // bottom right
        30.0f,  -2.0f,   1.5f,  0.0f, 0.0f, // bottom left 
        30.0f,   1.0f,   1.5f,  0.0f, 1.0f, // top left    
        30.0f,  -2.0f,   1.5f,  0.0f, 0.0f, // bottom left 
        38.5f,   1.0f,  10.0f,  3.0f, 1.0f, // top right   

        // side_4                                         
        30.0f,   1.0f,   1.5f,  3.0f, 1.0f, // top right   
        30.0f,  -2.0f,   1.5f,  3.0f, 0.0f, // bottom right
        30.0f,  -2.0f, -11.5f,  0.0f, 0.0f, // bottom left 
        30.0f,   1.0f, -11.5f,  0.0f, 1.0f, // top left    
        30.0f,  -2.0f, -11.5f,  0.0f, 0.0f, // bottom left 
        30.0f,   1.0f,   1.5f,  3.0f, 1.0f, // top right   

        // side_5                                         
        30.0f,   1.0f, -11.5f,  3.0f, 1.0f, // top right   
        30.0f,  -2.0f, -11.5f,  3.0f, 0.0f, // bottom right
        38.5f,  -2.0f, -20.0f,  0.0f, 0.0f, // bottom left 
        38.5f,   1.0f, -20.0f,  0.0f, 1.0f, // top left    
        38.5f,  -2.0f, -20.0f,  0.0f, 0.0f, // bottom left 
        30.0f,   1.0f, -11.5f,  3.0f, 1.0f, // top right   

        // side_6                                         
        38.5f,   1.0f, -20.0f,  3.0f, 1.0f, // top right   
        38.5f,  -2.0f, -20.0f,  3.0f, 0.0f, // bottom right
        51.5f,  -2.0f, -20.0f,  0.0f, 0.0f, // bottom left 
        51.5f,   1.0f, -20.0f,  0.0f, 1.0f, // top left    
        51.5f,  -2.0f, -20.0f,  0.0f, 0.0f, // bottom left 
        38.5f,   1.0f, -20.0f,  3.0f, 1.0f, // top right   

        // side_7                                         
        51.5f,   1.0f, -20.0f,  3.0f, 1.0f, // top right   
        51.5f,  -2.0f, -20.0f,  3.0f, 0.0f, // bottom right
        60.0f,  -2.0f, -11.5f,  0.0f, 0.0f, // bottom left 
        60.0f,   1.0f, -11.5f,  0.0f, 1.0f, // top left    
        60.0f,  -2.0f, -11.5f,  0.0f, 0.0f, // bottom left 
        51.5f,   1.0f, -20.0f,  3.0f, 1.0f, // top right   

        // side_8                          
        60.0f,   1.0f,   1.5f,  3.0f, 1.0f, // top right   
        60.0f,  -2.0f,   1.5f,  3.0f, 0.0f, // bottom right
        60.0f,  -2.0f, -11.5f,  0.0f, 0.0f, // bottom left
        60.0f,   1.0f, -11.5f,  0.0f, 1.0f, // top left
        60.0f,  -2.0f, -11.5f,  0.0f, 0.0f, // bottom left
        60.0f,   1.0f,   1.5f,  3.0f, 1.0f, // top right 


        //external roofs
        // down                                         
        30.0f,   0.9f,   0.13f,  1.0f, 4.0f, // top right   
        26.72f,  0.9f,   0.13f,  1.0f, 0.0f, // bottom right
        26.72f,  0.9f,  -2.60f,  0.0f, 0.0f, // bottom left 
        30.0f,   0.9f,  -2.60f,  0.0f, 4.0f, // top left    
        26.72f,  0.9f,  -2.60f,  0.0f, 0.0f, // bottom left 
        30.0f,   0.9f,   0.13f,  1.0f, 4.0f, // top right  

        // Up                                         
        30.0f,   1.6f,   0.13f,  1.0f, 4.0f, // top right   
        26.72f,  1.2f,   0.13f,  1.0f, 0.0f, // bottom right
        26.72f,  1.2f,  -2.60f,  0.0f, 0.0f, // bottom left 
        30.0f,   1.6f,  -2.60f,  0.0f, 4.0f, // top left    
        26.72f,  1.2f,  -2.60f,  0.0f, 0.0f, // bottom left 
        30.0f,   1.6f,   0.13f,  1.0f, 4.0f, // top right   

        // right                                         
        30.0f,   1.6f,   0.13f,  1.0f, 1.0f, // top right   
        30.0f,   0.9f,   0.13f,  1.0f, 0.0f, // bottom right
        26.72f,  0.9f,   0.13f,  0.0f, 0.0f, // bottom left 
        26.72f,  1.2f,   0.13f,  0.0f, 1.0f, // top left    
        26.72f,  0.9f,   0.13f,  0.0f, 0.0f, // bottom left 
        30.0f,   1.6f,   0.13f,  1.0f, 1.0f, // top right   

        // left                                         
        30.0f,   1.6f,  -2.60f,  1.0f, 1.0f, // top right   
        30.0f,   0.9f,  -2.60f,  1.0f, 0.0f, // bottom right
        26.72f,  0.9f,  -2.60f,  0.0f, 0.0f, // bottom left 
        26.72f,  1.2f,  -2.60f,  0.0f, 1.0f, // top left    
        26.72f,  0.9f,  -2.60f,  0.0f, 0.0f, // bottom left 
        30.0f,   1.6f,  -2.60f,  1.0f, 1.0f, // top right

        // bottom                                         
        26.72f,   1.2f,   0.13f,  1.0f, 1.0f, // top right   
        26.72f,   0.9f,   0.13f,  1.0f, 0.0f, // bottom right
        26.72f,   0.9f,  -2.60f,  0.0f, 0.0f, // bottom left 
        26.72f,   1.2f,  -2.60f,  0.0f, 1.0f, // top left    
        26.72f,   0.9f,  -2.60f,  0.0f, 0.0f, // bottom left 
        26.72f,   1.2f,   0.13f,  1.0f, 1.0f, // top right
                              
    };

    // blue base vertices
    float firstVertices[] = {

           // side_1                          
           60.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right      
           60.0f,  1.0f,   1.5f,  2.0f, 0.0f, // bottom right 
           51.5f,  1.0f,  10.0f,  0.0f, 0.0f, // bottom left  
           51.5f,  6.0f,  10.0f,  0.0f, 1.0f, // top left     
           51.5f,  1.0f,  10.0f,  0.0f, 0.0f, // bottom left  
           60.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right    
                                                              
           // side_2                                              
           51.5f,  6.0f,  10.0f,  2.0f, 1.0f, // top right    
           51.5f,  1.0f,  10.0f,  2.0f, 0.0f, // bottom right 
           38.5f,  1.0f,  10.0f,  0.0f, 0.0f, // bottom left  
           38.5f,  6.0f,  10.0f,  0.0f, 1.0f, // top left     
           38.5f,  1.0f,  10.0f,  0.0f, 0.0f, // bottom left  
           51.5f,  6.0f,  10.0f,  2.0f, 1.0f, // top right    
                                                              
           // side_3                                              
           38.5f,  6.0f,  10.0f,  2.0f, 1.0f, // top right    
           38.5f,  1.0f,  10.0f,  2.0f, 0.0f, // bottom right 
           30.0f,  1.0f,   1.5f,  0.0f, 0.0f, // bottom left  
           30.0f,  6.0f,   1.5f,  0.0f, 1.0f, // top left     
           30.0f,  1.0f,   1.5f,  0.0f, 0.0f, // bottom left  
           38.5f,  6.0f,  10.0f,  2.0f, 1.0f, // top right    
                                                              
           // side_4                                              
           30.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right    
           30.0f,  1.0f,   1.5f,  2.0f, 0.0f, // bottom right 
           30.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left  
           30.0f,  6.0f, -11.5f,  0.0f, 1.0f, // top left     
           30.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left  
           30.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right    
                                                              
           // side_5                                              
           30.0f,  6.0f, -11.5f,  2.0f, 1.0f, // top right    
           30.0f,  1.0f, -11.5f,  2.0f, 0.0f, // bottom right 
           38.5f,  1.0f, -20.0f,  0.0f, 0.0f, // bottom left  
           38.5f,  6.0f, -20.0f,  0.0f, 1.0f, // top left     
           38.5f,  1.0f, -20.0f,  0.0f, 0.0f, // bottom left  
           30.0f,  6.0f, -11.5f,  2.0f, 1.0f, // top right    
                                                              
           // side_6                                              
           38.5f,  6.0f, -20.0f,  2.0f, 1.0f, // top right    
           38.5f,  1.0f, -20.0f,  2.0f, 0.0f, // bottom right 
           51.5f,  1.0f, -20.0f,  0.0f, 0.0f, // bottom left  
           51.5f,  6.0f, -20.0f,  0.0f, 1.0f, // top left     
           51.5f,  1.0f, -20.0f,  0.0f, 0.0f, // bottom left  
           38.5f,  6.0f, -20.0f,  2.0f, 1.0f, // top right    
                                                              
           // side_7                                              
           51.5f,  6.0f, -20.0f,  2.0f, 1.0f, // top right    
           51.5f,  1.0f, -20.0f,  2.0f, 0.0f, // bottom right 
           60.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left  
           60.0f,  6.0f, -11.5f,  0.0f, 1.0f, // top left     
           60.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left  
           51.5f,  6.0f, -20.0f,  2.0f, 1.0f, // top right    

           // side_8                          
           60.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right   
           60.0f,  1.0f,   1.5f,  2.0f, 0.0f, // bottom right
           60.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left
           60.0f,  6.0f, -11.5f,  0.0f, 1.0f, // top left
           60.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left
           60.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right 

           
    };

    // 
    float secondVertices[] = {

        // side_1                          
        60.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right      
        60.0f,  1.0f,   1.5f,  2.0f, 0.0f, // bottom right 
        51.5f,  1.0f,  10.0f,  0.0f, 0.0f, // bottom left  
        51.5f,  6.0f,  10.0f,  0.0f, 1.0f, // top left     
        51.5f,  1.0f,  10.0f,  0.0f, 0.0f, // bottom left  
        60.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right    

        // side_2                                              
        51.5f,  6.0f,  10.0f,  2.0f, 1.0f, // top right    
        51.5f,  1.0f,  10.0f,  2.0f, 0.0f, // bottom right 
        38.5f,  1.0f,  10.0f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.0f,  10.0f,  0.0f, 1.0f, // top left     
        38.5f,  1.0f,  10.0f,  0.0f, 0.0f, // bottom left  
        51.5f,  6.0f,  10.0f,  2.0f, 1.0f, // top right    

        // side_3                                              
        38.5f,  6.0f,  10.0f,  2.0f, 1.0f, // top right    
        38.5f,  1.0f,  10.0f,  2.0f, 0.0f, // bottom right 
        30.0f,  1.0f,   1.5f,  0.0f, 0.0f, // bottom left  
        30.0f,  6.0f,   1.5f,  0.0f, 1.0f, // top left     
        30.0f,  1.0f,   1.5f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.0f,  10.0f,  2.0f, 1.0f, // top right    

        // side_4                                              
        30.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right    
        30.0f,  1.0f,   1.5f,  2.0f, 0.0f, // bottom right 
        30.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left  
        30.0f,  6.0f, -11.5f,  0.0f, 1.0f, // top left     
        30.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left  
        30.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right    

        // side_5                                              
        30.0f,  6.0f, -11.5f,  2.0f, 1.0f, // top right    
        30.0f,  1.0f, -11.5f,  2.0f, 0.0f, // bottom right 
        38.5f,  1.0f, -20.0f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.0f, -20.0f,  0.0f, 1.0f, // top left     
        38.5f,  1.0f, -20.0f,  0.0f, 0.0f, // bottom left  
        30.0f,  6.0f, -11.5f,  2.0f, 1.0f, // top right    

        // side_6                                              
        38.5f,  6.0f, -20.0f,  2.0f, 1.0f, // top right    
        38.5f,  1.0f, -20.0f,  2.0f, 0.0f, // bottom right 
        51.5f,  1.0f, -20.0f,  0.0f, 0.0f, // bottom left  
        51.5f,  6.0f, -20.0f,  0.0f, 1.0f, // top left     
        51.5f,  1.0f, -20.0f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.0f, -20.0f,  2.0f, 1.0f, // top right    

        // side_7                                              
        51.5f,  6.0f, -20.0f,  2.0f, 1.0f, // top right    
        51.5f,  1.0f, -20.0f,  2.0f, 0.0f, // bottom right 
        60.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left  
        60.0f,  6.0f, -11.5f,  0.0f, 1.0f, // top left     
        60.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left  
        51.5f,  6.0f, -20.0f,  2.0f, 1.0f, // top right    

        // side_8                          
        60.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right   
        60.0f,  1.0f,   1.5f,  2.0f, 0.0f, // bottom right
        60.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left
        60.0f,  6.0f, -11.5f,  0.0f, 1.0f, // top left
        60.0f,  1.0f, -11.5f,  0.0f, 0.0f, // bottom left
        60.0f,  6.0f,   1.5f,  2.0f, 1.0f, // top right 


    };

    // around the dome vertices
    float aroundDomeVertices[] = {


        // side_1
        50.0f,  7.0f,  -1.5f,  2.0f, 1.0f, // top right     
        60.0f,  5.0f,   1.5f,  2.0f, 0.0f, // bottom right
        51.5f,  5.0f,  10.0f,  0.0f, 0.0f, // bottom left  
        47.5f,  7.0f,   0.0f,  0.0f, 1.0f, // top left     
        51.5f,  5.0f,  10.0f,  0.0f, 0.0f, // bottom left  
        50.0f,  7.0f,  -1.5f,  1.0f, 1.0f,  // top right    

        // side_2                                           
        47.5f,  7.0f,   0.0f,  2.0f, 1.0f, // top right   
        51.5f,  5.0f,  10.0f,  2.0f, 0.0f, // bottom right
        38.5f,  5.0f,  10.0f,  0.0f, 0.0f, // bottom left 
        42.5f,  7.0f,   0.0f,  0.0f, 1.0f, // top left     
        38.5f,  5.0f,  10.0f,  0.0f, 0.0f, // bottom left  
        47.5f,  7.0f,   0.0f,  1.0f, 1.0f, // top right    
        
        // side_3                                              
        42.5f,  7.0f,   0.0f,  2.0f, 1.0f, // top right    
        38.5f,  5.0f,  10.0f,  2.0f, 0.0f, // bottom right 
        30.0f,  5.0f,   1.5f,  0.0f, 0.0f, // bottom left  
        40.0f,  7.0f,  -2.5f,  0.0f, 1.0f, // top left     
        30.0f,  5.0f,   1.5f,  0.0f, 0.0f, // bottom left  
        42.5f,  7.0f,   0.0f,  1.0f, 1.0f, // top right    
        
        // side_4                                              
        40.0f,  7.0f,  -2.5f,  2.0f, 1.0f, // top right    
        30.0f,  5.0f,   1.5f,  2.0f, 0.0f, // bottom right 
        30.0f,  5.0f, -11.5f,  0.0f, 0.0f, // bottom left  
        40.0f,  7.0f,  -7.5f,  0.0f, 1.0f, // top left     
        30.0f,  5.0f, -11.5f,  0.0f, 0.0f, // bottom left  
        40.0f,  7.0f,  -2.5f,  1.0f, 1.0f, // top right    
        
        // side_5                                              
        40.0f,  7.0f,  -7.5f,  2.0f, 1.0f, // top right    
        30.0f,  5.0f, -11.5f,  2.0f, 0.0f, // bottom right 
        38.5f,  5.0f, -20.0f,  0.0f, 0.0f, // bottom left  
        43.5f,  7.0f, -10.0f,  0.0f, 1.0f, // top left     
        38.5f,  5.0f, -20.0f,  0.0f, 0.0f, // bottom left  
        40.0f,  7.0f,  -7.5f,  1.0f, 1.0f, // top right    
        
        // side_6                                              
        43.5f,  7.0f, -10.0f,  2.0f, 1.0f, // top right    
        38.5f,  5.0f, -20.0f,  2.0f, 0.0f, // bottom right 
        51.5f,  5.0f, -20.0f,  0.0f, 0.0f, // bottom left  
        47.5f,  7.0f, -10.0f,  0.0f, 1.0f, // top left     
        51.5f,  5.0f, -20.0f,  0.0f, 0.0f, // bottom left  
        43.5f,  7.0f, -10.0f,  1.0f, 1.0f, // top right    
        
        // side_7                                              
        47.5f,  7.0f, -10.0f,  2.0f, 1.0f, // top right    
        51.5f,  5.0f, -20.0f,  2.0f, 0.0f, // bottom right 
        60.0f,  5.0f, -11.5f,  0.0f, 0.0f, // bottom left  
        50.0f,  7.0f,  -7.5f,  0.0f, 1.0f, // top left     
        60.0f,  5.0f, -11.5f,  0.0f, 0.0f, // bottom left  
        47.5f,  7.0f, -10.0f,  1.0f, 1.0f, // top right    
        
        // side_8                          
        50.0f,  7.0f,  -1.5f,  2.0f, 1.0f, // top right   
        60.0f,  5.0f,   1.5f,  2.0f, 0.0f, // bottom right
        60.0f,  5.0f, -11.5f,  0.0f, 0.0f, // bottom left
        50.0f,  7.0f,  -7.5f,  0.0f, 1.0f, // top left
        60.0f,  5.0f, -11.5f,  0.0f, 0.0f, // bottom left
        50.0f,  7.0f,  -1.5f,  1.0f, 1.0f, // top right 


    };

    // mosque ground vertices
    float mocketVertices[] = 
    {    
           
       60.0f,  -1.95f, -20.0f,  10.0f, 10.0f, // 6 and 8 - right top
       60.0f,  -1.95f,  10.0f,  0.0f, 10.0f, // 2 and 8 - right bottom
       30.0f,  -1.95f, -20.0f,  10.0f, 0.0f, // 4 and 6 - left top
       30.0f,  -1.95f,  10.0f,  0.0f, 0.0f, // 4 and 2 - left botoom

       150.0f,  -1.97f, -75.0f,  30.0f, 20.0f, // 6 and 8 - right top
       150.0f,  -1.97f,  75.0f,   0.0f, 20.0f, // 2 and 8 - right bottom
      -125.0f,  -1.97f,  75.0f,   0.0f,  0.0f, // 4 and 2 - left botoom
                    
       150.0f,  -1.97f, -75.0f,  30.0f, 20.0f, // 6 and 8 - right top
      -125.0f,  -1.97f, -75.0f,  30.0f,  0.0f, // 4 and 6 - left top
      -125.0f,  -1.97f,  75.0f,   0.0f,  0.0f, // 4 and 2 - left botoom


       60.0f,  -1.93f, -20.0f,   0.5f,  1.0f, // 6 and 8 - right top
       51.5f,  -1.93f, -20.0f,   1.0f,  0.0f, // right bottom
       60.0f,  -1.93f, -11.5f,   0.0f,  0.0f, // left bottom
                   
       60.0f,  -1.93f,  10.0f,  0.5f,  1.0f, // 2 and 8 - right bottom
       60.0f,  -1.93f,   1.5f,  1.0f,  0.0f, // right botom
       51.5f,  -1.93f,  10.0f,  0.0f,  0.0f, // left bottom
                   
       30.0f,  -1.93f, -20.0f,  0.5f,  1.0f, // 4 and 6 - left top
       38.5f,  -1.93f, -20.0f,  1.0f,  0.0f, // right botom
       30.0f,  -1.93f, -11.5f,  0.0f,  0.0f, // left bottom
                   
                   
       30.0f,  -1.93f,  10.0f,  0.5f,  1.0f, // 4 and 2 - left botoom
       30.0f,  -1.93f,  1.5f,  1.0f,  0.0f, // right bottom
       38.5f,  -1.93f, 10.0f,  0.0f,  0.0f, // left bottom

    };

    unsigned int mocketIndices[] = {
        // 1st mocket
        0,1,3,
        0,2,3,
    };

    // the second side vetices 
    float thirdVertices[] = {

        // side_1                          
        59.5f,  6.0f,   1.5f,  5.0f, 1.0f, // top right      
        59.5f,  4.9f,   1.5f,  5.0f, 0.0f, // bottom right 
        51.5f,  4.9f,   9.5f,  0.0f, 0.0f, // bottom left  
        51.5f,  6.0f,   9.5f,  0.0f, 1.0f, // top left     
        51.5f,  4.9f,   9.5f,  0.0f, 0.0f, // bottom left  
        59.5f,  6.0f,   1.5f,  5.0f, 1.0f, // top right    

        // side_2                                              
        51.5f,  6.0f,  9.5f,  5.0f, 1.0f, // top right    
        51.5f,  4.9f,  9.5f,  5.0f, 0.0f, // bottom right 
        38.5f,  4.9f,  9.5f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.0f,  9.5f,  0.0f, 1.0f, // top left     
        38.5f,  4.9f,  9.5f,  0.0f, 0.0f, // bottom left  
        51.5f,  6.0f,  9.5f,  5.0f, 1.0f, // top right    

        // side_3                                              
        38.5f,  6.0f,  9.5f,  5.0f, 1.0f, // top right    
        38.5f,  4.9f,  9.5f,  5.0f, 0.0f, // bottom right 
        30.5f,  4.9f,  1.5f,  0.0f, 0.0f, // bottom left  
        30.5f,  6.0f,  1.5f,  0.0f, 1.0f, // top left     
        30.5f,  4.9f,  1.5f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.0f,  9.5f,  5.0f, 1.0f, // top right    

        // side_4                                              
        30.5f,  6.0f,   1.5f,  5.0f, 1.0f, // top right    
        30.5f,  4.9f,   1.5f,  5.0f, 0.0f, // bottom right 
        30.5f,  4.9f, -11.5f,  0.0f, 0.0f, // bottom left  
        30.5f,  6.0f, -11.5f,  0.0f, 1.0f, // top left     
        30.5f,  4.9f, -11.5f,  0.0f, 0.0f, // bottom left  
        30.5f,  6.0f,   1.5f,  5.0f, 1.0f, // top right    

        // side_5                                              
        30.5f,  6.0f, -11.5f,  5.0f, 1.0f, // top right    
        30.5f,  4.9f, -11.5f,  5.0f, 0.0f, // bottom right 
        38.5f,  4.9f, -19.5f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.0f, -19.5f,  0.0f, 1.0f, // top left     
        38.5f,  4.9f, -19.5f,  0.0f, 0.0f, // bottom left  
        30.5f,  6.0f, -11.5f,  5.0f, 1.0f, // top right    

        // side_6                                              
        38.5f,  6.0f, -19.5f,  5.0f, 1.0f, // top right    
        38.5f,  4.9f, -19.5f,  5.0f, 0.0f, // bottom right 
        51.5f,  4.9f, -19.5f,  0.0f, 0.0f, // bottom left  
        51.5f,  6.0f, -19.5f,  0.0f, 1.0f, // top left     
        51.5f,  4.9f, -19.5f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.0f, -19.5f,  5.0f, 1.0f, // top right    

        // side_7                                              
        51.5f,  6.0f, -19.5f,  5.0f, 1.0f, // top right    
        51.5f,  4.9f, -19.5f,  5.0f, 0.0f, // bottom right 
        59.5f,  4.9f, -11.5f,  0.0f, 0.0f, // bottom left  
        59.5f,  6.0f, -11.5f,  0.0f, 1.0f, // top left     
        59.5f,  4.9f, -11.5f,  0.0f, 0.0f, // bottom left  
        51.5f,  6.0f, -19.5f,  5.0f, 1.0f, // top right    

        // side_8                          
        59.5f,  6.0f,   1.5f,  5.0f, 1.0f, // top right   
        59.5f,  4.9f,   1.5f,  5.0f, 0.0f, // bottom right
        59.5f,  4.9f, -11.5f,  0.0f, 0.0f, // bottom left
        59.5f,  6.0f, -11.5f,  0.0f, 1.0f, // top left
        59.5f,  4.9f, -11.5f,  0.0f, 0.0f, // bottom left
        59.5f,  6.0f,   1.5f,  5.0f, 1.0f, // top right 


    };

    // top between first and second side
    float forthVertices[] = {

       // side_1      
       // left                    
       59.75f,  6.25f,   1.5f, 10.0f, 1.0f, // top right      
       60.0f,  6.0f,    1.5f,  10.0f, 0.0f, // bottom right 
       51.5f,  6.0f,   10.0f,  0.0f, 0.0f, // bottom left  
       51.5f,  6.25f, 9.75f,   0.0f, 1.0f, // top left     
       51.5f,  6.0f,   10.0f,  0.0f, 0.0f, // bottom left  
       59.75f,  6.25f,   1.5f, 10.0f, 1.0f, // top right

       // right                    
       59.75f,  6.25f,   1.5f, 10.0f, 1.0f, // top right   
       59.5f,  6.0f,    1.5f,  10.0f, 0.0f, // bottom right
       51.5f,  6.0f,    9.5f,  0.0f, 0.0f, // bottom left 
       51.5f,  6.25f, 9.75f,  0.0f, 1.0f, // top left    
       51.5f,  6.0f,    9.5f,  0.0f, 0.0f, // bottom left 
       59.75f,  6.25f,   1.5f, 10.0f, 1.0f, // top right   
      
        // side_2         
        // left                                     
        51.5f,  6.25f, 9.75f,  10.0f, 1.0f, // top right    
        51.5f,  6.0f,  10.0f,  10.0f, 0.0f, // bottom right 
        38.5f,  6.0f,  10.0f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.25f, 9.75f,  0.0f, 1.0f, // top left     
        38.5f,  6.0f,  10.0f,  0.0f, 0.0f, // bottom left  
        51.5f,  6.25f, 9.75f,  10.0f, 1.0f, // top right   
        // right
        51.5f,  6.25f, 9.75f,  10.0f, 1.0f, // top right   
        51.5f,   6.0f,  9.5f,  10.0f, 0.0f, // bottom right
        38.5f,   6.0f,  9.5f,  0.0f, 0.0f, // bottom left 
        38.5f,  6.25f, 9.75f,  0.0f, 1.0f, // top left    
        38.5f,   6.0f,  9.5f,  0.0f, 0.0f, // bottom left 
        51.5f,  6.25f, 9.75f,  10.0f, 1.0f, // top right   

        // side_3
        // left                                              
        38.5f,  6.25f,  9.75f,  10.0f, 1.0f, // top right    
        38.5f,   6.0f,  10.0f,  10.0f, 0.0f, // bottom right 
        30.0f,   6.0f,   1.5f,  0.0f, 0.0f, // bottom left  
        30.25f, 6.25f,   1.5f,  0.0f, 1.0f, // top left     
        30.0f,   6.0f,   1.5f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.25f,  9.75f,  8.0f, 1.0f, // top right  

        // right                                          
        38.5f,  6.25f, 9.75f,  5.0f, 1.0f, // top right   
        38.5f,   6.0f,  9.5f,  5.0f, 0.0f, // bottom right
        30.5f,   6.0f,  1.5f,  0.0f, 0.0f, // bottom left 
        30.25f,  6.25f, 1.5f,  0.0f, 1.0f, // top left    
        30.5f,   6.0f,  1.5f,  0.0f, 0.0f, // bottom left 
        38.5f,  6.25f, 9.75f,  10.0f, 1.0f, // top right   
       
        // side_4    
        // left                                          
        30.25f, 6.25f,   1.5f,  10.0f, 1.0f, // top right    
        30.0f,  6.0f,    1.5f,  10.0f, 0.0f, // bottom right 
        30.0f,  6.0f,  -11.5f,  0.0f, 0.0f, // bottom left  
        30.25f, 6.25f, -11.5f,  0.0f, 1.0f, // top left     
        30.0f,  6.0f,  -11.5f,  0.0f, 0.0f, // bottom left  
        30.25f, 6.25f,   1.5f,  10.0f, 1.0f, // top right  
        // right
       30.25f,  6.25f,   1.5f,  10.0f, 1.0f, // top right   
        30.5f,   6.0f,   1.5f,  10.0f, 0.0f, // bottom right
        30.5f,   6.0f, -11.5f,  0.0f, 0.0f, // bottom left 
       30.25f,  6.25f, -11.5f,  0.0f, 1.0f, // top left    
        30.5f,   6.0f, -11.5f,  0.0f, 0.0f, // bottom left 
       30.25f,  6.25f,   1.5f,  10.0f, 1.0f, // top right   
       
        // side_5            
        // left                                  
        30.25f,  6.25f, -11.5f,  10.0f, 1.0f, // top right    
        30.0f,   6.0f, -11.5f,  10.0f, 0.0f, // bottom right 
        38.5f,   6.0f, -20.0f,  0.0f, 0.0f, // bottom left  
        38.5f,  6.25f,  -19.75f,  0.0f, 1.0f, // top left     
        38.5f,   6.0f, -20.0f,  0.0f, 0.0f, // bottom left  
        30.25f,  6.25f, -11.5f,  10.0f, 1.0f, // top right   

        //right
        30.25f,6.25f, -11.5f, 10.0f, 1.0f,  // top right   
        30.5f,  6.0f, -11.5f, 10.0f, 0.0f,  // bottom right
        38.5f,  6.0f, -19.5f, 0.0f, 0.0f,  // bottom left  
        38.5f, 6.25f,-19.75f, 0.0f, 1.0f,  // top left     
        38.5f,  6.0f, -19.5f, 0.0f, 0.0f,  // bottom left  
        30.25f,6.25f, -11.5f, 10.0f, 1.0f,  // top right   
       
        // side_6
        // left                                              
        38.5f,  6.25f,  -19.75f, 10.0f, 1.0f, // top right    
        38.5f,   6.0f,   -20.0f, 10.0f, 0.0f, // bottom right 
        51.5f,   6.0f,   -20.0f, 0.0f, 0.0f, // bottom left  
        51.5f,  6.25f,  -19.75f, 0.0f, 1.0f, // top left     
        51.5f,   6.0f,   -20.0f, 0.0f, 0.0f, // bottom left  
        38.5f,  6.25f,  -19.75f, 10.0f, 1.0f, // top right

        // right                                          
        38.5f,  6.25f,   -19.75f, 10.0f, 1.0f, // top right  
        38.5f,   6.0f,   -19.5f,  10.0f, 0.0f, // bottom righ
        51.5f,   6.0f,   -19.5f,  0.0f, 0.0f, // bottom left
        51.5f,  6.25f,   -19.75f, 0.0f, 1.0f, // top left   
        51.5f,   6.0f,   -19.5f,  0.0f, 0.0f, // bottom left
        38.5f,  6.25f,   -19.75f, 10.0f, 1.0f, // top right  
       
       // side_7
       // left                                              
       51.5f, 6.25f,-19.75f, 10.0f, 1.0f, // top right    
       51.5f,  6.0f,-20.0f, 10.0f, 0.0f, // bottom right 
       60.0f,  6.0f,-11.5f, 0.0f, 0.0f, // bottom left  
       59.75f,6.25f, -11.5f, 0.0f, 1.0f, // top left     
       60.0f,  6.0f,-11.5f, 0.0f, 0.0f, // bottom left  
       51.5f, 6.25f,-19.75f, 10.0f, 1.0f, // top right   
       
       //right
       51.5f, 6.25f,-19.75f, 10.0f, 1.0f, // top right   
       51.5f,  6.0f,-19.5f, 10.0f, 0.0f, // bottom right
       59.5f,  6.0f,-11.5f, 0.0f, 0.0f, // bottom left 
       59.75f,6.25f, -11.5f, 0.0f, 1.0f, // top left    
       59.5f,  6.0f,-11.5f, 0.0f, 0.0f, // bottom left 
       51.5f, 6.25f,-19.75f, 10.0f, 1.0f, // top right   

       
        // side_8
        // left                          
       59.75f,  6.25f,   1.5f,  10.0f, 1.0f, // top right   
        60.0f,   6.0f,   1.5f,  10.0f, 0.0f, // bottom right
        60.0f,   6.0f, -11.5f,  0.0f, 0.0f, // bottom left
       59.75f,  6.25f, -11.5f,  0.0f, 1.0f, // top left
        60.0f,   6.0f, -11.5f,  0.0f, 0.0f, // bottom left
       59.75f,  6.25f,   1.5f,  10.0f, 1.0f, // top right 

        // right                          
       59.75f,  6.25f,   1.5f,  10.0f, 1.0f, // top right   
        59.5f,   6.0f,   1.5f,  10.0f, 0.0f, // bottom right
        59.5f,   6.0f, -11.5f,  0.0f, 0.0f, // bottom left
       59.75f,  6.25f, -11.5f,  0.0f, 1.0f, // top left
        59.5f,   6.0f, -11.5f,  0.0f, 0.0f, // bottom left
       59.75f,  6.25f,   1.5f,  10.0f, 1.0f, // top right 


    };
    
    // Gardens
    float GardenVertices[] =
    {
        //  Garden                                               
        -75.0f,  -1.95f, -25.0f,  8.0f, 4.0f, // top right    
        -75.0f,  -1.95f,  5.0f,   8.0f, 0.0f, // bottom right 
       -124.4f,  -1.95f,  5.0f,   0.0f, 0.0f, // bottom left  
       -124.4f,  -1.95f, -25.0f,  0.0f, 4.0f, // top left     
       -124.4f,  -1.95f,  5.0f,   0.0f, 0.0f, // bottom left  
        -75.0f,  -1.95f, -25.0f,  8.0f, 4.0f, // top right
    };
    
    circle = new Circle(1.2, 128);
    Cyl1 = new Cylinders(1.12, 0.5, 128);
    Cyl2 = new Cylinders(1.2, 0.05, 128);
    semiCyl = new Cylinders(1.0, 0.55, 128, true);

    dome = new Dome(128, 128);

    // setup ground VAO
    glGenVertexArrays(1, &this->baseVAO);
    glGenBuffers(1, &this->baseVBO);
    glBindVertexArray(this->baseVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->baseVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(baseVertices), baseVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenVertexArrays(1, &this->firstVAO);
    glGenBuffers(1, &this->firstVBO);
    glBindVertexArray(this->firstVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->firstVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstVertices), firstVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenVertexArrays(1, &this->secondVAO);
    glGenBuffers(1, &this->secondVBO);
    glBindVertexArray(this->secondVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->secondVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondVertices), secondVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenVertexArrays(1, &this->mocketVAO);
    glGenBuffers(1, &this->mocketVBO);
    glGenBuffers(1, &this->mocketEBO);
    glBindVertexArray(this->mocketVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->mocketVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mocketVertices), mocketVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->mocketEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mocketIndices), mocketIndices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenVertexArrays(1, &this->aroundDomeVAO);
    glGenBuffers(1, &this->aroundDomeVBO);
    glBindVertexArray(this->aroundDomeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->aroundDomeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(aroundDomeVertices), aroundDomeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenVertexArrays(1, &this->thirdVAO);
    glGenBuffers(1, &this->thirdVBO);
    glBindVertexArray(this->thirdVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->thirdVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(thirdVertices), thirdVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenVertexArrays(1, &this->forthVAO);
    glGenBuffers(1, &this->forthVBO);
    glBindVertexArray(this->forthVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->forthVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(forthVertices), forthVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    

    // setup Garden VAO
    glGenVertexArrays(1, &this->GardenVAO);
    glGenBuffers(1, &this->GardenVBO);
    glBindVertexArray(this->GardenVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->GardenVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GardenVertices), GardenVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
}

unsigned int DomeOfTheRock::loadTexture(char const* path)
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

void DomeOfTheRock::renderDomeOfTheRock()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, baseTexture);
    glBindVertexArray(this->baseVAO);
    glDrawArrays(GL_TRIANGLES, 0, 48);

    glm::mat4 model = glm::mat4(1.0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, base2Texture);
    
    model = glm::translate(model, glm::vec3(0.0, 0.0, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.195f));
    this->shader->setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 48, 30);

    model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(0.0, 0.0, -6.5f));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.195f));
    this->shader->setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 48, 30);

    model = glm::mat4(1.0);
    this->shader->setMat4("model", model);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, firstTexture);
    glBindVertexArray(this->firstVAO);
    glDrawArrays(GL_TRIANGLES, 0, 48);

    // mocketRender
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mocket_2Texture);
    glBindVertexArray(this->mocketVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, groundTexture);
    glDrawArrays(GL_TRIANGLES, 4, 18);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, aroundDomeTexture);
    glBindVertexArray(this->aroundDomeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 48);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, thirdTexture);
    glBindVertexArray(this->thirdVAO);
    glDrawArrays(GL_TRIANGLES, 0, 48);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, forthTexture);
    glBindVertexArray(this->forthVAO);
    glDrawArrays(GL_TRIANGLES, 0, 96);



    // RENDER THE DOME
    model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(45.5f, 8.0f, -4.65f));
    model = glm::scale(model, glm::vec3(6.5f, 6.5f, 6.5f));
    this->shader->setMat4("model", model);
    Cyl1->renderCylinder(cylinderTexture);

    model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(45.5f, 9.5f, -4.65f));
    model = glm::scale(model, glm::vec3(6.5f, 6.5f, 6.5f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    this->shader->setMat4("model", model);
    circle->renderCircle(domeTexture);

    model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(45.5f, 9.75f, -4.65f));
    model = glm::scale(model, glm::vec3(6.5f, 6.5f, 6.5f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    this->shader->setMat4("model", model);
    circle->renderCircle(domeTexture);

    model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(45.5f, 9.625f, -4.65f));
    model = glm::scale(model, glm::vec3(6.5f, 6.5f, 6.5f));
    //model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    this->shader->setMat4("model", model);
    Cyl2->renderCylinder(cylinder2Texture);

    // DOME RENDER
    model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(45.5f, 9.5f, -4.65f));
    model = glm::scale(model, glm::vec3(7.4f, 7.8f, 7.4f));
    //model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    this->shader->setMat4("model", model);
    dome->renderDome(domeTexture);


    model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(28.5f, 0.9f, -4.68f));
    model = glm::scale(model, glm::vec3(5.4f, 2.15f, 1.55f));
    model = glm::rotate(model, glm::radians(90.0f),  glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    this->shader->setMat4("model", model);
    semiCyl->renderCylinder(cylinderTexture);

    for (int i = 0; i < 3; i++)
    {
        float z = i * -50;

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(220.0f, 0.01f, 60.0f + z));
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
        shader->setMat4("model", model);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, GardenTexture);

        glBindVertexArray(this->GardenVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

    }
}

void DomeOfTheRock::renderEnd()
{
    glDeleteVertexArrays(1, &baseVAO);
    glDeleteBuffers(1, &baseVBO);

    glDeleteVertexArrays(1, &firstVAO);
    glDeleteBuffers(1, &firstVBO);

    glDeleteVertexArrays(1, &secondVAO);
    glDeleteBuffers(1, &secondVBO);
}







