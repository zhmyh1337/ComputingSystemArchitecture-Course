#include "plane.h"

Plane::Plane(int speed, float distance, int maxDistance, int carryingCapacity)
    : BaseTransport(speed, distance), m_maxDistance(maxDistance), m_carryingCapacity(carryingCapacity)
{
}

void Plane::Out(std::ostream& out)
{
    BaseTransport::Out(out);
    out << ", max distance = " << m_maxDistance << ", carrying capacity = " << m_carryingCapacity << std::endl;
}

std::string_view Plane::GetName()
{
    return "Plane";
}
