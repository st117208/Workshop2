#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


void in(float a[], int n)
{
    std::ifstream in("Input.csv");
    float col = 0;
    for (int i = 0; i < n; i++)
    {
        in >> col;
        a[i] = col;
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

void amperage(float a[], int n, float r)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 1000 * (a[i] / r);
    }
}

void out(float a[], int n, float r)
{
    std::ofstream out("Output.csv");
    amperage(a, n, r);

    for (int i = 0; i < n; i++)
    {
        float col = roundx(a[i], 1);
        out << col << " " << std::setprecision(2) << log(col) << std::endl;
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