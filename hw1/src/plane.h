#ifndef __PLANE_H
#define __PLANE_H

//------------------------------------------------------------------------------
// plain.h - �������� �������� ��������
//------------------------------------------------------------------------------

#include <stdio.h>

typedef struct _Plane
{
    // ��������
    int speed;
    // ���������� ����� �������� ���������� � ����������
    float distance;

    // ��������� ������
    int maxDistance;
    // ����������������
    int carryingCapacity;
} Plane;

// ���� �������� �� �����
void PlaneIn(Plane* this, FILE* file);

// ��������� ���� ��������
void PlaneInRnd(Plane* this, FILE* file);

// ����� �������� � ����
void PlaneOut(Plane* this, FILE* file);

// ��������� ����� ����������� ����
float PlaneIdealTime(Plane* this);

#endif
