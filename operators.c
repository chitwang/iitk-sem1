/*Automated Grading Scheme:
Total marks: 40

Visible test case carries 5 marks.
Hidden cases:
Test case 1 has 5 marks.
Test cases 2, 3, and 4 have 10 marks each.

----------------------------------------------------------------------------------------------------------------------------
Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Header files allowed - stdio.h, stdlib.h, string.h
----------------------------------------------------------------------------------------------------------------------------


Stimulus Corp has decided to design a domain-specific programming language (DSL) for a scientific study. The language has a custom precedence and associativity of the operators. Stimulus Corp requires you to develop a program to decide the order of operator evaluation in the DSL. Given a sequence of operators, the program should print the order of evaluation of operators as output.



Operator definitions


The sequence of operators can be a combination of the following operators.



Multiply (*)

Division (/)

Modulo (%)

Addition (+)

Subtraction (-)

Greater than (>)

Less than (<)

Bitwise XOR(^)

Bitwise AND (&)

Bitwise OR (|)

Assignment (=)



The definition of all operators is the same as in your favorite C language.



The associativity of all operators is left-to-right.

The order of precedence is as follows (low to high).


Bitwise operator (&,|,^) -> Assignment (=) -> Division/Multiplication/Modulo (/,\*,%) -> Relational operator (<,>) -> Addition/Subtraction (+,-) .


Addition/Subtraction (+,-) implies that the addition and subtraction operators have the same precedence.



An expression will be evaluated left to right for operators with the same precedence.




Constraints


The input is a string of operators.

The maximum number of operators in the string is 5.

Library functions are allowed.


Input


The first line will contain the number of test cases.

Each test case is a sequence of operators followed by a newline character\n.


Output

Your program should print the order of operator evaluation for each test case in the format given in visible test case.





Input


1
/*+


Output


+ / *

Explanation: The precedence of +  is higher than * and /. Therefore it is evaluated first. Among * and / both have same precedence, so / will be evaluated first.*/

// solution:

#include <stdio.h>
#include <stdlib.h>
int getrow(char **op, char x)
{
    int row;
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (op[i][j] == x)
            {
                flag = 1;
                row = i;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    return row;
}
int getcol(char **op, int row, char x)
{
    for (int j = 0; j < 3; j++)
    {
        if (op[row][j] == x)
        {
            return j;
        }
    }
}
void swap(char str[5], int i, int j)
{
    char t = str[j];
    str[j] = str[i];
    str[i] = t;
}
int main()
{
    char **op;
    op = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++)
    {
        op[i] = (char *)malloc(3 * sizeof(char));
    }
    op[0][0] = '+';
    op[0][1] = '-';
    op[1][0] = '<';
    op[1][1] = '>';
    op[2][0] = '/';
    op[2][1] = '*';
    op[2][2] = '%';
    op[3][0] = '=';
    op[4][0] = '&';
    op[4][1] = '|';
    op[4][2] = '^';
    int t;
    scanf("%d\n", &t);
    char str[5];
    char ch;
    for (int g = 0; g < t; g++)
    {
        int n = 0;
        scanf("%c", &ch);
        while (ch != '\n')
        {
            str[n] = ch;
            n++;
            scanf("%c", &ch);
        }
        /*for(int u=0;u<n;u++)
        {
            printf("%c" , str[u]);
        }*/
        for (int i = n - 1; i > 0; i--)
        {
            /*for(int j=i+1;j<n;j++)
            {*/
            if (getrow(op, str[i]) < getrow(op, str[i - 1]))
            {
                swap(str, i, i - 1);
            }
            else if (getrow(op, str[i]) == getrow(op, str[i - 1]) && getrow(op, str[i]) == 4)
            {
                if (getcol(op, 4, str[i]) < getcol(op, 4, str[i - 1]))
                {
                    swap(str, i, i - 1);
                }
            }
            // }
        }
        for (int u = 0; u < n; u++)
        {
            printf("%c", str[u]);
            if (u < n)
            {
                printf(" ");
            }
        }
        if (g < t - 1)
        {
            printf("\n");
        }
    }
    return 0;
}
