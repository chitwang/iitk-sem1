/*Automated Grading Scheme:

Visible:  5  marks for each visible test case.

Hidden:  5  marks for first four Hidden test case and  10  marks for last hidden test case.


Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0"); 
Penalty :  
-20% for using any future concepts
-50% marks for using global variable
-50% for static allocation of array, example : int mat[100] or similar declaration
0 marks for not using given template. It is mandatory to utilize each component of template.

------------------------------------------------------------
Mr. T has joined a hotel as an intern. The hotel has N lockers for the housekeeping staff.


T is tasked with managing the lockers. Let us assume that T assigns the locker i to one housekeeping staff. The value i is generated using the locker_index() function provided in the template. The locker_index() function takes the input ID of the housekeeping staff. If a locker is already occupied, T should not assign the locker to the staff.


T can perform the following operations.



Assign a locker to a staff

Remove a staff as the owner of the locker on request

Check whether a staff has already been assigned a locker

Stop the operations (i.e., program exit)



operations-code:
a : assign 
r : remove
s : search
e : exit

Constraints


Locker id starts from zero

Use of global variables are not allowed

Use of stdlib.h is allowed

staff_id starts from 1

N is always greater than equal to 2

The remove operation (r) is only invoked for staff having a locker



Input


The first line in each test case will contain the number of available lockers N.

Each line following the first line will be of the form  (ignore the angular brackets)

The last line will contain e denoting the end of input


Output


The program should print the correct message corresponding to each operation



Assign a locker to the staff (a):

Success: Print Locker assigned to staff .

Failure: Print Locker < locker_id> to already assigned to staff < staff_id >.



Remove a locker assigned to a staff (r):

Success: Print Removed staff < staff_id > from locker < locker_id >.



Search for a locker assigned to a staff (s):

Success: Print Found, locker < locker_id > assigned to staff < staff_id >.

Failure: Print No locker assigned to staff < staff_id >.





The program should output the status of lockers at the end of input using print_locker_status() function provided in the template



The locker status contains the locker ID and staff ID to whom the locker is assigned in the format :

If a locker is not assigned to any staff, do not print the details


Sample Test Case 

Input


3
a 2
a 3
s 5
s 3
a 5
e

Output


Locker 1 assigned to staff 2.
Locker 2 assigned to staff 3.
No locker assigned to staff 5.
Found, locker 2 assigned to staff 3.
Locker 1 is already assigned to staff 2.
1:2 2:3
*/


//solution:

#include <stdio.h>
#include <stdlib.h>

// DO NOT MODIFY THE FUNCTION
// N is the number of lockers in hotel
int locker_index(int staff_id, int N)
{
    int index = 0;
    index = (staff_id + 5) % N;
    return index;
}

// EDIT THIS FUNCTION
void assign(int staff_id, int *locker, int n)
{
    // ...
    int x = locker_index(staff_id, n);
    if (locker[x] != 0)
    {
        printf("Locker %d is already assigned to staff %d.\n", x, locker[x]);
        return;
    }
    locker[x] = staff_id;
    printf("Locker %d assigned to staff %d.\n", x, staff_id);
    return;
}

// EDIT THIS FUNCTION
void removal(int *locker, int staff_id, int n)
{
    // ...
    for (int i = 0; i < n; i++)
    {
        if (locker[i] == staff_id)
        {
            locker[i] = 0;
            printf("Removed staff %d from locker %d.\n", staff_id, i);
            return;
        }
    }
}

// EDIT THIS FUNCTION
void search_assigned_locker(int *locker, int staff_id, int n)
{
    // ...
    for (int i = 0; i < n; i++)
    {
        if (locker[i] == staff_id)
        {
            printf("Found, locker %d assigned to staff %d.\n", i, staff_id);
            return;
        }
    }
    printf("No locker assigned to staff %d.\n", staff_id);
}

// DO NOT MODIFY THE FUNCTION
void print_locker_status(int *ptr, int size)
{
    int i = 0;
    for (; i < size; i++)
    {
        if (ptr[i] != 0)
            printf("%d:%d ", i, ptr[i]);
    }
    printf("\n");
}

int main()
{
    // ...
    int n;
    scanf("%d\n", &n);
    int *locker = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(locker + i) = 0;
    }
    char type;
    int staff_id;
    while (1)
    {
        scanf("%c", &type);
        if (type == 'a')
        {
            scanf("%d\n", &staff_id);
            assign(staff_id, locker, n);
        }
        else if (type == 's')
        {
            scanf("%d\n", &staff_id);
            search_assigned_locker(locker, staff_id, n);
        }
        else if (type == 'r')
        {
            scanf("%d\n", &staff_id);
            removal(locker, staff_id, n);
        }
        else if (type == 'e')
        {
            print_locker_status(locker, n);
            break;
        }
    }
    return 0;
}