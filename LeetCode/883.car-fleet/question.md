N cars are going to the same destination along a one lane road.&nbsp; The destination is target&nbsp;miles away.

Each car i&nbsp;has a constant speed speed[i]&nbsp;(in miles per hour), and initial position position[i]&nbsp;miles towards the target along the road.

A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.

The distance between these two cars is ignored - they are assumed to have the same position.

A car fleet is some non-empty set of cars driving&nbsp;at the same position and same speed.&nbsp; Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will&nbsp;still be&nbsp;considered as one car fleet.


How many car fleets will arrive at the destination?

&nbsp;

Example 1:


Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 and 8 become a fleet, meeting each other at 12.
The car starting at 0 doesn&#39;t catch up to any other car, so it is a fleet by itself.
The cars starting at 5 and 3 become a fleet, meeting each other at 6.
Note that no other cars meet these fleets before the destination, so the answer is 3.



Note:


	0 &lt;= N &lt;= 10 ^ 4
	0 &lt; target&nbsp;&lt;= 10 ^ 6
	0 &lt;&nbsp;speed[i] &lt;= 10 ^ 6
	0 &lt;= position[i] &lt; target
	All initial positions are different.
