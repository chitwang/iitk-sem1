/*Alice and Bob are playing a game using a pair of normal six-faced dice.


First, Alice rolls the pair of dice. If the two die show a1 and a2 respectively, then Alice's score is calculated as a1 + a2. Next, Bob rolls the pair of dice. If the two die show b1 and b2 respectively, then Bob's score is calculated as b1 + b2. The player with a higher score wins the game. It is a draw if the scores of both the players are equal.


Given a1, a2, b1, and b2 as input (positive integers between 1 and 6, both inclusive), print "Alice" (without quotes) if Alice wins, "Bob" (without quotes) if Bob wins and "Draw" (without quotes) if the game ends in a draw.


Input Format: 4 integers


The input will be given in the order a1, a2, b1, and b2.


Output Format: One of the following - Alice/Bob/Draw


Example Input
1 2 3 5


Example Output
Bob*/

// solution:

#include <stdio.h>

int main()
{
    int a1;
    int a2;
    int b1;
    int b2;
    int Alice_score;
    int Bob_score;
    scanf("%d", &a1);
    scanf("%d", &a2);
    scanf("%d", &b1);
    scanf("%d", &b2);
    Alice_score = a1 + a2;
    Bob_score = b1 + b2;
    if (Alice_score > Bob_score)
    {
        printf("Alice");
    }
    else if (Bob_score > Alice_score)
    {
        printf("Bob");
    }
    else
    {
        printf("Draw");
    }
    return 0;
}