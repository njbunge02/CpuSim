#include "GUI.h"

float aspect = (float)WIDTH / (float)HEIGHT;
float nearPlane = 1.0f;
float farPlane = 1000.0f;

float fov = 60.0f;
bool drawStep = true;

using namespace std;

CPU cpuGlobal;

void initCPU(string filename)
{
CPU cpu1(filename);
cpuGlobal = cpu1;
}


void stepRun()
{
	cpuGlobal.executeNextInstruction();
   cpuGlobal.executeNextInstruction();
	cpuGlobal.executeNextInstruction();
   cpuGlobal.printAllRegisters();
}

void cpuRun()
{

}



void renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

float boxX = -0.25f;
float boxY = -0.4f;
float scale = 1.0f;

float boxLeft = (-0.08f + boxX) * scale;
float boxRight = (0.08f + boxX) * scale;
float boxBottom = (-0.045f + boxY) * scale;
float boxTop = (0.045f + boxY) * scale;

float boxX2 = 0.25f;
float boxY2 = -0.4f;
float scale2 = 1.0f;

float boxLeft2 = (-0.08f + boxX2) * scale2;
float boxRight2 = (0.08f + boxX2) * scale2;
float boxBottom2 = (-0.045f + boxY2) * scale2;
float boxTop2 = (0.045f + boxY2) * scale2;








void mouse(int button, int state, int x, int y) {
    // Convert mouse coordinates to OpenGL coordinates
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    // Convert mouse coordinates to OpenGL coordinates
    float mouseX = (float)x / (float)windowWidth * 2.0f - 1.0f;
    float mouseY = 1.0f - (float)y / (float)windowHeight * 2.0f;


   
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Check if mouse coordinates fall within the boundaries of the first box
        if (mouseX  >= -0.321875f && mouseX  <= -0.164062f && mouseY >= -0.780556f && mouseY <= -0.611111f) { //left box step execution
            stepRun();
        }
        // Check if mouse coordinates fall within the boundaries of the second box
        if (mouseX >= 0.167187 && mouseX <= 0.325f && mouseY >= -0.775f && mouseY <= 0.-0.613889f) {  //right run
            drawStep = false;
            cpuRun();
        }  
    }
}


// Function to draw the button
void drawStepButton() {
 glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(boxLeft, boxBottom); // Bottom left corner
    glVertex2f(boxRight, boxBottom);  // Bottom right corner
    glVertex2f(boxRight, boxTop);   // Top right corner
    glVertex2f(boxLeft, boxTop);  // Top left corner
    glEnd();
}

void drawRunButton() {
 glColor3f(0.0f, 0.0f, 1.0f); // blue color
    glBegin(GL_QUADS);
    glVertex2f(boxLeft2, boxBottom2); // Bottom left corner
    glVertex2f(boxRight2, boxBottom2);  // Bottom right corner
    glVertex2f(boxRight2, boxTop2);   // Top right corner
    glVertex2f(boxLeft2, boxTop2);  // Top left corner
    glEnd();
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

 

      gluLookAt(0.0, 0.0, 1.0,   // eye position
              0.0, 0.0, 0.0,   // look-at position
              0.0, 1.0, 0.0);  // up vector

   glutPostRedisplay();   
   
   drawRunButton();
  if (drawStep)
   drawStepButton();
  
   //renderBitmapString(0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "CPU GUI Test");

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