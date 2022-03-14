/*You are given a number N. And, your task is print all string of length 2*N which consist of N opening and N closing parentheses in lexico-graphical order.


Input Format

A single line containing an integer N.


Output Format

Print all strings of length 2*N which consist of N opening and N closing parentheses in lexico-graphical order.


Example Input

3


Example Output

((()))
(()())
(())()
()(())
()()()*/

// solution:

#include <stdio.h>
void func(int n, char arr[], int up, int down)
{
    int x = up + down;
    if (down == n)
    {
        for (int i = 0; i < x; i++)
        {
            printf("%c", arr[i]);
        }
        printf("\n");
        return;
    }
    if (up > down && up < n)
    {
        arr[x] = '(';
        func(n, arr, up + 1, down);
        arr[x] = ')';
        func(n, arr, up, down + 1);
        return;
    }
    if (up > down && up == n)
    {
        arr[x] = ')';
        func(n, arr, up, down + 1);
    }
    if (up > n)
    {
        return;
    }
    if (up == down)
    {
        arr[x] = '(';
        func(n, arr, up + 1, down);
        return;
    }
    if (down > up)
    {
        return;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    char arr[2 * n];
    func(n, arr, 0, 0);
}