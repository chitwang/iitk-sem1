/*Numbers are represented as linked lists such that each digit of a number corresponds to a node in the linked list. You have to add 1 to such a representation. For example, 1999 is represented as (1->9->9->9) and adding 1 to it should change it to (2->0->0->0). Note that the units place will be the tail.


You are required to input n and store it in a linked list representation as mentioned above. Then, you are required to process this linked list by adding 1, also as mentioned above. Then, print the final linked list by calling the print() function given. The argument to this function should be the pointer to the head of the final linked list.


Notes: You are supposed to add 1 to the linked-list representation. Adding directly to the input number before creating the linked list will result in a penalty. No marks if linked-lists are not used.


INPUT: The number n (given that n is a non-negative integer).
OUTPUT: The number n + 1. You have to call the print() function defined with the pointer to the head of the linked list as argument. Usage of printf() other than the print() function in the template is not allowed. Do not change this function.


Sample Input:


1999


Sample Output:


2000*/

// solution:

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int digit;
    struct Node *next;
};

void print(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d", node->digit);
        node = node->next;
    }
}

struct Node *make_node(int x)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->digit = x;
    new->next = NULL;
    return new;
}

struct Node *makelistofinteger(int n)
{
    struct Node *head = make_node(n % 10);
    n = n / 10;
    struct Node *curr, *prev;
    prev = head;
    while (n)
    {
        curr = make_node(n % 10);
        n = n / 10;
        prev->next = curr;
        prev = curr;
    }
    return head;
}
struct Node *add(struct Node *head)
{
    struct Node *ptr = head;
    int carry = 1;
    while (ptr->next != NULL)
    {
        int g = ptr->digit + carry;
        ptr->digit = g % 10;
        carry = g / 10;
        ptr = ptr->next;
    }
    ptr->digit = carry + ptr->digit;
    return head;
}
struct Node *reverse(struct Node *head)
{
    struct Node *cur = head, *pre = NULL, *next = NULL;
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
    int n;
    scanf("%d", &n);
    print(reverse(add(makelistofinteger(n))));
    return 0;
}
