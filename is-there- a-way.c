/*[40 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  2  each for all visible test cases

Hidden:  6  each for all hidden test cases



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% each for using any library other than stdio.h
-25% for using global variables

Note: Use of recursion is must. Otherwise, 0 marks are rewarded.
----------------------------------------------------------------------
You are given an N x N grid. You need to find if there exists a path from the cell (x_1, y_1) to the cell (x_2, y_2).

If you are at (x, y) and the value at this cell of the grid is a then you can either move to (x+a, y) or to (x, y+a), provided that you stay inside the grid.


Input

First line of the input contains the number N.

On each of the next N, lines there will be N entries where the jth entry on the ith line cooresponds to the value at the cell (i, j) of the grid. All these entries will be positive.

The next line contains 4 integers, x_1, y_1, x_2 and y_2. All these entries are greater than or equal to 1 and less than or equal to N.


Output

If there exists a path from (x_1, y_1) to (x_2, y_2) print YES, otherwise print NO.


Note:

The numbering of the cells starts from (1,1) and goes on to (N, N).


Examples:


Input 1

2

1 2

1 100

1 1 2 2


Output 1

YES


Explanation 1

From (1, 1) go to (1 + 1, 1) (as a = 1 for (1, 1)) and from (2, 1) go to (2, 1 + 1) (as a = 1 for (2, 1)).


Input 2

4

 3 2 1 4

 3 2 1 3

 3 2 1 2

 3 2 1 1

 1 4 4 4


Output 2

NO


Explanation 2

We can move from (1, 4) to (1 + 4, 4) or (1, 4 + 4) and both these points take us out of the grid, so it is not possible to reach (4, 4) from (1, 4).*/

// solution:

#include <stdio.h>
void recursion(int n, int mat[n][n], int i, int j, int p, int q, int *flag)
{
    if (i == p && j == q)
    {
        *flag = *flag + 1;
        return;
    }
    if (i > n - 1 || j > n - 1 || i > p || j > q)
    {
        return;
    }
    if (i == n - 1)
    {
        recursion(n, mat, i, j + mat[i][j], p, q, flag);
    }
    else if (j == n - 1)
    {
        recursion(n, mat, i + mat[i][j], j, p, q, flag);
    }
    else
    {
        recursion(n, mat, i + mat[i][j], j, p, q, flag);
        recursion(n, mat, i, j + mat[i][j], p, q, flag);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int flag = 0;
    recursion(n, mat, x1 - 1, y1 - 1, x2 - 1, y2 - 1, &flag);
    if (flag == 0)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}