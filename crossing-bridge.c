/*[20 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  2 and 3 marks respectively for visible test cases

Hidden:  5  each for all hidden test cases



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% each for using any library other than stdio.h
-20% for using any built-in function

Crossing Bridges


On her adventures across some mysterious lands, Phos comes across a stream blocking her path. Fortunately, there are a number of makeshift bridges that could help her cross the stream. Let us consider one such bridge. This bridge consists of n stones arranged in a linear order from one riverbank to another. Each of these stones have a numeric value associated with them, which denotes how far you can jump if you are on that stone. For example if a stone has a value of 5 you can make a leap skipping upto the next 4 stones, landing directly on the fifth, although, you are allowed to make a shorter jump than that as well. If instead a stone has a value of 0 you can not move anywhere from that position.
Can you help Phos find which bridges will actually allow her to cross the stream and which won't?
(Note: You can assume that you start off standing on the first stone of the bridge and have crossed the river if you are standing on the final stone of the bridge)


INPUT:

The input consists of 2b+1 lines. The first line contains a single integer b denoting the number of bridges. Of the remaining 2b lines, each pair of lines describe a single bridge. The first of these two lines contains a single  integer n, denoting the length of the bridge. The next line contains n space separated integers denoting the numeric value associated with each stone of the bridge.


OUTPUT:

The output should consist of b lines.
For each bridge you have to print YES if the bridge can actually be crossed and NO otherwise.
The output for each bridge must be printed in a separate line.


CONSTRAINTS:

1 <= b <= 10
1 <= n <= 50


Example Input


2
5
1 1 1 0 1
5
1 1 2 0 1
Example Output


NO
YES*/

// solution:

#include <stdio.h>
void scan(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    return;
}
void func(int arr[], int n, int pos, int *flag)
{
    if (pos == n - 1)
    {
        *flag = *flag + 1;
        return;
    }
    if (pos >= n)
    {
        return;
    }
    if (pos < n - 1 && arr[pos] == 0)
    {
        return;
    }
    for (int i = 1; i <= arr[pos]; i++)
    {
        func(arr, n, pos + i, flag);
    }
}
int main()
{
    //  Insert your code here.
    int b;
    scanf("%d", &b);
    int arr[50];
    int n;
    for (int t = 0; t < b; t++)
    {
        scanf("%d", &n);
        scan(arr, n);
        int flag = 0;
        func(arr, n, 0, &flag);
        if (flag == 0)
        {
            printf("NO");
        }
        else
        {
            printf("YES");
        }
        if (t < b - 1)
        {
            printf("\n");
        }
    }
    return 0;
}