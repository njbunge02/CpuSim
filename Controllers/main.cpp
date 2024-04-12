#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>   

#include <iostream>
#include <fstream>
#include <string>

#include <math.h>
#include "../Views/GUI.h"
#include "CPU.h"
#include "../Models/Instruction.h"
#include "../Models/Memory.h"
#include "../Views/Console.h"


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


   
	if(argc != 2) {
		cerr << "Error. Program executed incorreclty. Please use './<program name> yourBinary.bin'" << endl;
	}


   
   CPU cpu1(argv[1]);

   cpu1.executeNextInstruction();
   cpu1.executeNextInstruction();
   cpu1.executeNextInstruction();
   cpu1.executeNextInstruction();
   cpu1.executeNextInstruction();
   cpu1.executeNextInstruction();
   cpu1.executeNextInstruction();
   cpu1.executeNextInstruction();
   cpu1.executeNextInstruction();
   
	

   return 0;
}