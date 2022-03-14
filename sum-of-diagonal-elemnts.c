/*For an n*n matrix diagonal elements are given. All non-diagonal elements are equal, say x. Find out the minimum value of x such that the sum of diagonal elements is less than the sum of non-diagonal elements. Matrix elements can have negative integers too.



 Input :

First line contain the number of diagonal elements, n.
Next line contain n diagonal elements.

 Output :

Print the Matrix with non-diagonal elements as x.


Testcase1:
Input:
4
5 10 4 7
Output:
5 3 3 3
3 10 3 3
3 3 4 3
3 3 3 7*/

// solution:

#include <stdio.h>

int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    int diag = 0;
    int y[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
        diag += y[i];
    }
    int x = (diag / (n * n - n)) + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("%d ", y[i]);
            }
            else
            {
                printf("%d ", x);
            }
        }
        printf("\n");
    }
    return 0;
}