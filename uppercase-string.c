/*Automated Grading Scheme:

Visible: 2.5 marks for each visible test case.

Hidden: 2.5 marks for 1st, 2nd, 3rd and 4th test case.

Hidden: 5 marks for 5th and 6th test case.



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% for using any future concepts
-20% each for using any library function (string library) other than printf and scanf. So getline(), gets(), fgets(), etc. are not allowed at all.
-20% each for using any library other than stdio.h

 Important Note
If '\0' (null character) is not appended to end of string, the output might contain garbage value across multiple run.
Try executing solution multiple times to see if no garbage value is printed as output.


---------------------------------------------------------------------
Given a character array S. The maximum length of array is 100. The words in the string are separated by a single whitespace. The end of string is marked by newline character(\n).
Print the string after converting each alphabet in alternate word of string to UPPERCASE.


Constraint:


The digit and special characters in the character array remain unchanged.

Make sure, the output string does not contain garbage values.



Input:


Each test case comprise of single line of input.


The only line in each test case will contain the character string.

The string will consist of uppercase, lowercase alphabets, digits and special character(@ , \ ? !) .


Output:


The output will contains the modified string followed by a newline.




Sample TestCase :

  Input


  Hi, how are you?
  Output:


  HI, how ARE you?
  Explanation:
 The first and third word of the string are converted to uppercase. The special characters, second and fourth word of the string remains unmodified.


Sample TestCase :

  Input


  Hi, I AM Here.
  Output:


  HI, I AM Here.
  Explanation:
 The first word of the string is converted to uppercase. The third word was already in uppercase. The special characters, second and fourth word of the string remains unmodified. The uppercase alphabet in second and third word remains unchanged. */

// solution:

#include <stdio.h>

int main()
{
    //  Insert your code here.
    char c;
    char str[100];
    int n = 0;
    scanf("%c", &c);
    while (c != '\n')
    {
        str[n] = c;
        n++;
        scanf("%c", &c);
    }
    int space = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] != ' ')
        {
            if (space % 2 == 0)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                {
                    str[i] = str[i] - 'a' + 'A';
                }
            }
        }
        if (str[i] == ' ')
        {
            space++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%c", str[i]);
    }
    return 0;
}