#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "common.hpp"

void InitControl(MouseData *);
void MouseButtonEventHandler(int, int, int, int);
void MouseDragEventHandler(int, int);
void MouseMoveEventHandler(int, int);

#endif