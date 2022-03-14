/*All of Mr C's clones have the latest mobile phone in the market and he does not want to be left out. However, he is in a dilemma. Some phones have a better camera whereas others have better battery life. Moreover, Mr C's parents gave him only a limited budget to purchase a phone. Help Mr C choose a phone to purchase. Mr C has collected a list of phones available in the market including their costs and ratings in 5 different categories - Camera, Performance, Battery, Hardware and Design. Mr C wants to buy a phone within his budget with the highest average rating across the 5 categories.


The first line of the input will contain two strictly positive integer, n and b, separated by a space. n will denote the number of phones in the market and b will denote Mr C's budget. In the next n lines, we will give you the specifications of each of the phones. Each specification will consist of 2 integers and 5 floating point numbers separated by space as shown below. The phone id will be unique, i.e. no two phones will have the same id.


id price cam perf bat hard des


In your output, you have to print the id of the phone which has the highest average rating among phones that Mr C can buy, i.e. phones whose price is less than or equal to Mr C's budget. If there is no phone Mr C can buy, print -1 in your output. If there is more than one phone with highest average rating among those Mr C can buy, choose the phone with the lowest price. If there is more than one phone with lowest price and highest average rating among those Mr C can buy, choose the phone that appears earliest in the list of phones. Use a structure to maintain details about the phone to help simplify your code.


Note:

Phone ids will not be given to you in any particular order, nor will the phones be listed such that prices or ratings are in any particular order.

The price of a phone will be a non-negative integer but may be zero.

The ratings of a phone will be a non-negative floating point number but may be zero.

The id of a phone will be a strictly positive integer.


Sample Input 1:

3 100

89 40 8.0 8.0 8.0 8.0 6.5

93 99 8.0 5.0 5.0 5.0 10.0

84 50 8.1 8.0 8.2 8.2 6.0


Sample Output 1:

89


Explanation:

All phones are affordable and phone ids 89 and 84 have equal average rating of 7.7. However, phone id 89 is cheaper.


Sample Input 2:

4 100

89 40 8.0 8.0 8.0 8.0 6.5

93 99 8.0 5.0 5.0 5.0 10.0

84 50 8.1 8.0 8.2 8.2 6.0

83 40 9.0 9.1 9.2 9.3 1.9


Sample Output 2:

89


Explanation:

All phones are affordable and phone ids 89, 84 and 83 have equal average rating of 7.7. However, phone with ids 89 and 83 are cheaper. Since phone id 89 comes earlier in the input so the answer is 89.*/

// solution:

#include <stdio.h>
struct phone
{
    int id;
    int price;
    float cam;
    float perf;
    float bat;
    float hard;
    float des;
    float avg;
};
int main()
{
    //  Insert your code here.
    int n;
    int b;
    int ans;
    scanf("%d %d", &n, &b);
    struct phone arr[n];
    float rating = -1.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %f %f %f %f %f", &arr[i].id, &arr[i].price, &arr[i].cam, &arr[i].perf, &arr[i].bat, &arr[i].hard, &arr[i].des);
        arr[i].avg = (arr[i].cam + arr[i].perf + arr[i].bat + arr[i].hard + arr[i].des) / 5;
    }
    int flag = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i].avg >= rating && arr[i].price <= b)
        {
            rating = arr[i].avg;
            ans = arr[i].id;
            flag = 1;
        }
    }
    if (flag)
    {
        printf("%d", ans);
    }
    else
    {
        printf("-1");
    }
    return 0;
}