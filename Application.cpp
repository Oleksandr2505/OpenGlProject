#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<fstream>
#include<string>
#include<sstream>
#include"Renderer.h"
#include"IBO.h"
#include"VBO.h"
#include"Shader.h"
#include<vector>
#include"VAO.h"
#include"vertexBufferLayout.h"
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"

using namespace std;


int main(void)
{

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        cout << "error" << endl;

    cout << glGetString(GL_VERSION) << endl;
    {
        float positions[]
        {
            -0.5f, -0.5f, // left
            0.5f, -0.5f, //right
            0.5f, 0.5f ,   //top
            -0.5f, 0.5f,  //right


        };
        unsigned int indecies[] = {
            0, 1, 2,
            2, 3, 0
        };
       
        //glEnable(GL_BLEND);
        //glCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        VAO va;
        VBO vb(positions , 4 * 2 * sizeof(float) );
        
         
        vertexBufferLayout layout;
        layout.push<float>(2);
        //layout.push<float>(2);
        va.addBuffer(vb,layout);
       

        IBO ibo(indecies, 6);
        glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
     
        Shader s;
        s.Bind();
        s.setUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
        s.setUniformMat4f("u_MVP",proj);
        Renderer renderer;

        //Texture texture("src\res\textures\Inkedlogo.jpg");
        //texture.Bind();
        //s.setUniform1i("u_Texture", 0);

        vb.unBind();
        va.unBind();
        ibo.unBind();
        s.unBind();
      
        float r = 0.0f;
        float increment = 0.05f;

        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            renderer.Clear(r);

            s.Bind();
            s.setUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
           
            renderer.Draw(ibo, va, s);


            if (r > 1.0f)
                increment = -0.05f;
            else if (r < 0.0f)
                increment = 0.05f;
            r += increment;

            glfwSwapBuffers(window);
            /* Swap front and back buffers * /
            *
            

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
  
    glfwTerminate();
    return 0;

}