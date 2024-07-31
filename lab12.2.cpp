#include <stdio.h> 
#include <iostream>
#include <stdlib.h>
/*** freeglut ***/
#include ".\GL\freeglut.h"
#include <GL/glut.h>

// Rotation angles for different parts of the robot
float headRotation = 0.0f;
float rightShoulderRotation = 0.0f;
float leftShoulderRotation = 0.0f;
float rightElbowRotation = 0.0f;
float leftElbowRotation = 0.0f;
float rightWristRotation = 0.0f;
float leftWristRotation = 0.0f;
float rightHipRotation = 0.0f;
float leftHipRotation = 0.0f;
float rightKneeRotation = 0.0f;
float leftKneeRotation = 0.0f;
float rightAnkleRotation = 0.0f;
float leftAnkleRotation = 0.0f;

void drawTorso() {
    glPushMatrix();
    glScalef(2.0f, 3.0f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawHead() {
    glutSolidSphere(1.0f, 20, 20);
}

void drawUpperArm() {
    glPushMatrix();
    glScalef(0.5f, 1.5f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawLowerArm() {
    glPushMatrix();
    glScalef(0.5f, 1.5f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawHand() {
    glutSolidCube(0.5f);
}

void drawUpperLeg() {
    glPushMatrix();
    glScalef(0.5f, 2.0f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawLowerLeg() {
    glPushMatrix();
    glScalef(0.5f, 2.0f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawFoot() {
    glPushMatrix();
    glScalef(0.7f, 0.3f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawRobot() {
    glPushMatrix();
    glTranslatef(0.0f, 10.0f, 0.0f);
    drawTorso();

    // Draw Head
    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glRotatef(headRotation, 0.0f, 1.0f, 0.0f);
    drawHead();
    glPopMatrix();

    // Draw Right Arm
    glPushMatrix();
    glTranslatef(-2.0f, 1.0f, 0.0f);
    glRotatef(rightShoulderRotation, 1.0f, 0.0f, 0.0f);
    drawUpperArm();
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(rightElbowRotation, 1.0f, 0.0f, 0.0f);
    drawLowerArm();
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(rightWristRotation, 1.0f, 0.0f, 0.0f);
    drawHand();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Draw Left Arm (mirrored)
    glPushMatrix();
    glTranslatef(2.0f, 1.0f, 0.0f);
    glRotatef(leftShoulderRotation, 1.0f, 0.0f, 0.0f);
    drawUpperArm();
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(leftElbowRotation, 1.0f, 0.0f, 0.0f);
    drawLowerArm();
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(leftWristRotation, 1.0f, 0.0f, 0.0f);
    drawHand();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Draw Right Leg
    glPushMatrix();
    glTranslatef(-0.8f, -2.5f, 0.0f);
    glRotatef(rightHipRotation, 1.0f, 0.0f, 0.0f);
    drawUpperLeg();
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(rightKneeRotation, 1.0f, 0.0f, 0.0f);
    drawLowerLeg();
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(rightAnkleRotation, 1.0f, 0.0f, 0.0f);
    drawFoot();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Draw Left Leg (mirrored)
    glPushMatrix();
    glTranslatef(0.8f, -2.5f, 0.0f);
    glRotatef(leftHipRotation, 1.0f, 0.0f, 0.0f);
    drawUpperLeg();
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(leftKneeRotation, 1.0f, 0.0f, 0.0f);
    drawLowerLeg();
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(leftAnkleRotation, 1.0f, 0.0f, 0.0f);
    drawFoot();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 20.0f, 30.0f, 0.0f, 10.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Draw the robot
    drawRobot();

    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, 1.0f, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
    // Update rotation angles for animation
    headRotation += 1.0f;
    rightShoulderRotation += 1.0f;
    leftShoulderRotation -= 1.0f;
    rightElbowRotation += 1.0f;
    leftElbowRotation -= 1.0f;
    rightWristRotation += 1.0f;
    leftWristRotation -= 1.0f;
    rightHipRotation += 1.0f;
    leftHipRotation -= 1.0f;
    rightKneeRotation += 1.0f;
    leftKneeRotation -= 1.0f;
    rightAnkleRotation += 1.0f;
    leftAnkleRotation -= 1.0f;

    // Ensure angles stay within 360 degrees
    headRotation = fmod(headRotation, 90.0f);
    rightShoulderRotation = fmod(rightShoulderRotation, 90.0f);
    leftShoulderRotation = fmod(leftShoulderRotation, 90.0f);
    rightElbowRotation = fmod(rightElbowRotation, 90.0f);
    leftElbowRotation = fmod(leftElbowRotation, 90.0f);
    rightWristRotation = fmod(rightWristRotation, 90.0f);
    leftWristRotation = fmod(leftWristRotation, 90.0f);
    rightHipRotation = fmod(rightHipRotation, 90.0f);
    leftHipRotation = fmod(leftHipRotation, 90.0f);
    rightKneeRotation = fmod(rightKneeRotation, 90.0f);
    leftKneeRotation = fmod(leftKneeRotation, 90.0f);
    rightAnkleRotation = fmod(rightAnkleRotation, 90.0f);
    leftWristRotation = fmod(leftWristRotation, 90.0f);

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Animated Robot");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}

