/*[100 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible: 2,3, and 5 marks for 1, 2 and 3 test case respectively

Hidden: 10 for each hidden test case



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% for using 1-D array/2-D array or any using any future concepts
-10% each for using any library function other than printf and scanf
-20% each for using any library other than stdio.h

----------------------------------------------------------------------
DINO WALK

Dino loves to walk during lab hours and visits various places. Each location has a unique code place@x@y where x,y are positive integers. There are some constraints that Dino has to respect in a walk.

He can neither visit nor cross barriers

He can only move to a location that is to his right, i.e, from place@i@j to place@i@j+1

He can only move if the location to his right has an equal or greater movability index than the previous location


Each location has a movability index which is a positive integer. If the movability index for a location is prime, then the place acts as a barrier.


A walk is represented as place@k@l → place@k@l+1 → ........... → place@k@m ,  where none of the places lying in this walk acts as a barrier and movability index of places are in non-decreasing order. The length of a walk is defined as the number of places in the walk (it is m-l+1 for the above example).


Dino is provided with a map which is represented as a matrix (MxN), where each entry in i row and j column of a matrix denotes the movability index of place@i@j.


Dino is interested in finding the walk with the maximum length for every row. The sum of lengths of these maximum length walks represents a HIGH score. As a pro-gamer (programmer) of the Dino Game, you have to calculate the HIGH score.


Input Format: The first line will contain M and N followed by M lines, where each line contains N integers.


Output format: A single integer representing the sum of the lengths of the maximum walk for each row.


Example Input:

3 5

1 2 4 8 16
1 3 7 15 31
2 3 5 17 11


Example Output:

4

Explanation:


Row ↓ /Col →	1	2	3	4	5
   1           	1	2	4	8	16
   2	        1	3	7	15	31
   3	        2	3	5	17	11
A bold places indicates a barrier(prime)


In Row 1:

place@1@2 will acts as a barrier. In this row, there are 7 walks possible.


Walk 1 : place@1@1 (length : 1)

Walk 2 : place@1@3 (length : 1)

Walk 3 : place@1@4 (length : 1)

Walk 4 : place@1@5 (length : 1)

Walk 5 : place@1@3 → place@1@4 (length : 2)

Walk 6 : place@1@4 → place@1@5 (length : 2)

Walk 7 : place@1@3 → place@1@4 → place@1@5 (length : 3)


Walk 7 has maximum length which is 3.


In Row 2:

Two walks are possible:


Walk 1: place@2@1

Walk 2: place@2@4


Both walks have length 1. So, walk with maximum length is 1.


In Row 3:

There are no walks in Row3 since all places have prime movability index.


Answer:

So, Higher Score = 3(for row 1) + 1 (for row 2) + 0 = 4*/

// solution:

#include <stdio.h>

int main()
{
    int ans = 0;
    int m;
    int n;
    scanf("%d %d", &m, &n);
    int curr;
    for (int i = 0; i < m; i++)
    {
        int prev = 0;
        int maxlen = 0;
        int len = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &curr);
            int count = 0;
            for (int p = 1; p <= curr; p++)
            {
                if (curr % p == 0)
                {
                    count++;
                }
            }
            if (count == 2)
            {
                len = 0;
                prev = 0;
                continue;
            }
            else
            {
                if (curr >= prev)
                {
                    len++;
                }
                else
                {
                    len = 1;
                }
            }
            if (len > maxlen)
            {
                maxlen = len;
            }
            prev = curr;
        }
        ans = ans + maxlen;
    }
    printf("%d", ans);
}