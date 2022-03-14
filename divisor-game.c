/*Automated Grading Scheme:

Visible: 1 marks for each visible test case.

Hidden: 6 marks for 1st, 2nd and 3rd test case.

Hidden: 6.5 marks for 4th test case.

Hidden: 7.5 marks for 5th, 6th and 7th test case.



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% for using any future concepts
-20% each for using any library function (string library) other than printf and scanf. So getline(), gets(), fgets(), etc. are not allowed at all.
-20% each for using any library other than stdio.h

--------------------------------------------------------------------------------------------------------------

 Divisor-Game


You are given a character array of N characters where each character belongs to either [A-Z] or [a-z].


You need to perform the following operation for all possible non-empty subarrays of array.



Find the number of subarrays in which the characters are arranged in increasing order of ASCII values.

Print the largest subarray in which the characters are arranged in increasing order of ASCII values.


Note: If two subarrays have the same length then the subarray which starts first will be selected. For example, in array "ABCABD", though "ABC" and "ABD" are of same length, "ABC" will be printed as it starts first.


Input Format:

The first line contains an integer N denoting the size of the array. The next line contains N characters without space denoting the elements of the array.


Ouput Format:

Print the number of sub arrays according to property 1 in first line and largest subarray in second line.


Sample Input:

3

abc


Sample Output

6

abc


Explanation

Our sub-arrays are: [a], [b], [c], [ab], [bc], [abc]

All subarrays are in increasing order of ASCII value.
The largest subarray is abc.*/

// solution:

#include <stdio.h>
int check(char str[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i + 1] <= str[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d\n", &n);
    char arr[n];
    char ans[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &arr[i]);
    }
    int count = 0;
    int max = 0;
    for (int size = 1; size <= n; size++)
    {
        for (int i = 0; i <= n - size; i++)
        {
            if (check(arr + i, size))
            {
                count++;
                if (size > max)
                {
                    max = size;
                    for (int j = 0; j < size; j++)
                    {
                        ans[j] = arr[i + j];
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    for (int x = 0; x < max; x++)
    {
        printf("%c", ans[x]);
    }
    return 0;
}