/*You are given an integer n. In the next n lines you have been given the first-name, surname, birth year, and institute name for n students. You have generate an email from that data, with the following format.


(the first 3 letters of the first-name in uppercase)_(the first 3 letters of the surname in uppercase)(last 2 digits of the birth year)@(institute name in lowercase).ac.in

Input:

First line with specify n the number of students.
the next n lines will have the data as mentioned above in the following format:


first-name,surname,birthyear,institute-name,


Note : The first-name and surname will have atleast 3 characters each, and will comprise of only alphabetical characters. The institute name will comprise only of alphabetical characters. The birthyear will comprise only of numerical characters. The first-name, surname, and institue-name may not have consistent uppercase or lowercase maintained, for ex. this is a valid input:
AbcD,bACf,1999,IItK


Note : There will be no spaces in any of the lines.

Output:

The emails as mentioned as mentioned above, each in new line.


Note : Do NOT add any extra spaces. There should not be a newline after the last email.


Visible Test Case


Testcase1:

Input
2
abcd,efgd,1989,IITK,
HIJK,LmNO,1999,IIITH,
Output

ABC_EFG89@iitk.ac.in
HIJ_LMN99@iiith.ac.in*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    char c;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        int countname = 0;
        int countsname = 0;
        int countyear = 0;
        scanf("%c", &c);
        while (c != ',')
        {
            if (countname < 3)
            {
                if (c <= 'z' && c >= 'a')
                {
                    c = c - 'a' + 'A';
                    printf("%c", c);
                    countname++;
                }
                else if (c <= 'Z' && c >= 'A')
                {
                    printf("%c", c);
                    countname++;
                }
            }
            scanf("%c", &c);
        }
        printf("_");
        scanf("%c", &c);
        while (c != ',')
        {
            if (countsname < 3)
            {
                if (c <= 'z' && c >= 'a')
                {
                    c = c - 'a' + 'A';
                    printf("%c", c);
                    countsname++;
                }
                else if (c >= 'A' && c <= 'Z')
                {
                    printf("%c", c);
                    countsname++;
                }
            }
            scanf("%c", &c);
        }
        scanf("%c", &c);
        while (c != ',')
        {
            if (c <= '9' && c >= '0')
            {
                if (countyear >= 2)
                {
                    printf("%c", c);
                }
                countyear++;
            }
            scanf("%c", &c);
        }
        printf("@");
        scanf("%c", &c);
        while (c != ',')
        {
            if (c <= 'Z' && c >= 'A')
            {
                c = c - 'A' + 'a';
                printf("%c", c);
            }
            else if (c <= 'z' && c >= 'a')
            {
                printf("%c", c);
            }
            scanf("%c", &c);
        }
        if (i == n - 1)
        {
            printf(".ac.in");
        }
        else
        {
            printf(".ac.in\n");
            getchar();
        }
    }
    return 0;
}
