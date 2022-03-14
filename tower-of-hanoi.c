/*You have 3 stacks and N disks of unequal radii. Initially, all the N disks are placed on a singe stack such that if a disk is on top of another disk, it has a smaller radius than the disk below it. Your task is to find the minimum number of moves in which all N disks can be moved to a separate stack such that the following conditions are always obeyed.



A disk cannot be placed above a disk smaller than itself.

You can only move the uppermost disk on any stack.


Input Format

A single line containing an integer N.


Output Format

A single line containing the single integer output, denoting the minimum number of moves required to accomplish the task.


Example Input

3


Example Output

7*/

// solution:

#include <stdio.h>
static int count = 0;
void hanoirecursion(int n)
{
    if (n == 1)
    {
        count++;
        return;
    }
    hanoirecursion(n - 1);
    count++;
    hanoirecursion(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoirecursion(n);
    printf("%d", count);
    return 0;
}