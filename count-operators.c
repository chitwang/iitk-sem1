/*[30 Points]

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Automated Grading Scheme:

Visible: 2 marks for each visible test case.

Hidden: 2 marks for 1, 2, 5, 6,7 and 8 test case.

Hidden: 3 marks for 3, 4, 9 and 10 test case.



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% for using strings, arrays, or array indexing to solve this problem,or any future concepts
-20% each for using any library function (string library) other than printf and scanf
-20% each for using any library other than stdio.h

----------------------------------------------------------------------
Count Operators

Given two integers A and B. Your task is to convert A to B. You are allow to double the value (multiply by 2) or half it (integer division by 2). These operations can be performed any number of times.


The program should print the minimum number of multiplication and integer division required to convert A to B.


Constraint:


The integer B is always in power of 2, i.e 2^n where n can be 0,1,2,3,4,....



Refrain from using floating point variables for storing A, B and number of operations.




Input:


Each test case contains two space separated integer. (The program should handle long integer too)


Output:


The program should print the minimum number of operations required for each operator separated by space to convert initial value into final value for each test case.

If number of operations for both multiplication and integer division are 0. Print No operation required.


Visible TestCases:


TestCase1: 2 marks
Input
1 1
Output:
No operation required.

TestCase2: 2 marks
Input
4 16
Output:
2 0

TestCase3: 2 marks
Input
5 32
Output:
4 1



Explanation:
TEST CASE1: Initial value and final value are same. No operation required.


TEST CASE2: Multiplying 4 two times by 2 gives 16, i.e., 4 * 2 = 8, 8 * 2= 16.  No need to half the value.


TEST CASE3: Division of 5 once gives 2. Multiply 2 four times by 2 gives 32.*/

// solution:

#include <stdio.h>

int main()
{
    long int a;
    long int b;
    scanf("%ld %ld", &a, &b);
    int mul = 0;
    int divi = 0;
    while (b % a != 0)
    {
        a = a / 2;
        divi++;
    }
    while (a != b)
    {
        a = a * 2;
        mul++;
    }
    if (mul == 0 && divi == 0)
    {
        printf("No operation required.");
    }
    else
    {
        printf("%d %d", mul, divi);
    }
    return 0;
}
