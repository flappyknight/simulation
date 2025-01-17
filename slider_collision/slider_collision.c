//
// Created by Admin on 2025/1/17.
//
#include "slider_collision.h"
#include "../utils.h"

#define SIMULATION_TIME 100
#define SPIT_FRE 10.0
#define SPIT_MASS 1
#define OBJECT_MASS 100
#define SPIT_VELOCITY 10

int main()
{
    double current_time;
    for (int i = 0; i < (int)SIMULATION_TIME/DT; i++)
    {
        current_time = i * DT;
        if (mod(current_time, 1/SPIT_FRE) == 0)
        {
            spit();
        }
    }

}


void  collision(Slider *slider1, Slider *slider2)
{

}


void move(Slider *slider, double dt)
{

}

Slider *spit()
{
    Slider *slider = malloc(sizeof(Slider));
    slider->mass = SPIT_MASS;
    slider->velocity = SPIT_VELOCITY;
    slider->x = 0;
    return slider;
}