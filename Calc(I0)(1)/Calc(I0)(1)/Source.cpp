#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

void in(float a[], float b[], double n)
{
    std::ifstream in("Input.csv");
    float col1 = 0;
    float col2 = 0;

    for (int i = 0; i < n; i++)
    {
        in >> col1 >> col2;
        a[i] = col1;
        b[i] = col2;
    }
}

float roundx(float m, int n)
{
    if (m == 0)
    {
        return 0;
    }
    int exp = static_cast<int>(std::floor(std::log10(std::abs(m))));
    float val = std::pow(10, n - exp);
    float tmp = round(m * val) / val;
    return tmp;
}

float lni(float a[], float b[], float tga, double n)
{
    float sum1 = 0;
    float sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 + a[i];
        sum2 = sum2 + b[i];
    }

    float tmp1 = roundx((sum1 / n), 1);
    float tmp2 = roundx((sum2 / n), 1);

    return tmp2 - tga * tmp1;
}

void out(float a[], float b[], float tga, double n)
{
    float ln = roundx(lni(a, b, tga, n), 1);
    std::ofstream out("Output.csv");
    out << std::setprecision(2) << ln << " " << std::setprecision(2) << exp(ln);
}
int main()
{
    float a[16];
    float b[16];
    float tga = 32.5;
    double n = 16;

    in(a, b, n);
    out(a, b, tga, n);

    return EXIT_SUCCESS;
}