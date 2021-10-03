#ifndef __TRAIN_H
#define __TRAIN_H

//------------------------------------------------------------------------------
// plain.h - содержит описание поезда
//------------------------------------------------------------------------------

#include <stdio.h>

typedef struct _Train
{
    // скорость
    int speed;
    // расстояние между пунктами оправления и назначения
    float distance;

    // количество вагонов
    int carsCount;
} Train;

// Ввод поезда из файла
void TrainIn(Train* this, FILE* file);

// Случайный ввод поезда
void TrainInRnd(Train* this, FILE* file);

// Вывод поезда в файл
void TrainOut(Train* this, FILE* file);

// Идеальное время прохождения пути
float TrainIdealTime(Train* this);

#endif
