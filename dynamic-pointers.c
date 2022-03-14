/*You are on the starting point of a dirt track, having your speedy car ready by your side. The track is straight from start to finish, and there are N lanes along which a car can go. You have a choice as to which lane you want to start with. Each lane is comprised of N blocks, each of which has some points marked which indicate the speed at which that block can be crossed. Your task is to choose a lane that maximizes your points by the end of the race, i.e. allows you to travel at the fastest speeds.


So the track is represented by a 2D matrix, and you are given a pointer to it. You have to compute column sum (where each column is a lane on the track) for all the columns and report the maximum such column sum. Each row indicates the points obtainable from a set of adjacent blocks on different lanes.


Note: You must use dynamic memory allocation for this question.


Input

The first line contains an integer N, denoting the number of rows and columns in the matrix.
The next N lines contain N integers each, every line denoting the points marked on all the blocks on that level.


Output

One integer, denoting the largest column sum.


Explanation: The last column has sum 14 (3 + 8 + 3), which is greater than that of the other columns (2 and 11).


Public test cases:
Input:
3
1 2 3
0 7 8
1 2 3
Output:
14*/

// solution:

#include <stdio.h>
#include <stdlib.h>

int get_max_col_sum(int **A, int n)
{
    // function to get maximum column sum
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i][j];
        }
        if (sum > ans)
        {
            ans = sum;
        }
    }
    return ans;
}

int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    int **mat;
    mat = (int **)malloc(n * (sizeof(int *)));
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("%d", get_max_col_sum(mat, n));
    return 0;
}