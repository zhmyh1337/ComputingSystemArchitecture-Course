#include <stdlib.h>
#include "train.h"
#include "input_helper.h"

void TrainIn(Train* this, FILE* file)
{
    if (fscanf(file, "%d %f %d", &this->speed, &this->distance, &this->carsCount) != 3)
    {
        InvalidInput();
    }
}

void TrainInRnd(Train* this, FILE* file)
{
    this->speed = rand() % 1000;
    this->distance = (float)(rand() % 5000);

    this->carsCount = rand() % 40;
}

void TrainOut(Train* this, FILE* file)
{
    fprintf(file, "Train: speed = %d, distance = %f, cars count = %d, ideal time = %f\n",
        this->speed, this->distance, this->carsCount, TrainIdealTime(this));
}

float TrainIdealTime(Train* this)
{
    return this->distance / this->speed;
}
