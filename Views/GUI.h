#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>
#include <cstring>


//mac headers
/*#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>  */ 

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>  

#include "../Controllers/CPU.h"

#include <math.h>


#define WIDTH 1280
#define HEIGHT 720

void renderBitmapString(float x, float y, void *font, const char *string);
void initWindow();
void display(void);
void keyboard(unsigned char key, int x, int y);


#endif
