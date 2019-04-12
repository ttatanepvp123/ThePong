# The Pong

old pong project.

I have been on Linux since recently, so I will make it compatible ^^

## compilation instructions

**Windows**

``gcc *.c -o bin/Prog -I include -L lib -lSDL2_image.dll -lSDL2main -lSDL2.dll -lSDL2_image.dll -lSDL2_image -lSDL2_mixer.dll -lSDL2_mixer -lSDL2_ttf.dll -lSDL2_ttf -lws2_32``

Note : if you use mingw do not forget to put ``-lmingw32``

**Linux (Ubuntu)**

SDL2 installation

``sudo apt install libsdl2-dev libsdl2-mixer-dev``

compilation

``gcc *.c -o bin/Prog $(sdl2-config --cflags --libs) -lSDL2_mixer``