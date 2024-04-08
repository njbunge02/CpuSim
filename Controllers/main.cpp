#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include <OpenGL/gl.h>
// #include <OpenGL/glu.h>
// #include <GLUT/glut.h>   

#include <iostream>
#include <fstream>
#include <string>

#include <math.h>
#include "../Views/GUI.h"

using namespace std;

int main (int argc, char *argv[])
{
		
	// glutInit(&argc, argv); 
	// glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	// glutInitWindowSize(WIDTH,HEIGHT); 
	
	// glutCreateWindow("CPU Simulator");


	// glutDisplayFunc(display);  
	// glutIdleFunc(display);


	// glutKeyboardFunc(keyboard);
	// initWindow();				             //create_window

	// glutMainLoop();                 // Initialize The Main Loop

	// return 0;

	if(argc != 2) {
		cout << "Error. Program executed incorreclty. Please use './<program name> yourBinary.bin'" << endl;
	}

	ifstream file(argv[1]);

	if(!file.is_open()){
		cerr << "Error: Unable to open the file" << endl;
		return 1;
	}

	char buffer[100]; //Assumes a 100 bytes per read
	while(file.read(buffer, sizeof(buffer))) {
		cout.write(buffer, file.gcount());
	}

	if(!file.eof()){
		cerr << "Error: Failed to read from the file" << endl;
		return 1;
	}
	


	file.close();
}