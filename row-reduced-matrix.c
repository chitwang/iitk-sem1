/*You will be given a square matrix of size n x n, where n <= 10. A matrix is in row-reduced form if both conditions hold:



Row conditions: The first non-zero element of every row, if it exists, must be 1.



Column conditions: If the first non-zero element of some row is in column j, then every other element in column j is 0.




In this question, the input matrix may or may not be row-reduced form. You have to output the number of rows violating the condition above the number of columns which violate the conditions above. If there are no violations, you have to output 0 0.


Input Format


The first line contains the integer n.

The next n lines contain n integers each, representing the n rows of the matrix.


Output Format

Print two space-separated integers r c, where r is the number of rows violating the above condition, and c is the number of column violating the condition. In case all rows follow the condition, print 0 for it, and similarly for columns as well.


Note


1 <= n <= 10


Example/Visible Case 1

Input:


3
1 2 1
0 1 2
1 3 1
Output:


0 2*/

// solution:

#include <stdio.h>
int spanner(int arr[], int n, int b)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == b)
            {
                flag = 1;
                break;
            }
        }
        return flag;
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
    int r = 0;
    int c = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                if (mat[i][j] != 1)
                {
                    r++;
                }
                if (spanner(arr, c, j) == 0)
                {
                    for (int h = 0; h < n; h++)
                    {
                        if (h != i)
                        {
                            if (mat[h][j] != 0)
                            {
                                arr[c] = j;
                                c++;
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    printf("%d %d", r, c);
    return 0;
}