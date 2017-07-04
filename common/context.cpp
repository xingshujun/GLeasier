#include <stdio.h>
#include <tuple>
#include <vector>
#include <algorithm>

#include <GL/glew.h>
#ifdef __linux__
#include <GLFW/glfw3.h>
#elif __WIN32
#include <GL/glfw3.h>
#endif


#include "context.hpp"

//problem is, this is the boring code, nobody want to use it
//you will have to setup your own window callback function
context::context(int width, int height, const char *winname)
{
	_win = NULL;
       
	if (!glfwInit()) {
		fprintf(stderr, "Error: glfw init failed!\n");
		return;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3, shit
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

	//create windows
	_win = glfwCreateWindow(width, height, winname, NULL, NULL);

	if (!_win) {
		fprintf(stderr, "man, no windows???\n");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(_win);
	glewExperimental = true;
	
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		glfwTerminate();
		return;
	}
	const GLubyte* renderer = glGetString(GL_RENDERER); /// Get renderer string
	const GLubyte* version = glGetString(GL_VERSION); /// Version as a string
	fprintf(stderr,"Renderer: %s\n", renderer);
	fprintf(stderr, "OpenGL version supported %s\n", version);
	glViewport(0, 0, width, height);
}

context::~context()
{
	glfwDestroyWindow(_win);
	glfwTerminate();
}



int
context::init(void)
{
	for (unsigned int i = 0; i < drawobjs.size(); i++) {
		
		glUseProgram(drawobjs[i]->program());
		drawobjs[i]->init_setup();
//		GLuint prog = std::get<0>(_init_cbs[i]);

//		cb_t callback = std::get<1>(_init_cbs[i]);
//		callback(prog, std::get<2>(_init_cbs[i]));
	}
	return 0;
}


int
context::run()
{
	do {
		glfwPollEvents();
		//here comes the problem, should I finish all the setup before drawing or not?
		for (unsigned int i = 0; i < drawobjs.size(); i++) {
			drawobjs[i]->itr_setup();
		}
		for (unsigned int i = 0; i < drawobjs.size(); i++) {
			glUseProgram(drawobjs[i]->program());
			drawobjs[i]->itr_draw();
		}
		glfwSwapBuffers(_win);
	} while (glfwGetKey(_win, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		 !glfwWindowShouldClose(_win));
	return 0;
}

