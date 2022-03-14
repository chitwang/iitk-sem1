/*[100 Points]

----------------------------------------------------------------------
Grading Scheme:
For visible Testcases: 5 marks each
For hidden Testcases: testcase2 of 15 marks and remaining all Testcases of 10 marks

Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Using future concepts will deduct 20% marks
Using other header files except stdio.h will lead to penalize 20% marks


Write code recursively, otherwise, 0 marks will be given.

Problem

John loves playing games and solving tough mathematical problems. Knowing this, his brother Rick decided to give him the following riddle to solve.


You are given N stones and a number K. Your task involves making a division of the N stones into heaps of stones such that is satisfies the following properties:



The sum of the number of stones in all heaps must equal N, i.e., no stone can be left unused.

Each heap must have at least K stones in it.


You have to then find the number of such divisions possible.


For example: For the case N=10 and K=3 we can divide N stones as follows:


10 = 3 + 3 + 4
   = 3 + 7
   = 4 + 6
   = 5 + 5
   = 10
So the answer in this case would be 5.


Can you help John solve this problem?


Constraints

It is guaranteed that at least 1 division will be possible for each input. Also, N >= K >=1


Input Format

The 1st line contains two space separated integers N and K.


Output Format:

On a single line, print the number of possible partitions.
*/

// solution:

#include <stdio.h>
void recursive(int in, int s, int *count, int istart)
{
    if (in == s)
    {
        *count = *count + 1;
        return;
    }
    if (in > s)
    {
        return;
    }
    for (int i = istart; i <= s; i++)
    {
        istart = i;
        recursive(in + i, s, count, istart);
    }
}
int main()
{
    //  Insert your code here.
    int n;
    int k;
    scanf("%d %d", &n, &k);
    int count = 0;
    recursive(0, n, &count, k);
    printf("%d", count);
    return 0;
}