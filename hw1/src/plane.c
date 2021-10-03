#include <stdlib.h>
#include "plane.h"
#include "input_helper.h"

void PlaneIn(Plane* this, FILE* file)
{
    if (fscanf(file, "%d %f %d %d", &this->speed, &this->distance, &this->maxDistance, &this->carryingCapacity) != 4)
    {
        InvalidInput();
    }
}

void PlaneInRnd(Plane* this, FILE* file)
{
    this->speed = rand() % 1000;
    this->distance = (float)(rand() % 5000);

    this->maxDistance = rand() % 30000;
    this->carryingCapacity = rand() % 1000;
}

void PlaneOut(Plane* this, FILE* file)
{
    fprintf(file, "Plane: speed = %d, distance = %f, max distance = %d, carrying capacity = %d, ideal time = %f\n",
        this->speed, this->distance, this->maxDistance, this->carryingCapacity, PlaneIdealTime(this));
}

float PlaneIdealTime(Plane* this)
{
    return this->distance / this->speed;
}
