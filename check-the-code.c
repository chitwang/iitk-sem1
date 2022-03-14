/*You are given a three-letter word (the 3 letters will be distinct from each other), after which a string of letters follow. Determine whether the three-letter word is present in the string or not. Note that all letters are uppercase alphabets and print the location of the first occurence.

Input Format

The first line contains three letters (uppercase) without spacing.

The next line contains a single integer n.

The third line contains a string of n uppercase alphabet without spacing.

Output format

Print a single integer as the location of the first occurence of the code (the first letter) in the string if it exists.

(Consider the first letter to be at location 1.)

Print -1 if the code is not present.

Note

All the characters are uppercase alphabet.

n will be at least 3.

HINT: You might need to read extra characters (new line etc.)

Examples

Sample 1

Input

ESC
19
ILOVEESCPROGRAMMING
Output

6*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    char a;
    char b;
    char c;
    char c1;
    int temp;
    int flag = 0;
    int count = 0;
    scanf("%c", &a);
    scanf("%c", &b);
    scanf("%c", &c);
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        scanf("%c", &c1);
        if (count == 0)
        {
            if (c1 == a)
            {
                count++;
                temp = i;
            }
        }
        else if (count == 1)
        {
            if ((i == temp + 1) && c1 == b)
            {
                count++;
            }
            else if ((i == temp + 1) && c1 == a)
            {
                count = 1;
                temp = temp + 1;
            }
            else
            {
                count = 0;
            }
        }
        else if (count == 2)
        {
            if ((i == temp + 2) && c1 == c)
            {
                flag = 1;
                break;
            }
            else if (i == temp + 2 && c1 == a)
            {
                count = 1;
                temp = temp + 2;
            }
            else
            {
                count = 0;
            }
        }
    }
    if (flag == 0)
    {
        printf("-1");
    }
    else if (flag == 1)
    {
        printf("%d", temp);
    }
    return 0;
}