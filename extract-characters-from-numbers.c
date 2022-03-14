/*We know that an int variable occupies 4 bytes of space whereas a char variable occupies 1 byte. Therefore, one integer variable has the capacity to store four chracter values in it. Given an integer value n, extract and print the 4 characters in it. The extraction is done as follows. The binary representation of n has 32 bits. These are divided into 4 segments of 8 bits (1 byte) each and each byte is treated as the ASCII value of the character it represents. These characters are to be printed.


Note: It is guaranteed that the number n is given in such a way that the characters extracted are always alphabets or digits.


Input Format:
A positive integer n.


Output Format:
The 4 characters extracted from the binary representation of n with no separators.


Example

Input:
1094861636


Output:
ABCD


Explanation:
Binary representation of 1094861636 is 01000001010000100100001101000100. Separating it as 4 segments of 8 bits each, we get 01000001 = 65,  01000010 = 66, 01000011 = 67, 01000100 = 68. These values represent A, B, C and D respectively by the ASCII mapping.


Public Test Cases

Input	Output
1094861636	ABCD*/

// solution:

#include <stdio.h>
int power(int a, int b)
{
    int p = 1;
    for (int i = 0; i < b; i++)
    {
        p = p * a;
    }
    return p;
}

int main()
{
    //  Insert your code here.
    long int n;
    scanf("%ld", &n);
    int brr[32];
    int count = 0;
    int arr[32];
    while (n != 0)
    {
        arr[count] = (n % 2);
        n = n / 2;
        count++;
    }
    for (int i = 0; i < (32 - count); i++)
    {
        brr[i] = 0;
    }
    for (int i = (32 - count), j = 0; i < 32; i++)
    {
        brr[i] = arr[count - 1 - j];
        j++;
    }
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < 32; i++)
    {
        int x = (i % 8);
        if (i < 8)
        {
            a = a + (brr[i] * power(2, (7 - x)));
        }
        else if (i < 16)
        {
            b = b + (brr[i] * power(2, (7 - x)));
        }
        else if (i < 24)
        {
            c = c + (brr[i] * power(2, (7 - x)));
        }
        else
        {
            d = d + (brr[i] * power(2, (7 - x)));
        }
    }
    printf("%c%c%c%c", a, b, c, d);
}