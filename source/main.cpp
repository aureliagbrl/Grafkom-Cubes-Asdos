#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>

#include "texture.hpp"
#include "common.hpp"
#include "control.hpp"
#include "render.hpp"

MouseData mouseData;
CameraData cameraData;
CubeTextureData cubeTextureData;

void
InitGame()
{
    std::cerr << "Initializating Game..." << std::endl;
    std::cerr << "    Setting Mouse State..." << std::endl;
    // Mouse Init
    mouseData.buttonNumber = 0;
    mouseData.isPressed = false;
    mouseData.mousePos.x = 0;
    mouseData.mousePos.y = 0;

    std::cerr << "    Setting Camera Position..." << std::endl;
    // Camera Init
    cameraData.pos.x = 0;
    cameraData.pos.y = 0;
    cameraData.pos.z = -7;

    cameraData.rotation.x = 0;
    cameraData.rotation.y = 0;
    cameraData.rotation.z = 0;
    cameraData.angle = 0;

    std::cerr << "    Loading Texture..." << std::endl;
    // Cube Texture Load;
    cubeTextureData.face1 = LoadTexture("../Data/1.bmp", 1024, 1024);
    cubeTextureData.face2 = LoadTexture("../Data/2.bmp", 1024, 1024);
    cubeTextureData.face3 = LoadTexture("../Data/3.bmp", 1024, 1024);
    cubeTextureData.face4 = LoadTexture("../Data/4.bmp", 1024, 1024);
    cubeTextureData.face5 = LoadTexture("../Data/5.bmp", 1024, 1024);
    cubeTextureData.face6 = LoadTexture("../Data/6.bmp", 1024, 1024);

    InitRender(&cameraData, &cubeTextureData, &mouseData);
    InitControl(&mouseData);
    std::cerr << "Initalization Done !" << std::endl << std::endl << std::endl;
}

int
main(int argc, char** argv) {
    std::cerr << "Program Load, Begin Glut Initialization" << std::endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(2450, 100);
    glutCreateWindow("Koeboes");

    InitGame();    

    glutDisplayFunc(RenderDisplay);
    glutReshapeFunc(ReshapeDisplay);
    glutMouseFunc(MouseButtonEventHandler);
    glutMotionFunc(MouseDragEventHandler);
    glutPassiveMotionFunc(MouseMoveEventHandler);

    glutTimerFunc(16, BlitDisplay, 0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClearDepth(1.0f);

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);   
    glDepthFunc(GL_LEQUAL);    
    glShadeModel(GL_SMOOTH);   
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  

    glLoadIdentity();

    glutMainLoop();

    return 0;
}