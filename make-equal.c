/*You are given two strings, find out minimum number of character deletions required to make two strings equal. You can delete any character from any string. Two strings are said to equal if every character of one string is also present in other string at any place. Example : "abc" and "cab" are equal strings.


Note : String contains lower case alphabets only. Size of string will be given by the user and use dynamic memory allocation.


Input Format : First two lines contain the size of the first string and the string itself. Next two lines contain the size of the second string and the string itself.


Output Format : Print minimum number of character deletions required to make the strings equal.


Public Test Cases

Input	Output
3
 cde
 3
 abc	4*/

// solution:

#include <stdio.h>
#include <stdlib.h>
int count(char c, char *str, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(str + i) == c)
        {
            cnt++;
        }
    }
    return cnt;
}
int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int n1;
    int n2;
    char *s1;
    char *s2;
    scanf("%d\n", &n1);
    s1 = (char *)malloc(n1 * sizeof(char));
    for (int i = 0; i < n1; i++)
    {
        scanf("%c", (s1 + i));
    }
    scanf("%d\n", &n2);
    s2 = (char *)malloc(n2 * sizeof(char));
    for (int i = 0; i < n2; i++)
    {
        scanf("%c", (s2 + i));
    }
    int del = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        int cnt1 = count(c, s1, n1);
        int cnt2 = count(c, s2, n2);
        if (cnt1 != cnt2)
        {
            del += max(cnt1, cnt2) - min(cnt1, cnt2);
        }
    }
    printf("%d", del);
}
