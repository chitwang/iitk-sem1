/*Consider a city with n places (numbered 0, 1, 2, ..., n-1)connected by a bus network. A matrix C of size n × n is used to store the direct connectivity between places: C[i][j] = 1 is there is a direct bus between place i and j, 0 otherwise.


Since the buses are few, and number of places is large, most of the entries in C are 0. It is possible to save space by storing only the places that have connection in a dynamically allocated matrix (A "sparse" matrix). Here information is stored only for pairs of cities that have direct connection.


Your job is to create a 2-Dimensional dynamic array D and populate it using C. Entries in the D matrix are as follows:



D[i] = NULL, if i place does not have a direct bus to any other point.

D[i] is a dynamically allocated array of size k if i is connected directly to k places.

D[i][0], D[i][1],...,D[i][k-1] entries store these places (number) in sorted order.


INPUT:


First line contains n, number of places.

Next n lines contain n entries each where each entry is either a 0 or 1 (C matrix denoting absence or presence of direct bus).


OUTPUT:

First line prints the number of non-NULL entries in D.
Next n lines print the rows of D. Print NULL if the row is NULL. Columns are separated by single space.


NOTE:

Use dynamic array to store C (or one row of C). Free it after D matrix is populated.


Example1 Input:

3
0 1 0
0 0 1
1 0 0
Example1 Output:

3
1
2
0*/

// solution:

#include <stdio.h>
#include <stdlib.h>
int main()
{
    // Insert your code here.
    int n;
    scanf("%d", &n);
    int **c;
    c = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        c[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    int **d;
    int nonnull = 0;
    int arr[n];
    d = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] != 0)
            {
                nonnull++;
                k++;
            }
        }
        arr[i] = k;
        if (k != 0)
        {
            d[i] = (int *)malloc(k * sizeof(int));
        }
    }
    printf("%d\n", nonnull);
    for (int i = 0; i < n; i++)
    {
        int g = 0;
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] != 0)
            {
                printf("%d", j);
                if (g < (arr[i] - 1))
                {
                    printf(" ");
                }
                g++;
            }
        }
        if (arr[i] == 0)
        {
            printf("NULL");
        }
        if (i < n - 1)
        {
            printf("\n");
        }
    }
    free(c);
    return 0;
}