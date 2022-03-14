/*Cricket is the most popular sport in India. The Indian cricket team has been lucky to have great world-class talents in their side. Today we have Virat Kohli, but back in the day, we had the God of cricket, Sachin Tendulkar. Both being such high-class talents, it is impossible for the fans to not compare them.


Suppose you are a data analyst at a sports analytics firm. You have been assigned the duty to find out what minimum runs Virat Kohli should score in the remaining matches, so that he overtakes Sachin as the best batsman in the history of the sport. As a newbie, you only like to work with integers. So, you need to first check if the average of Sachin is an integer or not. If it is not an integer, simply print "ERROR" (without quotes), other wise print "INTEGER". If it is an integer you need to calculate the runs Virat needs to score in order to overtake Sachin. Virat will overtake Sachin only if his total runs scored and his net average are both higher than that of Sachin's. In case of any equality, Sachin will be considered the better batsman.


Note: The average is calculated as the number of runs scored per match played.


Input Format:


The first line contains two numbers which represent the number of innings played by Sachin (M1) and the total runs scored by him (R1), respectively. The next line contains three numbers, the number of innings played by Virat Kohli (M2), total runs scored by him (R2) and the remaining matches he is yet to play(K).


All the inputs are positive integers.


Output Format:


If the average of Sachin is not an integer, simply print "ERROR" without quotes, else print "INTEGER". In case of integer average, you need to output the minimum runs (an integer) that Virat needs to score to overtake Sachin at the end of his career in the next line.


Example Test Cases

Input	Output
400 16000
 300 12000 50	INTEGER
 4001
----------
350 17500
 300 16500 100	INTEGER
 3501
----------
404 17300
 380 16300 40	ERROR


Explanation



In first sample test case, Virat needs to score atleast 4001 runs more in remaining 50 matches. Doing so, his total runs (16001) and average(~45.71) will be more than Sachin's runs(16000) and average(40).

In second test case, Sachin's runs are 17500 and his average is 50. Virat will need to score to atleast 3501 runs in remaining 100 matches. Doing so, his total runs will be 20001 and the average will be 50.0025, helping him overtake Sachin.

In third test case, average of Sachin is not an integer. Thus the corresponding output is 'ERROR'.*/

// solution:

#include <stdio.h>

int main()
{
    int M1;
    int R1;
    int M2;
    int R2;
    int K;
    int Vtotal; // Vtotal is used for runs so that total runs of Virat are more
                // than that of Sachin.
    int Vavg;   // Vavg is used for runs so that average of Virat is more than
              //  that of Sachin.
    scanf("%d", &M1);
    scanf("%d\n", &R1);
    scanf("%d", &M2);
    scanf("%d", &R2);
    scanf("%d", &K);
    if (R1 % M1 != 0)
    {
        printf("ERROR");
    }
    else
    {
        printf("INTEGER\n");
        Vtotal = R1 - R2;
        Vavg = (((R1) * (M2 + K)) / M1) - R2;
        if (R1 > R2)
        {
            if (Vavg > Vtotal)
            {
                printf("%d", Vavg + 1);
            }
            else
            {
                printf("%d", Vtotal + 1);
            }
        }
        else if (R1 <= R2)
        {
            if (Vavg > 0)
            {
                printf("%d", Vavg + 1);
            }
            else
            {
                printf("0");
            }
        }
    }
    return 0;
}