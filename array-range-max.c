/*[20 Points]

----------------------------------------------------------------------
Automated Grading Scheme:
Public Test Cases (1 point each. 1*2 = 2 points)
Hidden Test Cases (2 point each. 2*9 = 18 points)


Manual Grading Scheme
Note: Any form of hard-coding will lead to zero marks. Eg: printf("0");
Penalty: Solutions using functions to answer the queries should be awarded 0 points.
----------------------------------------------------------------------

You are given a character array (called str) of length n. The array elements will only be uppercase letters. A total of q queries will be made. Each query will be of the form [l, r], where [0 <= l <= r <= n-1]. For each query, you have to print the maximum array element between indices l and r (both inclusive).


Any solution that uses functions (for answering the queries) will be awarded ZERO points.


Input Format


The first line contains an integer n that represents the length of the str array. The next line contains n uppercase letters that constitute str (NOT space separated). The third line contains an integer q, which is the total number of queries that will be made). The next q lines contain 2 integers l and r each, representing the query's range.


Output Format


Print a total of q characters (NOT space separated). The ith character of the output corresponds to the answer of the ith query.


Sample Input 1


10
DCBAEFGHJI
5
0 4
5 9
0 9
3 6
2 7


Sample Output 1


EJJGH


Explanation 1



The character array between indices [0, 4] is DCBAE, so the answer is E

The character array between indices [5, 9] is FGHJI, so the answer is J

The character array between indices [0, 9] is DCBAEFGHJI, so the answer is J

The character array between indices [3, 6] is AEFG, so the answer is G

The character array between indices [2, 7] is BAEFGH, so the answer is H


Sample Input 2


3
JLE
2
0 1
0 2


Sample Output 2


LL


Explanation 2



The character array between indices [0, 1] is JL, so answer is L

The character array between indices [0, 2] is JLE, so answer is L


Be careful while taking the character array input. The character \n after n characters (i.e., length of the array) is NOT a part of the character array.*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    int a;
    int b;
    int q;
    scanf("%d", &n);
    getchar();
    char str[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &str[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &a, &b);
        char max = 'A';
        for (int j = a; j <= b; j++)
        {
            if (str[j] > max)
            {
                max = str[j];
            }
        }
        printf("%c", max);
    }
    return 0;
}