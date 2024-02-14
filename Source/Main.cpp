#include"Manager.h"
#include<random>

#include<irrKlang.h>
#pragma comment(lib, "irrklang.lib") 



using namespace irrklang;

bool isInsideDomeOfTheRock(const glm::vec3& position) {


    glm::vec3 domeCenter = glm::vec3(15.0f, 2.0f, 0.0f);
    float domeRadius = 25.0f;

    // Calculate the distance between the camera and the Dome of the Rock
    float distance = glm::length(position - domeCenter);


    return distance <= domeRadius;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
//unsigned int loadTexture(const char* path);

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

// framebuffer size
int fb_width;
int fb_height;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 0.0f));
float lastX = (float)SCR_WIDTH / 2.0;
float lastY = (float)SCR_HEIGHT / 2.0;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// lighting info
// -------------
const glm::vec3 lightDir = glm::normalize(glm::vec3(250.0f, 100.0f, 250.0f));
unsigned int lightFBO;
unsigned int lightDepthMaps;
constexpr unsigned int depthMapResolution = 4096;

bool showQuad = false;

std::random_device device;
std::mt19937 generator = std::mt19937(device());

std::vector<glm::mat4> lightMatricesCache;


Manager project(SCR_WIDTH, SCR_HEIGHT);

int main()
{

    irrklang::ISoundEngine* soundEngine = irrklang::createIrrKlangDevice(irrklang::ESOD_AUTO_DETECT);

    if (!soundEngine) {
        // Failed 
        return 1;
    }

    soundEngine->play2D("Resources/Audio/goldenage.mp3", true);





    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // window creation
    project.createWindow();
    
    glfwMakeContextCurrent(project.window);
    glfwSetFramebufferSizeCallback(project.window, framebuffer_size_callback);
    glfwSetCursorPosCallback(project.window, mouse_callback);
    glfwSetScrollCallback(project.window, scroll_callback);
    glfwGetFramebufferSize(project.window, &fb_width, &fb_height);

    // tell GLFW to capture our mouse
    glfwSetInputMode(project.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile shaders
    // -------------------------
    project.InitResources();




    irrklang::ISound* azanSound = nullptr; // Store object 


    glm::vec3 domeCenter = glm::vec3(9.0f, 2.0f, 0.0f); 
    
    float maxVolumeDistance = 20.0f; // Example maximum distance for full volume

    // Define the minimum distance for minimum volume
    float minVolumeDistance = 5.0f; // Example minimum distance for minimum volume

    // max for azan
    float maxVolume = 1.0f; 
    float minVolume = 0.1f; 
    float fadeDistance = 5.0f; 


    irrklang::ISoundEngine* areaSoundEngine = irrklang::createIrrKlangDevice(irrklang::ESOD_AUTO_DETECT);
    bool hasEnteredArea = false;
    bool isGoldenAgePlaying = true;
    bool isAzanPlaying = false;





    // render loop
    // -----------
    while (!glfwWindowShouldClose(project.window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(10*glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(project.window);



        // Check if the camera enters the area around the Dome of the Rock
        bool isCurrentlyInsideDome = isInsideDomeOfTheRock(camera.Position);

        // Calculate the distance between the camera and the Dome of the Rock
        float distanceToDome = glm::length(camera.Position - domeCenter);

        // Calculate the volume based on distance for fade-in and fade-out effect
        float volume = 0.0f;

        if (isCurrentlyInsideDome) {
         
            if (!isAzanPlaying && areaSoundEngine) {
                azanSound = areaSoundEngine->play2D("Resources/Audio/azan.mp3", true, false, true);
                if (azanSound) {
                    isAzanPlaying = true;
                }
            }
            // Calculate fade-in effect based on distance
            volume = glm::clamp((distanceToDome - minVolumeDistance) / (maxVolumeDistance - minVolumeDistance), 0.0f, 1.0f);
        }
        else {
            // If outside the area, fade-out the sound gradually until it stops
            if (isAzanPlaying) {
                // Calculate fade-out effect based on distance
                volume = 1.0f - glm::clamp((distanceToDome - minVolumeDistance) / (maxVolumeDistance - minVolumeDistance), 0.0f, 1.0f);
                if (volume <= 0.01f) {
                    azanSound->stop(); 
                    isAzanPlaying = false; 
                }
            }
        }

        // Apply the calculated volume to the sound
        if (azanSound) {
            azanSound->setVolume(volume);
        }


        // render
        // ------
        project.renderScene(camera);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(project.window);
        glfwPollEvents();
    }

    // Deallocate resources
// --------------------
    if (areaSoundEngine) {
        areaSoundEngine->drop();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    project.End();

    glfwTerminate();

    std::cin.get(); // Wait for a character input before exiting

    soundEngine->drop();

    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}



