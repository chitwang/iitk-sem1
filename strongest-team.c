/*Alice is given a list of n players and their skill level. It is guaranteed that the skill level of each player is some non-negative number.

Now he wants to make a team of k players (k <= n) to participate in a tournament. But since he is lazy, he wants to select only adjacent players. He also wants to make the team which has maximum value so that the chance of winning is maximised.
The value of a team is defined as the sum of skill level of each player in that team.


Input Format:

The input consists of three lines.

The first line contains the number of players, n.

The second line contains n space-separated non-negative integers denoting the skill level of each player.

The third line contains integer k.


Output Format:

Output an integer denoting the value of Alice's team.


Sample Input:

5

12 3 5 11 15

3


Sample Output:

31


Explanation:

All the possible teams that Alice can make are {1, 2, 3}, {2, 3, 4} and {3, 4, 5}.

The corresponding values of teams are 20, 19 and 31 respectively.

So the value of Alice's team is 31.*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    int k;
    int max = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum = sum + arr[i + j];
        }
        if (sum > max)
        {
            max = sum;
        }
    }
    printf("%d", max);
    return 0;
}