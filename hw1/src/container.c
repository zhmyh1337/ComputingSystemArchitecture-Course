#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include "input_helper.h"
#include "container.h"

void ContainerInit(Container* this)
{
    this->len = 0;
}

void ContainerIn(Container* this, FILE* file)
{
    // проверка на пустой файл
    fseek(file, 0, SEEK_END);
    if (!ftell(file))
    {
        return;
    }

    rewind(file);
    while (!feof(file))
    {
        TransportIn(&this->data[this->len++], file);
    }
}

void ContainerInRnd(Container* this, FILE* file)
{
    int count, seed;
    if (fscanf(file, "%d %d", &count, &seed) != 2)
    {
        InvalidInput();
    }

    if (count < 0 || count > MAX_CONTAINER_LENGTH)
    {
        InvalidInput();
    }

    srand(seed);
    this->len = count;
    for (int i = 0; i < count; i++)
    {
        TransportInRnd(&this->data[i], file);
    }
}

void ContainerOut(Container* this, FILE* file)
{
    for (int i = 0; i < this->len; i++)
    {
        TransportOut(&this->data[i], file);
    }
}

void ContainerSort(Container* this)
{
    Transport key;
    int i, j;
    for (i = 1; i < this->len; i++)
    {
        key = this->data[i];
        j = i - 1;

        while (j >= 0 && TransportIdealTime(&this->data[j]) > TransportIdealTime(&key))
        {
            this->data[j + 1] = this->data[j];
            j = j - 1;
        }

        this->data[j + 1] = key;
    }
}
