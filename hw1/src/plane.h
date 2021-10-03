#ifndef __PLANE_H
#define __PLANE_H

//------------------------------------------------------------------------------
// plain.h - содержит описание самолета
//------------------------------------------------------------------------------

#include <stdio.h>

typedef struct _Plane
{
    // скорость
    int speed;
    // расстояние между пунктами оправления и назначения
    float distance;

    // дальность полета
    int maxDistance;
    // грузоподъемность
    int carryingCapacity;
} Plane;

// Ввод самолета из файла
void PlaneIn(Plane* this, FILE* file);

// Случайный ввод самолета
void PlaneInRnd(Plane* this, FILE* file);

// Вывод самолета в файл
void PlaneOut(Plane* this, FILE* file);

// Идеальное время прохождения пути
float PlaneIdealTime(Plane* this);

#endif
