##GLeasier

This project is the result from my `OpenGL` learning experience. We always have
to setup too many things before we can actually draw something. This library
does most of that. Well, for a condition.

You will use `glfw3`, `glew`, `assimp`, `opencv`(to load images and
pre-processing them).

Here is an example of drawing procedures:

	int main(int argc, char **argv)
	{
		context contx(width, height, "window");
		GLuint cubeTex = loadTexture2GPU("../imgs/container.jpg");
	
		ShaderMan shader("vs.glsl", "fs.glsl");
		
		DrawObj cubes(&shader);
		contx.append_drawObj(&cubes);
		
		contx.init();
		contx.run();
	}
	
	
