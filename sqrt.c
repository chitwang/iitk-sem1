/*Given an integer x, find it’s square root. If x is not a perfect square, then return floor(√x).


Constraints:

0 <= x <= 1e9


Note:
The constraints are such that it can be done using linear search over integers. Try using binary search which was covered in Week 8 Tutorial.


Sample Input:

4


Sample Output:

2*/

// solution:

#include <stdio.h>
long int func(long int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    int ans;
    long int l = 1;
    long int r = x / 2;
    while (l <= r)
    {
        long int mid = (l + r) / 2;
        long int sq = mid * mid;
        if (sq == x)
        {
            return mid;
        }
        if (sq < x)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    //  Insert your code here.
    long int x;
    scanf("%ld", &x);
    printf("%ld", func(x));
    return 0;
}