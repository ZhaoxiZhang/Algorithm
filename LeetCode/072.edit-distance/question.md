Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:


	Insert a character
	Delete a character
	Replace a character


Example 1:


Input: word1 = &quot;horse&quot;, word2 = &quot;ros&quot;
Output: 3
Explanation: 
horse -&gt; rorse (replace &#39;h&#39; with &#39;r&#39;)
rorse -&gt; rose (remove &#39;r&#39;)
rose -&gt; ros (remove &#39;e&#39;)


Example 2:


Input: word1 = &quot;intention&quot;, word2 = &quot;execution&quot;
Output: 5
Explanation: 
intention -&gt; inention (remove &#39;t&#39;)
inention -&gt; enention (replace &#39;i&#39; with &#39;e&#39;)
enention -&gt; exention (replace &#39;n&#39; with &#39;x&#39;)
exention -&gt; exection (replace &#39;n&#39; with &#39;c&#39;)
exection -&gt; execution (insert &#39;u&#39;)

