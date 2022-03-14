/*[31 Points]
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Automated Grading Scheme:

Visible: 1 marks for each visible test case.

Hidden: 2 marks for 1, 2 and 3 test case.

Hidden: 3 marks for 7 and 8 test case.

Hidden: 4 marks for 4, 5, 6 and 9 test case.



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% for using strings, arrays, or array indexing to solve this problem,or any future concepts
-20% each for using any library function (string library) other than printf and scanf
-20% each for using any library other than stdio.h

---------------------------------------------------------------------
Decode Numbers


You were taught about the binary and hexadecimal representations in the lectures about the ASCII codes. It is also possible to have numbers represented with bases other than the powers of two.


Let us say that you want to represent a number with the base 17. Any integer can be uniquely represented as: an17n-1 + an-117n-2 + ... + a1*170, where for each ai, 0 <= ai < 17


In the hexadecimal representation, we represented 10 by A, 11 by B, ..., and 15 by F. Similarly, in our base 17 representation we can represent 1-15 as we did in the hexadecimal representation, and represent 16 by G.


Using this scheme we can represent any number to any base in the range 2-20 (even larger bases are possible, but we are going to restrict to 20). You are given a base and a number represented with the base. Your job is to convert the number to its decimal representation or print "INVALID" if it is not possible to do the same.


It may not always be possible to construct the decimal representation of a given number as it may contain characters, which should not be part of the representation. For instance, let us say that you are asked to convert "1012" base 2 to its decimal representation. It is not possible to do so as 2 is >= 2, and the representation of a number base k should contain characters from 0 to (k-1) only. Similarly, if you are asked to convert "ABC" base 12 to its decimal representation, it is not possible to do so as it contains C which represents 12, which is equal to the base. For such cases, you should print "INVALID".


You need not worry about integer overflow issues as the inputs are small enough to fit inside the integer datatype.


Constraints

You are not allowed to use strings, arrays, or array indexing to solve this problem, you can only scan the input character by character.


Input:



The first line contains an integer from 2-20 which is to be interpreted as the base of the number.

The second line contains the number of characters in the following representation.

The third line contains as many characters as given in the previous input. Each of these characters can be either uppercase English letters or numbers from 0-9.


Output:



Your program should print the decimal representation of the number given in the third line


Sample TestCases

Test Case 1

Input:

2
4
1010

Output:

10

Explanation: "1010" can be converted to its decimal representation as 1(2^3) + 0(2^2) + 1(2^1) + 0(2^0) = 8 + 0 + 2 + 0 = 10


Test Case 2

Input:

12
4
AB10

Output:

18876

Explanation: "AB10" can be converted to its decimal representation as 10(12^3) + 11(12^2) + 1(12^1) + 0(12^0) = 17280 + 1584 + 12 + 0 = 18876


Test Case 3

Input:

17
4
ABHE

Output:

INVALID

Explanation: "ABHE" contains the character H, which expands to 17 in the scheme described above, and it cannot be in a number represented to the base 17.*/

// solution:

#include <stdio.h>

int main()
{
    int b;
    int n;
    char c;
    int decimal = 0;
    int flag = 0;
    scanf("%d", &b);
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        scanf("%c", &c);
        if (c <= '9' && c >= '0')
        {
            if (c - 48 >= b)
            {
                flag = 1;
                break;
            }
            else
            {
                int p = (c - 48);
                for (int count = 1; count <= n - i; count++)
                {
                    p = p * b;
                }
                decimal = decimal + p;
            }
        }
        else if (c >= 'A' && c <= 'Z')
        {
            if (c - 55 >= b)
            {
                flag = 1;
                break;
            }
            else
            {
                int q = 1;
                int g = c - 55;
                for (int count = 1; count <= n - i; count++)
                {
                    q = q * b;
                }
                q = q * g;
                decimal = decimal + q;
            }
        }
    }
    if (flag == 0)
    {
        printf("%d", decimal);
    }
    else if (flag == 1)
    {
        printf("INVALID");
    }
    return 0;
}