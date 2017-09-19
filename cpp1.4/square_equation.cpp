#include <cstdio>
#include <cmath>

int main()
{
    std::puts("Please enter 'a', 'b' and 'c' for 'ax^2 + bx + c = 0");
    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);
    float d = (b * b) - 4 * a * c;
    float x1 = (-b + sqrt(d)) / 2;
    float x2 = (-b - sqrt(d)) / 2;
    std::printf("%fx^2 + %fx + %f = 0\n", a, b, c);
    std::printf("x1 = %f, x2 = %f", x1, x2);
}