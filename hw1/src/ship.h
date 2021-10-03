#ifndef __SHIP_H
#define __SHIP_H

//------------------------------------------------------------------------------
// ship.h - содержит описание корабля
//------------------------------------------------------------------------------

#include <stdio.h>

typedef struct _Ship
{
    // скорость
    int speed;
    // расстояние между пунктами оправления и назначения
    float distance;

    // водоизмещение
    int displacement;
    // тип судна
    enum
    {
        Liner, // лайнер
        Tow, // буксир
        Tanker, // танкер
    } vesselType;
} Ship;

// Ввод корабля из файла
void ShipIn(Ship* this, FILE* file);

// Случайный ввод корабля
void ShipInRnd(Ship* this, FILE* file);

// Вывод корабля в файл
void ShipOut(Ship* this, FILE* file);

// Идеальное время прохождения пути
float ShipIdealTime(Ship* this);

#endif
