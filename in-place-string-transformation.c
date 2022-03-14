/*Input a string str and store it in the heap memory. The maximum length of the string is 2000 characters. You are required to execute q queries on the string, and do in-place transformations (i.e., modify str directly).


Each query represents a transformation and consists of three integers: t, s, and e. The choice t specifies the type of transformation (1 <= t <= 3). The numbers s and e denote the start index and the end index respectively, with 0 <= s <= e < length(str). The particular transformation is to be applied only to the substring that lies between indices specified by s and e (both are inclusive).


A transformation could be one of the following three types. You are required to write a function to implement each transformation.



void reverse(char* substr, int len) - Reverse substr of length len. Eg: "abc" ? "cba"

void cyclicShift(char* substr, int len) - Shift substring cyclically towards the right by 2 places. Eg: "abcde" ? "deabc".

void swapCase(char* substr, int len) - Swap the cases of all alphabets in substr. Eg: "Ab2" ? "aB2".


You should not change the given function prototypes. You may write other helper functions if necessary.


Execute all the q transformations on the respective segments of str by calling the concerned functions with the correct parameters. Print the final string obtained after all the queries have been executed.


You should not use statically allocated arrays for this question. You should allocate and free space for the string using dynamic memory allocation and use pointers to reference it. Do not use array subscripting in your program. Using string library functions is also prohibited.


Input Format:


The first line is the input string str (newline is not part of the string). The second line specifies the number of queries q. The next q lines are triplets (type, start, end), representing the transformations you have to carry out in order.


Output Format:


The final string after applying all the queries.


Example

Input:


AbcDEFghiJ
3
1 1 4
3 0 9
2 3 7

Output:


aedGHCBfIj


Explanation:
Query 1: AbcDEFghiJ ? AEDcbFghiJ
Query 2: AEDcbFghiJ ? aedCBfGHIj
Query 3: aedCBfGHIj ? aedGHCBfIj


Public Test Cases (1 * 4 = 4 marks)

Input	      Output
AbcDEFghiJ
 3
 1 1 4
 3 0 9
 2 3 7	      aedGHCBfIj


Grading scheme

- 50% penalty for using static arrays or the array subscript operator or string library functions such as strlen()

- 25% penalty for not writing the functions asked or using different function prototypes i.e., changing the return type or the argument types

Hidden test cases 6*6 = 36 marks
*/

// solution:

#include <stdio.h>
#include <stdlib.h>
void reverse(char *s, int n)
{
    for (int i = 0; i < (n / 2); i++)
    {
        char a = *(s + i);
        *(s + i) = *(s + n - 1 - i);
        *(s + n - 1 - i) = a;
    }
}
void cyclicShift(char *s, int n)
{
    char x = *(s + n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        *(s + i + 1) = *(s + i);
    }
    *(s + 0) = x;
    x = *(s + n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        *(s + i + 1) = *(s + i);
    }
    *(s + 0) = x;
}

void swapCase(char *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        char c = *(s + i);
        if (c >= 'a' && c <= 'z')
        {
            c = c - 'a' + 'A';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = c - 'A' + 'a';
        }
        *(s + i) = c;
    }
}

int main()
{
    char *str = (char *)malloc(2000 * (sizeof(char)));
    char c;
    int n = 0;
    scanf("%c", &c);
    while (c != '\n')
    {
        *(str + n) = c;
        n++;
        scanf("%c", &c);
    }
    int q;
    scanf("%d", &q);
    int t;
    int s;
    int e;
    for (int z = 0; z < q; z++)
    {
        scanf("%d %d %d", &t, &s, &e);
        int len = e - s + 1;
        // printf("%d%d" , s , e);
        if (t == 1)
        {
            reverse(str + s, len);
        }
        else if (t == 2)
        {
            cyclicShift(str + s, len);
        }
        else if (t == 3)
        {
            swapCase(str + s, len);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%c", *(str + i));
    }
    free(str);
    return 0;
}
