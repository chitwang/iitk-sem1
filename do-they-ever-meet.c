/*Note: You need to use structures for this question.


Atin has been given two line segments (defined uniquely by two endpoints). He turns to you to ask if the segments intersect or not. Can you help him?


You need to define a struct for storing a point, and another struct for storing a line segment (which should use the struct defined for point).


INPUT:

Two line segments, each containing four floating point numbers, denoting the X1, Y1, X2 and Y2 respectively, where X1 and Y1 denote the X and Y coordinates of the first point, and X2 and Y2 denote the X and Y coordinates of the second point.
You can assume that the two points used to specify a line are not the same, i.e. (X1, Y1) not equal to (X2, Y2).


OUTPUT:

In case the line segments do not intersect, print "No".
Otherwise, print "Yes".


Example Input


0.0 0.0 1.2 2.5

1.0 3.2 0.0 0.0


Example Output


Yes


Explanation
The two lines intersect at (0.00, 0.00).*/

// solution:

#include <stdio.h>
struct point
{
    float x;
    float y;
};
struct segment
{
    struct point p1;
    struct point p2;
};
float min(float a, float b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
struct point inter(struct segment a, struct segment b)
{
    struct point ans;
    float m1 = (a.p2.y - a.p1.y) / (a.p2.x - a.p1.x);
    float m2 = (b.p2.y - b.p1.y) / (b.p2.x - b.p1.x);
    float c1 = a.p1.y - m1 * a.p1.x;
    float c2 = b.p1.y - m2 * b.p1.x;
    ans.x = (c1 - c2) / (m2 - m1);
    ans.y = (m2 * c1 - m1 * c2) / (m2 - m1);
    return ans;
}
float max(float a, float b)
{
    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
float interdash(struct segment a, struct segment b)
{
    float an = ((b.p2.y - b.p1.y) * (a.p1.x - b.p1.x) / (b.p2.x - b.p1.x)) + b.p1.y;
    return an;
}
int check(struct segment a, struct segment b)
{
    if (a.p1.x == a.p2.x)
    {
        if (b.p1.x == b.p2.x)
        {
            if (a.p1.x == b.p1.x)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            float ans = interdash(a, b);
            if (ans <= max(a.p1.y, a.p2.y) && ans >= min(a.p1.y, a.p2.y) && ans <= max(b.p2.y, b.p1.y) && ans >= min(b.p1.y, b.p2.y))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    if (b.p1.x == b.p2.x)
    {
        if (a.p1.x == a.p2.x)
        {
            if (a.p1.x == b.p1.x)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            float ans = interdash(b, a);
            if (ans <= max(a.p1.y, a.p2.y) && ans >= min(a.p1.y, a.p2.y) && ans <= max(b.p2.y, b.p1.y) && ans >= min(b.p1.y, b.p2.y))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    float p = (a.p2.y - a.p1.y) * (b.p2.x - b.p1.x);
    float q = (b.p2.y - b.p1.y) * (a.p2.x - a.p1.x);
    if (p == q)
    {
        if ((a.p1.y <= max(b.p1.y, b.p2.y) && a.p1.y >= min(b.p1.y, b.p2.y) && a.p1.x <= max(b.p1.x, b.p2.x) && a.p1.x >= min(b.p1.x, b.p2.x)) || (a.p2.y <= max(b.p1.y, b.p2.y) && a.p2.y >= min(b.p1.y, b.p2.y) && a.p2.x <= max(b.p1.x, b.p2.x) && a.p2.x >= min(b.p1.x, b.p2.x)) || (b.p1.y <= max(a.p1.y, a.p2.y) && b.p1.y >= min(a.p1.y, a.p2.y) && b.p1.x <= max(a.p1.x, a.p2.x) && b.p1.x >= min(a.p1.x, a.p2.x)) || (b.p2.y <= max(a.p1.y, a.p2.y) && b.p2.y >= min(a.p1.y, a.p2.y) && b.p2.x <= max(a.p1.x, a.p2.x) && b.p2.x >= min(a.p1.x, a.p2.x)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (inter(a, b).x <= max(a.p1.x, a.p2.x) && inter(a, b).x >= min(a.p1.x, a.p2.x) && inter(a, b).y <= max(a.p1.y, a.p2.y) && inter(a, b).y >= min(a.p1.y, a.p2.y) && inter(a, b).x <= max(b.p1.x, b.p2.x) && inter(a, b).x >= min(b.p1.x, b.p2.x) && inter(a, b).y <= max(b.p1.y, b.p2.y) && inter(a, b).y >= min(b.p1.y, b.p2.y))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    //  Insert your code here.
    struct segment l1;
    struct segment l2;
    scanf("%f %f %f %f", &l1.p1.x, &l1.p1.y, &l1.p2.x, &l1.p2.y);
    scanf("%f %f %f %f", &l2.p1.x, &l2.p1.y, &l2.p2.x, &l2.p2.y);
    if (check(l1, l2))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}