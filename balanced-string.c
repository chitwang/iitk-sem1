/*[100 Points]

----------------------------------------------------------------------
Grading Scheme:
Visible Testcase: Testcase 1st and 2nd are of 5 marks each, and Testcase 3rd of 10 marks
Hidden Testcase: 20 marks each
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Using future concepts will deduct 20% marks
Using other header files except stdio.h will lead to penalize 20% marks

Write code recursively, otherwise, 0 marks will be given.

lexicographic order

A string S is lexicographic smaller than another string T, such that for smallest i where S[i] != T[i] condition S[i] < T[i] must hold. where S[i] denotes the i-th character of S, and T[i] denotes the i-th character of T. Here, lengths of S and T are equal.


Note : '(' < ')' < '{' < '}' for lexicographic order.


Problem Statement

You have to generate all balanced string of parenthesis & curly braces of length 2n + 2m in lexicographic order.


Definition of balanced string

String with length 0 is always balanced.


A balanced string S of length 2n + 2m is consisting of n pairs of parentheses and m pairs of curly braces, such that the number of opening parentheses ( is equal to the number of closing parentheses ) and number of opening curly bracket { is equal to number of closing curly bracket }. And, for every opening bracket there is a matching closing bracket such that subtring(may be with length 0) of S between these brackets is balanced.


for example, "({})" ,"{({}())}",, "{}(()())" , "{}{}", "(){()} are some example of balanced parentheses string. while "){}(", "}((()", "(({)}))", "}()(){", "{({}{(}))} are not balanced parentheses string.


Input Format

The first line contains two whole numbers n and m.


Output Format

Print all the balanced strings of length 2n + 2m in lexicographic order.
Note: Don't forget to print newline character after last string.


Example Input1

3 0


Example Output1

((()))
(()())
(())()
()(())
()()()
Example Input2

1 1


Example Output2

1 1
(){}
({})
{()}
{}()
*/

// solution:

#include <stdio.h>
char check(char c)
{
    if (c == '(')
    {
        return ')';
    }
    if (c == '{')
    {
        return '}';
    }
    return -1;
}
int tester(char str[], int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 0;
    }
    if (str[0] == ')' || str[0] == '}')
    {
        return 0;
    }
    char closing = check(str[0]);
    int i = 0;
    int count = 0;
    for (i = 1; i < n; i++)
    {
        if (str[i] == str[0])
        {
            count++;
        }
        if (str[i] == closing)
        {
            if (count == 0)
            {
                break;
            }
            count--;
        }
    }
    if (i == n)
    {
        return 0;
    }
    if (i == 1)
    {
        return tester(str + 2, n - 2);
    }
    return tester(str + 1, i - 1) && tester(str + i + 1, n - i - 1);
}
void func(int n, int m, int op, int cl, int up, int down, char arr[])
{
    int x = up + down + op + cl;
    // printf("x=%d m=%d n=%d down=%d cl=%d up=%d op=%d\n",x,m,n,down,cl,up,op);
    if (down == m && cl == n && up == m && op == n)
    {
        if (tester(arr, x) == 1)
        {
            for (int e = 0; e < (up + down + op + cl); e++)
            {
                printf("%c", arr[e]);
            }
            printf("\n");
        }
        return;
    }
    if (down > up || cl > op || up > m || op > n)
    {
        return;
    }
    if (up >= down && up <= m && op >= cl && op <= n)
    {
        arr[x] = '(';
        func(n, m, op + 1, cl, up, down, arr);
        arr[x] = ')';
        func(n, m, op, cl + 1, up, down, arr);
        arr[x] = '{';
        func(n, m, op, cl, up + 1, down, arr);
        arr[x] = '}';
        func(n, m, op, cl, up, down + 1, arr);
    }
    else if (cl == n && down < m)
    {
        if (up < m)
        {
            arr[x] = '{';
            func(n, m, op, cl, up + 1, down, arr);
            arr[x] = '}';
            func(n, m, op, cl, up, down + 1, arr);
        }
        else
        {
            arr[x] = '}';
            func(n, m, op, cl, up, down + 1, arr);
        }
    }
    else if (down == m && cl < n)
    {
        if (op < n)
        {
            arr[x] = '(';
            func(n, m, op + 1, cl, up, down, arr);
            arr[x] = ')';
            func(n, m, op, cl + 1, up, down, arr);
        }
        else
        {
            arr[x] = ')';
            func(n, m, op, cl + 1, up, down, arr);
        }
    }
}
int main()
{
    // Insert your code here.
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int _ = 2 * n + 2 * m;
    char arr[_];
    func(n, m, 0, 0, 0, 0, arr);
    return 0;
}