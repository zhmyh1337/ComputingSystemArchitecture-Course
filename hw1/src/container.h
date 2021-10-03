#ifndef __CONTAINER_H
#define __CONTAINER_H

//------------------------------------------------------------------------------
// container.h - �������� ��� ������, �������������� ���������� ���������
//------------------------------------------------------------------------------

#include <stdio.h>
#include "transport.h"

#define MAX_CONTAINER_LENGTH 10000

// ���������� ��������� �� ������ ����������� �������
typedef struct _Container
{
    size_t len; // ������� �����
    Transport data[MAX_CONTAINER_LENGTH];
} Container;

// ������������� ����������
void ContainerInit(Container* this);

// ���� ����������� ����������
void ContainerIn(Container* this, FILE* file);

// ��������� ���� ����������� ����������
void ContainerInRnd(Container* this, FILE* file);

// ����� ����������� ����������
void ContainerOut(Container* this, FILE* file);

// ���������� ����������
void ContainerSort(Container* this);

#endif
