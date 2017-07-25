## GLeasier

This project is the result from my `OpenGL` learning experience. We always have
to setup too many things before we can actually draw something. This library
does most of that. Well, for a condition.

You will use `glfw3`, `glew`, `assimp`, `opencv`(to load images and
pre-processing them).

Here is an template of drawing procedures:

	int main(int argc, char **argv)
	{
		context contx(width, height, "window");
	
		ShaderMan shader("vs.glsl", "fs.glsl");
		
		DrawObj cubes(&shader);
		contx.append_drawObj(&cubes);
		//init() and run() functions handles all the complexities
		contx.init();
		contx.run();
	}
	
Here is an example to render shadows with this project.
[![Shadow mapping](https://www.dropbox.com/s/30qpifb3jg3gg5m/screen_cap.png?dl=0)]
