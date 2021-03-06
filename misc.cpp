#include "h/misc.hpp"
#include "h/gl.hpp"

#include <GL/glut.h>

#include <chrono>
using namespace std::chrono;

void initGL(int argc, char** argv)
{
    #define WIDTH 640
    #define HEIGHT 480
    #define TITLE "OpenGL01" 

    // Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT); // Set the window size
	
	// Create the window
	glutCreateWindow(TITLE);
	initRendering(); // Initialize rendering
	
	// Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutMainLoop(); // Start the main loop. glutMainLoop doesn't return.
}

bool loopFirst = true;
time_point<steady_clock> loopTime;
double getDeltaTime()
{
    double deltaTime = 0;
	time_point<steady_clock> nowTime = steady_clock::now();

	if(loopFirst)
		loopFirst = false;
    else
        deltaTime = duration_cast<duration<double>>(nowTime - loopTime).count();

	loopTime = nowTime;

    return deltaTime;
}