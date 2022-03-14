/*Given a partially filled 9×9 2D array A[9][9], the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and the disjoint subgrids of size 3×3 contains exactly one instance of the digits from 1 to 9.


INPUT:


9 lines contain 9 space separated integers from 1 to 9 denoting the filled value and 0 denoting empty cell.


OUTPUT:


9 lines of 9 space separated numbers containing the completely filled grid.


Example1 Input:

3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
Example1 Output:

3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9*/

// solution:

#include <stdio.h>
int isvalid(int sud[9][9], int row, int col, int n)
{
    for (int x = 0; x < 9; x++)
    {
        if (sud[x][col] == n)
        {
            return 0;
        }
    }
    for (int x = 0; x < 9; x++)
    {
        if (sud[row][x] == n)
        {
            return 0;
        }
    }
    int k = row - row % 3;
    int l = col - col % 3;
    for (int x = k; x < k + 3; x++)
    {
        for (int y = l; y < l + 3; y++)
        {
            if (sud[x][y] == n)
            {
                return 0;
            }
        }
    }
    return 1;
}
int solve(int sud[9][9], int row, int col)
{
    if (row == 8 && col == 9)
    {
        return 1;
    }
    if (col == 9)
    {
        col = 0;
        row++;
    }
    if (sud[row][col] != 0)
    {
        return solve(sud, row, col + 1);
    }
    for (int n = 1; n <= 9; n++)
    {
        if (isvalid(sud, row, col, n) == 1)
        {
            sud[row][col] = n;
            if (solve(sud, row, col + 1) == 1)
            {
                return 1;
            }
        }
        sud[row][col] = 0;
    }
    return 0;
}
int main()
{
    //  Insert your code here.
    int sud[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &sud[i][j]);
        }
    }
    solve(sud, 0, 0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", sud[i][j]);
        }
        if (i < 8)
        {
            printf("\n");
        }
    }
    return 0;
}
