#include "itools.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

int itools::is_valid_int()
{
    int input_value = 0;

    while (!(std::cin >> input_value))
    {
        std::cout << "Wrong input!  Please input integer.\n";

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input_value;
}


int itools::is_valid_int_range(const int low, const int high)
{
    int input_value;
    bool done = false;
    do
    {
        input_value = itools::is_valid_int();

        if (input_value < low || input_value > high)
            std::cout << "Value should between " << low << " and " <<
                         high << ".\n";
        else
            done = true;
    }
    while (!done);

    return input_value;
}


double itools::is_valid_double()
{
    double input_value = 0.0;

    while (!(std::cin >> input_value))
    {
        std::cout << "Wrong input!  Please input a number.\n";

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input_value;
}


double itools::is_valid_double_range(const double low, const double high)
{
    double input_value;
    bool done = false;
    do
    {
        input_value = itools::is_valid_double();

        if (input_value < low || input_value > high)
            std::cout << "Value should between " << low << " and " <<
                         high << ".\n";
        else
            done = true;
    }
    while (!done);

    return input_value;
}



















