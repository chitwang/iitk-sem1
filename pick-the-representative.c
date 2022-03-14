/*Your wing has come up with a hassle free solution to pick their wing representative! The N students sit in a circle. Starting from one student and moving around the circle in a clockwise manner the students are numbered from 1 to N. The students then pick a random positive integer k>0.


Counting begins from the student numbered 1 and proceeds around the circle in a clockwise direction. After each k-1 students, the kth student is eliminated from the contest. The circle keeps growing smaller and smaller as the eliminated contestants are removed. At last only one student remains, who is conferred the coveted post of Wing Representative !


Being an ESC101 student you decide to sabotage the plan. Given the number of students N and the number K, your task is to find the index of the student who would remain until the end and get chosen as the representative, so that you can make sure you are sitting at that index.


You must use a circular linked list to solve this question. Circular linked list is a linked list where all nodes are connected to form a circle. You will be graded out 10 if arrays are used.


The head of the linked list is the node with index 1.


Eg. Given N=5 and K=3


The initial linked list looks like:


->1->2->3->4->5--
|________________|
The elimination proceeds as follows:


START: 1 2 3 4 5 (Start counting from 1)
Step 1: 1 2 4 5 (3 is eliminated)
Step 2: 2 4 5 (1 is eliminated)
Step 3: 2 4 (5 is eliminates)
Step 4: 4 (2 is eliminated )
STOP: The Winning index is 4.


Struct node and global pointers to keep track of the head of the list have been given in the template. The template is given for you convenience. You may change it if you want to.
Given an int N and K. You must first create a circular linked list as described above and then perform the eliminations to determine the winning index.


INPUT: 2 space separated integers N and K
OUTPUT: A single integer.
Assume that N >= 1 and K >= 1


Sample Input:
5 3

Sample Output:
4*/

// solution:

#include <stdio.h>
#include <stdlib.h>

// Node in the circular linked list
struct node
{
    int num; // stores the index
    struct node *next;
};

// head of the circular linked list
struct node *head;

void create(int);
int eliminate(int);

int main()
{
    // Insert your code here
    int n;
    int k;
    scanf("%d %d", &n, &k);
    create(n);
    printf("%d", eliminate(k) - 1);
    return 0;
}

void create(int n)
{
    // Create a circular linked list of n students.
    head = (struct node *)malloc(sizeof(struct node));
    head->num = 1;
    head->next = NULL;
    struct node *prev;
    prev = head;
    struct node *new;
    for (int i = 2; i <= n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->num = i;
        new->next = NULL;
        prev->next = new;
        prev = new;
    }
    new->next = head;
}

int eliminate(int k)
{
    // Return winning index after the elimination.
    struct node *ptr = head;
    while (ptr->next != ptr)
    {
        for (int i = 0; i < k - 1; i++)
        {
            ptr = ptr->next;
        }
        struct node *temp;
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
    return ptr->num;
}
