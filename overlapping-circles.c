/*Two circles overlap, if they have some point that is common to both the circles.

You should design a structure corresponding to a circle, such that it has fields that clearly determine a circle.

You need to figure out, whether the two circles overlap. Even if two circles barely touch each other at a point, they are considered to be overlapping.


Input Format:
First line containing the x and y co-ordinates of the center and radius of the first circle.

Second line containing the x and y co-ordinates of the center and radius of the second circle.


Output Format:

YES - If the two circles overlap.

NO - If the two circles do not overlap.


Sample Input 1:

0 0 4

1 1 3


Sample Output 1:

YES


Sample Input 2:

0 0 4

10 10 3


Sample Output 2:

NO */

// solution:

#include <stdio.h>
struct circle
{
    int x;
    int y;
    int radius;
};
int main()
{
    struct circle a;
    struct circle b;
    scanf("%d %d %d", &a.x, &a.y, &a.radius);
    scanf("%d %d %d", &b.x, &b.y, &b.radius);
    int r = (a.radius + b.radius) * (a.radius + b.radius);
    int d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    if (d <= r)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}