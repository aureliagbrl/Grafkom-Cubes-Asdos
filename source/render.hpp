#ifndef RENDER_HPP
#define RENDER_HPP

#include "common.hpp"

void InitRender(CameraData *, CubeTextureData *, MouseData *);
void RenderDisplay();
void BlitDisplay(int);
void ReshapeDisplay(int, int);

#endif