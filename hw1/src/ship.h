#ifndef __SHIP_H
#define __SHIP_H

//------------------------------------------------------------------------------
// ship.h - �������� �������� �������
//------------------------------------------------------------------------------

#include <stdio.h>

typedef struct _Ship
{
    // ��������
    int speed;
    // ���������� ����� �������� ���������� � ����������
    float distance;

    // �������������
    int displacement;
    // ��� �����
    enum
    {
        Liner, // ������
        Tow, // ������
        Tanker, // ������
    } vesselType;
} Ship;

// ���� ������� �� �����
void ShipIn(Ship* this, FILE* file);

// ��������� ���� �������
void ShipInRnd(Ship* this, FILE* file);

// ����� ������� � ����
void ShipOut(Ship* this, FILE* file);

// ��������� ����� ����������� ����
float ShipIdealTime(Ship* this);

#endif
