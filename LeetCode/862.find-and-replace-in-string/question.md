To some string S, we will perform some&nbsp;replacement&nbsp;operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word&nbsp;x&nbsp;and a target word&nbsp;y.&nbsp; The rule is that if x&nbsp;starts at position i&nbsp;in the original string S, then we will replace that occurrence of&nbsp;x&nbsp;with&nbsp;y.&nbsp; If not, we do nothing.

For example, if we have&nbsp;S = &quot;abcd&quot;&nbsp;and we have some replacement operation&nbsp;i = 2, x = &quot;cd&quot;, y = &quot;ffff&quot;, then because&nbsp;&quot;cd&quot;&nbsp;starts at position 2&nbsp;in the original string S, we will replace it with &quot;ffff&quot;.

Using another example on S = &quot;abcd&quot;, if we have both the replacement operation i = 0, x = &quot;ab&quot;, y = &quot;eee&quot;, as well as another replacement operation&nbsp;i = 2, x = &quot;ec&quot;, y = &quot;ffff&quot;, this second operation does nothing because in the original string&nbsp;S[2] = &#39;c&#39;, which doesn&#39;t match&nbsp;x[0] = &#39;e&#39;.

All these operations occur simultaneously.&nbsp; It&#39;s guaranteed that there won&#39;t be any overlap in replacement: for example,&nbsp;S = &quot;abc&quot;, indexes = [0, 1],&nbsp;sources = [&quot;ab&quot;,&quot;bc&quot;] is not a valid test case.

Example 1:


Input: S = &quot;abcd&quot;, indexes = [0,2], sources = [&quot;a&quot;,&quot;cd&quot;], targets = [&quot;eee&quot;,&quot;ffff&quot;]
Output: &quot;eeebffff&quot;
Explanation: &quot;a&quot; starts at index 0 in S, so it&#39;s replaced by &quot;eee&quot;.
&quot;cd&quot; starts at index 2 in S, so it&#39;s replaced by &quot;ffff&quot;.


Example 2:


Input: S = &quot;abcd&quot;, indexes = [0,2], sources = [&quot;ab&quot;,&quot;ec&quot;], targets = [&quot;eee&quot;,&quot;ffff&quot;]
Output: &quot;eeecd&quot;
Explanation: &quot;ab&quot; starts at index 0 in S, so it&#39;s replaced by &quot;eee&quot;. 
&quot;ec&quot; doesn&#39;t starts at index 2 in the original S, so we do nothing.


Notes:


	0 &lt;=&nbsp;indexes.length =&nbsp;sources.length =&nbsp;targets.length &lt;= 100
	0&nbsp;&lt;&nbsp;indexes[i]&nbsp;&lt; S.length &lt;= 1000
	All characters in given inputs are lowercase letters.


&nbsp;