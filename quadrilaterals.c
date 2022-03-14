/*In the input, you will be give you the coordinates of 4 points on the 2D plane. The coordinates will be all be integers and will be separated by a space. The format is given below
x1 y1 x2 y2 x3 y3 x4 y4
These form the points p1 = (x1, y1), p2 = (x2, y2), p3 = (x3, y3) and p4 = (x4, y4). The four points will form either a square or a rectangle or a parallelogram or a trapezium.


If the quadrilateral is a square, print SQUARE (without quotes)
If the quadrilateral is not a square but is a rectangle, print RECTANGLE (without quotes)
If the quadrilateral is not a rectangle but is a parallelogram, print PARALLELOGRAM (without quotes)
If the quadrilateral is not a parallelogram, print TRAPEZIUM (without quotes).


We assure you that the points will be given to you in counterclockwise order i.e. starting from p1 if you move around the quadrilateral in a counter clockwise manner, you will encounter first p2, then p3, then p4 and then back to p1. This hint is very important as it will help you figure out the edges of the quadrilateral. Since points are given in counter clockwise order (p1 p2) will be an edge of the quadrilateral, as will be (p2 p3) but (p1 p3) will be a diagonal of the quadrilateral.


Caution



The squares, rectangles etc may be rotated and not be axis aligned. Coordinates will be integers but may be negative or zero.
Be careful of vertical and horizontal lines

The question may require you to compare floating point numbers like slopes etc. Since comparing floating point numbers for equality is dangerous, we will consider two floating point numbers to be the same if their difference in absolute terms is less than 0.0001. Use the fabs() function from math.h to get the absolute value of floating point numbers.

We will never give you a test case where any three points are collinear or where the quadrilateral is a scalene quadrilateral (i.e. neither of the cases mentioned above).
Be careful not to have any missing spaces or extra newlines in your output.


HINTS


Write functions to check whether two lines are parallel to each other and whether two lines are perpendicular to each other. Lines are represented using two Point variables (see below). Also write a function to compute the Euclidean distance between two Point variables. Use these functions to decide which type of quadrilateral we have given you.


Sample Input


1 4 10 4 20 5 7 5


Sample Output


TRAPEZIUM


Explanation: Only one pair of opposite sides is parallel, no corner angle is 90 degrees and the quadrilateral is a trapezium.*/

// solution:

#include <stdio.h>
#include <math.h>
struct point
{
    int x;
    int y;
};
struct line
{
    struct point p1;
    struct point p2;
};
int distance(struct point a, struct point b)
{
    int _ = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return _;
}
int parallel(struct line a, struct line b)
{
    if (a.p1.x == a.p2.x)
    {
        if (b.p1.x == b.p2.x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (b.p1.x == b.p2.x)
    {
        if (a.p1.x == a.p2.x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    float m1 = (a.p1.y - a.p2.y) / (a.p1.x - a.p2.x);
    float m2 = (b.p1.y - b.p2.y) / (b.p1.x - b.p2.x);
    if (fabs(m1 - m2) < 0.0001)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int perp(struct line a, struct line b)
{
    if (a.p1.x == a.p2.x)
    {
        if (b.p1.y == b.p2.y)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (b.p1.x == b.p2.x)
    {
        if (a.p1.y == a.p2.y)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int m1 = (a.p2.y - a.p1.y) * (b.p2.y - b.p1.y);
    int m2 = (a.p2.x - a.p1.x) * (b.p2.x - b.p1.x);
    if (m1 + m2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct point p[4];
    struct line l1;
    struct line l2;
    struct line l3;
    struct line l4;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    l1.p1 = p[0];
    l1.p2 = p[1];
    l2.p1 = p[1];
    l2.p2 = p[2];
    l3.p1 = p[2];
    l3.p2 = p[3];
    l4.p1 = p[3];
    l4.p2 = p[0];
    int ab = distance(p[0], p[1]);
    int bc = distance(p[1], p[2]);
    int cd = distance(p[2], p[3]);
    int da = distance(p[3], p[0]);
    int sq = ((ab == bc) && (bc == cd) && (cd == da) && (da == ab) && parallel(l1, l3) && parallel(l2, l4) && perp(l1, l2) && perp(l2, l3) && perp(l3, l4) && perp(l4, l1));
    int rect = ((ab == cd) && (bc == da) && parallel(l1, l3) && parallel(l2, l4) && perp(l1, l2) && perp(l2, l3) && perp(l3, l4) && perp(l4, l1));
    int llgm = ((ab == cd) && (bc == da) && parallel(l1, l3) && parallel(l2, l4));
    if (sq)
    {
        printf("SQUARE");
    }
    else if (rect)
    {
        printf("RECTANGLE");
    }
    else if (llgm)
    {
        printf("PARALLELOGRAM");
    }
    else
    {
        printf("TRAPEZIUM");
    }
}
