The Angency
===========
a test from [UVAlive 5780](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3791)
--------------------------------------------------------------------


Following in the footsteps of a number of flight searching startups you want to create the first interplanetary travel website. Your first problem is to quickly find the cheapest way to travel between two planets. You have an advantage over your competitors because you have realized that all the planets and the flights between them have a special structure. Each planet is represented by a string of N bits and there is a flight between two planets if their N-bit strings differ in exactly one position.

The cost of a flight is the cost of landing on the destination planet. If the ith character in a planet's string is a 1 then the ith tax must be paid to land. The cost of landing on a planet is the sum of the applicable taxes.

Given the starting planet, ending planet, and cost of the ith tax compute the cheapest set of flights to get from the starting planet to the ending planet.

Input
------
Input for each test case will consist of two lines. The first line will have N (1$ \le$N$ \le$1, 000), the number of bits representing a planet; S, a string of N zeroes and ones representing the starting planet; and E, a string representing the ending planet in the same format. The second line will contain N integers the ith of which is the cost of the ith tax. All costs will be between 1 and 1,000,000. The input will be terminated by a line with a single `0'.

Output
------
For each test case output one number, the minimum cost to get from the starting planet to the ending planet, using the format given below.


Sample Input
------------
3 110 011
3 1 2
5 00000 11111
1 2 3 4 5
4 1111 1000
100 1 1 1
30 000000000000000000000000000000 111111111111111111111111111111
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
0

Sample Output
-------------
Case 1: 4
Case 2: 35
Case 3: 106
Case 4: 4960


Standard Input
--------------
[input](http://acm.ashland.edu/2011/Problem-Set/Data/A.in)

Standard Output
----------------
[output](http://acm.ashland.edu/2011/Problem-Set/Data/A.out) 
