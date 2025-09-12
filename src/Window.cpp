#include <GLFW/glfw3.h>
#include <iostream>

#define GL_SILENCE_DEPRECATION

#define START_HEIGHT 600
#define START_WIDTH 800

void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, std::vector<unsigned char>& framebuffer, int width){
    int index = (y * width + x) * 3;
    framebuffer[index] = r;
    framebuffer[index + 1] = g;
    framebuffer[index + 2] = b;
}

void drawGradient(std::vector<unsigned char>& framebuffer, int width, int height){
    for( int i = 0; i < height; i++){
        for( int j = 0; j < width; j++){
            unsigned char r = (i*255)/height;
            unsigned char g = (j*255)/width;

            setPixel(j, height - 1 - i, r, g, 0, framebuffer, width);
        }
    }
}


int main() {

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(START_WIDTH, START_HEIGHT, "My GLFW Window", NULL, NULL);
    

    glfwMakeContextCurrent(window);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    std::vector<unsigned char> framebuffer(START_WIDTH * START_HEIGHT * 3);
    drawGradient(framebuffer,START_WIDTH, START_HEIGHT);
    int windowWidth, windowHeight;

    while (!glfwWindowShouldClose(window)) {
        
        glfwGetFramebufferSize(window, &windowWidth, &windowHeight);

        std::vector<unsigned char> framebuffer(windowWidth * windowHeight * 3);
        drawGradient(framebuffer,windowWidth, windowHeight);


        // Render here
        glDrawPixels(windowWidth, windowHeight, GL_RGB, GL_UNSIGNED_BYTE, framebuffer.data());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}