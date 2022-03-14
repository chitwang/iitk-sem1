/*One day, Alice went treasure hunting. She had to surpass various obstacles to get to the treasure. Upon reaching the door of the treasure, she had a complicated puzzle to solve. She was given an integer n and some sequence of non-negative integers delimited by -1. Now, she needs to figure out the value of a+b-c, where a,b and c are defined as follows:



a is the maximum of the minimums of even integers for every n integers in the sequence.

b is the minimum of the maximums of odd integers for every n integers in the sequence.

c is defined as the maximum of numbers that are divisible by 13 and not divisible by 37 over all the numbers. If there are no such numbers, c is 0.


Input Format: The first integer is n. It is followed by the sequence of numbers delimited by -1 (i.e., the last number in the sequence is -1).


The integer n is at least 2. For every n integers, there will be at least one even integer and one odd integer. The total numbers input after the first number are divisible by n.


Output Format: Print a single integer, a+b-c.


Public Test Cases

Input	                  Output
Input1	                  Output1
6
4 5 3 63 2 1
481 23 13 37 99 0
22 147 111 22 22 22 -1	  72
Input2	                  Output2
5
244 27 46 173 33
144 162 70 263 350
67 42 167 249 50 -1	      243

Note: In the above examples the inputs are in diffierent lines its only to help in understanding. Actual inputs will be given as described.


Explanation (Case 1):

Value of a: Minimum values of even integers in the three consecutive sequences of length 6 are 2, 0, 22 The maximum value among the minimums is : 22.

Value of b: Maximum values of odd integers in the three consecutive sequences of length 6 are 63, 481,147. The minimum value among the maximums is 63.

Value of c: only one number, i.e., 13 is divisible by 13 and not 37, therefore c is 13

So the output is a+b-c = 72.


Grading Scheme

Visible - 2 marks each

Hidden - 6 marks each

Penalties - Usage of arrays is not allowed. 1/3rd penalty will be levied if arrays are used.
*/

// solution:

#include <stdio.h>

int main()
{
    int a = 0;
    int b = 9999999999;
    int c = 0;
    int min = 99999999999;
    int max = 0;
    int n;
    int e;
    scanf("%d", &n);
    scanf("%d", &e);
    int count = 0;
    while (e != -1)
    {
        if (count < n)
        {
            if (e % 13 == 0 && e % 37 != 0)
            {
                if (e > c)
                {
                    c = e;
                }
            }
            if (count <= n)
            {
                if (e % 2 == 0)
                {
                    if (e < min)
                    {
                        min = e;
                    }
                }
                if (e % 2 != 0)
                {
                    if (e > max)
                    {
                        max = e;
                    }
                }
                count++;
            }
            if (count == n)
            {
                if (min > a)
                {
                    a = min;
                }
                if (max < b)
                {
                    b = max;
                }
                max = 0;
                min = 99999999999;
                count = 0;
            }
            scanf("%d", &e);
        }
    }
    printf("%d", a + b - c);
    return 0;
}
