#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


void in(double a[], int n)
{
    std::ifstream inputFile("Input.csv");
    double col1 = 0;
    double col2 = 0;
    for (int i = 0; i < n; i++)
    {
        inputFile >> col1 >> col2;
        a[i] = col2;
    }
}

void amperage(double a[], int n, double r)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 1000 * (a[i] / r);
    }
}

void out(double a[], int n, double r)
{
    std::ofstream outputFile("Output.csv");
    amperage(a, n, r);
    double tmp = 0;

    for (int i = 0; i < n; i++)
    {
        int exponent = static_cast<int>(std::floor(std::log10(std::abs(a[i]))));
        double scale = std::pow(10, 1 - exponent);
        tmp = round(a[i] * scale) / scale;
        outputFile << tmp << " " << std::setprecision(2) << log(tmp) << std::endl;
    }

}

int main()
{
    double r = 12;
    int n = 16;
    double a[16];
    in(a, n);
    out(a, n, r);

    return EXIT_SUCCESS;
}