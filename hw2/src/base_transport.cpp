#include <string>
#include "base_transport.h"
#include "input_helper.h"
#include "plane.h"
#include "train.h"
#include "ship.h"

BaseTransport::BaseTransport(int speed, float distance)
    : m_speed(speed), m_distance(distance)
{
}

BaseTransport* BaseTransport::Create(std::istream& in)
{
    std::string type;
    if (!(in >> type))
    {
        InputHelper::InvalidInput();
    }

    int speed;
    float distance;
    if (!(in >> speed >> distance))
    {
        InputHelper::InvalidInput();
    }

    if (type == "plane")
    {
        int maxDistance;
        int carryingCapacity;
        if (!(in >> maxDistance >> carryingCapacity))
        {
            InputHelper::InvalidInput();
        }

        return new Plane(speed, distance, maxDistance, carryingCapacity);
    }
    else if (type == "train")
    {
        int carsCount;
        if (!(in >> carsCount))
        {
            InputHelper::InvalidInput();
        }

        return new Train(speed, distance, carsCount);
    }
    else if (type == "ship")
    {
        int displacement;
        std::string vesselTypeStr;
        if (!(in >> displacement >> vesselTypeStr))
        {
            InputHelper::InvalidInput();
        }

        Ship::VesselType vesselType;
        if (vesselTypeStr == "liner")
        {
            vesselType = Ship::VesselType::Liner;
        }
        else if (vesselTypeStr == "tow")
        {
            vesselType = Ship::VesselType::Tow;
        }
        else if (vesselTypeStr == "tanker")
        {
            vesselType = Ship::VesselType::Tanker;
        }
        else
        {
            InputHelper::InvalidInput();
            return nullptr;
        }

        return new Ship(speed, distance, displacement, vesselType);
    }
    else
    {
        InputHelper::InvalidInput();
        return nullptr;
    }
}

BaseTransport* BaseTransport::CreateRnd(std::istream& in, Random& rng)
{
    auto speed = rng.Next(1000);
    auto distance = rng.NextFloat(5000);
    switch (rng.Next(3))
    {
    case 0:
        return new Plane(speed, distance, rng.Next(30000), rng.Next(1000));

    case 1:
        return new Train(speed, distance, rng.Next(40));

    case 2:
        return new Ship(speed, distance, rng.Next(30000), static_cast<Ship::VesselType>(rng.Next(static_cast<int>(Ship::VesselType::MaxIndex))));

    default:
        return nullptr;
    }
}

float BaseTransport::GetIdealTime()
{
    return m_distance / m_speed;
}

void BaseTransport::Out(std::ostream& out)
{
    out << GetName() << ": speed = " << m_speed << ", distance = " << m_distance << ", ideal time = " << GetIdealTime();
}
