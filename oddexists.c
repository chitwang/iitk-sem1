/*Write a program that checks if there exists an odd integer in an array of integers.


Input Format:
The first line of input contains the size n of the array. Then n lines of input follow giving the contents of the array.


Output Format:
You must output Yes or No if there exits an element with the desired property or not respectively in the given array


Variable Constraints:
The size of the array is smaller than 20.
The contents of the array  are integers in the range from -32768 to 32767.


Sample Input 1:
5

2 3 4 6 102


Sample Output 1:
Yes


Sample Input 2:
3

74 18 64


Sample Output 2:
No*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    int arr[20];
    int flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 != 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("No");
    }
    else if (flag == 1)
    {
        printf("Yes");
    }
    return 0;
}