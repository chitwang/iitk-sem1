/*[30 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Public Test Cases (2.5 point each. 2.5*2 = 5 points)
Hidden Test Cases (5 point each. 5*5 = 25 points)

Manual Grading Scheme
Note: Any form of hard-coding will lead to zero marks. Eg: printf("0");
Penalty: -15 marks for use of any inbuilt function to calculate GCD or LCM.
----------------------------------------------------------------------

Suppose you are a part of a 22 member squad of IITK Football team. Inter IIT is coming around, so it is important for the team to start training.

The first day of training is simply jogging. Since it is the first day, not all team members need to be present. Every team member jogs around the field at their own pace and hence takes a different time to complete a single round. To track the time, the coach uses a stopwatch. All of them start from the same starting point. The stopwatch reads 00:00:00 at the time of start. The coach wants to know how many times any two players meet each other at the starting point in the whole jogging period. He would also like to know how many times will the whole team meet at the starting point together. The final reading of the stopwatch after training is hh:mm:ss.

In case multiple team members are at the starting point simultaneously, each pair is counted individually towards the result of the first part.

Input Format


    The first line contains the number of team members (n) out of 22 that showed up at training that day.

    The second line contains the final reading of the stopwatch. It is provided in a character array format. The number of characters is 8. The character array looks like hh:mm:ss, where hh represents the hours, mm represents the minutes, and ss represents the seconds.

    The third and the last line contains n positive integers ai, representing the time taken (in seconds) by the n team members to complete a single round of the field.


Output Format


    The first line of the output should represent the number of times any two players meet at the starting point during the total training.

    The second line of the output must represent the number of times the whole squad meets together at the starting point.

    Constraints:


    1 < n <= 22


    0 < ai <= 1000 for i ?

     [0,n-1]

    The total jogging duration will not be greater than 12 hours.

    Hours (hh) <= 12, Minutes (mm) < 60, Seconds (ss) < 60

    You are only allowed to use Standard Input-Output library.


Public Test Cases

Sample Input 1

3
00:10:00
50 100 150

Sample Ouput 1

12
 2



Sample Input 2

 6
02:00:00
40 40 40 40 40 40

Sample Ouput 2

2700
 180

Explanation

In the first test case, only 3 players showed up at training, and the training was only for 10 minutes. The players took 50, 100, and 150 seconds to run around the field. Players 1 and 2 will meet at the starting point after every 100s, thus meeting 6 times in total. Players 2 and 3 meet after every 300s at the starting point, making them meet 2 times during the 10 minutes. Players 1 and 3 meet after 150s, thus meeting 4 times in total. Hence, the total number of times the players meet are 6+4+2 = 12. All three players will meet together at every 300s, hence making them meet 2 times in 10 minutes.*/

// solution:

#include <stdio.h>
int lcm(int a, int b)
{
    int temp;
    if (b < a)
    {
        temp = b;
        b = a;
        a = temp;
    }
    int ta = a;
    int tb = b;
    while (ta != 0)
    {
        temp = ta;
        ta = tb % ta;
        tb = temp;
    }
    int hcf = tb;
    int lcm = (a * b) / hcf;
    return lcm;
}
int main()
{
    int n;
    int ttime;
    scanf("%d", &n);
    getchar();
    char arr[8];
    int brr[n];
    for (int i = 0; i < 8; i++)
    {
        scanf("%c", &arr[i]);
    }
    arr[0] = arr[0] - 48;
    arr[1] = arr[1] - 48;
    arr[3] = arr[3] - 48;
    arr[4] = arr[4] - 48;
    arr[6] = arr[6] - 48;
    arr[7] = arr[7] - 48;
    ttime = (arr[0] * 10 + arr[1]) * 3600 + (arr[3] * 10 + arr[4]) * 60 + arr[6] * 10 + arr[7];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &brr[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            count += ttime / lcm(brr[i], brr[j]);
        }
    }
    printf("%d\n", count);
    int x = brr[0];
    for (int i = 0; i < n; i++)
    {
        x = lcm(x, brr[i]);
    }
    printf("%d", ttime / x);
    return 0;
}