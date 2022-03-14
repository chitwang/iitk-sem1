/*DK and AK are preparing for IIT exam but series is a weak topic for them. They need your help to calculate Arithmetico-Geometric Series so that they can verify their results.


Arithmetico-Geometric Series is given by:
                a, (a+d)r, (a+2d)r^2, (a+3d)*r^3, ...


You will be given the following four inputs in a single line separated by space.



The first term of the series (a): (real number)

The number for terms in the series(n): (natural number)

The common ratio of series(r): (real number)

The common difference of the series(d): (real number)


First, you will be required to give the terms of the series starting from first term separated by new line
Secondly, you will be required to give average of the series in last line.
You are not allowed to use pow() functionality.
All results must be printed with 3 places of decimal.


Input Format:


First line contains input values separated by space.


Output Format:


Output will contain the terms of the series separated by new line and average of series in lastline.


Marking Scheme:
Visible Test Case: 4 marks
Hidden Test Case: 6*6 = 36 marks
Total: 40 Marks.


Public Test Cases

Test Case:
1 3 2 1
Output
1.000
4.000
12.000
5.667

----------------------------------------------------------------------
Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty: Only 20 marks(maximum half marks) to be awarded if pow() function is used.*/

// solution:

#include <stdio.h>

int main()
{
    float a;
    float r;
    float d;
    int n;
    float b = 1;
    scanf("%f", &a);
    scanf("%d", &n);
    scanf("%f", &r);
    scanf("%f", &d);
    float sum = a;
    int count = 1;
    printf("%0.3f\n", a);
    while (count < n)
    {
        a = a + d;
        b = b * r;
        printf("%0.3f\n", a * b);
        sum = sum + (a * b);
        count++;
    }
    printf("%0.3f", sum / n);
    return 0;
}