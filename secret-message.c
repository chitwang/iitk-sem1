/*[80 marks]
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Automated Grading Scheme:

Visible: 5 marks for each visible test case.

Hidden: 10 marks for each hidden test case.



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% for using strings, arrays, or array indexing to solve this problem,or any future concepts
-20% each for using any library function (string library) other than printf and scanf
-20% each for using any library other than stdio.h

----------------------------------------------------------------------
Secret Message

Sherlock Holmes has to send a letter to Dr. Watson providing him the address of a thief in hiding. To stop the thief's friends from intercepting the message, they decide to use a special cipher to encode the message that requires a key to decode it. The key is a positive integer. The message is a sentence composed only of uppercase (A-Z) and lowercase (a-z) letters, along with spaces separating the words. The encoding is described below.


Suppose k is the key for the cipher. Then, shift the first letter in the message by k letters, the second letter by k+1 letters, the third letter by k+2 letters, and so on. The white spaces in the sentence are not changed and should be printed as it is, and ignored while incrementing the key. Moreover, the case (upper or lower) of each letter remains the same.


Consider the encoding to cycle. So shifting one letter beyond Z will take it back to A, and z to a. Consider the following example. Suppose key is 2 and the message is HappY Boy.



H is shifted by 2 to J ( H -> I -> J )

a is shifted by 3 to d ( a -> b -> c -> d )

p is shifted by 4 to t ( p -> q -> r -> s -> t )

p is shifted by 5 to u ( p -> q -> r -> s -> t -> u )

Y is shifted by 6 to E ( Y -> Z -> A -> B -> C -> D -> E )

Space remains the same.

B is shifted by 7 to I

o is shifted by 8 to w

y is shifted by 9 to h


So the output would become JdtuE Iwh.


Sherlock wants you to create a program that takes the key and the message as the input, and prints the encoded message.


Input Format

The input contains a single line. The line first has an integer giving the key k. This is followed by a single space. Then a sentence of uppercase/lowercase letters follows with words separated by a single space. The final character is ? which marks the end of the input.



Ignore the first space after the key. The sentence will start with a letter.

The sentence will have no trailing spaces.

DO NOT print the final ? in the output. It is only to mark the end of the input sentence.


Output Format

Print the encoded message. Do not print any leading/trailing white spaces or new lines.


Sample Test Cases

Sample Case 1


Input:


2 HappY Boy?

Output:


JdtuE Iwh




Sample Case 2


Input:


5 aaaaaaaa?

Output:


fghijklm
*/

// solution:

#include <stdio.h>

int main()
{
    int k;
    char c;
    scanf("%d", &k);
    getchar();
    scanf("%c", &c);
    int i = 0;
    while (c != '?')
    {
        if (c != ' ')
        {
            if (c >= 'a' && c <= 'z')
            {
                c = (c + k + i - 'a') % 26;
                /*if(c > 122)
                {
                    c = c - 26;
                }*/
                printf("%c", c + 97);
            }
            else if (c >= 'A' && c <= 'Z')
            {
                c = (c + k + i - 'A') % 26;
                /*if(c >= 91)
                {
                    c = (c - 26);
                }*/
                printf("%c", c + 65);
            }
            i++;
        }
        else
        {
            printf("%c", c);
        }
        scanf("%c", &c);
    }
    return 0;
}