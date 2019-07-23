#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>

#include "common.hpp"
#include "control.hpp"
#include "render.hpp"

MouseData mouseData;

void
InitGame()
{
    mouseData.buttonNumber = 0;
    mouseData.isPressed = false;
    mouseData.mousePos.x = 0;
    mouseData.mousePos.y = 0;

    InitControl(&mouseData);
}

int
main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
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
    
    glEnable(GL_DEPTH_TEST);   
    glDepthFunc(GL_LEQUAL);    
    glShadeModel(GL_SMOOTH);   
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  

    glutMainLoop();

    return 0;
}