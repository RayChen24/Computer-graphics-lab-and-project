#include <GL/freeglut.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
GLfloat xRotate = 0;
GLfloat yRotate = 0;
GLfloat zRotate = 0;
GLfloat xTranslate = 0;
GLfloat yTranslate = 0;
GLfloat zTranslate = 0;
GLfloat pointx = 0.0f + 1;
GLfloat pointy = 0.0f + 1.25;
GLfloat pointx1 = 0.0f + 1;
GLfloat pointy1 = 0.0f + 1.25;
GLfloat angle = 0;
GLfloat xMax = INT_MIN;
GLfloat yMax = INT_MIN;
GLfloat zMax = INT_MIN;
GLfloat xMin = INT_MAX;
GLfloat yMin = INT_MAX;
GLfloat zMin = INT_MAX;
GLfloat colora; 
GLfloat colorb;
GLfloat colorc;
GLfloat a = 0;
GLfloat b = 1;
GLfloat c = 0;
#define Math_PI 3.14159265358979
using namespace std;
GLfloat degree(GLfloat deg)
{
    return deg * Math_PI / 180.0;
}

struct Vertex {float x, y, z;};

struct Face {unsigned int v1, v2, v3;};



std::vector<Vertex> objVertices;
//std::vector<Face> objFaces;
vector<vector<GLfloat>> objFaces;
enum class RenderMode{POINTS,WIREFRAME,SOLID};
RenderMode currentRenderMode = RenderMode::POINTS;
void changesize(int w, int h)
{
    printf("Window Size= %d X %d\n", w, h);
    glViewport(0, 0, w, h);
}
void loadOBJ(string filename) 

