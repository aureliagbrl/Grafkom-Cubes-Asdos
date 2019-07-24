#include <iostream>
#include <GL/glut.h>

#include "control.hpp"

MouseData * mouseDataP;

void InitControl(MouseData * initMouseData)
{
    mouseDataP = initMouseData;
}

void
MouseButtonEventHandler(int buttonNumber, int state, int posX, int posY)
{
    mouseDataP->buttonNumber = buttonNumber;
    mouseDataP->isPressed = true ? state == 0 : false;
    mouseDataP->mousePos.x = posX - 400;
    mouseDataP->mousePos.y = posY - 400;
}

void
MouseDragEventHandler(int posX, int posY)
{
    mouseDataP->mousePos.x = posX - 400;
    mouseDataP->mousePos.y = posY - 400;
}

void
MouseMoveEventHandler(int posX, int posY)
{
    mouseDataP->mousePos.x = posX - 400;
    mouseDataP->mousePos.y = posY - 400;
}