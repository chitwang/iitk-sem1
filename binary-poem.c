/*A Noob-Robot is asking from you to write a program to print a binary poem which consists of only 1's and 0's.
You're given a number N. And, your task is print all string of length 2*N which consists of N 1's and N 0's in lexico-graphical order.


A string S is lexicographically smaller than another string T if S comes before T in the dictionary.
For e.g
if S = "1001" and T = "1010" then S is lexicographically smaller than T.
if S = "10" and T = "01" then T is lexicographically smaller than S.


Input Format

A single line containing an integer N.


Output Format

Print all strings of length 2*N which consist of N 1's and N 0's in lexico-graphical order.


Example Input

3


Example Output

000111
001011
001101
001110
010011
010101
010110
011001
011010
011100
100011
100101
100110
101001
101010
101100
110001
110010
110100
111000*/

// solution:

#include <stdio.h>
#include <stdlib.h>
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", *(arr + i));
    }
    printf("\n");
}
void recursion(int n, int *arr, int one, int zero)
{
    int x = one + zero;
    if (one == n && zero == n)
    {
        print(arr, x);
        return;
    }
    if (one < n && zero < n)
    {
        *(arr + x) = 0;
        recursion(n, arr, one, zero + 1);
        *(arr + x) = 1;
        recursion(n, arr, one + 1, zero);
        return;
    }
    if (one < n && zero == n)
    {
        *(arr + x) = 1;
        recursion(n, arr, one + 1, zero);
        return;
    }
    if (zero < n && one == n)
    {
        *(arr + x) = 0;
        recursion(n, arr, one, zero + 1);
        return;
    }
    if (zero > n || one > n)
    {
        return;
    }
}
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(2 * n * sizeof(int));
    recursion(n, arr, 0, 0);
    return 0;
}