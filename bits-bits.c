/*In the input, you will be given a strictly positive integer K denoting the length of the strings you have to print. In your output, on each line, you have to print a string of length K using only the characters '0' and '1' (without quotes). The strings must be printed in lexicographically increasing order i.e. if you think of these strings as numbers, the numbers should appear in increasing order.


The only property these strings must satisfy is that no two consecutive characters in the strings you generate can be the character '0'. Two or more consecutive characters can be '1' but two consecutive characters cannot be '0'.


Note

The first character in the string can freely be 0 or 1 since there is no previous character to cause consecutive 0. However, second character onwards, we must have a 0 only if the previous character was not 0 to avoid consecutive 0.
Be sure to print all leading 0 in the output. Every string you print must contain k characters.


There should be no extra spaces anywhere. There  MUST  be a trailing newline after the last string printed.


Example Input

2
Example Output

01
10
11
Explanation

00 is an illegal string.*/

// solution:

#include <stdio.h>
#include <math.h>
void func(int n, int k)
{
    int t = n;
    int bin[32];
    int i = 0;
    while (i < k)
    {
        bin[i] = t % 2;
        t /= 2;
        i++;
    }
    int flag = 0;
    for (int j = 0; j < i - 1; j++)
    {
        if (bin[j] == 0 && bin[j + 1] == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            printf("%d", bin[j]);
            if (j == 0)
            {
                printf("\n");
            }
        }
    }
}
int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 1; i < (pow(2, k)); i++)
    {
        func(i, k);
    }
    return 0;
}