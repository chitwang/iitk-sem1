/*[22 marks]
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Automated Grading Scheme:

Visible: 2 marks for each visible test case.

Hidden: 4 marks for hidden test case 1, 2, 5 and 3 marks for hidden test case 3, 4.



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% for using strings, arrays, or array indexing to solve this problem,or any future concepts
-20% each for using any library function (string library) other than printf and scanf
-20% each for using any library other than stdio.h

----------------------------------------------------------------------
Problem Description



You are given a passage. There are mistakes regarding which words should begin with capital letters in the passage. For instance, in the following passage, the first letter of the second sentence begins with a lowercase letter: "This course is Fundamentals of Computing. we hope you enjoy it!" You have to write to a program to take a passage as input and print the corrected version, with the following rule:



The first letter of each sentence in the corrected version begins with a capital letter.


Note that the input will obey the following rules:



The first letter of each sentence will always begin with either a lowercase or uppercase letter.

Each sentence can end with either of the following 3 punctuation marks: '.', '?', '!'.

There is a whitespace character after each sentence, except the last one.


Constraints


You are not allowed to use strings, arrays, or array indexing to solve this problem, you can only scan the input character by character. You are not allowed to use any string library functions for checking if a character is lowercase or uppercase.


Input:



The first line contains an integer specifying the number of the sentence in the input.

The second line contains the passage. Note that there are new newline characters in the passage.


Output:



Your program should print the correct version of the passage according to the rules specified above.


Sample Test Cases

Test Case 1


Input:


2
This is already a correct sentence. No change is required.


Output:


This is already a correct sentence. No change is required.


Explanation: The above input already obeys the rule we had, hence the output is the same as the input.




Test Case 2


Input:


2
the first sentence itself begins with a lowercase letter. It should be capitalized.


Output:


The first sentence itself begins with a lowercase letter. It should be capitalized.


Explanation: As mentioned in the rules the first letter of each sentence should begin with an uppercase letter. Hence, "the" should be transformed to the "The".*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    char c;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        scanf("%c", &c);
        if (c <= 'z' && c >= 'a')
        {
            c = c - 'a' + 'A';
        }
        printf("%c", c);
        scanf("%c", &c);
        while (1)
        {
            if (c == '.' || c == '!' || c == '?')
            {
                printf("%c", c);
                break;
            }
            else
            {
                printf("%c", c);
            }
            scanf("%c", &c);
        }
        if (i < n)
        {
            printf(" ");
            getchar();
        }
    }
    return 0;
}