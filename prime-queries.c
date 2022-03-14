/*Your friend, Shyam recieved a problem from his teacher. The problem goes like this
You will be provided an array of non-negative integers. Next, you will be asked some queries. There will be two types of queries - type 'A' and type 'B'.


For query of type 'A', you will be provided with two valid indices of array, you need to report how many numbers between these indices in the array (including these numbers) are prime.
For query of type 'B', you will be provided with two valid indices of array, you need to report how many numbers between these indices in the array (including these numbers) are not prime.


Input Format



The first line contins a integer equal to n, i.e the number of elements.

Next line contains 'n' space separated non-negative integers.

Next line contians q, which represent the number of queries

Each of the next 'q' lines contains one character c, and two integers i and j all separated by integers.


Constraints



1<= n <= 1000



1<= q <=500

c is either 'A' or 'B'

i <=j < n


Output Format



Print the answer of the above queries. Answer each query in a separate line.




Sample Input


5

5 3 1 2 4

3

A 0 4

A 0 2

B 2 4


Sample Output


3

2

2*/

// solution:

#include <stdio.h>
int ispr(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    int q;
    char t;
    int a;
    int b;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    scanf("%d", &q);
    getchar();
    for (int i = 0; i < q; i++)
    {
        int res = 0;
        scanf("%c %d %d", &t, &a, &b);
        if (t == 'A')
        {
            for (int j = a; j <= b; j++)
            {
                if (ispr(ar[j]) == 1)
                {
                    res++;
                }
            }
            printf("%d", res);
        }
        else if (t == 'B')
        {
            for (int j = a; j <= b; j++)
            {
                if (ispr(ar[j]) == 0)
                {
                    res++;
                }
            }
            printf("%d", res);
        }
        if (i < q - 1)
        {
            printf("\n");
            getchar();
        }
    }
    return 0;
}