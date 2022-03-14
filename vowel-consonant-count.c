/*Given a string, you are required to calculate the number of vowels and consonants in the string. It is mandated that you use pointers and dynamic memory allocation to store the string (in the heap memory) and use a function of the following prototype for doing the computation.


int* count_vowel_consonant(char* s, int n)
The function takes a character pointer and an integer as arguments and returns an integer pointer with information on both vowel and consonant counts.


Do not change the given function prototype. You may write other helper functions if necessary.


You should not use statically allocated arrays for this question. You should allocate and free space using dynamic memory allocation and use only pointers referencing and dereferencing to access the string. Do not use array subscripting in your program. Using string library functions is also prohibited.


Input Format:
The first line is an integer n that denotes the length of the string.
The second line contains a string str consisting of n non-null characters.


Output Format:
The count of vowels in str followed by the count of consonants in str separated by a space.


Example

Input:


4
Ck3A

Output:


1 2

Public Test Cases

Input	Output
4
 Ck3A	1 2*/

// solution:

#include <stdio.h>
#include <stdlib.h>
int *count_vowel_consonant(char *str, int n)
{
    char c;
    int *res;
    res = (int *)malloc(2 * sizeof(int));
    int vowel = 0;
    int cons = 0;
    for (int i = 0; i < n; i++)
    {
        c = *(str + i);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vowel++;
        }
        else if ((c > 65 && c <= 90) || (c > 97 && c <= 122))
        {
            cons++;
        }
    }
    *(res) = vowel;
    *(res + 1) = cons;
    printf("%d %d", *res, *(res + 1));
    return res;
}
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d\n", &n);
    char *str;
    str = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        scanf("%c", (str + i));
        // printf("%c" , *(str+i));
    }
    count_vowel_consonant(str, n);
    return 0;
}