/*[100 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  10 for visible test case

Hidden:  30  each for all hidden test cases


----------------------------------------------------------------------

Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% each for using any library other than stdio.h, stdlib.h
- No marks if linked lists not used
- No marks if structure provided in template is tampered with in any way
----------------------------------------------------------------------


Problem Statement

This problem is aimed at giving you a flavor of designing a system.

You are approached by an online delivery shipping firm, which asks you to write them code for some tasks they face. The products they ship have some attributes, which are as follows:



Product ID (Integer) [This is unique for every product]

Product label (String)

Manufacturer (String)


All strings are of maximum length 100 and contain only alphanumeric characters.

The products arrive one by one, and a common queue is maintained for all of them. Also, there is a fixed set of manufacturers the company has a tie-up with:



Nike

Adidas

Reebok

Puma

Diadora


You are to automate some repetitive tasks. The tasks are as follows:

1) Add a new product to the queue.
2) Deliver the next product of the queue and print the product information delivered.
3) Query how many products of a given manufacturer is currently present in the queue.
4) Query how many products of a given manufacturer has been shipped already.


Initially, the product queue is empty. It is also guaranteed that when new products are added, all information is consistent, i.e., it is a valid product from a valid partner manufacturer.


**It is necessary to maintain the queue as a linked list and there is a penalty for not doing so.


Input Format

The first line contains an integer n, denoting the number of tasks to be performed.
The following n lines can be of the following types:



1 Product_ID Product_label Manufacturer (Eg. 1 12 Bottle Puma)

2

3 Manufacturer (Eg. 3 Adidas)

4 Manufacturer (Eg. 4 Nike)


Output Format

We are supposed to take the following actions for each type of input from {1,2,3,4,5}

1) Insert the product with the given attributes at the back of the queue. Then print Product_ID ADDED (Eg. 23 ADDED)
2) If the queue is non empty, remove the product at the front of the queue and print all 3 attributes of the delivered product in a space separated manner. If queue is empty, print NOTHING TO DELIVER NOW
3) Print an integer corresponding to the answer (print -1 if the manufacturer is not a partner manufacturer)
4) Print an integer corresponding to the answer (print -1 if the manufacturer is not a partner manufacturer)


Note that all outputs are in a new line.


Example Input

6
2
1 23 Bottle Adidas
1 56 Shoes Nike
3 Adidas
2
3 Adidas
Example Output

NOTHING TO DELIVER NOW
23 ADDED
56 ADDED
1
23 Bottle Adidas
0
Explanation

Initially, queue is empty. So nothing to deliver initially.
Then 2 products added.
Query return 1 since we have 1 product of Adidas.
Adidas product delivered, so details are printed.
Query returns 0, since Adidas product has been removed from queue.*/

// solution:

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int prod_ID;
    char label[100];
    char manufacturer[20];
    struct node *next;
};
struct node *insert(struct node *head, char labe[], char comp[], int id, int y, int z)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->prod_ID = id;
    for (int g = 0; g < y; g++)
    {
        new->label[g] = labe[g];
    }
    for (int g = 0; g < z; g++)
    {
        new->manufacturer[g] = comp[g];
    }
    if (head == NULL)
    {
        return new;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
        return head;
    }
}
struct node *delete (struct node *head)
{
    head = head->next;
    return head;
}
int coun(struct node *head, char w)
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->manufacturer[0] == w)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}
int main()
{
    //  Insert your code here.
    int type;
    int id;
    char labe[100];
    char comp[20];
    int n;
    int brr[5];
    scanf("%d", &n);
    struct node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &type);
        if (type == 1)
        {
            scanf("%d ", &id);
            int y = 0;
            char dummy;
            scanf("%c", &dummy);
            while (dummy != ' ')
            {
                labe[y] = dummy;
                y++;
                scanf("%c", &dummy);
            }
            int z;
            if (i == n - 1)
            {
                scanf("%c", &dummy);
                if (dummy == 'N')
                {
                    char com[4] = {'N', 'I', 'K', 'E'};
                    z = 4;
                    head = insert(head, labe, com, id, y, z);
                }
                else if (dummy == 'A')
                {
                    z = 6;
                    char com[6] = {'A', 'D', 'I', 'D', 'A', 'S'};
                    head = insert(head, labe, com, id, y, z);
                }
                else if (dummy == 'R')
                {
                    z = 6;
                    char com[6] = {'R', 'E', 'E', 'B', 'O', 'K'};
                    head = insert(head, labe, com, id, y, z);
                }
                else if (dummy == 'P')
                {
                    z = 4;
                    char com[4] = {'P', 'U', 'M', 'A'};
                    head = insert(head, labe, com, id, y, z);
                }
                else if (dummy == 'D')
                {
                    z = 7;
                    char com[7] = {'D', 'I', 'A', 'D', 'O', 'R', 'A'};
                    head = insert(head, labe, com, id, y, z);
                }
            }
            else
            {
                z = 0;
                scanf("%c", &dummy);
                while (dummy != '\n')
                {
                    comp[z] = dummy;
                    z++;
                    scanf("%c", &dummy);
                }
                head = insert(head, labe, comp, id, y, z);
            }
            printf("%d ADDED", id);
        }
        else if (type == 2)
        {
            if (head == NULL)
            {
                printf("NOTHING TO DELIVER NOW");
            }
            else
            {
                if (head->manufacturer[0] == 'N')
                {
                    brr[0]++;
                }
                else if (head->manufacturer[0] == 'A')
                {
                    brr[1]++;
                }
                else if (head->manufacturer[0] == 'R')
                {
                    brr[2]++;
                }
                else if (head->manufacturer[0] == 'P')
                {
                    brr[3]++;
                }
                else if (head->manufacturer[0] == 'D')
                {
                    brr[4]++;
                }
                printf("%d %s %s", head->prod_ID, head->label, head->manufacturer);

                head = delete (head);
            }
        }
        else if (type == 3)
        {
            char dummy;
            int y = 0;
            scanf("%c", &dummy);
            if (i == n - 1)
            {
                /* while(dummy != EOF)
             {
                 comp[y] = dummy;
                 y++;
                 scanf("%c" , &dummy);
             }*/
                comp[0] = dummy;
            }
            else
            {
                while (dummy != '\n')
                {
                    comp[y] = dummy;
                    y++;
                    scanf("%c", &dummy);
                }
            }
            if (!(comp[0] == 'N' || comp[0] == 'A' || comp[0] == 'R' || comp[0] == 'P' || comp[0] == 'D'))
            {
                printf("-1");
            }
            else
            {
                printf("%d", coun(head, comp[0]));
            }
        }
        else if (type == 4)
        {
            char dummy;
            int y = 0;
            scanf("%c", &dummy);
            if (i == n - 1)
            {
                /*while(dummy != EOF)
            {
                comp[y] = dummy;
                y++;
                scanf("%c" , &dummy);
            }*/
                comp[0] = dummy;
            }
            else
            {
                while (dummy != '\n')
                {
                    comp[y] = dummy;
                    y++;
                    scanf("%c", &dummy);
                }
            }
            if (comp[0] == 'N')
            {
                printf("%d", brr[0]);
            }
            else if (comp[0] == 'A')
            {
                printf("%d", brr[1]);
            }
            else if (comp[0] == 'R')
            {
                printf("%d", brr[2]);
            }
            else if (comp[0] == 'P')
            {
                printf("%d", brr[3]);
            }
            else if (comp[0] == 'D')
            {
                printf("%d", brr[4]);
            }
            else
            {
                printf("-1");
            }
        }
        printf("\n");
    }
    return 0;
}