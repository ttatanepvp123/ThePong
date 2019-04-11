#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct Mouse {
    int MouseX;
    int MouseY;
    int MouseLeftClic;
    int MouseRightClic;
    int MouseWheelUp;
    int MouseWheelDown;
} Mouse;

typedef struct Keyboard {
    int ArrowUp;
    int ArrowDown;
    int Keyz;
    int Keys;
    //debug
    int Keyt;
    int Keyg;
    int Keyh;
    int Keyi;
    int Keyk;
    int Keyl;
} Keyboard;

typedef struct Raquette {
    float x;
    float y;
    float w;
    float h;
    float speed;
    int Score;
    int mode;
} Raquette;

typedef struct Ball {
    float x;
    float y;
    float w;
    float h;
    float dirx;
    float diry;
    float speed;
    int mode;
} Ball;
#endif // STRUCT_H_INCLUDED
 