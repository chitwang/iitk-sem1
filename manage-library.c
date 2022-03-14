/*[35 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  1 ,  2  and  2  marks for first, second and third visible test cases. Total = 5 Marks

Hidden:  6  each for all hidden test cases. Total = 30 Marks



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Header files allowed - stdio.h, stdlib.h
0 marks for not using template.
-----------------------------------------------------------------------------------------
In this problem, you are going to use structures and dynamic memory allocation to represent the state of a library. This library is arranged as multiple stacks of books in shelves of different sizes. Books can be removed and added to stacks.


When a stack becomes equal in size to the capacity of the shelf, it is moved from the current shelf to a shelf with twice the current capacity. The capacity of the shelves can only be powers of 2 (i.e. 1, 2, 4, 8 .....). For example if in a stack there were 3 books and it was in a shelf with a capacity of 4, and another book was added, then this stack is moved from the current shelf to a shelf with a capacity of 8.


If a book is removed from a stack, and the number of books in the stack falls below half of the maximum capacity of the current shelf, the book is moved to a shelf with capacity equal to half the capacity of the current shelf. For example if a stack has 4 books and is placed in a shelf with a capacity of 8, and then a book is removed, then the stack is moved to a shelf with a capacity of 4.


You can assume that there are infite shelves of each possible capacity. But the number of stacks will not change, i.e, we can add a book to only one of the existing stacks, and no new stacks will be created. However each stack starts out with 0 books in a shelf with capacity 1.


Note that books can only be removed and added to the end of the stack. For example if the stack has the following 3 books : A, B, C, and then a book D is added, then the stack will look like A, B, C, D. If removed is called then, the stack would look like A, B, C.


We will use the following structs to represent a book and a stack respectively :


struct Book
{
    /* data
    char name[20];
    char author[20];
};

struct Stack
{
    /* data
    struct Book * books;
    int num_books;
    int current_shelf_capacity;
};
In the Stack structure, books is supposed to be pointer pointing to array of size current_shelf_capacity. So for changing the shelf of the current stack, one will need to change the current_shelf_capacity, and also the size of the array pointed to by the books pointer(Hint : you can use what you learnt in dynamic memory allocation to accomplish this).


You will need to implement the following functions :


1.void add_book(struct Stack * s, struct Book b);
// adds a book to the stack of books, and updates the stack structure accordingly.
2.void remove_book(struct Stack * s);
// removes the most recently added book from the stack of books, and updates the stack structure accordingly.
3.struct Book get_most_recent_book(struct Stack * s);
// gets the book which was added most recently out of the books which are still remaining in the stack, note that the book still continues to be the part of the stack, it's NOT removed
4.void destroy_stack(struct Stack * s);
//frees all memory corresponding to the books of the current stack. Note that you do not need to free the memory corresponding the other fields of the stack structure, as that has not been dynamically allocated in this questions.
Note : You can be asked to remove from empty stack, in that case you should not do anything. You can be asked to get most recent book from empty stack, in that case return a book, with name "NA" (without quotes) and author "NA" (without quotes).


INPUT:

The input consists of n+2 lines, where n is the number of operations. The first line contains the number of stacks. The second line contains the number of operations.
The next n lines contains :
The first number in the line contains an opcode. Opcode 1, 2, and 3 correspond to addition, removal and get_most_recent respectively.


If the opcode is 1, the line contains which stack to do the operation on(going from 0 to number of stacks -1), then it contains the name of book and the name of the author. Both are strings with no spaces.


If the opcode is 2 or 3, the next thing in the line is the index of the stack.


OUTPUT:

You do not need to worry about the output, as all the output is printed in the template.
The output is the result of the opcode 3 operations, and in the end the status of all the stacks is printed. You can look at the main function in the template code, for the output.


Visible Test Case 1


Input:


1
3
1 0 a b
1 0 c d
1 0 e f


Output:


printing the status of the stacks
Stack Number 0, Shelf capacity 4
a b
c d
e f


Explanation:


1 0 a b - a, b is put on stack, and then the capacity of the shelf goes from 1 to 2, as the size of stack becomes equal to the shelf capacity
1 0 c d - c, d is put on the stack, then the capacity of the shelf goes from 2 to 4
1 0 e f - e, f is put on the stack, then the capacity remains the same as the stack size is not equal to the shelf capacity

Visible Test Case 2


Input:


1
3
1 0 a b
2 0
3 0

1 0 a b - a, b is put on stack, and then the capacity of the shelf is increased from 1 to 2, as the size of stack becomes equal to the shelf capacity
2 0 - a, b is removed from the stack, and the shelf capacity is reduced from 2 to 1, as the size of stack becomes 0 which is less than half of 2.


Output:


NA NA
printing the status of the stacks
Stack Number 0, Shelf capacity 1

Visible Test Case 3


Input:


1
5
1 0 a b
2 0
2 0
1 0 c d
3 0


Output:


c d
printing the status of the stacks
Stack Number 0, Shelf capacity 2
c d


Explanation:


1 0 a b - First a, b is put on the stack
2 0 - Then it is removed.
2 0 - The stack is empty right now, and hence nothing is done
1 0 c d - c, d is put on the stack
3 0 - c, d is on the top of the stack and hence that is printed*/

