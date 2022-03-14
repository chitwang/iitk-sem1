/*You are given two words. You have to compute the following functions for each word, and based on the output you have to tell which is larger. The function is defined as follows.
f(c), where c is a character f(a) = 0, f(b) = 1, .... f(z) = 25.
f(S), where s is a word = sum over all c in S(f(c)).
For example f(abc) = f(a) + f(b) + f(c) = 0 + 1 + 2 = 3.


Constraint:

The word will only consist of lowercase letters.


Input:


The input will span accross 4 lines:

n1

word of length n1

n2

word of length n2


Output:


The program should print:



first, if the function for the first word is larger

second, if the function for the second word is larger

tie, if the function for both is same


There should be any spaces or newline chars in the outputs.


Sample TestCase:


TestCase1:

Input


1
a
2
aa
Output:


tie

TestCase2:

Input


1
a
1
b
Output:


second

Explanation:

TEST CASE1: The function for both the words is 0, hence it is a tie.


TEST CASE2: The function for the first is 0 and for the second is 1, hence it is second*/

// solution:

#include <stdio.h>

int main()
{
    int n1;
    int n2;
    int func1 = 0;
    int func2 = 0;
    char c;
    scanf("%d", &n1);
    getchar();
    for (int i = 0; i < n1; i++)
    {
        scanf("%c", &c);
        func1 = func1 + c - 97;
    }
    scanf("%d", &n2);
    getchar();
    for (int j = 0; j < n2; j++)
    {
        scanf("%c", &c);
        func2 = func2 + c - 97;
    }
    if (func1 > func2)
    {
        printf("first");
    }
    else if (func2 > func1)
    {
        printf("second");
    }
    else
    {
        printf("tie");
    }
    return 0;
}