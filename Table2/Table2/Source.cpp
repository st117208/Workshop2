#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


void in(float a[], float b[], double n)
{
    std::ifstream in("Input.csv");

    float x1 = 0;
    float y1 = 0;
    float x2 = 0;
    float y2 = 0;

    for (int i = 0; i < n; i++)
    {
        in >> x2 >> x1 >> y2 >> y1;
        a[i] = x2 - x1;
        b[i] = y2 - y1;
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

void in_round(float a[], float b[], double n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = roundx(a[i], 1);
        b[i] = roundx(b[i], 1);
    }
}

float fx(float c[], double n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + c[i];
    }

    float tmp = roundx(sum / n, 2);
    return tmp;
}

void tgi(float a[], float b[], float c[], double n)
{
    in_round(a, b, n);
    for (int i = 0; i < n; i++)
    {
        c[i] = roundx(b[i] / a[i], 2);
    }
}

float tg_err(float c[], double n, float sum)
{
    float t = 2.4;
    float tg_err = sqrt(sum / (n - 1)) / sqrt(n) * t;

    float tmp = roundx(tg_err, 1);
    return tmp;
}

float ek(float x)
{
    float T = 296.15;
    float tmp = T * x;
    return tmp;
}

float ek_err(float x, float tg_err)
{
    float T = 296.15;
    float T_err = 0.5;
    float tmp = sqrt(pow(x, 2) * pow(T_err / 3, 2) + pow(T, 2) * pow(tg_err, 2));
    return tmp;
}

void out(float a[], float b[], float c[], double n)
{
    std::ofstream out("Output.csv");
    in_round(a, b, n);
    tgi(a, b, c, n);
    float sum1 = 0;
    float sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        float tmp1 = roundx(c[i] - fx(c, n), 1);
        float tmp2 = roundx(pow(tmp1, 2), 3);

        sum1 = sum1 + c[i];
        sum2 = sum2 + tmp2;
        out << a[i] << " " << b[i] << " " << c[i] << " " << tmp1 << " " << tmp2 << std::endl;
    }
    out << "sum = " << sum1 << " sum(^2) = " << sum2 << std::endl;
    out << fx(c, n) << std::endl;
    out << tg_err(c, n, sum2) << std::endl;
    out << ek(fx(c, n)) << std::endl;
    out  << ek_err(fx(c, n), tg_err(c, n, sum2)) << std::endl;
}

int main()
{
    double n = 8;
    float a[8];
    float b[8];
    float c[8];
    in(a, b, n);
    out(a, b, c, n);

    return EXIT_SUCCESS;
}