#ifndef COMMON_HPP
#define COMMON_HPP

template <typename T>
struct vec2_t{
    T x, y;
};

typedef vec2_t<int> MousePos;

struct MouseData{
    MousePos mousePos;
    bool isPressed;
    int buttonNumber;
};

#endif