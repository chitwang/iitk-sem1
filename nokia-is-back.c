/*You have one of the old Nokia phones. The keypad consists of the following mapping of buttons to letters.


2 : ABC
3 : DEF
4 : GHI
5 : JKL
6 : MNO
7 : PQRS
8 : TUV
9 : WXYZ

You are given a sequence of numbers from 2 to 9. You need to print all strings possible by typing those buttons. Print the strings in the lexicographical order. For example, for the input string "35", the strings are :


DJ, DK, DL, EJ, EK, EL, FJ, FK, FL

The number 3 corresponds to alphabets D, E, and F. 5 corresponds to J, K, and L. So all 2 length strings with the first letter among "DEF" and the second letter among "JKL" are valid.


Input

The first line contains a single integer n.
 The second line contains n characters, each among {2,3,4,5,6,7,8,9}.


Output

In each separate line, print all valid strings in lexicographic order.


Sample Input

2
23

Sample Output

AD
AE
AF
BD
BE
BF
CD
CE
CF

Sample Explanation

2 coresponds to "ABC" and 3 corresponds to "DEF"*/

// solution:

#include <stdio.h>
#include <stdlib.h>
struct keypad
{
    int num;
    char str[4];
};
void func(char ans[], int n, int i, struct keypad arr[], int brr[])
{
    if (i == n)
    {
        for (int x = 0; x < n; x++)
        {
            printf("%c", ans[x]);
        }
        printf("\n");
        return;
    }
    int z = brr[i] - 2;
    for (int j = 0; j < arr[z].num; j++)
    {
        ans[i] = arr[z].str[j];
        func(ans, n, i + 1, arr, brr);
    }
}
int main()
{
    //  Insert your code here.
    struct keypad arr[8];
    char ch = 'A';
    for (int i = 0; i < 8; i++)
    {
        if (i == 5 || i == 7)
        {
            arr[i].num = 4;
        }
        else
        {
            arr[i].num = 3;
        }
        for (int j = 0; j < arr[i].num; j++)
        {
            arr[i].str[j] = ch;
            // printf("%c" , arr[i].str[j]);
            ch++;
        }
    }
    int n;
    scanf("%d\n", &n);
    int brr[n];
    char dummy;
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &dummy);
        brr[i] = (int)(dummy - '0');
    }
    char ans[n];
    func(ans, n, 0, arr, brr);
    return 0;
}