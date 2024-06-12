#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
using namespace std;

void key_pressed(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main()
{
    
    GLFWwindow* window;
    
    int width, height;
     
    if (!glfwInit()) {
        cout << "Error when initializing GLFW" << endl;
        return -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(200, 200, "ChustrupFx", NULL, NULL);
    
    
    if (!window) {
        cout << "Error when creating window" << endl;
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_pressed);
    
    glfwGetFramebufferSize(window, &width, &height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, width, height);
    
    
    while (!glfwWindowShouldClose(window)) {
        
        
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(NULL);
    
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
        
    }
    
    
    glfwTerminate();
    return 0;
}
