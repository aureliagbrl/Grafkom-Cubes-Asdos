#ifndef COMMON_HPP
#define COMMON_HPP

template <typename T>
struct vec2_t{
    T x, y;
};

template <typename T>
struct vec3_t{
    T x, y, z;
};

typedef vec2_t<int> MousePos;

struct MouseData{
    MousePos mousePos;
    bool isPressed;
    int buttonNumber;
};

struct CameraData{
    vec3_t<float> pos;
    vec3_t<float> rotation;
    float angle;
};

#endif