#ifndef __TRANSPORT_H
#define __TRANSPORT_H

//------------------------------------------------------------------------------
// transport.h - содержит описание обобщенного транспорта
//------------------------------------------------------------------------------

#include <stdio.h>
#include "plane.h"
#include "train.h"
#include "ship.h"

// Обобщенный транспорт
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
        Train train;
        Ship ship;
    };
} Transport;

// Ввод обобщенного транспорта
void TransportIn(Transport* this, FILE* file);

// Случайный ввод обобщенного транспорта
void TransportInRnd(Transport* this, FILE* file);

// Вывод обобщенного транспорта
void TransportOut(Transport* this, FILE* file);

// Идеальное время прохождения пути
float TransportIdealTime(Transport* this);

#endif
