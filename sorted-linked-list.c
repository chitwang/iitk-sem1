/*In this exercise we will implement sorted linked lists.  The usual way to implement it is using "structures" in C, but since you have just started learning about structures, we'll implement it using arrays.


THEORY
A linked list is made up of nodes. Each node contains a number,  and a right link. We've written a function which on being called returns a node. Our implementation of a node is an array of size 2 which contains void pointers. The first entry is supposed to  contain  the address of an integer which can be used to store the value of this node.  The second entry contains an address to the next node in the linked list. If there is no next node in the list (which means this is the last node), then it's second entry would contain NULL.  Though this is an array of void, you can cast the address stored in the first entry to make it int and then access the integer.  (As shown in class)


Some sample lists:


|  2  |  2522  | ----->   |  4  |  8422  | ---------->  |  9 |  NULL  |
Property 1 :  In a sorted linked list the invariant property is that whenever you are at a node N containing integer k, the integers in the nodes to the left of N will have integers <=k and  those to the right must have integers >=k.


Given n integers, you have to build a sorted linked list from them. Make a function insert(value1) which inserts the integer "value1" in the tree  by first making a node and then placing it in the linked list  such that the modified list  satisfies Property 1 at the end of the insertion. The address of the first node of the list is stored in the global variable called root.  Basically you have to start from root and then keep on progressing through the list until you find a number which is greater than value1. Let's say that the first such  node that you find is N2. And the node before N2 was N1. So now we know that N1 stores a number <=value1 and N2 has a number >=value1. Now we make a new node N, insert value1 into it. And then make N1 point to N, and N point to N2. And you're done. But what if there is no N1? Or if all the nodes in the list have values <=value1 ? Think about these scenarios yourself.


INPUT

First line contains n, ie. the number of integers to follow.
Second line contains n space separated integers.


OUTPUT

Output the integers in a sorted fashion separated with spaces


Public test cases:


Public test cases:
Input
3
24 1 4
Output
1 4 24

Note: You are not allowed to create an array anywhere in your code. You can call getNode() function which allocates and returns an array. Apart from these arrays that you get from  getNode(), you are not allowed to make any arrays. You are not allowed to use structures.*/

// solution:

#include <stdio.h>
#include <stdlib.h>

void **root;

void **getNode()
{
    void **temp = calloc(2, sizeof(void *));
    temp[0] = malloc(sizeof(int));
    return temp;
}

void insert(int value)
{

    void **prev = 0;
    void **cur = root;
    void **temp;

    while (cur != 0)
    {
        int curnum = *(int *)cur[0];
        if (curnum >= value)
            break;

        temp = cur;
        cur = (void **)cur[1];
        prev = temp;
    }

    if (prev == 0) // if we have to enter at the beginning
    {
        temp = getNode();
        *(int *)temp[0] = value;
        temp[1] = root;
        root = temp;
    }
    else
    {
        temp = getNode();
        *(int *)temp[0] = value;
        temp[1] = prev[1];
        prev[1] = temp;
    }
}

void print(void **node)
{
    printf("%d ", *(int *)node[0]);

    if (node[1] != 0)
        print((void **)node[1]);
}

int main()
{

    int n;
    scanf("%d", &n);

    root = getNode();
    scanf("%d", (int *)root[0]);

    int temp;
    int i;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &temp);

        insert(temp);
    }

    print(root);

    return 0;
}
