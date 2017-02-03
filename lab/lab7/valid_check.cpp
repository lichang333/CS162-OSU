#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>

#include "valid_check.hpp"

int valid_check::is_valid_int()
{
    int input_value = 0;

    while (!(std::cin >> input_value))
    {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input_value;
}


int valid_check::is_valid_int_in_range(const int low, const int high)
{
    int input_value;
    bool done = false;
    do
    {
        input_value = valid_check::is_valid_int();

        if (input_value < low || input_value > high)
            std::cout << "valid value " << low << " - " << high << ".\n";
        else
            done = true;
    }
    while (!done);

    return input_value;
}


double valid_check::is_valid_double()
{
    double input_value = 0.0;

    while (!(std::cin >> input_value))
    {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input_value;
}


double valid_check::is_valid_double_in_range(
        const double low, const double high)
{
    double input_value;
    bool done = false;
    do
    {
        input_value = valid_check::is_valid_double();

        if (input_value < low || input_value > high)
            std::cout << "valid value " << low << " - " << high << ".\n";
        else
            done = true;
    }
    while (!done);
    return input_value;
}

std::ifstream& valid_check::open_in_file(std::ifstream& fs, std::string fn)
{
    fs.open(fn.c_str());
    if (fs.fail())
    {
        std::cerr << "unable open file: \'" << fn << "\'.\n";
        exit(1);
    }
    return fs;
}

std::ofstream& valid_check::open_out_file(std::ofstream& fs, std::string fn)
{
    fs.open(fn.c_str());

    if (fs.fail())
    {
        std::cerr << "unable open file: \'" << fn << "\'.\n";
        exit(1);
    }

    return fs;
}

