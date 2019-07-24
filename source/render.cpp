#include <iostream>
#include <GL/glut.h>

#include "common.hpp"
#include "render.hpp"

CameraData * cameraDataP;

void
InitRender(CameraData * initCameraData)
{
    cameraDataP = initCameraData;
}

void
RenderDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW);     

    glLoadIdentity();
    glTranslatef(
        cameraDataP->pos.x,
        cameraDataP->pos.y,
        cameraDataP->pos.z
    );
    glRotatef(
        cameraDataP->angle,
        cameraDataP->rotation.x,
        cameraDataP->rotation.y,
        cameraDataP->rotation.z
    );

    glBegin(GL_QUADS);                
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f( 1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f,  1.0f);
        glVertex3f( 1.0f, 1.0f,  1.0f);

        glColor3f(1.0f, 0.5f, 0.0f);     // Orange
        glVertex3f( 1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);

        glColor3f(1.0f, 0.0f, 0.0f);     // Red
        glVertex3f( 1.0f,  1.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f( 1.0f, -1.0f, 1.0f);

        glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f( 1.0f,  1.0f, -1.0f);

        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);

        glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
        glVertex3f(1.0f,  1.0f, -1.0f);
        glVertex3f(1.0f,  1.0f,  1.0f);
        glVertex3f(1.0f, -1.0f,  1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();

    glutSwapBuffers();
}

void
BlitDisplay(int deltaTime)
{
    cameraDataP->rotation.x = 1;
    cameraDataP->rotation.y = 0.5;
    cameraDataP->rotation.z = 0.25;
    cameraDataP->angle += 0.0003f;

    if(cameraDataP->angle >= 360)
    {
        cameraDataP->angle = 0.0f;
    }

    std::string title;
    title.append("x:");
    title.append(std::to_string(cameraDataP->angle * cameraDataP->rotation.x));
    title.append("y:");
    title.append(std::to_string(cameraDataP->angle * cameraDataP->rotation.y));
    title.append("z:");
    title.append(std::to_string(cameraDataP->angle * cameraDataP->rotation.z));
    title.append("         \r");
    std::cout << title;

    glutPostRedisplay();
    glutTimerFunc(deltaTime, BlitDisplay, 0);
}

void 
ReshapeDisplay(int newWidth, int newHeight)
{
    if (newHeight == 0) newHeight = 1;
    float aspect = (float)newWidth / (float)newHeight;

    glViewport(0, 0, newWidth, newHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    
    glutPostRedisplay();
}