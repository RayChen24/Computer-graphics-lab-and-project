
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
/*** freeglut***/
#include ".\GL\freeglut.h"
#define Math_PI 3.14159265358979 
GLfloat xRotate = 0;
GLfloat yRotate = 0; 
GLfloat zRotate = 0;
GLfloat xTranslate = 0;
GLfloat yTranslate = 0;
GLfloat zTranslate = 0;
GLfloat xscale = 1;
GLfloat yscale = 1;
GLfloat zscale = 1;
GLfloat pointx = 0.0f+1;
GLfloat pointy = 0.0f +1.25;
GLfloat pointx1 = 0.0f+1;
GLfloat pointy1 = 0.0f+1.25;
GLfloat angle = 0;


GLfloat degree(GLfloat deg)
{
    return deg * Math_PI / 180.0;
}
using namespace std;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}    // Front face
void translate() 
{
    GLfloat translate[]
    {
        1,0,0,0,
       0, 1, 0, 0,
       0, 0, 1, 0,
        pointx,pointy,0,1
    };
    GLfloat translate1[]
    {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        pointx1,pointy1,0,1
    };
    glLoadMatrixf(translate);
    glutSolidSphere(0.2, 64, 64);
    glLoadMatrixf(translate1);
    glutSolidSphere(0.2, 64, 64);
    glLoadIdentity();
}
void rotate()
{
    GLfloat rotMatrix[] =
    {
        1.0 ,                    0.0 ,                  0.0 , 0.0,
        0.0 ,   cosf(degree(xRotate)),sinf(degree(xRotate)), 0.0,
        0.0 ,   -sinf(degree(xRotate)), cosf(degree(xRotate)), 0.0,
        0.0 ,                    0.0 ,                  0.0 , 1.0,
    };
    glMultMatrixf(rotMatrix);

    GLfloat rotMatrix1[] =
    {
       cosf(degree(yRotate)),    0.0 , -sinf(degree(yRotate)) , 0.0,
        0.0 ,                    1.0 ,                   0.0 , 0.0,
       sinf(degree(yRotate)),    0.0 , cosf(degree(yRotate)), 0.0,
        0.0 ,                    0.0 ,                  0.0  , 1.0,
    };
    glMultMatrixf(rotMatrix1);

    GLfloat rotMatrix2[] =
    {
       cosf(degree(zRotate)),  sinf(degree(zRotate)),   0.0 , 0.0,
       -sinf(degree(zRotate)),  cosf(degree(zRotate)) ,   0.0 , 0.0,
        0.0 ,                    0.0 ,                   1.0 , 0.0,
        0.0 ,                    0.0 ,                   0.0 , 1.0,
    };
    glMultMatrixf(rotMatrix2);


    GLfloat transMatrix[] =
    {
               1.0 ,        0.0 ,       0.0 , 0.0 ,
               0.0 ,        1.0 ,       0.0 , 0.0 ,
               0.0 ,        0.0 ,       1.0 , 0.0 ,
        xTranslate , yTranslate ,zTranslate , 1.0 ,
    };
    glMultMatrixf(transMatrix);

    glTranslatef(xTranslate, yTranslate, zTranslate);
}
void scale()
{
    GLfloat scaleMatrix[] =
    {
        xscale ,     0.0 ,        0.0 ,     0.0,
        0.0    ,  yscale ,        0.0 ,     0.0,
        0.0    ,    0.0 ,      zscale ,     0.0,
        0.0    ,    0.0 ,          0.0,     1.0,
    };
    glMultMatrixf(scaleMatrix);
}
void drawtriangles()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1, 1);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(2.0, 0.0, 0.0);
    glVertex3f(1.0, 3.0, 0.0);
    glEnd();

    // Right face
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(2.0, 0.0, 0.0);
    glVertex3f(2.0, 0.0, -4.0);
    glVertex3f(1.0, 3.0, 0.0);
    glVertex3f(1.0, 3.0, -4.0);

    glEnd();

    // Left face
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -4.0);
    glVertex3f(1.0, 3.0, 0.0);
    glVertex3f(1.0, 3.0, -4.0);
    glEnd();

    // Bottom face
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -4.0);
    glVertex3f(2.0, 0.0, 0.0);
    glVertex3f(2.0, 0.0, -4.0);
    glEnd();

    // Back face
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(0.0, 0.0, -4.0);
    glVertex3f(2.0, 0.0, -4.0);
    glVertex3f(1.0, 3.0, -4.0);
    glEnd();
}
void drawaxis()
{
    // Draw X-axis
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-4.0, 1.2, 0.0);
    glVertex3f(6.0, 1.2, 0.0);
    glEnd();

    // Draw Y-axis
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(1.0, -4.0, 0.0);
    glVertex3f(1.0, 6.0, 0.0);
    glEnd();

    // Draw Z-axis
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(1, 1.25, -5.0);
    glVertex3f(1, 1.25, 5.0);
    glEnd();
    glFlush();
    glutSwapBuffers();
}
void display(void) 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();

    // Draw X-axis
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-5.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);
    glEnd();

    // Draw Y-axis
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(0.0, -5.0, 0.0);
    glVertex3f(0.0, 5.0, 0.0);
    glEnd();

    // Draw Z-axis
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(0.0, 0.0, -5.0);
    glVertex3f(0.0, 0.0, 5.0);
    glEnd();
    glFlush();
}
void rotateMatrix(float angle, GLfloat X, GLfloat Y, GLfloat Z)
{
    GLfloat cos = cosf(angle);
    GLfloat sin = sinf(angle);
    //GLfloat X = pointx1 - pointx;
    //GLfloat Y = pointy1 - pointy;
    //GLfloat total = X * X + Y * Y;
    //total = pow(total, 0.5);
    //X /= total;
    //Y /= total;
    GLfloat rotatematrix[] =
    {
        cos + (1 - cos) * X * X, (1 - cos) * X * Y - sin * 0,(1 - cos) * X * 0 + sin * Y,0,
        (1 - cos) * Y * X + sin * 0, cos + (1 - cos) * Y * Y,(1 - cos) * Y * 0 - sin * X,0,
        (1 - cos) * 0 * X - sin * Y, (1 - cos) * 0 * Y + sin * X,cos + (1 - cos) * 0 * 0,0,
        0,0,0,1
    };
    glMultMatrixf(rotatematrix);

};

