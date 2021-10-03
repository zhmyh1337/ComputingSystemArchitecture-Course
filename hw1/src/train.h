#ifndef __TRAIN_H
#define __TRAIN_H

//------------------------------------------------------------------------------
// plain.h - �������� �������� ������
//------------------------------------------------------------------------------

#include <stdio.h>

typedef struct _Train
{
    // ��������
    int speed;
    // ���������� ����� �������� ���������� � ����������
    float distance;

    // ���������� �������
    int carsCount;
} Train;

// ���� ������ �� �����
void TrainIn(Train* this, FILE* file);

// ��������� ���� ������
void TrainInRnd(Train* this, FILE* file);

// ����� ������ � ����
void TrainOut(Train* this, FILE* file);

// ��������� ����� ����������� ����
float TrainIdealTime(Train* this);

#endif
