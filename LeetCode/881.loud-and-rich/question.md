In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different amounts of money, and different levels of quietness.

For convenience, we&#39;ll call the person with label x, simply &quot;person x&quot;.

We&#39;ll say that richer[i] = [x, y] if person x&nbsp;definitely has more money than person&nbsp;y.&nbsp; Note that richer&nbsp;may only be a subset of valid observations.

Also, we&#39;ll say quiet[x] = q if person x&nbsp;has quietness q.

Now, return answer, where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]), among all people&nbsp;who definitely have&nbsp;equal to or more money than person x.

&nbsp;


Example 1:


Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
Explanation: 
answer[0] = 5.
Person 5 has more money than 3, which has more money than 1, which has more money than 0.
The only person who is quieter (has lower quiet[x]) is person 7, but
it isn&#39;t clear if they have more money than person 0.

answer[7] = 7.
Among all people that definitely have equal to or more money than person 7
(which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x])
is person 7.

The other answers can be filled out with similar reasoning.



Note:


	1 &lt;= quiet.length = N &lt;= 500
	0 &lt;= quiet[i] &lt; N, all quiet[i] are different.
	0 &lt;= richer.length &lt;= N * (N-1) / 2
	0 &lt;= richer[i][j] &lt; N
	richer[i][0] != richer[i][1]
	richer[i]&#39;s are all different.
	The&nbsp;observations in richer are all logically consistent.
