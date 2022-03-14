/*A robot is constrained to move along a one dimensional line. It receives input commands in the form of a stream of integers. A positive integer denotes that the robot must take that many steps towards +ve direction and  a negative integer denotes that the robot must take that many steps towards -ve direction. The robot starts at 0 and terminates its operations on encountering the integer -7. Also the robot is constrained to always remain between the positions -10 and +10. That is, say if the robot is already at +9 and it receives a command to go 3 steps in the positive direction, it will only go till +10 for that command.  You are supposed to find the final position of the robot.


Input Format

The first line has space separated integers terminated by a -7.


Output Format

A single integer, denoting the final position of the robot.


Sample Input

2 3 12 -4 -7
Sample Output

6
Explanation

First on encountering 2, the robot reaches the position 2.
Then on encountering 3, it reaches the position 5.
Then, on encountering 12, due the constraints on itself it only reaches 10.
Finally, on encountering -4, it reaches 6.
Then -7 command terminates the robot's operations cementing 6 as its final position.*/

// solution:

#include <stdio.h>

int main()
{
    int position = 0;
    int c;
    scanf("%d", &c);
    while (c != -7)
    {
        position = position + c;
        if (position > 10)
        {
            position = 10;
        }
        else if (position < -10)
        {
            position = -10;
        }
        scanf("%d", &c);
    }
    printf("%d", position);
    return 0;
}