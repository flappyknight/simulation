#include <stdlib.h>

#define DT 0.1

typedef struct {
    double mass;
    double velocity;
    double x;
}

Slider
;

void collision(Slider *slider1, Slider *slider2);

void move(void * slider, void * dt);

Slider *spit();

bool is_collision(Slider *slider1, Slider *slider2);

