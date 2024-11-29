#include <glad/glad.h>
#include <GLFW/glfw.h>
#include <iostream>


void framebuffer_size_callback(GLFWWindow* window, int width, int height){
  glViewport(0,0,800,600);
}

void processInput(GLFWWindow* window){
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
    glfwShouldCloseWindow(window, true);
  
  }
}

int main(){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_COMPAT_PROFILE);

  
  GLFWWindow* window = glfwCreateWindow(800,600,"OpenGL Window", nullptr, nullptr);
  if(window == NULL){
    std::cerr << "Failed To Open Window " << std::endl;
    return -1;
  }
  glfwMakeCurrentContext(window);

  if(!gladLoadGLLoader(gladLoadProc)glfwGetProcAddress){
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return -1;
  }  

  while(!glfwWindowShouldClose(window){

    processInput();
    
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  glfwTerminate();
  return 0;
}
