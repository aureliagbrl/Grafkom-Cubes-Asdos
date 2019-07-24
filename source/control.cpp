#include <iostream>
#include <GL/glut.h>

#include "control.hpp"

MouseData * mouseDataP;
int num;

void InitControl(MouseData * initMouseData)
{
    mouseDataP = initMouseData;
}

void
MouseButtonEventHandler(int buttonNumber, int state, int posX, int posY)
{
    mouseDataP->buttonNumber = buttonNumber;
    mouseDataP->isPressed = true ? state == 1 : false;
    mouseDataP->mousePos.x = posX;
    mouseDataP->mousePos.y = posY;
}

void
MouseDragEventHandler(int posX, int posY)
{
    mouseDataP->mousePos.x = posX;
    mouseDataP->mousePos.y = posY;

    std::cout << "(" << mouseDataP->mousePos.x << " " << mouseDataP->mousePos.y << ")" << "            \r"; fflush(stdout);
}

void
MouseMoveEventHandler(int posX, int posY)
{
    mouseDataP->mousePos.x = posX;
    mouseDataP->mousePos.y = posY;
}