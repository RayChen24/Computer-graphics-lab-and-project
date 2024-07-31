
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
//struct Point { float x1, y1; Point(float x_, float y_) :x1(x_), y1(y_) {} };

void drawpixel(float x, float y)
{
    glVertex2f(x, y);
}

void fillpixel(float r, float g, float b, GLfloat pointX, GLfloat pointY)
{
    glColor3f(r, g, b);
    //for (auto list : acc_pixels)
    //{
    //    glBegin(GL_POLYGON);
    //    glVertex2f(floor(list.x), floor(list.y));
    //    glVertex2f(floor(list.x + 1), floor(list.y));
    //    glVertex2f(floor(list.x + 1), floor(list.y + 1));
    //    glVertex2f(floor(list.x), floor(list.y + 1));
    //    glEnd();
    //}
    glBegin(GL_POLYGON);
        glVertex2f(floor(pointX), floor(pointY));
        glVertex2f(floor(pointX+1), floor(pointY));
        glVertex2f(floor(pointX+1), floor(pointY+1));
        glVertex2f(floor(pointX), floor(pointY+1));
        glEnd();
}
void midpoint(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    // Is gradient of line greater than 1
    bool steep = abs(y2 - y1) > abs(x2 - x1);
    GLfloat temp;

    if (steep) {   // If gradient > 1
        // Swap roles of x and y components to step in y instead
        temp = y1;
        y1 = x1;
        x1 = temp;

        temp = y2;
        y2 = x2;
        x2 = temp;
    }

    if (x2 < x1) {
        // Swap points such that step in x is positive
        temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    // Change in x and y which are now both positive
    GLfloat dx = x2 - x1;
    GLfloat dy = abs(y2 - y1);

    // Step in y
    GLfloat sy = y2 > y1 ? 1 : -1;
    GLfloat y = y1;

    //GLfloat x = x1;

    // Decision variable
    GLfloat d = 2 * dy - dx;
    GLfloat x_cor, y_cor;
    // Small step in x
    for (GLfloat x = x1; x <= x2; x++) {
        // Depending on gradient plot x and y
        if (steep) {
            //fillpixel(0,1,0,y, x);
            x_cor = y;
            y_cor = x;
        }
        else {
            //fillpixel(0,0,1,x, y);
            x_cor = x;
            y_cor = y;
        }

        // Update decision parameter
        if (d > 0) {
          
            fillpixel(0, 1, 0, x_cor, y_cor);
            y += sy;
            d += 2 * (dy - dx);
        }
        else {
            fillpixel(0, 0, 1, x_cor, y_cor);
            d += 2 * dy;
        }
    }
}
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


    
    
    if (acc_pixels.size() > 1)
    {
        glColor3f(0.5, 0.5, 0.5);
        for (int i = 0; i < acc_pixels.size() - 1; i++)
        {
            glBegin(GL_LINES);
            glVertex3f(acc_pixels[i].x, acc_pixels[i].y, 0);
            glVertex3f(acc_pixels[i + 1].x, acc_pixels[i + 1].y, 0);
            glEnd();
            
        }

        for (int i = 0; i <= acc_pixels.size() - 2; i++)
        {
            midpoint(acc_pixels[i].x, acc_pixels[i].y, acc_pixels[i + 1].x, acc_pixels[i + 1].y);
        }
    }
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
    glColor3f(1, 0, 0);
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
