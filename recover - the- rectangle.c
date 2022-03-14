/*[25 Points]

----------------------------------------------------------------------
Automated Grading Scheme:
Public Test Cases (2 point each. 2*2 = 4 points)
Hidden Test Cases (21 points)
Test Case numbers 1 to 2 are of 2 marks each
Test Case numbers 3 to 5 are of 5 marks each
Test case number 6 is of 6 marks



Manual Grading Scheme
Note: Any form of hard-coding will lead to zero marks. Eg: printf("0");
Penalty: 20% penalty if library functions of "stdlib.h" are used
 Header Files allowed:  stdio.h
----------------------------------------------------------------------
Mr C had drawn a nice axis-aligned rectangle (i.e. whose sides are parallel either to the x or the y axis) on a piece of paper and decorated his drawing with a few dots. However, one of his mischievous clones came and erased the lines forming the edges of the rectangle leaving only the dots for the corners behind. Help Mr C recover his nice rectangle.


The first line of the input will give you n, a strictly positive number, giving you the number of points on the plane. In the next n lines, we will give you the x and y coordinates of n points on the 2D plane, separated by a space. The coordinates will all be integers. In your output, you have to print the area of the largest axis-aligned rectangle that can be formed out of the n points we have given you. If no axis-aligned rectangle can be formed out of the points we have given you, simply print  -1 in the output.


Caution


Rest assured that we will give you at least 4 points i.e. n will be greater than or equal to 4.

The rectangle we are looking for has non-zero area. Please do not report a single point as a rectangle of area zero.

If there is no axis-aligned rectangle of non-zero area, you should print -1 as your output.

The rectangle we are looking for must be axis aligned. Do not report a rectangle whose sides are not parallel to the x and y axes.

Be careful about extra/missing lines and extra/missing spaces in your output.


HINTS: An axis-aligned rectangle, as we discussed in class, is always uniquely identified using its lower left corner and its upper right corner. You may also want to use a structure to store the points and use an array of these structure variables to process the points given to you.

struct Point{

   int x,y;

};

struct Point points[n];


Example Input


9

1 1

1 2

1 3

2 1

2 2

2 3

3 1

3 2

3 3


Example Output


4


Explaination
the points (1,1) (1,3) (3,1) (3,3) form a rectangle of area 4.*/

// solution:

#include <stdio.h>
struct point
{
    int x;
    int y;
};
int absolute(int z)
{
    if (z < 0)
    {
        return -1 * z;
    }
    return z;
}
int checkaxis(struct point a, struct point b, struct point c, struct point d)
{
    int flag = ((a.y == b.y) && (b.x == c.x) && (c.y == d.y) && (d.x == a.x));
    return flag;
}
int area(struct point a, struct point b, struct point c, struct point d)
{
    int l = a.x - b.x;
    int br = a.y - d.y;
    int are = l * br;
    return absolute(are);
}
int main()
{
    int n;
    scanf("%d", &n);
    struct point arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    struct point a = arr[i];
                    struct point b = arr[j];
                    struct point c = arr[k];
                    struct point d = arr[l];
                    if (checkaxis(a, b, c, d))
                    {
                        if (ans < area(a, b, c, d))
                        {
                            ans = area(a, b, c, d);
                        }
                    }
                    if (checkaxis(a, d, c, b))
                    {
                        if (ans < area(a, d, c, b))
                        {
                            ans = area(a, d, c, b);
                        }
                    }
                    if (checkaxis(a, b, d, c))
                    {
                        if (ans < area(a, b, d, c))
                        {
                            ans = area(a, b, d, c);
                        }
                    }
                    if (checkaxis(a, c, d, b))
                    {
                        if (ans < area(a, c, d, b))
                        {
                            ans = area(a, c, d, b);
                        }
                    }
                    if (checkaxis(a, c, b, d))
                    {
                        if (ans < area(a, c, d, b))
                        {
                            ans = area(a, c, d, b);
                        }
                    }
                    if (checkaxis(a, d, b, c))
                    {
                        if (ans < area(a, d, b, c))
                        {
                            ans = area(a, d, b, c);
                        }
                    }
                }
            }
        }
    }
    printf("%d", ans);
}