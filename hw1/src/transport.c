#include <string.h>
#include <stdlib.h>
#include "transport.h"
#include "input_helper.h"

void TransportIn(Transport* this, FILE* file)
{
    char buf[100] = { 0 };
    if (fscanf(file, "%s", buf) != 1)
    {
        InvalidInput();
    }

    if (!strcmp(buf, "plane"))
    {
        this->type = PlaneType;
        PlaneIn(&this->plane, file);
    }
    else if (!strcmp(buf, "train"))
    {
        this->type = TrainType;
        TrainIn(&this->train, file);
    }
    else if (!strcmp(buf, "ship"))
    {
        this->type = ShipType;
        ShipIn(&this->ship, file);
    }
    else
    {
        InvalidInput();
    }
}

void TransportInRnd(Transport* this, FILE* file)
{
    switch (rand() % 3)
    {
    case 0:
        this->type = PlaneType;
        PlaneInRnd(&this->plane, file);
        break;
    case 1:
        this->type = TrainType;
        TrainInRnd(&this->train, file);
        break;
    case 2:
        this->type = ShipType;
        ShipInRnd(&this->ship, file);
        break;
    }
}

void TransportOut(Transport* this, FILE* file)
{
    switch (this->type)
    {
    case PlaneType:
        PlaneOut(&this->plane, file);
    case TrainType:
        TrainOut(&this->train, file);
    case ShipType:
        ShipOut(&this->ship, file);
    }
}

float TransportIdealTime(Transport* this)
{
    switch (this->type)
    {
    case PlaneType:
        return PlaneIdealTime(&this->plane);
    case TrainType:
        return TrainIdealTime(&this->train);
    case ShipType:
        return ShipIdealTime(&this->ship);
    default:
        return 0;
    }
}
