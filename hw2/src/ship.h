#pragma once

//------------------------------------------------------------------------------
// ship.h - содержит описание корабля
//------------------------------------------------------------------------------

#include <iostream>
#include "base_transport.h"

// Корабль
class Ship : public BaseTransport
{
public:
    // тип судна
    enum class VesselType
    {
        Liner, // лайнер
        Tow, // буксир
        Tanker, // танкер

        MaxIndex, // последний индекс
    };

public:
    // Инициализация корабля
    Ship(int speed, float distance, int displacement, VesselType vesselType);

    void Out(std::ostream& out) override;

    std::string_view GetName() override;

private:
    // водоизмещение
    int m_displacement;
    VesselType m_vesselType;
};
