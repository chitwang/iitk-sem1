/*Given a doubly-linked list (say of n nodes where n > 0), rearrange the links between the nodes of the linked list such that the entire list is reversed in order. An example is described below.


Initial linked list:
1 → 2 → 3 → 4 → 5


Final linked list:
5 → 4 → 3 → 2 → 1


Note:



The nodes in the linked list are of the following structure.
struct node {
  int data;
  struct node* next;
};

Arrays are prohibited. No marks will be given if arrays are used.

Make sure that you actually rearrange the links in the list. Penalty will be imposed if the data field of any node is changed at any point after taking input.

Do not modify the print() function given in the template. Use this function to print the output by providing as argument, the pointer to the head node of the final doubly-linked list. Do not use any other printf() statement in the program.

It is guaranteed that the linked list given is not empty.


INPUT: One line which contains a stream of integers that ends with -1 (not to be included) which represents the linked list. It is guaranteed that the linked list contains atleast one node.


OUTPUT: One line containing the stream of integers separated by spaces that represent the final linked list after reversal. You will only need to call the print() function defined in the template with the pointer to the head of the final linked list as argument. This function prints both lines in the required format.


Sample Input:


1 2 3 4 5 -1


Sample Output:


5 4 3 2 1*/

// solution:

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *node)
{
    while (node != NULL)
    {
        if (node->next)
            printf("%d ", node->data);
        else
            printf("%d", node->data);
        node = node->next;
    }
}
struct node *make_node(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;
    return new;
}

struct node *input(int stop)
{
    int x;
    scanf("%d", &x);
    struct node *head = make_node(x);
    struct node *curr, *prev;
    prev = head;
    scanf("%d", &x);
    while (x != stop)
    {
        curr = make_node(x);
        prev->next = curr;
        prev = curr;
        scanf("%d", &x);
    }
    return head;
}
struct node *reverse(struct node *head)
{
    struct node *cur = head, *pre = NULL, *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
int main()
{
    // write code here
    print(reverse(input(-1)));
    return 0;
}