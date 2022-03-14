/*You are given a string of lowercase characters (without any spaces). You have to compress the word using the method described below.

The basic idea is to compress multiple consecutive occurences of a character to a single character and a number specifying the occurences. So, for instance the substring aaaa gets compressed to a4. Note that if a character occurs only once (consecutively), then there is no need of compression.

For example, suppose the given string is aaaabbcdddeee. Then the compressed output using above method will be a4b2cd3e3. Your task is to read the word (in the format specified below) and output the compressed string.

Input Format

The input consists of a single line. The line is a string of lowercase letters ending with a period (.). Note that period is not the part of the word.

Output format

Output the compressed word as a single string.

Note

All the characters are lowercase alphabet except the last ..

There will be at least one letter in the word.

Examples

Sample 1

Input

aaaabbcdddeee.
Output

a4b2cd3e3*/

// solution:

#include <stdio.h>

int main()
{
    int count = 1;
    char prev;
    char curr;
    prev = getchar();
    curr = getchar();
    while (curr != '.')
    {
        if (curr == prev)
        {
            count++;
        }
        else
        {
            if (count != 1)
            {
                printf("%c%d", prev, count);
            }
            else
            {
                printf("%c", prev);
            }
            count = 1;
        }
        prev = curr;
        curr = getchar();
    }
    if (count != 1)
    {
        printf("%c%d", prev, count);
    }
    else
    {
        printf("%c", prev);
    }
    return 0;
}