{
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    objVertices.clear();
    objFaces.clear();
    std::string line;
    while (std::getline(file, line))
    {
        if (line.substr(0, 2) == "v ") 
        {
            Vertex vertex;
            sscanf_s(line.c_str(), "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
            objVertices.push_back(vertex);
        }
        else if (line.substr(0, 2) == "f ")
        {
            /*Face face;
            sscanf_s(line.c_str(), "f %u %u %u", &face.v1, &face.v2, &face.v3);
            objFaces.push_back(face);*/
            //while (true)
            //{
            //    s1 >> i1;
            //    if (s1.fail()) break;//確認stringstream有正常流出，沒有代表空了
            //    sum += i1;//把每個轉換成int的數字都丟入sum累加
            //}
            vector<GLfloat> temp;
            stringstream content(line);
            int x;
            while (true)
            {
                content >> x;
                if (content.fail())
                    break;
            }
           
            objFaces.push_back(temp);
        }
    }
    xMax = INT_MIN;
    yMax = INT_MIN;
    zMax = INT_MIN;
    xMin = INT_MAX;
    yMin = INT_MAX;
    zMin = INT_MAX;
    for (int i = 0, n = objVertices.size(); i < n; i++)
    {
        if (objVertices[i].x > xMax)
            xMax = objVertices[i].x;
        if (objVertices[i].y> yMax)
            yMax= objVertices[i].y;
        if (objVertices[i].z > zMax)
            zMax = objVertices[i].z;
    }
    for (int i = 0, n =objVertices.size();i<n ;i++)
    {
        if (objVertices[i].x < xMin)
            xMin = objVertices[i].x;
        if (objVertices[i].y < yMin)
            yMin = objVertices[i].y;
        if (objVertices[i].z < zMin)
            zMin = objVertices[i].z;
    }

    file.close();
    glutPostRedisplay();
}

void select_obj(int index)
{
    switch (index)
    {
    case 1:
        loadOBJ("octahedron.obj");
        break;
    case 2:
        loadOBJ(".\\teapot.obj");
        break;
    case 3:
        loadOBJ(".\\teddy.obj");
        break;
    case 4:
        loadOBJ(".\\gourd.obj");
        break;
    default:
        break;
    }
}
void status (int index)
{
    switch (index)
    {
        case 1:
        break;
    }
}
void file(int index)
{
    switch (index)
    {
        case 1:
        break;
    }
}
void colormode(int index)
{
    switch (index)
    {
        case 1:
        break;
    }
}
int randomNumberGenerator()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    return (rand() % 100+ 1)/100;
}
void colorgenerator(int mode)
{
    if (mode == 0)
    {
        colora = 0;
        colorb = 0;
        colorc = 1;
    }
    else
    {
       colora = static_cast<GLfloat>(rand()) / RAND_MAX;
       colorb = static_cast<GLfloat>(rand()) / RAND_MAX;
       colorc = static_cast<GLfloat>(rand()) / RAND_MAX;
        /*colora = randomNumberGenerator();
        colorb = randomNumberGenerator();
        colorc = randomNumberGenerator();*/
    }
}
void select_colormode(int index)
{
    switch (index)
    {
    case 0:
        colorgenerator(0);
        glShadeModel(GL_FLAT);
        break;
    case 1:
        colorgenerator(1);
        glShadeModel(GL_SMOOTH);
        break;
    }
    glutPostRedisplay();
}
void select_color(int index)
{
    switch (index)
    {
    case 0:
        break;
    }
}
void select_status(int choice)
{
    std::string line;
    switch (choice)
    {
    case 1:
        currentRenderMode = RenderMode::POINTS;
        break;
    case 2:
        currentRenderMode = RenderMode::WIREFRAME;
        break;
    case 3:
        currentRenderMode = RenderMode::SOLID;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}
void mainMenu(int index){}

void draw_axis()
{
    // draw X axis
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
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
}
void keyboard(unsigned char key, int x, int y)
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
        angle = 0;
    }
    else  if (key == 'e')
        xTranslate += 1;
    else  if (key == 'f')
        yTranslate += 1;
    else  if (key == 'g')
        zTranslate += 1;
    else if (key == 'h')
        angle++;
    glutPostRedisplay();

}
void rotateMatrix(float angle, GLfloat X, GLfloat Y, GLfloat Z)
{
    GLfloat cos = cosf(angle);
    GLfloat sin = sinf(angle);
    GLfloat rotatematrix[] =
    {
        cos + (1 - cos) * X * X, (1 - cos) * X * Y - sin * 0,(1 - cos) * X * 0 + sin * Y,0,
        (1 - cos) * Y * X + sin * 0, cos + (1 - cos) * Y * Y,(1 - cos) * Y * 0 - sin * X,0,
        (1 - cos) * 0 * X - sin * Y, (1 - cos) * 0 * Y + sin * X,cos + (1 - cos) * 0 * 0,0,
        0,0,0,1
    };
    glMultMatrixf(rotatematrix);

};
void mouseClick(GLint button, GLint state, GLint x, GLint y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        pointx = x * ((xMax*1.5 - (xMin*1.5)) / 600.0f) + (xMin * 1.5);
        pointy = y * ((((yMin * 1.5) - yMax*1.5)) / 600.0f) - (yMin*1.5);
        cout << pointx << " " << pointy << endl;
       
    }

    else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
        pointx1 = x * ((xMax * 1.5 - (xMin * 1.5)) / 600.0f) + (xMin * 1.5);
        pointy1 = y * ((((yMin * 1.5) - yMax * 1.5)) / 600.0f) - (yMin * 1.5);
        cout << pointx1 << " " << pointy1 << endl;
    }
    glutPostRedisplay();
}

