/*[70 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  5  each for all visible test cases

Hidden:  10  each for all hidden test cases



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% each for using any library other than stdio.h
-20% for using any built-in function
----------------------------------------------------------------------
Maximum Fencing Sum

A farmer has a plot in the form of an n*m matrix (n rows, m columns). He has to create a square fenced area within the plot. Every cell of the matrix has been assigned an integer value representing the ease with which one can put a fence-post in that cell. This integer can be either positive or negative. You are tasked with finding the largest square within the matrix such that the sum of the integers on the cells along its perimeter is maximized.


NOTE: A single cell is not considered a square, i.e., the side length of the mentioned squares must be at least 2.


Constraints


3 <= n,m <= 50



Value in each cell will be in range [-100,100]




Input Format


The first line contains 2 integers n and m.



The next n lines each contain m space-separated integers. Each line gives a row of the matrix.




Output Format

Output two space-separated integers s l, where s is the maximum sum of values along the perimeter of the square within the matrix, and l is the side length of the square. In case the same sum occurs for different length squares, then print the l for the largest such square.


For example, consider the following matrix. The green-highlighted square of side length 3 has the highest sum on its perimeter (8). So the output for this case will be 8 3.


Maximum-Fencing-Sum


Sample Testcase

Input:


4 4
1 1 1 -1
1 -1 1 -1
1 1 1 -1
-1 -1 -1 -1
Output:


8 3*/

// solution:

#include <stdio.h>
int findperimeter(int n, int m, int mat[n][m], int s, int k, int j)
{
    int p = 0;
    for (int i = 0; i < s; i++)
    {
        p = p + mat[0 + k][i + j];
    }
    for (int i = 1; i < s; i++)
    {
        p = p + mat[i + k][s - 1 + j];
    }
    for (int i = s - 2; i >= 0; i--)
    {
        p = p + mat[s - 1 + k][i + j];
    }
    for (int i = s - 2; i >= 1; i--)
    {
        p = p + mat[i + k][0 + j];
    }
    return p;
}
int min(int a, int b)
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
int main()
{
    //  Insert your code here.
    int n, m;
    scanf("%d %d", &n, &m);
    int mat[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int ans = -999999;
    int size;
    int x = min(n, m);
    for (int s = 1; s < x; s++)
    {
        int i = 0;
        int j = 0;
        while (i + s < n)
        {
            if (j + s < m)
            {
                int sum = findperimeter(n, m, mat, s + 1, i, j);
                if (sum >= ans)
                {
                    ans = sum;
                    size = s + 1;
                }
            }
            j++;
            if (j == m)
            {
                j = 0;
                i++;
            }
        }
    }
    printf("%d %d", ans, size);
    return 0;
}
