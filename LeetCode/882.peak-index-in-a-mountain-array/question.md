Let&#39;s call an array A a mountain&nbsp;if the following properties hold:


	A.length &gt;= 3
	There exists some 0 &lt; i&nbsp;&lt; A.length - 1 such that A[0] &lt; A[1] &lt; ... A[i-1] &lt; A[i] &gt; A[i+1] &gt; ... &gt; A[A.length - 1]


Given an array that is definitely a mountain, return any&nbsp;i&nbsp;such that&nbsp;A[0] &lt; A[1] &lt; ... A[i-1] &lt; A[i] &gt; A[i+1] &gt; ... &gt; A[A.length - 1].

Example 1:


Input: [0,1,0]
Output: 1



Example 2:


Input: [0,2,1,0]
Output: 1


Note:


	3 &lt;= A.length &lt;= 10000
	0 &lt;= A[i] &lt;= 10^6
	A&nbsp;is a mountain, as defined above.
