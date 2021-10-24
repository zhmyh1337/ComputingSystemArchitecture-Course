#include <string_view>
#include "ship.h"

Ship::Ship(int speed, float distance, int displacement, VesselType vesselType)
    : BaseTransport(speed, distance), m_displacement(displacement), m_vesselType(vesselType)
{
}

void Ship::Out(std::ostream& out)
{
    std::string_view vesselTypeStr;
    switch (m_vesselType)
    {
    case VesselType::Liner:
        vesselTypeStr = "liner";
        break;
    case VesselType::Tow:
        vesselTypeStr = "tow";
        break;
    case VesselType::Tanker:
        vesselTypeStr = "tanker";
        break;
    }

    out << "displacement = " << m_displacement << ", vessel type = " << vesselTypeStr << std::endl;
}

std::string_view Ship::GetName()
{
    return "Ship";
}
