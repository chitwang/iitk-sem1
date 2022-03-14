/*A drone is floating in space. Its initial coordinates are (X,Y,Z). You send a series of C movement commands to the drone.There are 6 movement commands 1, 2, 3, 4, 5 and 6.


1--UP


For Example, if the drone is at (0,0,0), then after the command it will be at (0,0,1)


2--Down


For Example, if the drone is at (0,0,0), then after the command it will be at (0,0,-1)


3--North


For Example, if the drone is at (0,0,0), then after the command it will be at (1,0,0)


4--South


For Example, if the drone is at (0,0,0), then after the command it will be at (-1,0,0)


5--East


For Example, if the drone is at (0,0,0), then after the command it will be at (0,1,0)


6--West


For Example, if the drone is at (0,0,0), then after the command it will be at (0,-1,0)


Time Elapsed=0, just before the first command is issued.

Consider that each command takes 1 time unit to execute.

For Example, At Timestamp T=5 if the drone is at (1,5,3) and we issue the command 1(UP), then at Timestamp T=6 it will be at (1,5,4).


Given Q queries where each query is a timestamp t,  you will have to output the coordinate of the drone at each of the timestamps.


To sum up:
(X,Y,Z) is the initial position of the drone.
C is the number of commands issued
Q is the number of queries


Input Format:

The first line contains 5 space separated integers X, Y, Z, C, Q.

The second line contains C space separated integers describing the commands. Each of these C commands can be 1, 2, 3, 4, 5 or 6.

The third line contains Q space separated integers specifying the queries. Each of these Q queries specifies a timestamp t at which the coordinate of the drone is required. 0 ? t ? C.


Output:

Print Q lines corresponding to each of the Q queries.

In each line print 3 space separated integers a,b,c . Where (a,b,c) is the coordinate of the drone at the given timestamp.


Constraints:

1 <= N <= 200
1 <= Q <= 200


Example Input:

0 0 0 3 3

1 1 4

0 3 2


Example Output:

0 0 0

-1 0 2

0 0 2


Explanation:

At Timestamp T=0, position of Drone: (0,0,0)

At Timestamp T=1, position of Drone: (0,0,1)

At Timestamp T=2, position of Drone: (0,0,2)

At Timestamp T=3, position of Drone: (-1,0,2)*/

// solution:

#include <stdio.h>

int main()
{
    int X, Y, Z, C, Q;
    int c;
    int t;
    scanf("%d", &X);
    scanf("%d", &Y);
    scanf("%d", &Z);
    scanf("%d", &C);
    scanf("%d", &Q);
    int x[C + 2];
    int y[C + 2];
    int z[C + 2];
    x[0] = X;
    y[0] = Y;
    z[0] = Z;
    for (int i = 1; i <= C; i++)
    {
        scanf("%d", &c);
        if (c == 1)
        {
            Z++;
        }
        else if (c == 2)
        {
            Z--;
        }
        else if (c == 3)
        {
            X++;
        }
        else if (c == 4)
        {
            X--;
        }
        else if (c == 5)
        {
            Y++;
        }
        else if (c == 6)
        {
            Y--;
        }
        x[i] = X;
        y[i] = Y;
        z[i] = Z;
    }
    for (int j = 1; j <= Q; j++)
    {
        scanf("%d", &t);
        printf("%d %d %d", x[t], y[t], z[t]);
        if (j < Q)
        {
            printf("\n");
        }
    }
    return 0;
}