#include <fstream>
#include <string>

namespace valid_check
{
    double is_valid_double();
    double is_valid_double_in_range(const double low, const double high);
    int is_valid_int();
    int is_valid_int_in_range(const int low, const int high);

    std::ifstream& open_in_file(std::ifstream& fs, std::string fn);
    std::ofstream& open_out_file(std::ofstream& fs, std::string fn);
}
