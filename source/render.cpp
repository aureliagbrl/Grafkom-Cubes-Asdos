#include <iostream>
#include <GL/glut.h>

#include "common.hpp"
#include "render.hpp"

CameraData * cameraDataP;
CubeTextureData * cubeTextureDataP;

void
InitRender(CameraData * initCameraData, CubeTextureData * initCubeTextureData)
{
    cameraDataP = initCameraData;
    cubeTextureDataP = initCubeTextureData;
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

void
BlitDisplay(int)
{
    cameraDataP->rotation.x = 1;
    cameraDataP->rotation.y = 0.5;
    cameraDataP->rotation.z = 0.25;
    cameraDataP->angle += 1.0f;

    if(cameraDataP->angle >= 360)
    {
        cameraDataP->angle = 0.0f;
    }

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

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    
    glutPostRedisplay();
}