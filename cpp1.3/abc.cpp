#include <cstdio>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int f = (a + b + c);
    std::scanf("%d %d %d", &a, &b, &c);
    std::printf("%d + %d + %d = %d", a, b, c, (a + b + c));
}