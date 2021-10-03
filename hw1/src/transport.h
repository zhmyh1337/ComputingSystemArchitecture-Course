#ifndef __TRANSPORT_H
#define __TRANSPORT_H

#include <stdio.h>
#include "plane.h"

typedef struct _Transport
{
    enum
    {
        PlaneType,
        TrainType,
        ShipType,
    } type;

    union
    {
        Plane plane;
    };
} Transport;

// Ввод обобщенного транспорта
void In(Transport* this, FILE* file);

// Случайный ввод обобщенного транспорта
void InRnd(Transport* this, FILE* file);

// Вывод обобщенного транспорта
void Out(Transport* this, FILE* file);

// Идеальное время прохождения пути
float IdealTime(Transport* this);

#endif
