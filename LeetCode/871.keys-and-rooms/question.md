There are N rooms and you start in room 0.&nbsp; Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have&nbsp;some keys to access the next room.&nbsp;

Formally, each room i&nbsp;has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.&nbsp; A key rooms[i][j] = v&nbsp;opens the room with number v.

Initially, all the rooms start locked (except for room 0).&nbsp;

You can walk back and forth between rooms freely.

Return true&nbsp;if and only if you can enter&nbsp;every room.




Example 1:


Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.


Example 2:


Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can&#39;t enter the room with number 2.


Note:


	1 &lt;= rooms.length &lt;=&nbsp;1000
	0 &lt;= rooms[i].length &lt;= 1000
	The number of keys in all rooms combined is at most&nbsp;3000.

