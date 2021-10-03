#include <stdlib.h>
#include <string.h>
#include "ship.h"
#include "input_helper.h"

void ShipIn(Ship* this, FILE* file)
{
    char buf[100] = { 0 };
    if (fscanf(file, "%d %f %d %s", &this->speed, &this->distance, &this->displacement, buf) != 4)
    {
        InvalidInput();
    }

    if (!strcmp(buf, "liner"))
    {
        this->vesselType = Liner;
    }
    else if (!strcmp(buf, "tow"))
    {
        this->vesselType = Tow;
    }
    else if (!strcmp(buf, "tanker"))
    {
        this->vesselType = Tanker;
    }
    else
    {
        InvalidInput();
    }
}

void ShipInRnd(Ship* this, FILE* file)
{
    this->speed = rand() % 1000;
    this->distance = (float)(rand() % 5000);

    this->displacement = rand() % 30000;
    switch (rand() % 3)
    {
    case 0:
        this->vesselType = Liner;
        break;
    case 1:
        this->vesselType = Tow;
        break;
    case 2:
        this->vesselType = Tanker;
        break;
    }
}

void ShipOut(Ship* this, FILE* file)
{
    const char* vesselTypeStr;
    switch (this->vesselType)
    {
    case Liner:
        vesselTypeStr = "liner";
        break;
    case Tow:
        vesselTypeStr = "tow";
        break;
    case Tanker:
        vesselTypeStr = "tanker";
        break;
    }

    fprintf(file, "Ship: speed = %d, distance = %f, displacement = %d, vessel type = %s, ideal time = %f\n",
        this->speed, this->distance, this->displacement, vesselTypeStr, ShipIdealTime(this));
}

float ShipIdealTime(Ship* this)
{
    return this->distance / this->speed;
}
