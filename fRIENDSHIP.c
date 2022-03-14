/*There are four friends Abhay, Aditya, Akhilesh, and Atin standing at different points on a 2-D plane. Abhay is standing at (xA, yA), Aditya at (xB, yB), Akhilesh at (xC, yC), and Atin at (xD, yD). The strength of the friendship between any two friends is inversely proportional to the distance between the points where they are standing. Find the two friends whose friendship is the strongest. It is guaranteed that the pair will be unique.

The distance between two points (x1, y1) and (x2, y2) is calculated as |x2-x1|+|y2-y1|.

Input: Eight integers in the order xA, yA, xB, yB, xC, yC, xD, and yD.

Output: Print in alphabetical order the names of the two friends whose friendship is the strongest. Print the two names in a single line, separated by a single space.

Sample Input 1:
1 1 2 2 4 4 8 8

Sample Output 1:
Abhay Aditya

Sample Input 2:
-8 2 -2 8 -1 9 -4 6

Sample Output 2:
Aditya Akhilesh

Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");

Hint: Try to find the distance between each pair of friends and compare these distances. There will be 6 such pairs.*/

// SOLUTION

#include <stdio.h>
#include <math.h>
int main()
{
    int xA, yA, xB, yB, xC, yC, xD, yD;
    int rab, rbc, rac, rad, rbd, rcd;
    scanf("%d", &xA);
    scanf("%d", &yA);
    scanf("%d", &xB);
    scanf("%d", &yB);
    scanf("%d", &xC);
    scanf("%d", &yC);
    scanf("%d", &xD);
    scanf("%d", &yD);
    rab = sqrt((xB - xA) * (xB - xA)) + sqrt((yB - yA) * (yB - yA));
    rbc = sqrt((xB - xC) * (xB - xC)) + sqrt((yB - yC) * (yB - yC));
    rac = sqrt((xC - xA) * (xC - xA)) + sqrt((yC - yA) * (yC - yA));
    rad = sqrt((xD - xA) * (xD - xA)) + sqrt((yD - yA) * (yD - yA));
    rbd = sqrt((xB - xD) * (xB - xD)) + sqrt((yB - yD) * (yB - yD));
    rcd = sqrt((xC - xD) * (xC - xD)) + sqrt((yC - yD) * (yC - yD));
    if ((rab < rbc) && (rab < rac) && (rab < rad) && (rab < rbd) && (rab < rcd))
    {
        printf("Abhay Aditya");
    }
    else if ((rac < rbc) && (rab > rac) && (rac < rad) && (rac < rbd) && (rac < rcd))
    {
        printf("Abhay Akhilesh");
    }
    else if ((rad < rbc) && (rab > rad) && (rac > rad) && (rad < rbd) && (rad < rcd))
    {
        printf("Abhay Atin");
    }
    else if ((rad > rbc) && (rab > rbc) && (rac > rbc) && (rbc < rbd) && (rbc < rcd))
    {
        printf("Aditya Akhilesh");
    }
    else if ((rad > rbd) && (rab > rbd) && (rac > rbd) && (rbc > rbd) && (rbd < rcd))
    {
        printf("Aditya Atin");
    }
    else if ((rad > rcd) && (rab > rcd) && (rac > rcd) && (rbc > rcd) && (rbd > rcd))
    {
        printf("Akhilesh Atin");
    }
}

