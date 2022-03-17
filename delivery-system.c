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

int strcmp(char *a, char *b)
{
    int id = 0;
    while (a[id] != '\0' && b[id] != '\0')
    {
        if (a[id] != b[id])
            return 0;
        id++;
    }
    if (a[id] == '\0' && b[id] == '\0')
        return 1;
    return 0;
}

int get_manufacturer_ID(char *manufacturer, char *partner_maufacturers[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(manufacturer, partner_maufacturers[i]))
            return i;
    }
    return -1;
}

struct node *Insert(struct node *head, char *partner_manufacturers[], int inside_queue[])
{
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    scanf("%d %s %s", &curr->prod_ID, curr->label, curr->manufacturer);
    curr->next = NULL;
    if (!head)
        head = curr;
    else
    {
        curr->next = head;
        head = curr;
    }
    printf("%d ADDED", curr->prod_ID);
    inside_queue[get_manufacturer_ID(curr->manufacturer, partner_manufacturers)]++;
    return curr;
}

struct node *Print(struct node *head, char *partner_manufacturers[], int inside_queue[], int delivered[])
{
    struct node *curr = head;
    struct node *prev = NULL;
    if (!curr)
    {
        printf("NOTHING TO DELIVER NOW");
        return NULL;
    }
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    int manufacturer_ID = get_manufacturer_ID(curr->manufacturer, partner_manufacturers);
    inside_queue[manufacturer_ID]--;
    delivered[manufacturer_ID]++;
    printf("%d %s %s", curr->prod_ID, curr->label, curr->manufacturer);
    if (!prev)
    {
        free(curr);
        return NULL;
    }
    prev->next = NULL;
    free(curr);
    return head;
}

void Query(int a[], char *partner_maufacturers[])
{
    char manufacturer[20];
    scanf("%s", manufacturer);
    int ID = get_manufacturer_ID(manufacturer, partner_maufacturers);
    if (ID == -1)
    {
        printf("-1");
        return;
    }
    printf("%d", a[ID]);
}

int main()
{
    int n;
    scanf("%d", &n);
    struct node *head = NULL;
    char *partner_manufacturers[] = {"Nike", "Adidas", "Reebok", "Puma", "Diadora"};
    int inside_queue[5] = {0};
    int delivered[5] = {0};
    for (int i = 0; i < n; i++)
    {
        int typ;
        scanf("%d", &typ);
        if (typ == 1)
            head = Insert(head, partner_manufacturers, inside_queue);
        else if (typ == 2)
            head = Print(head, partner_manufacturers, inside_queue, delivered);
        else if (typ == 3)
            Query(inside_queue, partner_manufacturers);
        else if (typ == 4)
            Query(delivered, partner_manufacturers);
        if (i < n - 1)
            printf("\n");
        struct node *curr = head;
    }
    struct node *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}
