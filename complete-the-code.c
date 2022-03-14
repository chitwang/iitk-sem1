/*The code below is supposed to take an arbitrary number of integers from the input and calculate the mean of the numbers. You are supposed to complete the functions add_array() and get_mean() without changing the code given in the main function.



double get_mean(int *ptr,int n) - The function takes a pointer to the array, calculates the mean of the array, and returns the mean.

int *add_array(int *ptr, int n, int x) - The function creates a new array of size n+1, copies the contents of the original array denoted by ptr to the new array, appends the value x at the end of the new array (i.e., after copying), and returns the pointer to the new array. (Hint: Use malloc and free.)


You should not use statically allocated arrays for this question. You should allocate and free arrays using dynamic memory allocation and use pointers to reference the arrays.


You should not change the given function prototypes.


The main() function is as follows.


int main(){
    int *ptr = (int *)malloc(4);
    int d;
    scanf("%d", &d);
    ptr[0]=d;
    int n=1;
    while(scanf("%d",&d)) {
        if (d==-1) {
            break;
        }
         ptr = add_array(ptr,n,d);
         n++;
     }
     printf("%.2lf", get_mean(ptr,n));
     return 0;
}

Input Format: The input is an arbitrary number of integers separated by a single space. The sequence ends with -1. The input code is given in the main function snippet.


Output Format: The output is the mean. The output is rounded to two decimal places. The output code is given in the main function snippet.


Example

Input: 1 2 3 4 5 -1


Output: 3.00



Marking Scheme:
Public Test Case: 2 Marks
Hidden Test Case: 3 Marks

If given prototye functions are changed: Deduct 10 marks
If satically alloted arrays are used: Deduct 10 marks
*/

// solution:

#include <stdio.h>
#include <stdlib.h>
double get_mean(int *ptr, int n)
{
    double mean;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(ptr + i);
    }
    mean = sum / n;
    return mean;
}

int *add_array(int *ptr, int n, int x)
{
    int *new = (int *)malloc((n + 1) * (sizeof(int)));
    for (int i = 0; i < n; i++)
    {
        *(new + i) = *(ptr + i);
    }
    *(new + n) = x;
    return new;
}
int main()
{
    int *ptr = (int *)malloc(4);
    int d;
    scanf("%d", &d);
    ptr[0] = d;
    int n = 1;
    while (scanf("%d", &d))
    {
        if (d == -1)
            break;
        ptr = add_array(ptr, n, d);
        n++;
    }
    printf("%.2lf", get_mean(ptr, n));
    return 0;
}