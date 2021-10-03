#ifndef __TRANSPORT_H
#define __TRANSPORT_H

//------------------------------------------------------------------------------
// transport.h - �������� �������� ����������� ����������
//------------------------------------------------------------------------------

#include <stdio.h>
#include "plane.h"
#include "train.h"
#include "ship.h"

// ���������� ���������
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

// ���� ����������� ����������
void TransportIn(Transport* this, FILE* file);

// ��������� ���� ����������� ����������
void TransportInRnd(Transport* this, FILE* file);

// ����� ����������� ����������
void TransportOut(Transport* this, FILE* file);

// ��������� ����� ����������� ����
float TransportIdealTime(Transport* this);

#endif
