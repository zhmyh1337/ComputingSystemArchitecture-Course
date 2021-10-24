#include "train.h"

Train::Train(int speed, float distance, int carsCount)
    : BaseTransport(speed, distance), m_carsCount(carsCount)
{
}

void Train::Out(std::ostream& out)
{
    BaseTransport::Out(out);
    out << ", cars count = " << m_carsCount << std::endl;
}

std::string_view Train::GetName()
{
    return "Train";
}
