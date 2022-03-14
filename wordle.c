/*[75 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  5 for visible test case

Hidden:  10  each for all hidden test cases


----------------------------------------------------------------------

Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20 % each for using any library other than stdio.h, stdlib.h
It is mandatory to use at least one user-defined function.
-50 % if any user defined function is not used.

----------------------------------------------------------------------
Wordle is an online 5-letter word game. Where you have to guess a five letter word of the day and and players have six attempts to guess what the word of the day is. More information at : Wordle.
wordle-rule1


As shown above, if you have the right letter in the right spot, it shows up green. A correct letter in the wrong spot shows up yellow. A letter that isn't in the word in any spot shows up gray.


You can enter a total of six words, meaning you can enter five burner words from which you can learn hints about the letters and their placements. Then you get one chance to put those hints to use. Or you can try for performance and guess the word of the day in three, two or even one go.


An Example play would be Where the word of the day is CYNIC:

wordle-example


Actual problem statement starts from here. I just wanted to let you know about the game WORDLE ???? .


Score of a word/guess is defined as 2*number of green spots + number of yellow spots - 0.05*number of gray spots.


You are given a list of 5 letter distinct words and the day of the word, you have to give the number of sequences of words with strictly increasing score and sequence must be ended by the word of the day. Also, the length of the sequence must be at most 6.


Note: A sequence with only one word is a valid sequence.


Input Format

First line contains two integers N and K denoting the number of words and the position of the word of the day in the list respectively. Next N lines contain the words.


Here, N is a natural number and 1 <= K <= N.


Output Format

Print the number of sequences of words with strictly increasing score and sequence must be ended by the word of the day.


Example Input

4 4

STICK

CIRCA

CYCLE

CYNIC


Example Output

8


Explanation

The valid sequences are:

[STICK, CIRCA, CYCLE, CYNIC]

[CIRCA, CYCLE, CYNIC]

[STICK, CIRCA, CYNIC]

[STICK, CYCLE, CYNIC]

[STICK, CYNIC]

[CIRCA, CYNIC]

[CYCLE, CYNIC]

[CYNIC]*/

// solution:

#include <stdio.h>
#include <stdlib.h>
int spanner(char b, char str[])
{
    int flag = -9;
    for (int i = 0; i < 5; i++)
    {
        if (str[i] == b)
        {
            flag = i;
            break;
        }
    }
    return flag;
}
float score(char str[], char word[])
{
    float green = 0;
    float yellow = 0;
    int temp[5];
    for (int i = 0; i < 5; i++)
    {
        temp[i] = 0;
    }
    float grey = 0;
    for (int i = 0; i < 5; i++)
    {
        int c = spanner(str[i], word);
        if (str[i] == word[i])
        {
            green = green + 1;
            temp[i]++;
        }
        else if (c == -9)
        {
            grey = grey + 1;
        }
    }
    yellow = 5 - green - grey;
    float ans = 2 * green + yellow - 0.05 * grey;
    // printf("score\n");
    return ans;
}
int mini(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int checkvalid(char **ans, int x, char word[])
{
    if (x == 1)
    {
        return 1;
    }
    for (int i = 0; i < x - 1; i++)
    {
        if (score(ans[i], word) >= score(ans[i + 1], word))
        {
            return 0;
        }
    }
    return 1;
}
void func(char **ans, int n, char **mat, int x, int k, int *count, int i, int istart)
{
    if (i == x)
    {
        if (checkvalid(ans, x, mat[k - 1]))
        {
            *count = *count + 1;
        }
        return;
    }
    if (i > x)
    {
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (j == k - 1)
        {
            continue;
        }
        istart = j;
        for (int f = 0; f < 5; f++)
        {
            ans[i][f] = mat[istart][f];
        }
        func(ans, n, mat, x, k, count, i + 1, istart);
    }
}
int main()
{
    //  Insert your code here.
    int n;
    int k;
    scanf("%d %d\n", &n, &k);
    char **mat;
    mat = (char **)malloc(n * sizeof(char *));
    char **ans;
    int x = mini(n, 6);
    ans = (char **)malloc(x * sizeof(char *));
    for (int i = 0; i < x; i++)
    {
        ans[i] = (char *)malloc(5 * sizeof(char));
    }
    for (int i = 0; i < n; i++)
    {
        mat[i] = (char *)malloc(5 * sizeof(char));
        scanf("%s", mat[i]);
        // printf("%s\n" , mat[i]);
    }
    /*for(int i=0;i<n;i++)
    {
        printf("%f\n" , score(mat[i] , mat[k-1]));
    }*/
    // printf("%f" , score(mat[k-1] , mat[1]));
    // printf("%d" , checkvalid(mat,x-1,mat[k-1]));
    int count = 1;
    for (int h = 1; h < x; h++)
    {
        func(ans, n, mat, h, k, &count, 0, 0);
    }
    printf("%d", count);
    return 0;
}