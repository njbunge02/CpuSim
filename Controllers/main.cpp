#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>   

#include <iostream>
#include <fstream>
#include <string>

#include <math.h>
#include "../Views/GUI.h"
#include "CPU.h"


using namespace std;

int main (int argc, char *argv[])
{
/*		
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	glutInitWindowSize(WIDTH,HEIGHT); 
	
	glutCreateWindow("CPU Simulator");


	glutDisplayFunc(display);  
	glutIdleFunc(display);


	glutKeyboardFunc(keyboard);
	initWindow();				             //create_window

	glutMainLoop();                 // Initialize The Main Loop

*/

   CPU cpuSim;

   
	if(argc != 2) {
		cout << "Error. Program executed incorreclty. Please use './<program name> yourBinary.bin'" << endl;
	}
   
   cpuSim.readBinaryFile(argv[1]);

	
    return 0; // Exit successfully
	

   return 0;
}