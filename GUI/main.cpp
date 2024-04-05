//
//		          Programming Assignment #2 CPSC4050/6050
//
//					Daljit Singh Dhillon 
//
//
/***************************************************************************/

/* Include needed files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>   

#include <math.h>

#define WIDTH 1280
#define HEIGHT 720


/***************************************************************************/
// Forward declarations


float aspect = (float)WIDTH / (float)HEIGHT;
float nearPlane = 1.0f;
float farPlane = 1000.0f;

float fov = 60.0f;

void renderBitmapString(float x, float y, void *font, const char *string);



void renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

/***************************************************************************/
void initWindow()
/* Clear the image area, and set up the coordinate system */
{
    
   glClearColor(0.0,0.0,0.0,0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   gluPerspective(fov, (float)WIDTH / (float)HEIGHT, 1.0, 1000.0);
  
   

   glEnable(GL_DEPTH_TEST); 
 
}


/***************************************************************************/

void display(void)
{


   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

 

      gluLookAt(0.0, 0.0, 10.0,   // eye position
              0.0, 0.0, 0.0,   // look-at position
              0.0, 1.0, 0.0);  // up vector

   glutPostRedisplay();   
   
   renderBitmapString(0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "CPU GUI Test");

   glFlush();            
   glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:     //ESC key           
         exit(0);
         break;
   }

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
     
   glOrtho(-WIDTH/2, WIDTH/2, -HEIGHT/2, HEIGHT/2, -1000.0, 1000.0);

    glutPostRedisplay();
}


int main (int argc, char *argv[])
{
/* This main function sets up the main loop of the program and continues the
   loop until the end of the data is reached.  Then the window can be closed
   using the escape key.						  */
	
	//while (currExample != 0)
	{
		//intakeChoice();
		
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