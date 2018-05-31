A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid&nbsp;of integers, how many 3 x 3 &quot;magic square&quot; subgrids are there?&nbsp; (Each subgrid is contiguous).

&nbsp;

Example 1:


Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.


Note:


	1 &lt;= grid.length&nbsp;&lt;= 10
	1 &lt;= grid[0].length&nbsp;&lt;= 10
	0 &lt;= grid[i][j] &lt;= 15

