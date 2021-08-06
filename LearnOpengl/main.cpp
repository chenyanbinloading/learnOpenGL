//
//  main.cpp
//  LearnOpengl
//
//  Created by 陈艳斌 on 2020/11/19.
//  Copyright © 2020 陈艳斌. All rights reserved.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    // 初始化
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // 设置版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);// 最低版本好
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 设置为核心模式
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    // 渲染引擎
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
    while(!glfwWindowShouldClose(window))
    {
        // 输入
        processInput(window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        // 检查并调用事件，交换缓冲
        glfwSwapBuffers(window);
        glfwPollEvents();
        
        // 使用glGenBuffers函数和一个缓冲ID生成一个VBO对象：
        unsigned int VBO;
        glGenBuffers(1, &VBO);
        
        // 使用glBindBuffer函数把新创建的缓冲绑定到GL_ARRAY_BUFFER目标上：
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        
        // 调用glBufferData函数，把之前定义的顶点数据复制到缓冲的内存中：
        /*glBufferData是一个专门用来把用户定义的数据复制到当前绑定缓冲的函数。
         它的第一个参数是目标缓冲的类型：顶点缓冲对象当前绑定到GL_ARRAY_BUFFER目标上。
         第二个参数指定传输数据的大小(以字节为单位)；用一个简单的sizeof计算出顶点数据大小就行。
         第三个参数是我们希望发送的实际数据。
         第四个参数指定了我们希望显卡如何管理给定的数据 */
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
        
    }
    // 当渲染循环结束后我们需要正确释放/删除之前的分配的所有资源
    glfwTerminate();
    
    
    return 0;
}
