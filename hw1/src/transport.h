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

// ���� ����������� ����������
void In(Transport* this, FILE* file);

// ��������� ���� ����������� ����������
void InRnd(Transport* this, FILE* file);

// ����� ����������� ����������
void Out(Transport* this, FILE* file);

// ��������� ����� ����������� ����
float IdealTime(Transport* this);

#endif
