/*Automated Grading Scheme:

Visible: 5 marks for each visible test case.

Hidden: 5 marks for each Hidden test case.


Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% for using any future concepts


------------------------------------------------------------

The Hidden Key

This semester, Rohan took a course on cryptography. Being lazy, he was not able to complete his assignment on time so now he needs your help in completing his assignment on time. The assignment is as follows.

You will be given an input consisting of three lines.

In the first line, you will be given a positive integer n which will denote the size of message. In the next line, you will be given n space separated integers denoting the original message. The third line will also contain n space separated integers denoting the encrypted message.

The encrypted message is obtained by adding a secret key to the original message, which itself is a message of length k (you do not know k). Since the message length may be longer than the length of the key, the key is repeated as many times as required.

For example, if the plain message is [1 2 3 4 5] and the key is [1 2], then we first repeat the key till we obtain 5 elements as [1 2 1 2 1]. Note that we omitted 2 since we require only 5 integers. We now add the corresponding elements of these two messages (original message and repeated key message) to get the encrypted message. So the encrypted message in this case will be [2 4 4 6 6].


Given the original and encrypted message, you need to find the secret key used to encrypt the message. If there is no such key, then print the message No Such Key!. If there exists a key, then you need to output 2 lines. The first line should contain k which is the size of the secret key and the second line should contain k space separated integers denoting the secret key (output should not contain trailing spaces). If there are more than one possible secret keys, then output the secret key of the smallest length.


Note:



Secret keys may be of any non-negative length.

As the example below indicates, the integers in the message as well as in the keys, may be negative or even zero.

Be careful about extra/missing lines and spaces in your output.

It is guaranteed that the message length will always be < 100.


Input Format:

The first line contains an integer n denoting size of the message.

The second line contains n space separated integers denoting the original message.

The third line contains n space separated integers denoting the encrypted message.


Ouput Format:

Print two lines. First line should contain k and the second line should contain k space separated integers.


Sample Input:

2

31 43

31 43


Sample Output

1

0


Explanation

The original and encrypted messages are same. The smallest possible key is of length 1. So the secret key is [0]. Note that [0 0] is also a secret key here but we need to output the key of smallest length.


Sample Input:

4

1 1 5 6

2 3 6 8


Sample Output

2

1 2


Explanation

Note that there also exists a key of length 4 here but we need to output only smallest length secret key.8*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int orig_msg[100], enc_msg[100];
    for (int i = 0; i < n; i = i + 1)
        scanf("%d", &orig_msg[i]);
    for (int i = 0; i < n; i = i + 1)
        scanf("%d", &enc_msg[i]);

    // Generate the repeated key
    int repeated_key[100];
    for (int i = 0; i < n; i = i + 1)
        repeated_key[i] = enc_msg[i] - orig_msg[i];

    // Check for all possible key lengths
    //  Observe that there always exists a key of length n
    int key_len = 0;
    for (key_len = 1; key_len <= n; key_len = key_len + 1)
    {
        int possible_flag = 1;
        for (int i = 0; i < n; i = i + 1)
        {
            if (repeated_key[i] != repeated_key[i % key_len])
            {
                possible_flag = 0;
                break;
            }
        }
        if (possible_flag == 1)
            break;
    }

    printf("%d\n", key_len);
    for (int i = 0; i < key_len; i = i + 1)
    {
        printf("%d", repeated_key[i]);
        if (i != key_len - 1)
            printf(" ");
    }
    return 0;
}
