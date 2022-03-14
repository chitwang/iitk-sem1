/*You are given n timestamped (time in seconds) data points of bitcoin prices. You have to find out the slope of the best fit line for these data points. And, also you have to guess the price of bitcoin at after given amount of time.


The slope of the best fit line , you can calculate as following:


slope=(∑iy[i]x[i])−ny¯∗x¯)/(∑ix[i]x[i])−nx¯∗x¯)
where, x¯ and  y¯ are the means of arrays x and y.

intercept=y¯−slope∗x¯

where x[i] and y[i] are the time and price of the ith data point respectively.


P.S: You are just about to solve a classic ML problem, if you see fair Future then start investing.


Input Format

First line of the input contains an integer n denoting the number of data points.


Second line of the input contains n space separated integers denoting the time in seconds for each data point.


Third line of the input contains n space separated float point numbers denoting the price (in USD) of bitcoin at the given time.


Last line of the input contains an integer t denoting the time after which you have to predict the price of bitcoin.


1 USD = 75.27 INR


Note: In all testcases the values of n , array x and array y are same, testcases only differ in the value of t.


Output Format

Print the price (in INR) of bitcoin at the given time.



input :

46
1514764440 1514763960 1514758500 1514752980 1493886360 1485596340 1485088020 1483228920 1546300620 1546289280 1527001380 1520202660 1516868940 1514764860 1577836500 1557265260 1560292080 1551212220 1546300920 1609459020 1600750440 1598593260 1598592960 1598589060 1590860100 1585650000 1582516080 1606043100 1609458720 1609458000 1609459080 1609458420 1609452120 1609446360 1609431780 1609427700 1609427400 1609419300 1609409280 1645774380 1645767000 1645761420 1628449620 1619105400 1612589700 1609459260
13884.14 13929.96 13981.75 14111.01 1536.99 918.93 912.88 966.16 3688.83 3682.93 8216.02 11371.54 11350 13841.01 7175.69 5858 7925.62 3805 3689.73 29039.53 10458.37 11376.2 11375.84 11378.45 9530.68 6449.63 9778.4 18126.44 29006.61 29050.59 29044.79 28975.4 29064.63 28976.38 28699.7 28660 28602.45 28695.65 29113.15 38516.84 38511.07 38906.22 43525.87 54485.15 38967.87 29007.31
1645796226

output
2572755.607622*/

// solution:

#include <stdio.h>

int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    long long int arr[n];
    long double sum = 0.0;
    long long int t;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        sum = sum + arr[i];
    }
    long double timeavg = sum / n;
    sum = 0.0;
    long double brr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%Lf", &brr[i]);
        sum = sum + brr[i];
    }
    scanf("%lld", &t);
    long double priceavg = sum / n;
    long double num = -1 * n * timeavg * priceavg;
    long double den = -1 * n * timeavg * timeavg;
    for (int i = 0; i < n; i++)
    {
        num = num + brr[i] * arr[i];
        den = den + arr[i] * arr[i];
    }
    long double slope = num / den;
    long double price = slope * t + priceavg - (slope * timeavg);
    long double ans = price * 75.27;
    printf("%Lf", ans + 0.0000005);
    return 0;
}