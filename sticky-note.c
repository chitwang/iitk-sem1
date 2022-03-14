/*[50 Points]

----------------------------------------------------------------------
Automated Grading Scheme:
Public Test Cases (2 point each. 2*2= 4 points)
Hidden Test Cases (46 points)
Test Cases number 1 to 2 are of 2 marks each.
Test Cases number 3 to 6 are of 5 marks each.
Test Case number 7 is of 6 marks.
Test Cases 8 and 9 are of 10 marks each.



Manual Grading Scheme
Note: Any form of hard-coding will lead to zero marks. Eg: printf("0");
----------------------------------------------------------------------

You are a professional typist. One morning as you were finishing typing out a document, you notice a sticky note at the back of the document which states "Could you please replace all the occurences of alternating sequence of characters c1 and c2 with length greater than 1 in the document with a sentence s_new?"


Apart from being skilled in typing, you are also a skilled programmer. So to avoid the hassle of editing the document you decide to create a program for it. Suppose, you break the task into the following points for better understanding.



Replace a substring s1 in the original sentence S with sentence s_new

s1 consists of an alternating sequence of c1 and c2, i.e. of the form c1c2c1c2... or c2c1c2c1...

Length of s1 should be greater than or equal to 2


Input:


The input will be across 5 lines. The first line contains the original sentence S. The second line contains the character c1 and the third line contains the character c2. The fourth line contains an integer denoting the length of the string s_new. The last line contains the sentence s_new.


You can assume that the length of S is <= 600 and the length of s_new is <= 50.


Output Format


The final sentence S' after replacing all the occurrences of an alternating sequence of characters c1 and c2 in S with a sentence s_new.


Example Input
I did take a ride in Trinidad alongside Picadili Idaho
i
d
3
esc


Example Output


I esc take a resce in Trinescad alongsesce Picaescli Idaho


Brief Explanation


All the substitutions are marked in bold for clarity.


I esc take a resce in Trinescad alongsesce Picaescli Idaho*/

// solution:

#include <stdbool.h>
#include <stdio.h>

int main()
{
    char str[20000];

    int start = 0, end = 0;

    for (int i = 0; i < 600; i++)
    {
        char c;
        scanf("%c", &c);
        if (c == '\n')
            break;
        str[i] = c;
    }

    char c1;
    scanf("\n%c", &c1);
    char c2;
    scanf("\n%c", &c2);

    int s_n_len;
    scanf("%d", &s_n_len);

    char dummy;
    scanf("%c", &dummy);

    char subs1[s_n_len];
    for (int i = 0; i < s_n_len; i++)
    {
        char c;
        scanf("%c", &c);
        subs1[i] = c;
    }
    int i = -1;
    int length_str = 0;
    while (str[length_str] != '\0')
    {
        length_str++;
    }
    for (i = 0; i < length_str; i++)
    {

        int val;
        int seq_len = 0;
        int i2 = i;
        bool flagA = true, flagB = true; // Which char is allowed
        if (str[i2] != c1 && str[i2] != c2)
            val = -1;
        while ((str[i2] == c1 && flagA) || (str[i2] == c2 && flagB))
        {
            flagA = true, flagB = true;
            if (str[i2] == c1)
                flagA = false;
            else
                flagB = false;
            i2++;
            seq_len++;
        }
        if (seq_len > 1)
            val = i2 - 1;
        else
            val = -1;

        if (val >= 0)
        {
            start = i;
            end = val;

            int i3 = -1;
            int len = length_str;
            char temp[20000];
            do
            {
                i3++;
                temp[i3] = str[i3];
            } while (i3 != len);

            int j = start;

            for (i3 = 0; i3 < s_n_len; i3++)
            {
                str[j++] = subs1[i3];
            }

            for (i3 = end + 1; i3 <= len; i3++)
            {
                str[j++] = temp[i3];
            }

            i = start + s_n_len;
        }
        length_str = 0;
        while (str[length_str] != '\0')
        {
            length_str++;
        }
    }

    printf("%s", str);

    return 0;
}
