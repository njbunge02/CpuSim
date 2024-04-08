#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>   

#include <math.h>
#include "../Views/GUI.h"






int main (int argc, char *argv[])
{
	{
		
		glutInit(&argc, argv); 
		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
		glutInitWindowSize(WIDTH,HEIGHT); 
		
      glutCreateWindow("CPU Simulator");


		glutDisplayFunc(display);  
		glutIdleFunc(display);


		glutKeyboardFunc(keyboard);
		initWindow();				             //create_window
	
		glutMainLoop();                 // Initialize The Main Loop

        return 0;
	}
}