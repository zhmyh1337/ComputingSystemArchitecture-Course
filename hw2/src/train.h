#pragma once

//------------------------------------------------------------------------------
// plain.h - содержит описание поезда
//------------------------------------------------------------------------------

#include <iostream>
#include "base_transport.h"

// Поезд
class Train : public BaseTransport
{
public:
    // Инициализация поезда
    Train(int speed, float distance, int carsCount);

    void Out(std::ostream& out) override;

    std::string_view GetName() override;

private:
    // количество вагонов
    int m_carsCount;
};
