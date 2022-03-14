/*Given a doubly-linked list (say of n nodes where n > 0) and a positive integer k, rearrange the links between the nodes of the linked list in the following way. The nodes of the linked list are divided into segments of k nodes. If k does not divide n, then the final segment is of n % k nodes. The order of nodes in alternate segments (1st, 3rd, 5th, ...) are to be reversed. An example is described below.


Initial linked list:
1 ↔ 2 ↔ 3 ↔ 4 ↔ 5 ↔ 6 ↔ 7 ↔ 8 ↔ 9 ↔ 0


Final linked list after rearrangement with k = 3:
3 ↔ 2 ↔ 1 ↔ 4 ↔ 5 ↔ 6 ↔ 9 ↔ 8 ↔ 7 ↔ 0


Note:



The nodes in the linked list are of the following structure.


struct node {
  int data;
  struct node* next;
  struct node* prev;
};

No marks will be given if doubly-linked list is not used.



Arrays are prohibited. No marks will be given if arrays are used.

Make sure that you rearrange the links in the list. A penalty will be imposed if the data field of any node is changed at any point after taking input.

Do not modify the print() function given in the template. Use this function to print the output by providing as an argument, the pointer to the head node of the final doubly-linked list. Do not use any other printf() statement in the program.

Make sure that the prev field of the head and the next field of the tail take NULL values.

It is guaranteed that the linked list given is not empty. Therefore, the head passed to print() should not be NULL.


Input Format:


The input consists of two lines. The first line is a stream of integers that ends with -1 (not to be included), representing the linked list. It is guaranteed that the linked list contains at least one node. The second line is a single positive integer representing k.


Output Format:


The output consists of two lines. The first line is a stream of integers separated by spaces representing the final linked list after transformation. The second line is also a stream of integers that represents the same final linked list but in reverse order.
You will only need to call the print() function defined in the template with the pointer to the head of the final doubly-linked list as an argument. This function prints both lines in the required format.


Example

Input:


1 2 3 4 5 6 7 8 9 0 -1
3

Output:


3 2 1 4 5 6 9 8 7 0
0 7 8 9 6 5 4 1 2 3

Explanation:
Segment 1: 1 2 3 → 3 2 1
Segment 2: 4 5 6 → 4 5 6
Segment 3: 7 8 9 → 9 8 7
Segment 4: 0 → 0



- No marks to be given if arrays are used.
- 50% penalty if the `data` field of any node is changed at any point after being input.

Public Test Cases (1 * 5 = 5 marks)
Hidden Test Cases (5 * 8 = 40 marks)*/

// solution:

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *insert(struct node *head, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        return head;
    }
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}
struct node *reverse(struct node *head)
{
    struct node *temp = NULL;
    struct node *curr = head;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }
    return head;
}
struct node *combine(struct node *a, struct node *b)
{
    if (a == NULL)
    {
        return b;
    }
    struct node *temp = a;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = b;
    b->prev = temp;
    return a;
}
struct node *func(struct node *head, int k)
{
    struct node *result = NULL;
    struct node *ptr = head;
    int count = 1;
    while (ptr != NULL)
    {
        struct node *newhead = NULL;
        for (int i = 0; i < k && ptr != NULL; i++)
        {
            newhead = insert(newhead, ptr->data);
            ptr = ptr->next;
        }
        if (count % 2 != 0)
        {
            struct node *z = reverse(newhead);
            result = combine(result, z);
        }
        else
        {
            result = combine(result, newhead);
        }
        count++;
    }
    return result;
}
void print(struct node *head)
{
    if (head == NULL)
    {
        printf("ERROR - Head is never NULL");
        return;
    }
    while (head->next != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
    while (head->prev != NULL)
    {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("%d", head->data);
    return;
}

int main()
{
    int x;
    int k;
    scanf("%d", &x);
    struct node *head = NULL;
    while (x != -1)
    {
        head = insert(head, x);
        scanf("%d", &x);
    }
    scanf("%d", &k);
    print(func(head, k));
    return 0;
}