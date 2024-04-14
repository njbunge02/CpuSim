#include "GUI.h"

float aspect = (float)WIDTH / (float)HEIGHT;
float nearPlane = 1.0f;
float farPlane = 1000.0f;

float fov = 60.0f;
bool drawStep = true;

 int newLineCount = 0;
 float programY = -0.2f;


using namespace std;

CPU cpuGlobal;
string outputString = "";
string registerString = "";
string statsString = "";

void initCPU(string filename)
{
CPU cpu1(filename);
cpuGlobal = cpu1;
}



void stepRun()
{
   string outLog = "";
   outLog = cpuGlobal.executeNextInstruction();
   cpuGlobal.printAllRegisters();
   outputString += "----------\n" + outLog + "\n----------\n";

   programY = -0.2f;
   for (int i = 0; i < outputString.size(); ++i)
   {
      if (outputString[i] == '\n')
      {
         programY += 0.05f;
      }
   }

}  

void cpuRun()
{

}



void renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        if (*c == '\n') {
            // Move cursor to the beginning of the next line
            y += 0.05f;
            glRasterPos2f(x, y);
        } else {
            glutBitmapCharacter(font, *c);
        }
    }
}

void renderBitmapProgramString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        if (*c == '\n') {
            // Move cursor to the beginning of the next line
            y -= 0.05f;
            glRasterPos2f(x, y);
        } else {
            glutBitmapCharacter(font, *c);
        }
    }
}

void renderBitmapRegisterString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        if (*c == '\n') {
            // Move cursor to the beginning of the next line
            y += 0.025f;
            glRasterPos2f(x, y);
        } else {
            glutBitmapCharacter(font, *c);
        }
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
        if (mouseX  >= -0.321875f && mouseX  <= -0.164062f && mouseY >= -0.780556f && mouseY <= -0.611111f && drawStep) { //left box step execution
            stepRun();
        }
        // Check if mouse coordinates fall within the boundaries of the second box
        if (mouseX >= 0.167187 && mouseX <= 0.325f && mouseY >= -0.775f && mouseY <= -0.613889f) {  //right run
            drawStep = false;
            cpuRun();
        }  

         
         if (mouseX >= -0.839063f && mouseX <= -0.71875f && mouseY >= -0.491667 && mouseY <= -0.386111f) {  //right run
            cout << "UP" << endl;
            programY += 0.05f;
        }  

         if (mouseX >= -0.639063f && mouseX <= -0.526563 && mouseY >= -0.486111 && mouseY <= -0.388889f) {  //right run
            cout << "DOWN" << endl;
            
             if (programY > -0.15f)
               programY -= 0.05;
           
        }  


    }
}


// Function to draw the button
void drawStepButton() {
 glColor3f(1.0f, 1.0f, 1.0f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(boxLeft, boxBottom); // Bottom left corner
    glVertex2f(boxRight, boxBottom);  // Bottom right corner
    glVertex2f(boxRight, boxTop);   // Top right corner
    glVertex2f(boxLeft, boxTop);  // Top left corner
    glEnd();
}


void drawRunButton() {
 glColor3f(1.0f, 1.0f, 1.0f); // blue color
    glBegin(GL_QUADS);
    glVertex2f(boxLeft2, boxBottom2); // Bottom left corner
    glVertex2f(boxRight2, boxBottom2);  // Bottom right corner
    glVertex2f(boxRight2, boxTop2);   // Top right corner
    glVertex2f(boxLeft2, boxTop2);  // Top left corner
    glEnd();
}


float boxX5 = -0.25f;
float boxY5 = -0.46f;
float scale5 = 1.0f;

float boxLeft5 = (-1 + boxX5) * scale5;
float boxRight5 = (0.4f + boxX5) * scale5;
float boxBottom5 = (-0.3f + boxY5) * scale5;
float boxTop5 = (0.3f + boxY5) * scale5;

void drawBlackBox() {
 glColor3f(0.0f, 0.0f, 0.0f); // blue color
    glBegin(GL_QUADS);
    glVertex2f(boxLeft5, boxBottom5); // Bottom left corner
    glVertex2f(boxRight5, boxBottom5);  // Bottom right corner
    glVertex2f(boxRight5, boxTop5);   // Top right corner
    glVertex2f(boxLeft5, boxTop5);  // Top left corner
    glEnd();
}

float boxX4 = -0.8f;
float boxY4 = -0.25f;
float scale4 = 1.0f;

float boxLeft4 = (-0.06f + boxX4) * scale4;
float boxRight4 = (0.06f + boxX4) * scale4;
float boxBottom4 = (-0.03f + boxY4) * scale4;
float boxTop4 = (0.03f + boxY4) * scale4;

void drawUpButton() {
 glColor3f(1.0f, 1.0f, 1.0f); // blue color
    glBegin(GL_QUADS);
    glVertex2f(boxLeft4, boxBottom4); // Bottom left corner
    glVertex2f(boxRight4, boxBottom4);  // Bottom right corner
    glVertex2f(boxRight4, boxTop4);   // Top right corner
    glVertex2f(boxLeft4, boxTop4);  // Top left corner
    glEnd();
}


float boxX3 = -0.6f;
float boxY3 = -0.25f;
float scale3 = 1.0f;

float boxLeft3 = (-0.06f + boxX3) * scale3;
float boxRight3 = (0.06f + boxX3) * scale3;
float boxBottom3 = (-0.03f + boxY3) * scale3;
float boxTop3 = (0.03f + boxY3) * scale3;
void drawDownButton() {
 glColor3f(1.0f, 1.0f, 1.0f); // blue color
    glBegin(GL_QUADS);
    glVertex2f(boxLeft3, boxBottom3); // Bottom left corner
    glVertex2f(boxRight3, boxBottom3);  // Bottom right corner
    glVertex2f(boxRight3, boxTop3);   // Top right corner
    glVertex2f(boxLeft3, boxTop3);  // Top left corner
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

drawUpButton();
drawDownButton();
  
  char outputChar[outputString.size() + 1]; 
   strcpy(outputChar, outputString.c_str());
   renderBitmapString(-0.35f, -0.345f, GLUT_BITMAP_HELVETICA_18, "Step Execution");
   renderBitmapString(0.22f, -0.345f, GLUT_BITMAP_HELVETICA_18, "Run");

   renderBitmapString(-0.85f, -0.2f, GLUT_BITMAP_HELVETICA_18, "Up");
   renderBitmapString(-0.65f, -0.2f, GLUT_BITMAP_HELVETICA_18, "Down");


  
  


   registerString = cpuGlobal.getRegisterString();


   char registerChar[registerString.size() + 1]; 
   strcpy(registerChar, registerString.c_str());


   renderBitmapRegisterString(0.45f, -0.4f, GLUT_BITMAP_HELVETICA_10, registerChar);


   statsString = cpuGlobal.getStatsString();

   char statsChar[statsString.size()]; 
   strcpy(statsChar, statsString.c_str());
   renderBitmapString(-0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, statsChar);


  drawBlackBox();

   glColor3f(1.0f, 1.0f, 1.0f); 
  renderBitmapProgramString(-0.95f, programY, GLUT_BITMAP_HELVETICA_10, outputChar);
 

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