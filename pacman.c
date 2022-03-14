/*[ 70 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  5  each for all visible test cases

Hidden:  10  each for all hidden test cases



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% each for using any library other than stdio.h
-20% for using any built-in function
-20% for using global variables
----------------------------------------------------------------------
Pacman

The objective of Pacman is to start from a starting point and reach a destination while collecting the maximum rewards along the way. The possible paths can be seen as a 2D grid, which will be given as a matrix. The entries of the matrix correspond to possible cells where Pacman can reach.


These entries of the matrix contain some numbers. -1 correspond to the cells Pacman can not reach. These are blocked cells and the walk can not go through them. Other entries which are the possible cells, contain some non-negative numbers corresponding to the value of reward given to each cell. Pacman gets this reward when it lands on the corresponding cell. Your task is to output the maximum possible value of reward that can be obtained in reaching from the point corresponding to (0, 0) to (n-1, n-1).


The input is given as an n×n matrix containing integers. Pacman can not land on cells containing -1, while it gets reward v if it lands on a cell containing v. The rewards along the path are added, including the start and the destination. The top left entry of the matrix is the starting position (0, 0), while the bottom left entry is the destination (n-1, n-1). At one step, Pacman can go either down or right, i.e. from the entry (i, j) it can either go to (i+1, j) or (i, j+1). However, it can not go beyond the boundaries of the grid. You have to output the maximum possible reward.


Constraints:


The size of the matrix is n where 0 < n < 10.

Value of rewards is v, where 0 <= v <= 100.

Forbidden cells are given as -1.



Input:


First line contains n, the size of the matrix.



Next n lines contain n space separated numbers each, where each entry corresponds to a value of a reward v, or forbidden cell-1.


Output:


Print a single number which corresponds to the maximum value over any walks.


Sample TestCase:

  Input


  3
  0 0 5
  3 -1 -1
  1 0 0
  Output:


  4

  Explanation:
 Pacman starts from the left top cell (0, 0). It can either go right to (1, 0) or down to (0, 1), obtaining reward 0 in each case. The path going right ends at (2, 0) which has value 5, but Pacman can not go down (because of -1 at (2, 1)) nor right (because the grid ends). Thus it can only go down to (1, 0) obtaining reward 3, and then again down to (2, 0) since right was not a possible move, obtaining a total reward of 3+1=4. Then it can only go right twice to reach (2, 2). The output is thus the total value of reward, which is 4.*/

// solution:

#include <stdio.h>
void func(int n, int mat[n][n], int i, int j, int *reward, int ans)
{
    if (i == n - 1 && j == n - 1)
    {
        if (mat[i][j] != -1)
        {
            ans += mat[i][j];
        }
        if (ans > *reward)
        {
            *reward = ans;
        }
        return;
    }
    if (mat[i][j] == -1)
    {
        return;
    }
    else if (j == n - 1)
    {
        func(n, mat, i + 1, j, reward, ans + mat[i][j]);
    }
    else if (i == n - 1)
    {
        func(n, mat, i, j + 1, reward, ans + mat[i][j]);
    }
    else
    {
        func(n, mat, i + 1, j, reward, ans + mat[i][j]);
        func(n, mat, i, j + 1, reward, ans + mat[i][j]);
    }
}
int main()
{
    //  Insert your code here.
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
    int reward = 0;
    func(n, mat, 0, 0, &reward, 0);
    printf("%d", reward);
    return 0;
}