void trianglePrism(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //glRotatef(xRotate, 1, 0, 0);
    //glRotatef(yRotate, 0, 1, 0);
    //glRotatef(zRotate, 0, 0, 1);


    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    //glVertex3f(1, 1.25, 0);
    glVertex3f(pointx, pointy, 0);
    glVertex3f(pointx1, pointy1, 0);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);

    translate();
    rotate();
    scale();
    GLfloat X = pointx1 - pointx;
    GLfloat Y = pointy1 - pointy;
    GLfloat total = X * X + Y * Y;
    total = pow(total, 0.5);
    X /= total;
    Y /= total;
    rotateMatrix(angle, X, Y, 0);
    drawtriangles();
    drawaxis();
}

void keyboard(unsigned char key ,int x ,int y)
{
    if (key == 'a')
        xRotate += 1;
    else  if (key == 'b')
        yRotate += 1;
    else if (key == 'c')
        zRotate += 1;
    else if (key == 'd')
    {
        xRotate = 0;
        yRotate = 0;
        zRotate = 0;
        xTranslate = 0;
        yTranslate = 0;
        zTranslate = 0;
        xscale = 1;
        yscale = 1;

        zscale = 1;
    }
    else  if (key == 'e')
        xTranslate += 1;
    else  if (key == 'f')
        yTranslate += 1;
    else  if (key == 'g')
        zTranslate += 1;
    else  if (key == 'h')
        xscale += 1;
    else  if (key == 'i')
        yscale += 1;
    else  if (key == 'j')
        zscale += 1;
    else if (key == 'r')
    {
        pointx = 1;
        pointy = 1.25;
        pointx1 = 1;
        pointy1 = 1.25;
    }
    else if (key == 'q')
         angle += 1;

    glutPostRedisplay();
}
void mouseClick(GLint button, GLint state, GLint x, GLint y)
{
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        pointx = x * ((5 - (-5)) / 500.0f) + (-5);
        pointy = y * ((((-5) -5))/ 500.0f) + (5);
    }
            
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        pointx1 = x * ((5 - (-5)) / 500.0f) + (-5);
        pointy1= y * ((((-5) - 5)) / 500.0f) + (5);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle Prism");
    init();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(trianglePrism);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseClick);
    
    glutMainLoop();
    return 0;
}