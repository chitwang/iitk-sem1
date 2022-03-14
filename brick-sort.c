/*There are several sorting algorithms that have been developed over the years. We saw some during the lectures and will explore others here. One simple algorithm is called Brick Sort. The algorithm got its name since it sorts alternating elements of the array in subsequent phases, so that the whole arrangement (see figure below) looks like bricks have been laid down. This variant was originally designed for parallel processing and may work very well on parallel computing architectures such as GPUs.


Brick sort proceeds in n phases. In the first phase, even indices of the array get compared to the element to their immediate right and if the pair is out of order (i.e. the element at the even index is strictly greater than the element to its immediate right), then the pair is swapped. In the second phase, odd indices of the array get compared (and swapped if out of order) to the element to their immediate right. The third phase again considers the even indices and so on. If the array has n elements, then the algorithm works for n phases. The array is guaranteed to be sorted at the end of the n-th phase.


The first line of the input will give you n, a strictly positive integer and the second line will give you n integers, separated by a space. Store these numbers in an array of size n. In your output, you have to print the array after each phase of brick sort, on a separate line. Print the array by printing each number in the array from left to right with two numbers separated by a single space. However, there should be no space at the end of a line.


Note

If the array has an odd number of elements, say 5, then the index 4 element will have no element to its right in the phases when even elements are being compared to the element to their immediate right (for example the first phase). So nothing will need to be done for index 4.


The n numbers we give you may be positive, negative or zero. The same number may occur twice in the list too.

The number of elements n can be any strictly positive number, even 1. Your output must have exactly n lines. There should be no trailing newline character after the last line.

Some phases may not require any work. However, you must still print the array after those phases.


Example Input

4
3 4 1 2
Example Output

3 4 1 2
3 1 4 2
1 3 2 4
1 2 3 4
Explanation

First phase
3 4 1 2 (Checking for swap between 3 & 4 - nothing to be done)
3 4 1 2 (Checking for swap between 1 & 2 - nothing to be done)
No other even index elements left.


Second phase
3 1 4 2 (Checking for swap between 4 & 1 - swap them)
No other odd index elements left.


Third phase
1 3 4 2 (Checking for swap between 3 & 1 - swap them)
1 3 2 4 (Checking for swap between 4 & 2 - swap them)
No other even index elements left.


Fourth phase
1 2 3 4 (Checking for swap between 3 & 2 - swap them)
No other odd index elements left.*/

// solution:

#include <stdio.h>
void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
void even(int arr[], int n)
{
    if (n % 2 != 0)
    {
        for (int i = 0; i <= n - 3; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
            }
        }
    }
    else
    {
        for (int i = 0; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
            }
        }
    }
}
void odd(int arr[], int n)
{
    if (n % 2 != 0)
    {
        for (int i = 1; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
            }
        }
    }
    else
    {
        for (int i = 1; i <= n - 3; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
            }
        }
    }
}
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int phase;
    for (phase = 1; phase <= n; phase++)
    {
        if (phase % 2 != 0)
        {
            even(arr, n);
        }
        else
        {
            odd(arr, n);
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d", arr[i]);
            if (i < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}