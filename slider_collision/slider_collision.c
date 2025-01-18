//
// Created by Admin on 2025/1/17.
//
#include <stdbool.h>
#include <stdio.h>
#include "slider_collision.h"
#include "../utils.h"
#include "../queue.h"

#define SIMULATION_TIME 100
#define SPIT_FRE 10.0
#define SPIT_MASS 1
#define OBJECT_MASS 100
#define SPIT_VELOCITY 10
#define OBJECT_VELOCITY 0
#define DISTANCE 10



int main()
{
    double current_time;
    Queue queue;
    init_queue(&queue);
    Slider box = {OBJECT_MASS, OBJECT_VELOCITY, DISTANCE};
    const double dt = DT;
    int count=0;

    for (int i = 0; i < (int)SIMULATION_TIME/DT; i++)
    {
        current_time = i * DT;
        if (mod(current_time, 1/SPIT_FRE) == 0)
        {
            Slider * bullet = spit();
            add_item(&queue, bullet);
        }
        Slider * front_slider = (Slider*)queue.front->item;
        if(is_collision(front_slider, &box))
        {
            pop_item(&queue, (void **)&front_slider);
            collision(&box, front_slider);
            printf("after %d times of collision, the velocity of the box is %lf now",count, box.velocity);
        }
        traverse_queue(&queue, move, (void *)&dt);

    }

}


void  collision(Slider *slider1, Slider *slider2)
{
    slider2->velocity = ((slider2->mass-slider1->mass)*slider2->velocity + 2*slider1->mass*slider1->velocity) / (slider1->mass+slider2->mass);
    slider1->velocity = ((slider1->mass-slider2->mass)*slider1->velocity + 2*slider2->mass*slider2->velocity)/ (slider1->mass+slider2->mass);
}


void move(void * slider, void * dt)
{
    ((Slider *) slider)->x += *((double*) dt) * ((Slider *) slider)->velocity;
}

Slider *spit()
{
    Slider *slider = malloc(sizeof(Slider));
    slider->mass = SPIT_MASS;
    slider->velocity = SPIT_VELOCITY;
    slider->x = 0;
    return slider;
}


bool is_collision(Slider *slider1, Slider *slider2)
{
    if(slider1->x >= slider2->x)
        return true;
    else
        return false;
}

