#pragma once

//------------------------------------------------------------------------------
// container.h - содержит тип данных, представляющий простейший контейнер
//------------------------------------------------------------------------------

#include <iostream>
#include <array>
#include "base_transport.h"

// Простейший контейнер на основе одномерного массива
class Container
{
public:
    // Инициализация контейнера
    Container();

    // Терминация контейнера
    ~Container();

    // Ввод содержимого контейнера
    void In(std::istream& in);

    // Случайный ввод содержимого контейнера
    void InRnd(std::istream& in);

    // Вывод содержимого контейнера
    void Out(std::ostream& out);

    // Сортировка контейнера методом Straight Insertion
    void Sort();

private:
    static constexpr auto k_maxLength = 10000; // максимальная длина
    size_t m_len; // текущая длина
    std::array<BaseTransport*, k_maxLength> m_data; // содержимое
};
