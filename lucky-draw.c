/*You, along with your two best friends, go to a party, where a tile of 7 coupons is kept, one on top of the other. Each coupon has a unique non-negative integer number, which denotes how many gifts does someone win at the end of the party. You know that you and your friends will be the first to select the coupons, so you decide to cheat and keep the coupons with maximum, second maximum and third maximum at the top three places on the pile.


You will be given a list of 7 non-negative integers separated by a space as input. Write a code to find the position of the maximum element in the list, and swap it with the first element of the list. Then find the position of the second largest element of the list and swap it with the second element in the list. Finally, find the position of the third largest element in the list and swap it with the third element of the list. Output the resulting list with one space between two numbers. There should be no trailing spaces in your output.


Note:

Be careful about extra/missing lines and extra/missing spaces.

Be very careful, even though the evaluation may give you marks for extra spaces and newlines, the autograder will give you zero marks for any extra spaces or new lines.


Hint:

You will require the use of arrays in this question.


Examples:


Input 1

1 2 5 4 6 7 8


Output 1

8 7 6 4 5 2 1


Explanation 1

The maximum element is 8, which gets swapped with the first element 1. The second maximum element is 7, which gets swapped with the second element 2. The third largest element is 6, which gets swapped with the third element 5.


Input 2

6 5 4 3 2 1 7


Output 2

7 6 5 3 2 1 4


Explanation 2

First we swap 6 (first element) and 7 (largest element) and we get 7 5 4 3 2 1 6 and then we swap 5 (second element) and 6 (second largest element) and we get 7 6 4 3 2 1 5 and finally we swap 4 (third element) and 5 (third largest element) and we get 7 6 5 3 2 1 4 */

// solution:

#include <stdio.h>

int main()
{
    int arr[7];
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    int p1;
    int p2;
    int p3;
    int t1;
    int t2;
    int t3;
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max1)
        {
            max1 = arr[i];
            p1 = i;
        }
    }
    max1 = 0;
    t1 = arr[0];
    arr[0] = arr[p1];
    arr[p1] = t1;
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2)
        {
            max2 = arr[i];
            p2 = i;
        }
    }
    max1 = 0;
    max2 = 0;
    t2 = arr[1];
    arr[1] = arr[p2];
    arr[p2] = t2;
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2)
        {
            max3 = max2;
            max2 = arr[i];
        }
        else if (arr[i] > max3)
        {
            max3 = arr[i];
            p3 = i;
        }
    }
    t3 = arr[2];
    arr[2] = arr[p3];
    arr[p3] = t3;
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[6]);
}