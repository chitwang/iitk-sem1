/*Your friendly neighborhood shopkeeper has decided to reward your excellent performance at JEE and give you some candies. She gives you a list of 10 integers (not all may be positive) and tells you to select two locations in the list (i.e. two numbers between 1 and 10 -- the first number being smaller than or equal to the second number).


Once you tell her these two locations, the shopkeeper will to give as many candies as the sum of all the numbers occurring between the locations indicated by you (including the locations specified by you). Write an algorithm to calculate what is the maximum number of candies you can get this way. Your input will be a list of 10 integers and your output should be the maximum number of candies you can get, the starting location, and the ending location, all separated by a single space with no trailing spaces at the end.


Caution



Be careful about extra/missing lines and extra/missing spaces.

Be careful that array locations start from zero whereas in your output, you should give locations that start from one, just as we do in day to day conversations.


Constraints


All numbers lie between -1000 and 1000.


Sample Input


1 3 5 2 6 -7 1 1 -3 1


Sample Output:


17 1 5


Explanation : If you select the locations 1 and 5, then you get will get 1+3+5+2+6 = 17 candies since the numbers between the first and fifth locations (including both ends) in the list are 1, 3, 5, 2, 6. You can verify that this is the maximum number of candies you can get.*/

// solution:

#include <stdio.h>

int main()
{
    int arr[10];
    int max = 0;
    int a;
    int b;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j < 10; j++)
        {
            int sum = 0;
            for (int p = i; p <= j; p++)
            {
                sum += arr[p];
                if (sum > max)
                {
                    max = sum;
                    a = i + 1;
                    b = j + 1;
                }
            }
        }
    }
    printf("%d %d %d", max, a, b);
}
