A character is unique in string S if it occurs exactly once in it.

For example, in string S = &quot;LETTER&quot;, the only unique characters are &quot;L&quot; and &quot;R&quot;.

Let&#39;s define UNIQ(S) as the number of unique characters in string S.

For example, UNIQ(&quot;LETTER&quot;) =&nbsp; 2.

Given a string S with only uppercases, calculate the sum of UNIQ(substring) over all non-empty substrings of S.

If there are two or more equal substrings at different positions in S, we consider them different.

Since the answer can be very large, retrun the answer&nbsp;modulo&nbsp;10 ^ 9 + 7.

&nbsp;

Example 1:


Input: &quot;ABC&quot;
Output: 10
Explanation: All possible substrings are: &quot;A&quot;,&quot;B&quot;,&quot;C&quot;,&quot;AB&quot;,&quot;BC&quot; and &quot;ABC&quot;.
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10

Example 2:


Input: &quot;ABA&quot;
Output: 8
Explanation: The same as example 1, except uni(&quot;ABA&quot;) = 1.


&nbsp;

Note: 0 &lt;= S.length &lt;= 10000.
