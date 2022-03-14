/*You are given an array of integers. Let us call it row A .You need to write a program to verify whether A is an even row.
A row is said to be even if it has even number of even numbers. 0 is an even number and extend the definition of even numbers to negative integers also.


Input Format:


The first line of input contains the size n of the array. The next line of input contains the contents of the array.


Output Format:


You must output "Yes" or "No" in a separate line for each test case. Output "Yes" if the corresponding test case holds the required property else print "No".


Note:


You should not use statically allocated arrays for this question. You should allocate and free space using dynamic memory allocation and use only pointers referencing and dereferencing to access the array. Do not use array subscripting in your program.

You should define a function void scan_array(int *arr, int n) for scanning the array.

You should define a function int cnt(int *arr, int n) for finding the answer.


Example

Input:

4

1 2 3 4


Output:

Yes*/

// solution:

#include <stdio.h>
void scan_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
}
int cnt(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((*(arr + i)) % 2 == 0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    int arr[n];
    scan_array(arr, n);
    int x = cnt(arr, n);
    if (x % 2 == 0)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}