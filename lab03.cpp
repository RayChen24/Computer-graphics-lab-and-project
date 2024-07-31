
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
/*** freeglut***/
#include ".\GL\freeglut.h"
GLfloat xRotate = 0;
GLfloat yRotate = 0; 
GLfloat zRotate = 0;
GLfloat xTranslate = 0;
GLfloat yTranslate = 0;
GLfloat zTranslate = 0;

using namespace std;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glLoadMatrixf();
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

void trianglePrism(void) 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(xRotate, 1, 0, 0);
    glRotatef(yRotate, 0, 1, 0);
    glRotatef(zRotate, 0, 0, 1);
    glTranslatef(xTranslate, yTranslate, zTranslate);
    
    // Front face
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
    glVertex3f(0.0, 0.0, -5.0);
    glVertex3f(0.0, 0.0, 1.0);
    glEnd();
    //glRotatef(30.0f, 1, 1, 0);//rotate30 on x
    //glRotatef(xRotate, 1, 0, 0);
    //glRotatef(yRotate, 0, 1, 0);
    //glRotatef(zRotate, 0, 0, 1);
    //cout << xRotate << " " << yRotate << " " << zRotate << endl;
    //glTranslatef(xTranslate, yTranslate, zTranslate);
    //glRotatef(60.0f, 0, 1, 1);//rotate60 on y
    //glRotatef(90.0f, 1, 1, 1);//rotate60 on z
    glFlush();
}
void keyboard(unsigned char key ,int x ,int y)
{
    if (key == 'a')
        xRotate += 1;
    else  if (key == 'b')
        yRotate += 1;
    else if (key =='c')
        zRotate += 1;
    else if (key == 'd')
    {
        xRotate = 0;
        yRotate = 0;
        zRotate = 0;
        xTranslate = 0;
        yTranslate = 0;
        zTranslate = 0;
    }
    else  if (key == 'e')
        xTranslate += 1;
    else  if (key == 'f')
        yTranslate += 1;
    else  if (key == 'g')
        zTranslate += 1;
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
    
    glutMainLoop();
    return 0;
}