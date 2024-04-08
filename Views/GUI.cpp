#include "GUI.h"

float aspect = (float)WIDTH / (float)HEIGHT;
float nearPlane = 1.0f;
float farPlane = 1000.0f;

float fov = 60.0f;


void renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


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