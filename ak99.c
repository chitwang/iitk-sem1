/*[40 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  2.5 marks  for each visible test cases. Total = 2.5*2 = 5Marks

Hidden:  5 marks  each for all hidden test cases. Total = 5*7 = 35 Marks



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0"); 
50% penalty for not using the provided template.

Header files allowed - stdio.h, stdlib.h, math.h
-----------------------------------------------------------------------------------------

Planet AK-99



NASA scientists discovered a newly planet which also supports life, Planet AK-99. The people living in the planet are still developing mathematics, and have yet discovered only one 2D geometry figure - the triangle. NASA have decided to help them teach but they want to test the knowledge of humans first. NASA have decided to send you as their representative. Their problem statement goes as follows :


You will be provided some number of triangles. For each triangle, you need to report its area. Also, you need to tell for every trianle how many trianles are contained inside it. 


Note 
A is present in B if and only if there is no part of A that lies outside of B.


Input Format



The first line contains one integer n1. n1 represents the number of trianles.

Each of next n1 lines contain 6 numbers (separated by space), representing the three points of each trianle. The vertices will be in order x1,y1,x2,y2,x3,y3. Here xi and yi represented the x and y cordinates of ith vertex respectively.


Output Format



There will be a total of n1 lines in output.

Each of the n1 lines will have 2 outputs separated by spaces, corresponding to ith triangle. The first output will be number with the area of the triangle rounded off till 3 decimal places. The second number will be an integer, the number of triangles which are present in the ith triangle.


  Constraints:



1 < n1 <= 10.

You need to define and use the structures provided in the template code.

Use pi = 3.14159

You are allowed to use sqrt() and fabs() of math.h.


Public Test Cases

Input	              Output
1
0 0 1 1 1 0	          0.500 0


3
0 0 4 -3 4 3          12.000 1
0 1 1 1 0.5 0.5       0.250 0
2 1.5 3 1.3 3 -2	  1.650 0
Explanation


Marking Scheme


2*5 marks for public test cases 

5 marks for each hidden test cases

2*5+7*5 = 45 marks */

//solution:

