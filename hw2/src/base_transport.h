#pragma once

//------------------------------------------------------------------------------
// transport.h - содержит описание обобщенного транспорта
//------------------------------------------------------------------------------

#include <iostream>
#include <string_view>
#include "random.h"

// Обобщенный транспорт
class BaseTransport
{
public:
    // Создание транспорта
    static BaseTransport* Create(std::istream& in);

    // Создание транспорта (случайно)
    static BaseTransport* CreateRnd(std::istream& in, Random& rng);

    // Идеальное время прохождения пути
    float GetIdealTime();

    // Вывод транспорта
    virtual void Out(std::ostream& out);

    // Название транспорта
    virtual std::string_view GetName() = 0;

protected:
    BaseTransport(int speed, float distance);

private:
    // скорость
    int m_speed;
    // расстояние между пунктами оправления и назначения
    float m_distance;
};
