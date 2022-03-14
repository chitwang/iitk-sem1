/*[40 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  5  each for all visible test cases

Hidden:  5  for 1,2,3 hidden test cases and  10  for 4 and 5 hidden test case



Manual Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% each for using any library other than stdio.h, stdlib.h,
-20% for using any built-in function other than malloc
-50% for static allocation of matrix or array, example int mat[100][100] or similar declaration (for not using dynamic allocation)
-50% for changing template
----------------------------------------------------------------------

Welcome Modiji

As you know PM Modi visited IIT Kanpur for convocation and your recently graduated seniors were getting ready to witness the event. They have been told though that because of the rowdy crowd and zigzagging queues to get into the Auditorium, it will be extremely hard to walk straight and reach the venue in time. Thus, you may have to take a few turns along the way to optimize the time in which you reach the place.


The part of the campus from your hostel to the Auditorium is represented by a 2D square matrix, where you are initially at (0, 0) and the venue is at (N-1, N-1). Each of the cells (i, j) in between has some integer points P(i, j) attached to it. P(i, j) indicates how thin the crowd is at that location, and thus the ease of travel through that cell. You have to reach (N-1, N-1) from (0, 0), while collecting the maximum number of points. You are only allowed to move down or right, that is, from (i, j), you can move to (i+1, j) or (i, j+1) only.


Find out the maximum number of points that you collect along the way.


Note: Please don't alter the template given in the question. Using dynamic memory allocation is a must.

Hint: Think recursively: max points from a cell (i, j) = points at cell (i, j) + max(max from (i+1, j), max from (i, j+1))

Constraints: N will be >=1 and P[i][j] will be >=0 for each i,j

INPUT:

The first line contains an integer N, the dimensions of the 2D array.
The next N lines contain N space separated integers, denoting the array P.


OUTPUT:

One line containing a single integer, the maximum number of points that can be collected along the way.


EXAMPLE:

Input:

3

1 2 3

0 7 8

1 2 3


Output:

21


Explanation: (0, 0) -> (0, 1) -> (1, 1) -> (1, 2) -> (2, 2) gets you 1 + 2 + 7 + 8 + 3 = 21 points. */

// solution:

#include <stdio.h>
#include <stdlib.h>

int get_max_points(int **P, int nrow, int ncol, int N)
{
    // function to compute the maximum number of points thus obtainable
    if (nrow == N - 1 && ncol == N - 1)
    {
        return P[nrow][ncol];
    }

    if (nrow == N - 1)
    {
        return P[nrow][ncol] + get_max_points(P, nrow, ncol + 1, N);
    }

    if (ncol == N - 1)
    {
        return P[nrow][ncol] + get_max_points(P, nrow + 1, ncol, N);
    }

    int right_points = get_max_points(P, nrow, ncol + 1, N);
    int down_points = get_max_points(P, nrow + 1, ncol, N);
    int max_points = right_points > down_points ? right_points : down_points;
    return P[nrow][ncol] + max_points;
}

int main()
{
    int N, i, j;
    scanf("%d", &N);
    // create two dimensional points array
    int **P = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++)
    {
        P[i] = (int *)malloc(N * sizeof(int));
    }

    // take input for P
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &P[i][j]);
        }
    }

    int ans = get_max_points(P, 0, 0, N);
    printf("%d\n", ans);
    return 0;
}
