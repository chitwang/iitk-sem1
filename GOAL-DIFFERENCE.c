/*Football is the most popular sport in the world. You have been asked by the Premier League head to calculate the goal difference for a span of three matches.

In the first line of input you are given an integer (say X) representing the team. You are then provided the scores of three matches of that team: a - b, c - d, and e - f, where a, c, and e represent goals scored by the team, and b, d, and f represent goals scored against them. You need to compute the goal difference: total goals scored by X minus the total goals scored against X, and output it as "Goal Difference for Team X: goal_difference".

Be careful of extra/missing spaces and extra/missing lines

Use the visible test cases to guide yourself

Goal difference can be negative

Sample Input 1:
2
3 - 1, 4 - 2, 5 - 3

Sample Output 1:
Goal Difference for Team 2: 6

Sample Input 2:
1
1 - 1, 0 - 0, 1 - 1

Sample Output 2:
Goal Difference for Team 1: 0

Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Hint: In order to scan integers from a line following a pattern, write the line inside the scanf and replace the integer value to %d. Eg, suppose input is given in the form '2-1, 3' and you can scan the three integers using scanf("%d-%d, %d",&a,&b,&c);*/

// SOLUTION

#include <stdio.h>

int main()
{
    //  Insert your code here.
    int X;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    scanf("%d", &X);
    scanf("%d - %d,", &a, &b);
    scanf("%d - %d,", &c, &d);
    scanf("%d - %d", &e, &f);
    printf("Goal Difference for Team %d", X);
    printf(": %d", a - b + c - d + e - f);
    return 0;
}