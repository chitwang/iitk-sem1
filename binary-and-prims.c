/*Automated Grading Scheme:

Visible: 5  marks for each Visible test case.

Hidden: 5 marks for 1st, 2nd and 3rd Hidden test case.

Hidden: 10 marks for 4th Hidden test case.


Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-50% for changing template
-20% for using any future concepts
-20% for using built in function

---------------------------------------------------------------------------------

You are given an integer n. Consider the binary expansion of n denoted by the number s, i.e., s represents a number in base 2. Let N denote the decimal equivalent of the same string in the decimal system. Find the smallest prime number which is just greater than or equal to N.


For example, if n = 7, the binary expansion of n is 1112 where s = 111. Now, the decimal number represented by s is N = 111, which is "one hundred and eleven". The prime just larger than or equal to 111 will be 113, which is the correct output.


Note:


Stick to the template provided to define the important functions.

You are not allowed to use library functions.

You can create other user-defined functions.

You are required to define the three functions given in the template. Do not change the names of the functions of the template.


Input Format:

The first line contains an integer n.


Constraints:


2 <= n <= 50


Output Format:

The output should contain an integer n which will give the correct answer.


Sample Input:

5


Sample Output:

101*/

// solution:

#include <stdio.h>

// Write your code here.

int decimal_to_binary(int n)
{
    int p = 1;
    int bin = 0;
    while (n != 0)
    {
        bin = bin + (n % 2) * p;
        n = n / 2;
        p = p * 10;
    }
    return bin;
}

int is_prime(int p)
{
    // Write your code here.
    int count = 0;
    for (int i = 1; i <= p; i++)
    {
        if (p % i == 0)
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

int closest_prime(int N)
{
    // Write your code here.
    while (1)
    {
        if (is_prime(N) == 1)
        {
            break;
        }
        N++;
    }
    return N;
}

int main()
{
    // Do not change this part.
    int n = 0;
    scanf("%d", &n);
    printf("%d", closest_prime(decimal_to_binary(n)));
    return 0;
}