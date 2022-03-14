/*Write a program to add two distances. The distances will be in feet-inch format.


INPUT:

Two distances, each containing two integers, denoting the a, b, c and d respectively, where a and b denote the feet and inch measurements of the first distance, and c and d denote the feet and inch measurements of the second distance.


OUTPUT:

Print the sum of the two distances in feet-inch format separated by a space


Example Input
5 6 5 6


Example Output


11 0


Note: You need to use structures for this question. 12 inches = 1 feet*/

// solution:

#include <stdio.h>
struct distance
{
    int feet;
    int inch;
};
int main()
{
    //  Insert your code here.
    struct distance a;
    struct distance b;
    struct distance res;
    scanf("%d %d", &a.feet, &a.inch);
    scanf("%d %d", &b.feet, &b.inch);
    res.feet = 0;
    if ((a.inch + b.inch) % 12 == 0)
    {
        res.inch = 0;
    }
    else
    {
        res.inch = (a.inch + b.inch) % 12;
    }
    res.feet = a.feet + b.feet + (a.inch + b.inch) / 12;
    printf("%d %d", res.feet, res.inch);
    return 0;
}
