//mac headers
/*#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>  */ 

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>  

#include <iostream>
#include <fstream>
#include <string>

#include <math.h>
#include "../Views/GUI.h"
#include "CPU.h"
#include "../Models/Instruction.h"
#include "../Models/Memory.h"




using namespace std;

void mouse(int button, int state, int x, int y);
void initCPU(string filename);


int main (int argc, char *argv[])
{

	
	if(argc != 2) {
		cerr << "Error. Program executed incorreclty. Please use './<program name> yourBinary.bin'" << endl;
	}


	initCPU(argv[1]);


	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	glutInitWindowSize(WIDTH,HEIGHT); 
	
	glutCreateWindow("CPU Simulator");


	glutDisplayFunc(display);  
	glutIdleFunc(display);

   	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	initWindow();				             //create_window

	


	glutMainLoop();                 // Initialize The Main Loop



   


  

//    cpu1.executeNextInstruction();
//    cpu1.executeNextInstruction();
//    cpu1.executeNextInstruction();
//    cpu1.executeNextInstruction();
//    cpu1.executeNextInstruction();
//    cpu1.executeNextInstruction();
   


   return 0;
}


