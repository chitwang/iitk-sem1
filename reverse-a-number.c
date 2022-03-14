/*You are given 2 non-negative integers. Your task is to reverse these numbers (ignore leading zeros for reversed numbers), and then print their sum. In case of any invalid input, output "INVALID INPUT" (without quotes).


Examples:


Reversing a number can be understood by following examples:



468 -> 864

100 -> 1

0 -> 0


Input Format:


First line contains two space separated integers.


Output Format:


Output will contain either the sum or "INVALID INPUT" (without quotes) in case of invalid input.


Public Test Cases

Input
44 78
Output
131


Grading Scheme:
Visible Testcase : 1 marks
Hidden Testcases : 3 marks each
Penalty:
Use of any future concepts like arrays and strings will lead to 40% penalty.*/

// solution:

#include <stdio.h>

int main()
{
    int a;
    int b;
    int rem_a;
    int rem_b;
    int rev_a = 0;
    int rev_b = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    if ((a >= 0) && (b >= 0))
    {
        while (a != 0)
        {
            rem_a = a % 10;
            rev_a = (rev_a * 10) + rem_a;
            a = a / 10;
        }
        while (b != 0)
        {
            rem_b = b % 10;
            rev_b = (rev_b * 10) + rem_b;
            b = b / 10;
        }
        printf("%d", rev_a + rev_b);
    }
    else
    {
        printf("INVALID INPUT");
    }
    return 0;
}