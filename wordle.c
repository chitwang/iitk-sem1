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

float get_score(char word[], char target[])
{
    char wd[5], tg[5];
    for (int i = 0; i < 5; i++)
    {
        wd[i] = word[i];
        tg[i] = target[i];
    }
    float score = 0;
    for (int i = 0; i < 5; i++)
    {
        if (wd[i] == tg[i])
        {
            score += 2;
            wd[i] = '*'; // marking
            tg[i] = '#'; // marking
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (wd[i] == tg[j])
            {
                score += 1;
                wd[i] = '*'; // marking
                tg[j] = '#'; // marking
                break;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (wd[i] != '*')
        {
            score -= 0.05;
        }
    }
    return score;
}

int get_sqns(char words[][6], int n, int k, float curr_score, int num)
{
    if (num > 6)
    {
        return 0;
    }
    if (curr_score == 10)
        return 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        char curr[6];
        for (int j = 0; j < 6; j++)
        {
            curr[j] = words[i][j];
        }
        if (get_score(curr, words[k]) > curr_score)
            ans += get_sqns(words, n, k, get_score(curr, words[k]), num + 1);
    }
    return ans;
}

int main()
{
    int n, k;
    scanf("%d  %d", &n, &k);
    k--;
    char words[n][6];
    for (int i = 0; i < n; i++)
    {
        char inp[6];
        scanf("%s", inp);
        inp[5] = '\0';
        for (int j = 0; j < 6; j++)
            words[i][j] = inp[j];
    }

    printf("%d\n", get_sqns(words, n, k, -10, 0));
    return 0;
}