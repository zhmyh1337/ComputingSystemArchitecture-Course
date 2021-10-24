#include <iostream>
#include "container.h"
#include "input_helper.h"
#include "random.h"

Container::Container()
    : m_len(0), m_data{}
{
}

Container::~Container()
{
    for (size_t i = 0; i < m_len; i++)
    {
        delete m_data[i];
    }
}

void Container::In(std::istream& in)
{
    // проверка на пустой файл
    if (in.peek() == std::istream::traits_type::eof())
    {
        return;
    }

    while (!in.eof())
    {
        m_data[m_len++] = BaseTransport::Create(in);
    }
}

void Container::InRnd(std::istream& in)
{
    size_t count;
    int seed;
    if (!(std::cin >> count >> seed))
    {
        InputHelper::InvalidInput();
    }

    if (count < 0 || count > k_maxLength)
    {
        InputHelper::InvalidInput();
    }

    m_len = count;
    Random rng(seed);
    for (size_t i = 0; i < count; i++)
    {
        m_data[i] = BaseTransport::CreateRnd(in, rng);
    }
}

void Container::Out(std::ostream& out)
{
    for (size_t i = 0; i < m_len; i++)
    {
        m_data[i]->Out(out);
    }
}

void Container::Sort()
{
    BaseTransport* key;
    ptrdiff_t i, j;
    for (i = 1; i < static_cast<ptrdiff_t>(m_len); i++)
    {
        key = m_data[i];
        j = i - 1;

        while (j >= 0 && m_data[j]->GetIdealTime() > key->GetIdealTime())
        {
            m_data[j + 1] = m_data[j];
            j = j - 1;
        }

        m_data[j + 1] = key;
    }
}
