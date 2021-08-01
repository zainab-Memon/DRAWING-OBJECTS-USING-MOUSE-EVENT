#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include<string>
#include <sstream>
using namespace std;




int i=0;
int shapeno = 0;
int x1,z1,x2,z2;
GLsizei winWidth = 400, winHeight = 300;
GLint endPtCtr = 0;
int pntX1, pntY1, radius;
void plot(int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(x+pntX1, y+pntY1);
glEnd();
}

  void midPointCircleAlgo()
  {
int x = 0;
int y = radius;
float decision = 5/4 - radius;
plot(x, y);

while (y > x)
{
if (decision < 0)
{
x++;
decision += 2*x+1;
}
else
{
y--;
x++;
decision += 2*(x-y)+1;
}
plot(x, y);
plot(x, -y);
plot(-x, y);
plot(-x, -y);
plot(y, x);
plot(-y, x);
plot(y, -x);
plot(-y, -x);
}

    }


class scrPt
{
    public:
        GLint x,y;
};

static scrPt endPt1, endPt2;
    void Rectangle(scrPt endPt1, scrPt endPt2)
    {


    glBegin(GL_QUADS);
    glVertex2i(endPt1.x,endPt1.y);
    glVertex2i(endPt1.x,endPt2.y);
    glVertex2i(endPt2.x,endPt2.y);
    glVertex2i(endPt2.x,endPt1.y);
    glVertex2i(endPt2.x,endPt1.y);
    glEnd();

    }
void init (void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
 //     glShadeModel (GL_FLAT);
}
 int myrandom(int m) {

	return rand()%m;
}

void output(int x, int y, char *string)
{
  glColor3f( 0.0,0.0, 0.0 );
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
  }
}
void displayFcn(void)
{
   // glClear(GL_COLOR_BUFFER_BIT);
    switch (shapeno)
    {
    case 0:
    glClear(GL_COLOR_BUFFER_BIT);
         glPushMatrix();
         glBegin(GL_POINTS );
         midPointCircleAlgo();
            glEnd();
            glPopMatrix();

           // glutSwapBuffers();
             break;

    case 1:

           glClear(GL_COLOR_BUFFER_BIT);
             glPushMatrix();
        glBegin(GL_POINTS);

          Rectangle(endPt1,endPt2);
            glEnd();
            glPopMatrix();
            //glutSwapBuffers();
break;
    default:
        break;

    }
}
void setPixel(GLint xCoord, GLint yCoord)
{
        glBegin(GL_POINTS);
        glVertex2i(xCoord, yCoord);
    glEnd();
}
void winReshapeFcn(int newWidth, int newHeight)
{
    glViewport(0,0,newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,GLdouble(newWidth),0.0, GLdouble(newHeight));
    winWidth = newWidth;
    winHeight = newHeight;

}
void key(unsigned char key,int x, int y)
{
    switch(key)
    {
        case 't':
            shapeno = 0;
        break;
        case 'r':
            shapeno = 1;
        break;
        case 27:
            exit(0);
            break;
        default:
            shapeno = -1;
            break;

    }
    glutPostRedisplay();
}
void drawline(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if (endPtCtr == 0)
    {
        if (button == GLUT_RIGHT_BUTTON && action == GLUT_UP)
        {
            endPt1.x = xMouse;
            endPt1.y = winHeight - yMouse;
            setPixel(endPt1.x,endPt1.y);
            pntX1 = endPt1.x;
            pntY1 = endPt1.y;

         glColor3f((float)myrandom(255)/255, (float)myrandom(255)/255, (float)myrandom(255)/255);
        midPointCircleAlgo();


            endPtCtr = 1;
        }

    }
    else if (endPtCtr == 1)
    {
        if (button == GLUT_RIGHT_BUTTON && action == GLUT_UP)
        {
            endPt2.x = xMouse;
            endPt2.y = winHeight - yMouse;
            radius = sqrt(pow((endPt2.x - endPt1.x),2) + pow((endPt2.y - endPt1.y),2));
             glColor3f((float)myrandom(255)/255, (float)myrandom(255)/255, (float)myrandom(255)/255);
          //  midPointCircleAlgo();
            endPtCtr = 0;
        }

    }
    if (endPtCtr == 0)
    {
        if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
        {
            endPt1.x = xMouse;
            endPt1.y = winHeight - yMouse;
            setPixel(endPt1.x,endPt1.y);
            pntX1 = endPt1.x;
            pntY1 = endPt1.y;
            glColor3f((float)myrandom(255)/255, (float)myrandom(255)/255, (float)myrandom(255)/255);
        // Rectangle(endPt1,endPt2);
            endPtCtr = 1;
        }

    }
    else if (endPtCtr == 1)
    {
        if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
        {
            endPt2.x = xMouse;
            endPt2.y = winHeight - yMouse;
            radius = sqrt(pow((endPt2.x - endPt1.x),2) + pow((endPt2.y - endPt1.y),2));
             glColor3f((float)myrandom(255)/255, (float)myrandom(255)/255, (float)myrandom(255)/255);
             Rectangle(endPt1,endPt2);
            endPtCtr = 0;
        }

    }
 glFlush();

}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("An Example OpenGL Program");
    init();
    glutDisplayFunc(displayFcn);
    glutReshapeFunc(winReshapeFcn);
    glutMouseFunc(drawline);
     glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
