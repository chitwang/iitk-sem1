/*You are be given a triangle and a point. You need to tell if the point lies inside,on or outside the triangle.


Input Format



The first line of input contains 6 floating point numbers. These correspond to the coordinates of the points of traingle. The order of points will be x1,y1,x2,y2,x3,y3 where xi and yi correspond to x and y coordinate of the ith vertex of triangle.

The second line contain two numbers,say ax and ay  and which correspond to the the x-coordinate and y-coordiante of the point to be tested respectively.


Output Format



You need to print 'Inside', 'On' or 'Outside' depending upon if the point lies inside the triangle


Constraints



You need to use the structures provided in the template code.

You are allowed to use sqrt() and fabs() of math.h.


Sample Input 1:

0 0 4 0 0 4

0 1


Sample Output 1:

On


Sample Input 2:

0 1 2.5 1 1.25 -2

0 0


Sample Output 2:

Outside*/

// solution:

#include <stdio.h>
#include <math.h>
struct point
{
    float x;
    float y;
};
struct line
{
    struct point p1;
    struct point p2;
};
int check(struct line l, struct point p)
{
    float m1 = ((p.y - l.p1.y) * (l.p2.x - l.p1.x)) - ((l.p2.y - l.p1.y) * (p.x - l.p1.x));
    if (m1 == 0.0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
float area(struct point a, struct point b, struct point c)
{
    float t = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2;
    float z = fabs(t);
    return z;
}
int main()
{
    struct point a;
    struct point b;
    struct point c;
    struct line ab;
    struct line bc;
    struct line ca;
    struct point p;
    scanf("%f %f", &a.x, &a.y);
    scanf("%f %f", &b.x, &b.y);
    scanf("%f %f", &c.x, &c.y);
    scanf("%f %f", &p.x, &p.y);
    ab.p1 = a;
    ab.p2 = b;
    bc.p1 = b;
    bc.p2 = c;
    ca.p1 = c;
    ca.p2 = a;
    float sum = area(a, b, p) + area(b, c, p) + area(a, c, p) - area(a, b, c);
    if ((check(ab, p) || check(bc, p) || check(ca, p)) && sum <= 0.0)
    {
        printf("On");
        return 0;
    }
    /*printf("%d" , check(ab,p));
    printf("\n%d" , check(bc,p));
    printf("\n%d" , check(ca,p));*/
    if (sum == 0.0)
    {
        printf("Inside");
    }
    else
    {
        printf("Outside");
    }
}