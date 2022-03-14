/*[35 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  1 marks  for 1st testcase and 2 marks each for 2nd and 3rd test cases

Hidden:  5  each for all hidden test cases



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% each for using any library other than stdio.h,
-25% for using global varibles

-----------------------------------------------------------------------------------------

One day Bob went for fishing in a pond of size N x N with a net of size k x k. The pond is divided into cells of size 1 x 1. He knows the number of fishes in each cell. To collect fishes, Bob can throw his net only once. Bob wants to collect as many fishes as possible given the constraint. Where should Bob throw his net so that he collects maximum number of fishes? You need to output two integers denoting the row number and column number of the cell which should be the top left cell of the net where Bob will throw his net to collect maximum number of fishes.


NOTE:



Assume 1-based indexing i.e, rows and columns start from 1.

If there are more than one possible configurations of the net to get maximum fishes then output the configuration having the lowest row number.

If there are more than one possible configurations of the net to get maximum fishes having same row number then output the configuration having the lowest column number.

Assume that Bob cannot cut the net in parts and also the net should not go out of the boundary of the pond.


Input Format:

The first line contains two integers N and k separated by space. This is followed by N lines each containing N integers denoting number of fishes in the correspoding cell.


Constraints:


Assume k <= N.

N <= 10.

Maximum number of fishes in one cell is 1000.


Ouput Format:

Print two integers separated by space denoting the row and column number of the cell.


Sample Input:

3 2

1 1 1

2 2 2

3 3 3


Sample Output

2 1


Explanation

Bob can collect maximum 10 fishes using his 2x2 net. There can be 2 possible top-left positions to get 10 fishes -> (2, 1) and (2, 2). But as mentioned in the Note, you have to output 2 1 as the answer.*/

// solution:

#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int fishes[10][10];
    for (int i = 0; i < n; i = i + 1)
    {
        for (int j = 0; j < n; j = j + 1)
        {
            scanf("%d", &fishes[i][j]);
        }
    }
    int max_sum = -1;
    int x = -1, y = -1;
    for (int row_num = 0; row_num < n - k + 1; row_num = row_num + 1)
    {
        for (int col_num = 0; col_num < n - k + 1; col_num = col_num + 1)
        {
            int curr_sum = 0;
            for (int i = 0; i < k; i = i + 1)
            {
                for (int j = 0; j < k; j = j + 1)
                {
                    curr_sum = curr_sum + fishes[row_num + i][col_num + j];
                }
            }
            if (curr_sum > max_sum)
            {
                max_sum = curr_sum;
                x = row_num;
                y = col_num;
            }
        }
    }
    printf("%d %d", x + 1, y + 1);
    return 0;
}