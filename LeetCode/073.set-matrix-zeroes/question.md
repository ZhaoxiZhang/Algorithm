Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:


Input: 
[
&nbsp; [1,1,1],
&nbsp; [1,0,1],
&nbsp; [1,1,1]
]
Output: 
[
&nbsp; [1,0,1],
&nbsp; [0,0,0],
&nbsp; [1,0,1]
]


Example 2:


Input: 
[
&nbsp; [0,1,2,0],
&nbsp; [3,4,5,2],
&nbsp; [1,3,1,5]
]
Output: 
[
&nbsp; [0,0,0,0],
&nbsp; [0,4,5,0],
&nbsp; [0,3,1,0]
]


Follow up:


	A straight forward solution using O(mn) space is probably a bad idea.
	A simple improvement uses O(m + n) space, but still not the best solution.
	Could you devise a constant space solution?

