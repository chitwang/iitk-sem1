/*Given a stream of any number of non-negative integers separated by spaces, find and print the third largest number in the stream. The end of the stream is indicated by -1 and does not belong in the sequence of numbers. If such a number with the third largest value does not exist in the input stream, then print -1.


The largest number is strictly greater than the second largest number which in turn is strictly greater than the third largest number and so on.


Input Format:
Sequence of non-negative integers separated by spaces, the sequence ends with -1.


Output Format:
The third largest non-negative integer in the sequence or -1.


Example 1

Input:
91 27 78 42 -1


Output:
42


Explanation:
91 > 78 > 42 > 27



Example 2

Input:
34 49 34 -1
Output:
-1


Explanation:
49 > 34, so a third largest number does not exist in the stream.



Note: Usage of future concepts such as arrays is forbidden. If arrays are used, deduct 15 marks.*/

// solution:

#include <stdio.h>

int main()
{
    int a;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    scanf("%d", &a);
    int count = 1;
    while (a != -1)
    {
        if (a >= max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = a;
        }
        else if (a >= max2)
        {
            max3 = max2;
            max2 = a;
        }
        else if (a >= max3)
        {
            max3 = a;
        }
        scanf("%d", &a);
        count++;
    }
    if (count <= 4)
    {
        printf("-1");
    }
    else
    {
        if ((max1 > max2) && (max2 > max3))
        {
            printf("%d", max3);
        }
        else
        {
            printf("-1");
        }
    }
    return 0;
}