//xcamera = (xMin + xMax) / 2 * 1.5;
//ycamera = (yMin + yMax) / 2 * 1.5;
//zcamera = (zMin + zMax) / 2 * 1.5;
//xFocus = xcamera;
//yFocus = ycamera;
//zFocus = zcamera;
void display()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xMin*1.5, xMax*1.5, yMin*1.5, yMax*1.5, zMin*1.5, zMax*4);
    glMatrixMode(GL_MODELVIEW);
    //gluLookAt(0, 0,5,0,0,0,0,1,0);
    gluLookAt(0, 0, zMin * 1.5, (xMin+xMax)/2, (yMin + yMax) / 2, (zMin + zMax) / 2, 0, 1, 0);
    glLoadIdentity();
    /*gluLookAt(xcamera, ycamera, zcamera, xFocus, yFocus, zFocus, 0.0, 1.0, 0.0);*/
    glRotatef(xRotate, 1, 0, 0);
    glRotatef(yRotate, 0, 1, 0);
    glRotatef(zRotate, 0, 0, 1);
    glTranslatef(xTranslate, yTranslate, zTranslate);
    glColor3f(0, 1, 1);
    glBegin(GL_POINT);
    glVertex3f(pointx, pointy, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(pointx, pointy, 0);
    glVertex3f(pointx1, pointy1, 0);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    GLfloat X = pointx1 - pointx;
    GLfloat Y = pointy1 - pointy;
    GLfloat total = X * X + Y * Y;
    total = pow(total, 0.5);
   /* X /= total;
    Y /= total;
    rotateMatrix(angle, X, Y, 0);*/
    if (total!=0)
    {
        X /= total;
        Y /= total;
        rotateMatrix(angle, X, Y, 0);
    }
    for (const auto& face : objFaces)
    {
        switch (currentRenderMode)
        {
        case RenderMode::POINTS:
            glPointSize(5);
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            break;
        case RenderMode::WIREFRAME:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;
        case RenderMode::SOLID:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        default:
            break;
        }
        glBegin(GL_TRIANGLES);
        for (const auto& face : objFaces)
        {
            //colorgenerator(0);
            //colorgenerator(1);
            glColor3f(0, 1, 0);
            glColor3f(colora, colorb, colorc);
            glVertex3f(objVertices[face.v1 - 1].x, objVertices[face.v1 - 1].y, objVertices[face.v1 - 1].z);
            glVertex3f(objVertices[face.v2 - 1].x, objVertices[face.v2 - 1].y, objVertices[face.v2 - 1].z);
            glVertex3f(objVertices[face.v3 - 1].x, objVertices[face.v3 - 1].y, objVertices[face.v3 - 1].z);

        }
        glEnd();
    }
    //draw_axis();
    glutSwapBuffers();
}
void createmenu()
{
    int _status =glutCreateMenu(status);
    int _file =glutCreateMenu(file);
    int _colormode = glutCreateMenu(colormode);
    int _select_color = glutCreateMenu(select_color);
    int _select_status=glutCreateMenu(select_status);
    glutAddMenuEntry("point", 1);
    glutAddMenuEntry("line", 2);
    glutAddMenuEntry("face", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    int _select_obj =glutCreateMenu(select_obj);
    glutAddMenuEntry("octahedron", 1);
    glutAddMenuEntry("teapot", 2);
    glutAddMenuEntry("teddy", 3);
    glutAddMenuEntry("gourd", 4);
    int _select_colormode = glutCreateMenu(select_colormode);
    glutAddMenuEntry("single_color", 0);
    glutAddMenuEntry("random_color", 1);
    glutCreateMenu(mainMenu);
    glutAddSubMenu("file", _select_obj);
    glutAddSubMenu("status", _select_status);
    glutAddSubMenu("colormode",_select_colormode );
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

    int main(int argc, char** argv)
{
        //srand(static_cast<unsigned int>(time(nullptr)));
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(600, 600);
        glutCreateWindow("OBJ File Viewer");
        createmenu();
        glEnable(GL_DEPTH_TEST);
        if (argc > 1)
        {
            loadOBJ(argv[1]);
        }
        glutReshapeFunc(changesize);
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutMouseFunc(mouseClick);
        glutMainLoop();

        return 0;
}