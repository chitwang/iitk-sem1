/*You are given three strings s1, s2and s3 as input. You need to replace all the occurrences of s2 in s1 by s3. Print the string s1 unchanged if s2 does not occur in s1 even once.


Input Format:


Three lines of input each of them are of the form "n s" where n is size of the input string s.


Output Format:


The new string s1 after replacement.


Example

Input:

18 abcxyzdefxyzghixyz

3 xyz

2 uv


Output:

abcuvdefuvghiuv


Explanation:
s2 occurs in s1 at index 3, 9, 15. We replace the respective xyz by uv.


Public Test Cases

Input	Output
18 abcxyzdefxyzghixyz
 3 xyz
 2 uv	abcuvdefuvghiuv*/

// solution:

#include <stdio.h>
#include <stdlib.h>

void replace(char str[], char oldstr[], char newstr[], int n1, int n2, int n3)
{
    int arr[n1];
    char *result;
    int count = 0;
    for (int i = 0; i < n1; i++)
    {
        int j;
        for (j = 0; j < n2; j++)
        {
            if (str[i + j] != oldstr[j])
            {
                break;
            }
        }
        if (j == n2)
        {
            arr[count] = i;
            i = i + n2 - 1;
            count++;
        }
    }
    int len = n1 + (n3 - n2) * count;
    result = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < n1; i++)
    {
        int j;
        for (j = 0; j < n2; j++)
        {
            if (str[i + j] != oldstr[j])
            {
                break;
            }
        }
        if (j == n2)
        {
            for (int x = 0; x < n3; x++)
            {
                printf("%c", newstr[x]);
            }
            i = i + n2 - 1;
        }
        else
        {
            printf("%c", str[i]);
        }
    }
}
int main()
{
    int n1;
    int n2;
    int n3;
    scanf("%d", &n1);
    getchar();
    char s1[n1];
    for (int i = 0; i < n1; i++)
    {
        scanf("%c", &s1[i]);
    }
    scanf("%d", &n2);
    getchar();
    char s2[n2];
    for (int i = 0; i < n2; i++)
    {
        scanf("%c", &s2[i]);
    }
    scanf("%d", &n3);
    getchar();
    char s3[n3];
    for (int i = 0; i < n3; i++)
    {
        scanf("%c", &s3[i]);
    }
    replace(s1, s2, s3, n1, n2, n3);
}