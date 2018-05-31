Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.&nbsp; For example, flipping&nbsp;[1, 1, 0]&nbsp;horizontally results in&nbsp;[0, 1, 1].

To invert an image means&nbsp;that each 0 is replaced by 1, and each 1 is replaced by 0.&nbsp;For example, inverting&nbsp;[0, 1, 1]&nbsp;results in&nbsp;[1, 0, 0].

Example 1:


Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]


Example 2:


Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]


Notes:


	1 &lt;= A.length = A[0].length &lt;= 20
	0 &lt;= A[i][j]&nbsp;&lt;=&nbsp;1
