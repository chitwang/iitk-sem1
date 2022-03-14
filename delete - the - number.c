/*Write a program that takes a linked list and a number n as input and deletes the n th last node (nth node from the end) of the list. For this problem, n=1 means "delete the last node," n=2 means "delete the second last node," and so on. If n is greater than the length of the list (denoted by len), then modulus operation is performed on the absolute value of n by len, i.e., (n-1)/%len + 1  th   is used.


Each node of a linked list must have the following structure.


struct node {
    int data;
    struct node* next;
};

NOTE


Use of ARRAYS IS NOT PERMITTED. You will get marks if you use linked lists to solve the problem.

The template contains initial code for list manipulation. You can modify it or use it as it is. DO NOT change the print function.

No marks if you do not really delete the node. The print function provided must work as-it-is to print the modified list.


INPUT

The input will consist of two lines containing the numbers. The first line will contain a stream of numbers. Keep accepting the input until you get a -1. The second line will contain a number n, n will fit in an int.


OUTPUT

Display the final linked list, with nth last node deleted from the linked list. You must use the provided print routine. It prints an X at the end to mark the end of the list.


Examples

INPUT

1 2 3 4 5 -1
1


OUTPUT

1 2 3 4 X




Marks: 50 marks
Public Test Case: 4 marks
Private Test Cases: 6*6=36 marks*/

// solution:

#include <stdio.h>
#include <stdlib.h>

// to store the link list
struct node
{
    int data;
    struct node *next;
};

// insertion in the list "head", at the END
struct node *insert(struct node *head, int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->next = NULL;
    n->data = data;
    if (head == NULL)
        return n;
    struct node *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = n;
    return head;
}
struct node *reverse(struct node *head)
{
    struct node *cur = head;
    struct node *pre = NULL;
    struct node *nex = NULL;
    while (cur != NULL)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}
// print the list "head"
void print(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("X\n");
    return;
}
struct node *delete (struct node *head, int n)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (n == 1)
    {
        head = head->next;
        return head;
    }
    struct node *ptr = head;
    struct node *ptr1 = head;
    int i = 0;
    while (i < n - 1)
    {
        ptr1 = ptr;
        ptr = ptr->next;
        i++;
    }
    if (ptr->next == NULL)
    {
        ptr1->next = NULL;
        return head;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return head;
}
int main()
{
    // Fill this area with your code.
    int x;
    struct node *head;
    scanf("%d", &x);
    int len = 0;
    while (x != -1)
    {
        head = insert(head, x);
        len++;
        scanf("%d", &x);
    }
    int n;
    scanf("%d", &n);
    if (n > len)
    {
        n = (n - 1) % len + 1;
    }
    struct node *v = reverse(head);
    print(reverse(delete (v, n)));
    return 0;
}