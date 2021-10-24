#pragma once

#include <random>

class Random
{
public:
    Random(int seed);

    int Next(int from, int to);

    int Next(int to);

    float NextFloat(float from, float to);

    float NextFloat(float to);

    float NextFloat();

private:
    std::mt19937 m_rng;
};
