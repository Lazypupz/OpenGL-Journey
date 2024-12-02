#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,800,600);
}

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
      glfwShouldCloseWindow(window, true);
  
    }
}

const char* vertexShaderSrc = "R(
    #version 330 core
    layout( location = 0) in vec3 aPos;
    void main(){
        gl_Postition = vec4(aPos, 1.0f);
    }
)";

const char* fragmentShaderSrc = "R(
    #version 330 core 
    out vec4 fragColour;
    void main(){
        fragColour = vec4(0.8, 0.5, 0,2, 1,0);
    }

)";    

int main(){
    if(!glfwInit()){
        std::cerr << "Failed to initialise GLFW" << std::endl;
        glfwTerminate();
        return -1;
        
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_COMPAT_PROFILE);

    
    GLFWwindow* window = glfwCreateWindow(800,600,"OpenGL Window", nullptr, nullptr);
    if(window == NULL){
      std::cerr << "Failed To Open Window " << std::endl;
      return -1;
    }
    glfwMakeCurrentContext(window);

    if(!gladLoadGLLoader(gladLoadProc)glfwGetProcAddress){
      std::cerr << "Failed to initialize GLAD" << std::endl;
      return -1;
    }  

    GLuint VBO, VAO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER,)
    
    glGenVertexArray(1, &VAO);

    unsigned int vertexShader = glfwCreateShader(GL_VERTEX_SHADER);
    
    while(!glfwWindowShouldClose(window){

      processInput(window);
      
      glfwSwapBuffers(window);
      glfwPollEvents();
    }
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwTerminate();
    return 0;
}
