/*[100 Points]

----------------------------------------------------------------------
Automated Grading Scheme:
Public Test Cases (5 point each. 2*5 = 10 points)
Hidden Test Cases (90 points)
Test Case numbers 1 and 2 are of 15 marks each
Test Case numbers 3 and 4 are of 10 marks each
Test Case number 5 is of 20 marks
Test case number 6 is of 15 marks
Test case number 7 is of 5 marks

Manual Grading Scheme
Note: Any form of hard-coding will lead to zero marks. Eg: printf("0");
Penalty: -20% for using array and any other future concept
Penalty: -20% each for using any library function other than printf and scanf
Penalty: -20% each for using any library other than stdio.h

--------------------------------------------------------------------------------------------------------------
Your genius little cousin has just learned the concept of divisors and multiples. To play with him, you give him a sequence of positive integers and ask him to find the sum of divisors of each number x in the sequence. Finally, you ask him to add up the sum of digits in each of these sums and tell you the answer.


For example, for the sequence 10, 12, 6, you expect the sum of divisors being 18 for 10 (1+2+5+10), 28 for 12 (1+2+3+4+6+12) and 12 for 6 (1+2+3+6). So, what you want is (1+8) + (2+8) + (1+2) = 22 as the sum of the sum of digits.


However, the genius that he is, he is not interested in this easy task. For each number x, he finds the sum of divisors of x (let us call this sum_x; this is in base 10), and finally, for all these sum_x, he converts them to base k (k being his favorite number). He tells you the sum of the sum of digits of all these base k numbers, instead of what you originally wanted.


For example, let k=3.



For 10, we had the sum of divisors as 18, 18 in base 3 notation is 200

For 12, we had the sum of divisors as 28, 28 in base 3 notation is 1001

For 6, we had the sum of divisors as 12, 12 in base 3 notation is 110


So, he tells you the answer as (2+0+0) + (1+0+0+1) + (1+1+0) = 6


You happen to know his favorite number k. Given the sequence of numbers and k, write a program that prints the answer you wanted and the answer given by your cousin.


Note : In this problem, we do not necessarily have k <= 10. Assume there exists some number system where a single digit represents any arbitrarily large number. For example, we can write 142 in base 12 as AB where A represents 11 and B represents 10. So the sum of digits in base 12 in this case will be 11 + 10 = 21


Input

The first line contains 2 integers, n (number of integers in the list you have) and k (n > 0, k > 1). The second line contains n space-separated positive integers.


Output

Two integers separated by a space. The first one is the answer you desired. The second is the answer given by your cousin.


Sample Test Cases

Input:

3 3
10 12 6

Output:

22 6


Input:

2 2
5 7

Output:

14 3*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    int k;
    int x;
    int sumc = 0; // sumc is the sum given by cousin
    int sumd = 0; // sumd is the sum desired by us
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i = 1; i <= n; i++)
    {
        int sum_x = 0;
        scanf("%d", &x);
        for (int j = 1; j <= x; j++)
        {
            if (x % j == 0)
            {
                sum_x = sum_x + j;
            }
        }
        int temp = sum_x;
        while (temp != 0)
        {
            sumd = sumd + (temp % 10);
            temp = temp / 10;
        }
        while (sum_x != 0)
        {
            sumc = sumc + (sum_x % k);
            sum_x = sum_x / k;
        }
    }
    printf("%d %d", sumd, sumc);
    return 0;
}