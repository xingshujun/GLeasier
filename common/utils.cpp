#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <utils.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <assert.h>

static float ASPECT_RATIO = 1.0;

int
read_file(const char *fname, std::string *str)
{
	assert(str);
	std::stringstream ss;
	std::ifstream f(fname, std::ios::in);
	if (!f.is_open())
		return -1;

	ss << f.rdbuf();
	str->assign(ss.str());
	f.close();
	return 0;
}

void error_callback(int error, const char *description)
{
	fprintf(stderr, "Error Code: %d, %s\n", error, description);
}



void
window_resize_callback(GLFWwindow *window, int width, int height)
{
	//we need to figure out the viewport
	int x, y, w, h;
	if ( ( (float)width / (float)height ) > ASPECT_RATIO) {
		w = height * ASPECT_RATIO; h = height;
		x = (width - w)/2; y = 0;
	} else {
		w = width; h = (int)( (float)width/ASPECT_RATIO );
		x = 0; h = (height -h) / 2;
	}
	glViewport(x, y, w, h);
}
