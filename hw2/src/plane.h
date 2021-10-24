#pragma once

//------------------------------------------------------------------------------
// plain.h - содержит описание самолета
//------------------------------------------------------------------------------

#include <iostream>
#include "base_transport.h"

// Самолет
class Plane : public BaseTransport
{
public:
    // Инициализация самолета
    Plane(int speed, float distance, int maxDistance, int carryingCapacity);

    void Out(std::ostream& out) override;

    std::string_view GetName() override;

private:
    // дальность полета
    int m_maxDistance;
    // грузоподъемность
    int m_carryingCapacity;
};
