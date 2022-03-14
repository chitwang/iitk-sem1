/*Write a program that calculates variance of a stream of numbers where the stream will end in 0. Input will be given in the format of a stream of integers separated by a space and ending in 0. The output will be a real number which will be a variance of the numbers. The output must be printed upto two decimal points only.

Constraints: Assume that stream ends when 0 is encountered.

Note: This question can be solved without arrays.

Sample Input 1:

-1 1 0

Sample Output 1:

1.00

Sample Input 2:

1 2 3 4 5 0

Sample Output 2:

2.00 */

// solution:

#include <stdio.h>
int main()
{
    int sum = 0;
    int sq_sum = 0;
    int n1;
    float mean;
    float sq_mean;
    float var;
    int count = 0;
    scanf("%d", &n1);
    while (n1 != 0)
    {
        sum = sum + n1;
        sq_sum = sq_sum + (n1 * n1);
        count++;
        scanf("%d", &n1);
    }
    mean = (float)sum / count;
    sq_mean = (float)sq_sum / count;
    var = (sq_mean) - (mean * mean);
    printf("%0.2f", var);
}