#include "random.h"

Random::Random(int seed)
    : m_rng(seed)
{
}

int Random::Next(int from, int to)
{
    std::uniform_int_distribution<int> uni(from, to - 1);
    return uni(m_rng);
}

int Random::Next(int to)
{
    return Next(0, to);
}

float Random::NextFloat(float from, float to)
{
    std::uniform_real_distribution<float> uni(from, to);
    return uni(m_rng);
}

float Random::NextFloat(float to)
{
    return NextFloat(0.0f, to);
}

float Random::NextFloat()
{
    return NextFloat(0.0f, 1.0f);
}
