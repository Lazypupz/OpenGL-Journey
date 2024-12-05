#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

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

    //uniform vec4 someColour;
    void main(){
        fragColour = vec4(0.8, 0.5, 0,2, 1,0);
        //fragColour = someColour;
    }

)";    

int ShaderCompile(const char* source, const char* fSource){
    unsigned int vertexShader = glfwCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &source, nullptr);
    glCompileShader(vertexShader);
    shaderCompCheck(vertexShader);

    unsigned int fragmentShader = glfwCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fSource, nullptr);
    glCompileShader(fragmentShader);
    shaderCompCheck(fragmentShader);

    unsigned int shaderProgram;
    shaderProgram = glfwCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachSHader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    sProgramErrorCheck(sProgram);
    
    
    return 0;
}    

void sProgramErrorCheck(unsigned int sProgram){
    char infoLog[512];
    int success;
    glGetProgramiv(sProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "The error:" << infoLog << std::endl;
    } 
}

void shaderCompCheck(unsigned int shader){
    char infoLog[512];
    int success;
    glGetProgramiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "ERROR" << infoLog << std::endl;
        
    }
}

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
    glBindBuffer(GL_ARRAY_BUFFER,);
    //glBufferData(GL_ARRAY_BUFFER, 1, sizeof(verticies), verticies, nullptr, nullptr);
    
    glGenVertexArray(1, &VAO);
    

    ShaderCompile(&vertexShaderSrc, &fragmentShaderSrc);
    
    while(!glfwWindowShouldClose(window){
        glClearColour(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_CLEAR_COLOR_BIT);

        glUseProgram(shaderProgram);
        
        processInput(window);
        
        glSwapBuffers(window);
        glPollEvents();
    }
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwTerminate();
    return 0;
}
