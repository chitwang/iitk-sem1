/*[15 Points]

----------------------------------------------------------------------
Automated Grading Scheme:
Public Test Cases (0.5 point each. 0.5*2 = 1 points)
Hidden Test Cases (2 point each. 2*7 = 14 points)



Manual Grading Scheme
Note: Any form of hard-coding will lead to zero marks. Eg: printf("0");
Penalty: Award 0 points if struct is not used.

Header files Allowed: stdio.h
----------------------------------------------------------------------

You are given N points in 2-d plane. It is also given that x and y co-ordinate of each point is positive i.e, all the points lie in the first quadrant. You need to find rank of each point. Rank of a point is defined as the number of points that are dominated by this point. Point A dominates another point B if point B lies on or inside the rectangle drawn such that the upper-right corner is the point A and the bottom-left corner is the origin.


NOTE:



It is MANDATORY to use struct for storing the points otherwise you will be awarded ZERO points.

Output the ranks in the order as given in the input, in single line separated by space.


Input Format:

The first line contains an integer N denoting the total number of points. This is followed by N lines each containing 2 integers denoting x and y coordinates of point respectively.


Ouput Format:

Print N space separated integers denoting the rank of each point (Do not print trailing spaces).


Sample Input:

3

1 1

2 2

3 3


Sample Output

0 1 2


Explanation

According to the definition point (1, 1) does not dominate any point so rank = 0.

Point (2, 2) dominates point (1, 1) thus rank = 1.

Point (3, 3) dominates point (1, 1) and (2, 2) thus rank = 2.*/

// solution:

#include <stdio.h>
struct point
{
    int x;
    int y;
};
int checkdominate(struct point a, struct point b)
{
    if (b.x <= a.x && b.y <= a.y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void scan(struct point arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
}
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    struct point arr[n];
    scan(arr, n);
    for (int i = 0; i < n; i++)
    {
        int rank = -1;
        for (int j = 0; j < n; j++)
        {
            if (checkdominate(arr[i], arr[j]) == 1)
            {
                rank++;
            }
        }
        printf("%d", rank);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    return 0;
}
