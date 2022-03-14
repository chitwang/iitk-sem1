/*[100 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible: 10 each for 1 and 2

Hidden: 20 each for 1, 2, 3 and 4



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% for using array and any future concept
-20% for using pow()
-20% each for using any library function other than printf and scanf
-20% each for using any library other than stdio.h

----------------------------------------------------------------------
Finding Pretty Numbers

Your friend Naruto loves numbers with some unique qualities. He calls them pretty numbers. You, being his only friend, decide to go on a quest to find pretty numbers. While on the quest, you will find one number each day for N days. Pretty numbers can be described as:



All prime numbers are pretty

All numbers of the form 2ax3b, a>0 and b>0 are also pretty. For example, 6, 12, 18 are pretty. Note that 1, 2, and 3 do not satisfy this condition.


Naruto also hates negative numbers and considers them ugly. He wants you to count the number of pretty numbers and ugly numbers you encounter in your quest.


A prime number is a number n (n not equal to 1) with exactly two factors which are 1 and n itself. For example, 2, 13, and 17.


Input

A sequence of integers separated by spaces, the last integer in the sequence is 0.(i.e. sequence ends with 0)


Output

Two integers that are separated by ONE space. The first is the number of pretty integers and the second is the number of ugly numbers encountered during the quest.


Sample Test Cases

Input:

1 2 3 -4 121 0
Output:

2 1


Input:

-100 81 96 37 23 17 -999 10 512 243 0
Output:

4 2*/

// solution:

#include <stdio.h>

int main()
{
    int x;
    int pretty = 0;
    int ugly = 0;
    scanf("%d", &x);
    while (1)
    {
        if (x == 0)
        {
            break;
        }
        else if (x < 0)
        {
            ugly++;
        }
        else
        {
            int count = 0;
            for (int i = 1; i <= x; i++)
            {
                if (x % i == 0)
                {
                    count++;
                }
            }
            if (count == 2)
            {
                pretty++;
            }
            else
            {
                int a = 0;
                int b = 0;
                while (x % 2 == 0)
                {
                    x = x / 2;
                    a++;
                }
                while (x % 3 == 0)
                {
                    x = x / 3;
                    b++;
                }
                if (a > 0 && b > 0 && x == 1)
                {
                    pretty++;
                }
            }
        }
        scanf("%d", &x);
    }
    printf("%d %d", pretty, ugly);
    return 0;
}