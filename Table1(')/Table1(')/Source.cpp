#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


void in(float a[], int n)
{
    std::ifstream inputFile("Input.csv");
    float col1 = 0;
    float col2 = 0;
    for (int i = 0; i < n; i++)
    {
        inputFile >> col1 >> col2;
        a[i] = col2;
    }
}

void amperage(float a[], int n, float r)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 1000 * (a[i] / r);
    }
}

void out(float a[], int n, float r)
{
    std::ofstream outputFile("Output.csv");
    amperage(a, n, r);
    float val = 0;
    float tmp = 0;

    for (int i = 0; i < n; i++)
    {
        int exp = static_cast<int>(std::floor(std::log10(std::abs(a[i]))));
        val = std::pow(10, 1 - exp);
        tmp = round(a[i] * val) / val;
        outputFile << tmp << " " << std::setprecision(2) << log(tmp) << std::endl;
    }

}

int main()
{
    float r = 12;
    int n = 16;
    float a[16];
    in(a, n);
    out(a, n, r);

    return EXIT_SUCCESS;
}