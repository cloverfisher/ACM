Wally World
===========
[Wally World](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3799)

Two star-crossed lovers want to meet. The two lovers are standing at distinct points in the plane (but then again, aren't we all?). They can travel freely except that there is a single wall which cannot be crossed. The wall is a line segment which is parallel to either the x or y axis. Each lover can move 1 unit in 1 second. How long will it take them to be together if they both choose the best path?

Input
------
Input for each test case will consist of two lines each containing four integers. The first two integers will specify the x and y coordinates of the first lover; the next two integers will specify the x and y coordinates of the second lover. The next four integers will specify the start and end points of the wall. Furthermore, in all cases both lovers will not be on the (infinite) line containing the wall -- that is, the wall extended in both directions. All coordinates will be positive and less than or equal to 10000 and neither lover will start on the wall. The input will be terminated by a line containing four zeroes.

Output
------
For each test case, output the minimum time in seconds for the two lovers to meet. Print the answer to exactly 3 decimal places, using the output format shown in the example.

Sample Input 
-------------
5 2 7 2
1 1 1 100
1 2 3 2
2 1 2 100
0 0 0 0


Sample Output
--------------
Case 1: 1.000
Case 2: 1.414