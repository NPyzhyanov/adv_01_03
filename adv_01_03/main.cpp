#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

int main()
{
    const double pi = 3.1415926;
    std::vector<double> angles = {30. * pi / 180., 45. * pi / 180., 60. * pi / 180., 90. * pi / 180.};

    std::function<void(double)> print_sin = [] (double angle) {std::cout << "sin: " << sin(angle) << " ";};
    std::function<void(double)> print_cos = [] (double angle) {std::cout << "cos: " << cos(angle) << " ";};

    auto functions = std::vector<std::function<void(double)>> {print_sin, print_cos};

    std::cout << "[input data]: ";
    std::for_each(angles.begin(), angles.end(), [] (const double &angle) {std::cout << angle << " ";});
    std::cout << std::endl;

    std::cout << "[output data]:" << std::endl;
    for (const auto &angle : angles)
    {
        std::cout << angle << ": ";
        for (const auto &function : functions)
        {
            function(angle);
        }
        std::cout << std::endl;
    }

    return 0;
}
