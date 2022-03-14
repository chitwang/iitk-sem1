/*You are playing a game where you are given n tiles. Each tile has an associated cost C, and a score S. You have K amount of money with you. You need to pick up some tiles. Your total score for the game is the sum of scores of the tiles you have picked. The associated cost of your selection is the sum of costs of the tiles you have picked. You need to pick a set of tiles (without replacement) such that you maximize your score, subject to the constraint that the total cost of all tiles you have picked does not exceed K. Report the maximum score you can obtain.


*Note that you may select none of the tiles.


Input Format

The first line contains a single integer n, which is the number of tiles.

The next line contains n positive integers, each denoting the cost of a tile.

The next line contains n non-negative integers, each denoting the associated score from each tile.

The next line contains a single non-negative integer K, denoting the amount of money you have.


Output Format

A single integer, denoting the maximum score you can obtain.


Sample Input

5
3 4 2 1 6
0 1 2 3 4
2
Sample Output

3
Explanation

We can see that with 2 units of money, we can either get the third or fourth tile. It is optimal to get the fourth tile, giving a score of 3.*/

// solution:

#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int recursive(int n, int cost[], int score[], int k)
{
    if (n == 0 || k == 0)
    {
        return 0;
    }
    if (cost[n - 1] > k)
    {
        return recursive(n - 1, cost, score, k);
    }
    else
    {
        return max((score[n - 1] + recursive(n - 1, cost, score, k - cost[n - 1])), recursive(n - 1, cost, score, k));
    }
}
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    int cost[n];
    int score[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cost[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
    }
    int k;
    scanf("%d", &k);
    printf("%d", recursive(n, cost, score, k));
    return 0;
}