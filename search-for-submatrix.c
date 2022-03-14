/*Given a string, any contiguous set of characters occurring in that string is considered a substring of that string. Similarly we can extend that notion to submatrices as well. In the first line of the input, you will be given two strictly positive integers n and m, separated by a space. In the next n lines, you will be given the entries of an n x m integer matrix A with one row of A in each line with two entries separated by a single space.


Then in the next line you will be given two strictly positive integers k and l, separated by a space. In the next k lines, you will be given the entries of a k x l integer matrix B with one row of B in each line with two entries separated by a single space. We promise that k will be less than or equal to n and l will be less than or equal to m.


In your output you have to tell us if the matrix B occurs as a submatrix in A or not. If B never occurs as a submatrix inside A, simply print the words "SUBMATRIX NOT PRESENT" (without quotes) in the output. However, if B is present one or more times in A as a submatrix, then you have to print the indices (as in 2D array indices) of the top left hand corners of all these occurrences in the output, one occurrence in each line in a format given below.


Make sure you first output all occurrences (if any) where the top left hand corner is in the first row of A, followed by all occurrences (if any) where the top left hand corner is in the second row of A, followed by all occurrences (if any) where the top left hand corner is in the third row of A and so on and so forth. If there are multiple occurrences with top left hand corner on the same row of A, output these occurrences in increasing order of the column number (index) of the top left hand corner.


EXAMPLE INPUT:

2 4
1 5 1 5
2 6 1 5
1 2
1 5
EXAMPLE OUTPUT:

(0, 0)
(0, 2)
(1, 2)
Explanation:

Note that there were three occurrences of B in A but the two occurrences in the first row got reported first and then the occurrence in the second row got reported. Also, within the two occurrences in the first row, the one with smaller column number got reported first.*/

// solution:

#include <stdio.h>
void scan(int n, int m, int arr[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}
int checksub(int i, int j, int k, int l, int b[k][l], int n, int m, int a[n][m])
{
    for (int x = 0; x < k; x++)
    {
        for (int y = 0; y < l; y++)
        {
            if (a[i + x][j + y] != b[x][y])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    //  Insert your code here.
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    scan(n, m, a);
    int k, l;
    scanf("%d %d", &k, &l);
    int b[k][l];
    scan(k, l, b);
    int i = 0;
    int j = 0;
    int flag = 0;
    while (i <= n - k)
    {
        if (checksub(i, j, k, l, b, n, m, a) == 1)
        {
            flag += 1;
            printf("(%d, %d)\n", i, j);
        }
        j++;
        if (j > m - l)
        {
            j = 0;
            i++;
        }
    }
    if (flag == 0)
    {
        printf("SUBMATRIX NOT PRESENT");
    }
    return 0;
}