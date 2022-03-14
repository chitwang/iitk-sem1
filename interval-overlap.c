/*Two intervals overlap, if they have some point that is contained in both the intervals.
You should design a Data-Structure such that it has two fields, namely the left index and the right index.
Assume that the intervals specified will be closed intervals. You need to figure out, whether given two intervals, they overlap or not.


Input Format



First line containing two space separated integer numbers, specifying the first closed interval

Second line containing two space separated integer numbers, specifying the second closed interval


Output Format


YES or NO in one line depending on the overlapping nature of the intervals


Sample Input 1


4 10

-1 6


Sample Output 1


YES


Sample Input 2


4 10

-1 3


Sample Output2


NO
*/

// solution:

#include <stdio.h>
struct interval
{
    int left;
    int right;
};
int main()
{
    //  Insert your code here.
    struct interval a;
    struct interval b;
    scanf("%d %d", &a.left, &a.right);
    scanf("%d %d", &b.left, &b.right);
    if (a.left > b.right)
    {
        printf("NO");
        return 0;
    }
    if (b.left > a.right)
    {
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}