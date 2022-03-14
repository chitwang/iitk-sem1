/*[15 Points]

----------------------------------------------------------------------
Automated Grading Scheme:
Public Test Cases (0.5 point each. 0.5*2 = 1 points)
Hidden Test Cases (2 point each. 2*7 = 14 points)



Manual Grading Scheme
Note: Any form of hard-coding will lead to zero marks. Eg: printf("0");
Penalty: Award 0 points if struct is not used for storing the information of the shopkeepers.

Header files Allowed: stdio.h
----------------------------------------------------------------------

There are n shopkeepers (indexed from 1 to n) who sell apples, bananas, mangoes and oranges at their shops. Each shopkeeper has a fixed quantity of all these fruits and sells them at his own price (per kg). Alice wants to buy some fruits for herself and obviously, she will choose the shopkeeper who can fulfil her demands at the least cost possible. Find the shopkeeper from which she will buy and the amount she will pay for her purchase.


Input


The first line of the input contains a positive integer n


Each of the next n lines contain 8 non-negative integers.

Let us say, the numbers on ith such line are a A b B m M o O.

Here,

a = quantity of apples that the ith shopkeeper has.

A = price charged by the ith shopkeeper for 1 kg of apples.

b = quantity of bananas that the ith shopkeeper has.

B = price charged by the ith shopkeeper for 1 kg of bananas.

m = quantity of mangoes that the ith shopkeeper has.

M = price charged by the ith shopkeeper for 1 kg of mangoes.

o = quantity of oranges that the ith shopkeeper has.

O = price charged by the ith shopkeeper for 1 kg of oranges.


The next line contains four non-negative integers, x y z w.

Here,

x = quantity of apples that Alice wants to buy.

y = quantity of bananas that Alice wants to buy.

z = quantity of mangoes that Alice wants to buy.

w = quantity of oranges that Alice wants to buy.



Output


Print on a single line (space separated) the index number of the shopkeeper from whom Alice buys the fruits (if there are multiple such shopkeepers, print the least index) and the amount she pays for her purchase. Print -1 if no shopkeeper is able to fulfil her demands.


Note:

Solutions that do not use structs will be awarded ZERO points.

It is MANDATORY to use struct for storing the information of the shopkeepers.


Examples:


Input 1

1

10 10 20 20 30 30 40 40

5 10 15 20


Output 1

1 1500


Explanation 1

There is only 1 shopkeeper (index 1) and he can fulfil Alice's demands. Alice will have to pay him a total of 5*10 + 10*20 + 15*30 + 20*40 = 1500


Input 2

2

1 2 1 4 1 8 1 16

4 10 3 10 2 10 1 10

1 2 3 4


Output 2

-1


Explanation 2

It is clear that none of the two shopkeepers can fulfil Alice's demands, hence the output is -1.


Hidden Test Cases:

In hidden.txt


Grading Scheme: 2*0.5 + 7*2 = 15*/

// solution:

#include <stdio.h>
struct shopkeeper
{
    int a;
    int A;
    int b;
    int B;
    int m;
    int M;
    int o;
    int O;
};
struct fruit
{
    int x;
    int y;
    int z;
    int w;
};
int fulfill(struct shopkeeper func, struct fruit alice)
{
    if (func.a < alice.x)
    {
        return 0;
    }
    if (func.b < alice.y)
    {
        return 0;
    }
    if (func.m < alice.z)
    {
        return 0;
    }
    if (func.o < alice.w)
    {
        return 0;
    }
    return 1;
}
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    struct shopkeeper arr[n];
    int brr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &arr[i].a, &arr[i].A, &arr[i].b, &arr[i].B);
        scanf("%d %d %d %d", &arr[i].m, &arr[i].M, &arr[i].o, &arr[i].O);
    }
    struct fruit alice;
    scanf("%d %d %d %d", &alice.x, &alice.y, &alice.z, &alice.w);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (fulfill(arr[i], alice) == 1)
        {
            brr[i] = 1;
            count++;
        }
        else
        {
            brr[i] = 0;
        }
    }
    if (count == 0)
    {
        printf("-1");
        return 0;
    }
    int cost = 1e9 + 7;
    int index;
    for (int i = n - 1; i >= 0; i--)
    {
        if (brr[i] == 1)
        {
            int price = alice.x * arr[i].A + alice.y * arr[i].B + alice.z * arr[i].M + alice.w * arr[i].O;
            if (price <= cost)
            {
                index = i;
                cost = price;
            }
        }
    }
    printf("%d %d", index + 1, cost);
    return 0;
}