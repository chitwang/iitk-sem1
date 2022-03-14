/*[100 Points]

----------------------------------------------------------------------
Automated Grading Scheme:
Public Test Cases (5 point each. 2*5 = 10 points)
Hidden Test Cases (90 points)
Test Case number 1 is of 10 marks
Test Case number 2 to 3 are of 15 marks each
Test Case number 4 is of 20 marks
Test case number 5 is of 10 marks
Test case number 6 is of 20 marks

Grading Scheme:
Note: No marks should be awarded for test-cases passing on hardcoding
Penalty: -20% for using 1-D array/2-D array or any Future concepts
Penalty: -20% each for using any library other than stdio.h
----------------------------------------------------------------------------------------------
Trial of the Troll

Lyza is an esteemed adventurer who loves exploration. Once during another one of her escapades, she came across a troll blocking her way. The troll presents her with the following riddle and refuses passage until the riddle is solved.


You are given two square Matrices the same size. You have to find whether the trace of the first matrix is equal to the product of each element along the “anti-diagonal” of the second matrix.



Anti-diagonals are defined for square matrices only.

For a square matrix of size N, the anti-diagonal consists of the (N+1-i)-th element of the i-th row for each i between 1 and N.


Despite being adept at conducting expeditions, Lyza is not very good at solving Math problems and hence asks for your help to overcome this challenge.


Input Format

The 1st line contains an integer N. (Both matrices are of size N x N).
The next N lines contain N space separated integers each where the j-th integer at the i-th row corresponds to the (i,j)-th element of the first matrix.
The next N lines contain N space separated integers each where the j-th integer at the i-th row corresponds to the (i,j)-th element of the second matrix


Output Format:

If the required condition holds, print YES (in capital letters) in the first line. In the next line, print the trace of the first matrix, which is also equal to the product found for the second matrix.
If the required condition does not hold, print NO (in capital letters) in the first line. In the next line, print the trace of the first matrix, followed by the product found for the second matrix separated by a space.




Sample Test Cases

Input 1

4
2 3 4 1
5 3 2 1
6 4 3 3
2 3 1 7
2 6 -3 4
-2 -12 12 0
3 8 -5 4
1 3 2 4
Output 1:

NO
15 384
Input 2

3
5 3 1
5 3 2
6 1 4
2 -8 4
11 3 4
1 7 5
Output 2:

YES
12*/

// solution:

#include <stdio.h>

int main()
{
    int N;
    int a;
    int trace = 0;
    int product = 1;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &a);
            if (i == j)
            {
                trace = trace + a;
            }
        }
    }
    for (int p = 1; p <= N; p++)
    {
        for (int q = 1; q <= N; q++)
        {
            scanf("%d", &a);
            if (q == N + 1 - p)
            {
                product = product * a;
            }
        }
    }
    if (trace == product)
    {
        printf("YES\n");
        printf("%d", trace);
    }
    else
    {
        printf("NO\n");
        printf("%d %d", trace, product);
    }
    return 0;
}