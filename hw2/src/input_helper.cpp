#include <iostream>
#include <cstdlib>
#include "input_helper.h"

void InputHelper::InvalidInput()
{
    std::cout << "Invalid input. The program is terminating...\n";
    std::exit(1);
}
