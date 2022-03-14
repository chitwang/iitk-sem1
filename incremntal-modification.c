/*Given an array A of N integers and M increment operations, you must print the final state of the array after all operations.


An increment operation takes two arguments - a pointer to an array element and an integer value and it increments the array element by this value. This operation must be implemented using a void function, whose template is given. Do not modify the arguments of the template, you are supposed to fill in the code for the function body only.


#include

void Increment( int *p1, int delta){
    // Insert your code here. DO NOT modify the arguments of the function.

}

int main(){
    // Insert your code here.
    return 0;
}
Given an index i and a value delta, you must increment A[i] by d by passing the pointer of this array element to the void function.


Input Format:
First line contains N and M, where N is the size of integer array A and M is the number of increment operations.
Second line contains N integers of the array A.
Each of the next M lines contain an index i and an integer value delta corresponding to the increment of A[i] by value delta.


Constraints:
1 < N < 10000
1 < M < 100


Output Format:
You must print N comma separated integers corresponding to the final array A after all M increment operations.


Public Test Cases

Input	Output
5 2
 9 5 6 0 3
 0 -4
 2 2	5,5,8,0,3*/

// solution:

#include <stdio.h>

void Increment(int *p1, int delta)
{
    // Insert your code here. DO NOT modify the arguments of the function.
    *p1 = *p1 + delta;
}

int main()
{
    // Insert your code here.
    int N;
    int M;
    int x;
    int d;
    scanf("%d %d", &N, &M);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &d);
        Increment((arr + x), d);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d", arr[i]);
        if (i < N - 1)
        {
            printf(",");
        }
    }
    return 0;
}