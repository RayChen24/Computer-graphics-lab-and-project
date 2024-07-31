
#include <stdio.h> 
#include <stdlib.h>
/*** freeglut***/
#include ".\GL\freeglut.h"
#include <GL/glut.h>
#include<math.h>
#include <vector>
GLint a=10;
GLfloat pointx = 0.0f;
GLfloat pointy = 0.0f ;
GLfloat pointx1 = 0.0f;
GLfloat pointy1 = 0.0f;
void fill_pixels();
struct pixels { float x, y; };//int也可以
std::vector<pixels> acc_pixels;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINES);
    for (int i = -a; i <= a; i+=1) 
    {

        glVertex2f(-a, i);
        glVertex2f(a, i);

        glVertex2f(i, -a);
        glVertex2f(i, a);
    }
    glEnd();
    fill_pixels();
    glFlush();
}
void dimension(int index)
{
    switch (index)
    {
    case 0:
        a = 10;
        break;
    case 1:
        a = 20;
        break;
    case 2:
        a=30;
        break;
    }
    glutPostRedisplay();
}
void createmenu()
{
    glutCreateMenu(dimension);
    glutAddMenuEntry("10",0);
    glutAddMenuEntry("20",1);
    glutAddMenuEntry("30",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-40.0, 40.0, -40.0, 40.0, -1.0, 1.0);  
}

void mouseClick(GLint button, GLint state, GLint x, GLint y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        
        pointx = x * ((40 - (-40)) / 800.0f) + (-40);
        pointy = y * ((((-40) - 40)) / 800.0f) + (40);
        pixels pixel_a{ pointx,pointy};//或者是floor
        acc_pixels.push_back(pixel_a);
        printf("%f, %f\n", pixel_a.x, pixel_a.y);
        glutPostRedisplay();
    }
    /*printf("%f, %f\n", pointx, pointy);
    glutPostRedisplay();*/
}

void fill_pixels()
{
  /*  glBegin(GL_POLYGON);
    glVertex2f(floor(pointx), floor(pointy));
    glVertex2f(floor(pointx+1), floor(pointy));
    glVertex2f(floor(pointx+1), floor(pointy+1));
    glVertex2f(floor(pointx), floor(pointy+1));
    glEnd();*/
    for(auto list:acc_pixels)
    {
        glBegin(GL_POLYGON);
        glVertex2f(floor(list.x), floor(list.y));
        glVertex2f(floor(list.x + 1), floor(list.y));
        glVertex2f(floor(list.x + 1), floor(list.y + 1));
        glVertex2f(floor(list.x), floor(list.y + 1));
        glEnd();
    }
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("2D Grid");
    createmenu();
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
    glutMainLoop();

    return 0;
}
