#include <iostream>
#include <GL/glut.h>

#include "common.hpp"
#include "render.hpp"
#include "math.h"

CameraData * cameraDataP;
MouseData * mouseDataP2;
CubeTextureData * cubeTextureDataP;

void
InitRender(CameraData * initCameraData, CubeTextureData * initCubeTextureData, MouseData * initMouseData)
{
    cameraDataP = initCameraData;
    cubeTextureDataP = initCubeTextureData;
    mouseDataP2 = initMouseData;
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

    
    glBindTexture(GL_TEXTURE_2D, cubeTextureDataP->face1);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f,  1.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, cubeTextureDataP->face2);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, cubeTextureDataP->face3);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f,  1.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, cubeTextureDataP->face4);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, cubeTextureDataP->face5);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, cubeTextureDataP->face6);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();

    glutSwapBuffers();
}

MousePos lastPressedMousePos;
MousePos lastMousePos;
float lastMouseAngle = 0.0f;

void
BlitDisplay(int)
{
    if(mouseDataP2->isPressed){
        cameraDataP->rotation.x = (mouseDataP2->mousePos.y - lastMousePos.y );
        cameraDataP->rotation.y = (mouseDataP2->mousePos.x - lastMousePos.y );
        lastPressedMousePos.x = cameraDataP->rotation.x;
        lastPressedMousePos.y = cameraDataP->rotation.y;
        lastMouseAngle = (mouseDataP2->mousePos.x + mouseDataP2->mousePos.y)/2;
    } else {
        lastMousePos.x = mouseDataP2->mousePos.x;
        lastMousePos.y = mouseDataP2->mousePos.y;
    }

    cameraDataP->angle = lastMouseAngle;
    std::cout << "a:" << cameraDataP->angle << " ";
    std::cout << "x:" << cameraDataP->rotation.x << " ";
    std::cout << "y:" << cameraDataP->rotation.y << " ";
    std::cout << "lpx:" << lastPressedMousePos.x << " ";
    std::cout << "lpy:" << lastPressedMousePos.y << " ";
    std::cout << "lmx:" << lastMousePos.x << " ";
    std::cout << "lmy:" << lastMousePos.y << " ";
    std::cout << "                             \r";
    fflush(stdout);

    glutPostRedisplay();
    glutTimerFunc(16, BlitDisplay, 0);
}

void 
ReshapeDisplay(int newWidth, int newHeight)
{
    if (newHeight == 0) newHeight = 1;
    float aspect = (float)newWidth / (float)newHeight;

    glViewport(0, 0, newWidth, newHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 1.0f, 12.0f);
    
    glutPostRedisplay();
}