// solution

#include <stdio.h>
#include <stdlib.h>

struct Book
{
    /* data */
    char name[20];
    char author[20];
};

struct Stack
{
    /* data */
    struct Book *books;
    int num_books;
    int current_shelf_capacity;
};

void init_stack(struct Stack *s)
{
    s->books = (struct Book *)malloc(sizeof(struct Book));
    s->num_books = 0;
    s->current_shelf_capacity = 1;
}

void print_stack(struct Stack *s)
{
    for (int i = 0; i < s->num_books; i++)
    {
        printf("%s %s\n", s->books[i].name, s->books[i].author);
    }
}

void add_book(struct Stack *s, struct Book b)
{
    struct Book *new;
    if (s->current_shelf_capacity - 1 == s->num_books)
    {
        new = (struct Book *)malloc((s->current_shelf_capacity * 2) * sizeof(struct Book));
        s->current_shelf_capacity *= 2;
    }
    else
    {
        new = (struct Book *)malloc((s->num_books + 1) * sizeof(struct Book));
    }
    for (int i = 0; i < s->num_books; i++)
    {
        *(new + i) = s->books[i];
    }
    *(new + s->num_books) = b;
    s->books = new;
}
// adds a book to the stack of books, and updates the stack structure accordingly.
void remove_book(struct Stack *s)
{
    // struct Book *new = (struct Book*)malloc((num_books-1)*sizeof(struct Book));
    struct Book *new;
    if (s->num_books - 1 < s->current_shelf_capacity / 2)
    {
        new = (struct Book *)malloc((s->current_shelf_capacity / 2) * sizeof(struct Book));
        s->current_shelf_capacity /= 2;
    }
    else
    {
        new = (struct Book *)malloc((s->num_books - 1) * sizeof(struct Book));
    }
    for (int i = 0; i < s->num_books - 1; i++)
    {
        *(new + i) = s->books[i];
    }
    s->books = new;
    return;
}
// removes a book from the stack of books, and updates the stack structure accordingly.
struct Book get_most_recent_book(struct Stack *s)
{
    if (s == NULL)
    {
        struct Book ans; //= (struct Book*)malloc(sizeof(struct Book));
        ans.name[0] = 'N';
        ans.name[1] = 'A';
        ans.author[0] = 'N';
        ans.author[1] = 'A';
        return ans;
    }
    struct Book ans;
    ans = *(s->books + s->num_books - 1);
    return ans;
}
// gets the book which was added most recently, but does not delete it from the stack
void destroy_stack(struct Stack *s)
{
}
// frees all memory corresponding to the books of the current stack current stack

int main()
{
    int num_stacks;
    scanf("%d", &num_stacks);
    struct Stack stacks[num_stacks];

    for (int i = 0; i < num_stacks; i++)
    {
        init_stack(&stacks[i]);
    }

    int num_ops;
    scanf("%d", &num_ops);
    for (int i = 0; i < num_ops; i++)
    {
        int opcode;
        scanf("%d", &opcode);
        if (opcode == 1)
        {
            // add book
            int stack_num;
            scanf("%d", &stack_num);
            struct Book b;
            scanf("%s %s", b.name, b.author);
            add_book(&stacks[stack_num], b);
            // printf("done op\n");
            // printf("added %s %s to stack %d, the current shelf capacity is %d\n", b.name, b.author, stack_num, stacks[stack_num].current_shelf_capacity);
        }
        else if (opcode == 2)
        {
            // remove book
            int stack_num;
            scanf("%d", &stack_num);
            struct Book book_to_remove = get_most_recent_book(&stacks[stack_num]);
            remove_book(&stacks[stack_num]);
            // printf("removed %s %s from stack %d, the current shelf capacity is %d\n", book_to_remove.name, book_to_remove.author, stack_num, stacks[stack_num].current_shelf_capacity);
        }
        else if (opcode == 3)
        {
            // get the topmost book
            int stack_num;
            scanf("%d", &stack_num);
            struct Book b = get_most_recent_book(&stacks[stack_num]);
            printf("%s %s", b.name, b.author);
            printf("\n");
        }
    }

    printf("printing the status of the stacks\n");
    for (int i = 0; i < num_stacks; i++)
    {
        printf("Stack Number %d, Shelf capacity %d\n", i, stacks[i].current_shelf_capacity);
        print_stack(&stacks[i]);
    }

    for (int i = 0; i < num_stacks; i++)
    {
        destroy_stack(&stacks[i]);
    }

    return 0;
}