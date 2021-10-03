#ifndef __CONTAINER_H
#define __CONTAINER_H

//------------------------------------------------------------------------------
// container.h - содержит тип данных, представляющий простейший контейнер
//------------------------------------------------------------------------------

#include <stdio.h>
#include "transport.h"

#define MAX_CONTAINER_LENGTH 10000

// Простейший контейнер на основе одномерного массива
typedef struct _Container
{
    size_t len; // текущая длина
    Transport data[MAX_CONTAINER_LENGTH];
} Container;

// Инициализация контейнера
void ContainerInit(Container* this);

// Ввод содержимого контейнера
void ContainerIn(Container* this, FILE* file);

// Случайный ввод содержимого контейнера
void ContainerInRnd(Container* this, FILE* file);

// Вывод содержимого контейнера
void ContainerOut(Container* this, FILE* file);

// Сортировка контейнера методом Straight Insertion
void ContainerSort(Container* this);

#endif
