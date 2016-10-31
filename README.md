#lightoj-epic-solutions



##solution 1000 :

Simple addition program.

For given number of problems in each of the computers, we have to find the total number of problems



##solution 1001 :

its just a beginners problem of dividing the given number of items into two seperate baskets which can contain maximum of 10 elements.
so, just by using if (n > 10) we can divide them into two baskets.

##solution 1002 :

The problem description is very straightforward. The solution is achieved
with a simple Dijkstra with a simple modification: 

Instead of returning the value of the shortest path itself, the algorithm should 
return the maximum weight along the shortest path.

The Dijkstra algorithm should be used only once every input case, because after doing so, 
the output values are stored in the distance array. So it is not necessary to 
call it for every vertex in the graph.

##solution 1006 :

Basically in this qestion we have to optimize the code and make it efficient, We can clearly observer that the given problem has overlapping subproblems ie ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ), so we can use dynamic programming for solving this.
we can use an array to store the already computed values and can be used for calculation of new values.

=======
>>>>>>> a2ee7631fcb08c189b7f22bcbeae5d82f6f53fb6

##solution 1007 :

based  on  Euler totient function.
here dp[i] represents number of relative primes of ith number
first mark all prime numbers, now for each number 
if 'i' is a prime number: dp[i] = i-1 (one can think)
if its not,
   find the smallest factor, consider it to be some k.
	and i = k *(i/k) 
	if i/k % k  == 0
    	dp[i] = dp[i/k]*k
	else
		dp[i] = dp[i/k]*(k-1) 

	(just think how can we got above 2 equations)

##solution 1020 :

A simple problem based on number theory,if Alice takes first :

game would be like : 1 2 3 4 5 6 7 8 9
					 L W W L W W L W W

if bob takes first : 1 2 3 4 5 6 7 8 9
					 W W L W W L W W L

W - stands for winning , L stands for loosing and number represents 
number of marbles present.

##solution 1053 :
We just need to check the pythogras theroem ie a^2 + b^2 = c^2.


##solution 1053 :

A simple problem based on Pythagorean theorem. Pythagoras's theorem, is a fundamental relation in Euclidean geometry among the three sides of a right triangle. It states that the square of the hypotenuse is equal to the sum of the squares of the other two sides.
 
hypo ^ 2 =  side ^ 2 + side ^2

hypotenuse is larger than other two sides. In given 3 sides we can find maximum number and we can say that thoes are righttriangle sides or not by checking above theorm.


##solution 1069:

A simple problem based on addition , substration , multiplication operations. 
	
We'll be calculating whole traveling time of the lift after that adding to total operations time. 



##solution 1053 :

A simple problem based on Pythagorean theorem. Pythagoras's theorem, is a fundamental relation in Euclidean geometry among the three sides of a right triangle. It states that the square of the hypotenuse is equal to the sum of the squares of the other two sides.
 
hypo ^ 2 =  side ^ 2 + side ^2

hypotenuse is larger than other two sides. In given 3 sides we can find maximum number and we can say that thoes are righttriangle sides or not by checking above theorm.


##solution 1069:

A simple problem based on addition , substration , multiplication operations. 
	
We'll be calculating whole traveling time of the lift after that adding to total operations time. 



##solution 1078 :

we need to find minimum length of a string that contains only 'X' and that 
string should be divisible by 'K' and this is possible for every K such that
k % 2 != 0 and k %5 != 0.

we are given k and X.
now take temp =X , length = 1,mul = 10

while(temp % k != 0)
	temp += X*mul
	length++;
	mul *= 10

as value of temp can be greater than max value of int, we should think in a better way.
now instead of maintaining temp, maintain temp % k.
for example, k =111, X =3
111 % 3 =( 100 % 3 + 11 % 3) % 3
take another variable namely mod = X % k

while(mod != 0)
	mod = (X*mul % k + mod )% k
	length++
	mul = (mul *10) % k

length gives us the result

	


##solution 1087 :

size of each group atleast can be 3.
recursively take  groups of size greater than 2 (3,4,5....) for each curr
if possible.

dp[i] represents minimum number of groups can form starting from i to the last .
dp[0] gives us solution.

for(j = i+2 to n)
dp[i] = min(dp[i],1+ dp[j])

check the solution for better understanding.

##solution 1107 :

Just Check wheter the given input point satisfies the condition ((x3 > x1 && x3 < x2) && (y3 > y1 && y3 < y2))


##solution 1113 :

yo..use two stacks and do the operations as they are saying.	
stl stack minimized my work.


##solution 1116:

pretty simple problem 

only even numbers can be written as product of an even number and other number.
ex :  6=  2* 3 
so for every even number, 
first take m =2, n = number/m 
if(n is not odd) then make m = m*2
and continue the loop ,till we find n as odd number.


##solution 1119 :

	bitmask dynamic programming.

	generate all permutations of each subset of the given elements. 

	dp[i] = write i in bit format ,find number of bits set to 1. and calculate
	sum of these respective elements.  

	once we reach the condition of all bits set ,  break out of the function.

##Solution 1117 :

	category : Set inclusive and exclusive principle.

	count all the numbers which are present below 'n' and divisible by given
	 numbers.for doing this ,use set union formula. 

	i used a recursive function which finds all subsets of given array , and 
	in each subset count number of bits set and if it is odd ,add to our solution
	 else substract it.

	finally ans contains all numbers counted in this way and our final answer is n - ans.


##Solution 1123 :

	category : minimum spanning tree

	A good problem on this topic. I used prim's algorithm for constructing 
	the tree. if graph is not connected ,print -1 . Run a prims algorithm ,
	once we can travel every node to every other node. 

	After this, for each edge , construct the tree again on the previous built 
	 tree which contains n-1 edges exactly. instead of building from scatch again.
	 In this way, compexity can be well reduced.


##Solution 1124 :
  
  category : Set inclusion and exclusion

  x1 + x2 +x3 + ....xr = n

  here each ai <=  xi <= bi . Distributing n identical objects among r groups with limits on each group. Every group must have a1 objects ,so fill all the groups with corresponding ai. Now,
  we are left with  n - (a1 + a2 + a3+ ...ar).  
  So, our new update is 0 <= xi <= bi-ai. 
  Distribute these objects among R groups with formula 
  C(N1 + r -1,r-1 )  where N1 is new n.
  So,from this we need to remove all the cases where each xi > bi-ai .
  For doing this,generate all 2 ^r subsets .

##Solution 1125 :

	category : DP

	dp[i][j][k] represents "from i elements take j elements and sum of these elements modulo 'b' is k and also ith element is last included".
    
	for(temp is 0 to i-1)
	if(k > a[i])
		dp[i][j][k] +=  dp[temp][j-1][k-a[i]] ; 
	else
		dp[i][j][k]  += dp[temp][j-1][k-a[i] + b];

	to minimize complexity ,do some precomputations.

##Solution 1127 :
	
	category : bisection and binary search

	basically the idea is we need to get the sums  of all the subsets of the array and count no of sums which are lesser than the given weight. 
	max size of array is 30 . to generate all subsets, complexity will be O(2^ 30) which cross limits.

	to minimize this, find sums of all subsets of first half numbers .
	(complexity is O(2^15)) .
	store all these values inside a vector and sort them.
	now, generate sums of second half numbers which is again O(2 ^ 15). 
	then ,for each subset sum of second generated numbers , find number of all elements 
	in the first set such that total sum weight <= given weight .
	use vector upper bound for this .

	total complexity : O((2 ^ n/2 )*log n )

##Solution 1129 :
	problem is to check presence of any string that is prefix to
	any other string of the given input.
	the idea is to use a trie tree . whenever we insert a new 
	string in the trie , check whether is it a prefix ,or  this 
	contains  any other prefixes.
	Take a variable in each node which marks only leaf nodes.
	now , start thinking from here !!!!!

##Solution 1131 :
	
	problem is to find f(n) and g(n) .
	if n < 10^6 , we could have simply solved by using DP. but n value ranges upto 2 ^31 
	which is around 10 ^10 , we used technique called matrix exponentation. 

		fn =     |       |   fn-1
		fn-1 =   |       |   fn-2 
		fn-2 =   |       | 	 fn-3		
		gn =     |   M   | * gn-1
		gn-1=    |       | 	 gn-2
		gn-2 =   |       |   gn-3

		M is the coefficient Matrix here. 
		To find fn in terms of known variables, expand rhs again and again.
		and finally ,we obtain solution
		 fn =    |       |^(n-2)    f2
		fn-1 =   |       |          f1 
		fn-2 =   |       | 	        f0		
		gn =     |   M   |      *   g2
		gn-1=    |       | 	        g1
		gn-2 =   |       |          g0

		Matrix power can be done in log(n) time.
		So complexity will be ((M.rows)^3 )*log(n).


##solution 1133 :

we just need to use if else or switch case according to the given queries and compute the values.


##Solution 1134 :
	
	count no of substrings in an array which sum is a multiple of M.
	create another array where 
		arr[i] = (arr[i-1] + input[i] ) % m;
	which is basically adding the sum upto it modulo m. then count number of 
	pairs of equal numbers. bcoz we recieve the same number again in that array
	only when the sum of in between elements are divisible by m.
	complexity is O(N).

##Solution 1135 :
	
	segment trees with lazy propagation . first u need to learn the implementation
	of lazy propagation with segment trees.this one is a good example of that.

##Solution 1137 :
	
	this is an interesting one. there are 2 variables to be find out to get the
	solution .
		r*theta = length of segment (which is known)

	theta varies from 0 to PI/2 . So do binary search on theta and find out radius.

	chord length is given and compare this length with our new chord every time.
	new chord = r*sin(theta)

	once we find out theta, ans will be r -r*cos(theta).

##Solution 1138  :

	binary search. Just think in that way , u will get the solution.
	Only see my solution,if u are unable to solve it.

##Solution 1141 :
	
	typical bfs solution.


##Solution 1142 :
	
	f(2x) =   A + A^2 + A^3+....+ A^x + ...+ A^2x
		  =>  A+ A^2+ A^3+ ....+ A^X + A^x(A+ A^2+.....A^x)   	
		  => (A+ A^2+....A^x)(I + A^x)
	f(2x) = f(x)(I+A^(x/2));  
	f(2x+1) => f(2x) + A^x;

##Solution 1145 :

		dynamic programming .
		n dices,each range from 1 to k , sum should be S.
		dp[n][S] => number of ways of arranging n dices which give sum S.so,for the
		last dice possible values are 1 to k .
		suppose , if nth dice has value 1,
		dp[n][S] = dp[n-1][s-1] ,which is arranging n-1 dices with sum s-1.
		similarly , if nth dics got value 2,    
		dp[n][S] = dp[n-1][s-2] ,which is arranging n-1 dices with sum s-2.
		.
		.
		.upto k for nth dice.

		so, dp[n][S] = dp[n-1][s-1] + dp[n-1][s-2] + dp[n-1][s-3]+....+dp[n-1][s-k]

		we have to calculate this sum in O(1) time ,so we store this sum in temp array.and for calculating nth index , we require only n-1th index values. so, we 
		are not required to store all the n-2 index values.

		time complexity : O(N*S)
		memory complexity : O(2*S)

##Solution 1148:

	Goal is to minimize the total population. 
	count all the similar numbers in an array .suppose N= 3, and 
	their values are 2 2 2 , we could say that there are only 3 people
	all belongs to same team. and suppose when N = 5, and values are
	2 2 2 2 2 ,ans is 3+3 because 2 2 2 come under 1st set and the other
	 2 2 into another set.

	 similarly count all values from 0 to 10^6.
	 complexity : O(10^6). 

##Solution 1149: 
	
	find the  maximum bipartite matching of the graph after connecting
	to source and destination . i used ford fulkerson algorithm for implem
	enting the above said .

##Solution 1157:

	find the lcs array in following way :
	lcs[i][j] = longest common subsequence of two strings in which a starts
	with 'i' and b starts with 'j'.

	lcs[0][0] gives the solution .

	dp[i][j] = number of distinct lcs , a starts with i and b with j. 

	find the first occurrence of all alphabets in both strings for each postion . // precompute them .

	dp[i][j] : 
	all distinct subsequences having lcs[i][j] .
	count all
	=> subsequences starts with 'a'
 	=> subsequences starts with 'b'
 	..... 

 	fill everything recursively .
 	dp[0][0] gives us the solution.

##Solution 1158 :
	
	category : bitmasking with dp.

##Solution 1159 :	
	
	dynamic programming .

	lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1  , when a[i] == b[j] == c[k]
	else
	lcs[i][j][k] = max(lcs[i-1][j][k],lcs[i][j-1][k],lcs[i][j][k-1]);

##Solution 1161 :
	
	inclusion , exclusion .

	max numbers : 10000 
	we need to find all the 4-tuples whose gcd is 1 .
	idea is to count 4tuples having gcd 2, gcd 3, gcd 4, .....

	so , gcd (1) = nC4 - {gcd2 + gcd 3 + gcd 4 + gcd 5 ......} 

##Solution 1163 :
	
	 hint : pattern search by generating 'a-b' for every a starts from
	 1 .one can easily notice a pattern.

##Solution 1164 :

	lazy propagation with segment tree

##Solution 1166 :
	
	greedy , dfs

	for every misplaced number ,write dfs to find where the number is 
	appearing and count this values.

##Solution 1168 :

	category : scc 
	algorithm : tarzan's algorithm .

	find all the scc in the graph by using tarzans algorithm then for
	every scc find number of outgoing edges other than internal nodes.
	if any scc contains 2 or more outgoing edges we cannot have a single
	path .	

	complexity : tarzan algo is mainly dfs and which is O(V+E). 

##Solution 1169 :

	category : dp

	pretty simple when you are strong with dp.

##solution 1170 :

	catalan numbers,dynamic programming, upperbound ,lowerbound

	generate all perfect numbers below 1e10. start from 2 to 1e5 .easily 
	done in 1 sec. 

	now for each query,find out number of perfect numbers by using upper
	and lowerbounds. 

	dp[i] =  number of bsts of size i .

	dp[i] = dp[j] * dp[j-i-1] for 1 < j< i.	which is O(n^2) .
	catalan numbers does the same , // google catalan numbers.
	dp[i] = C(i) = 1/2n+1 C(2n,n). which work in O(N).

##Solution 1173 :

	dynamic programming .
	although my solution dint get accepted , i m sure about my
	approach  :p. 
	read this  :  http://lbv-pc.blogspot.in/2012/09/the-vindictive-coach.html

##Solution 1174 :
	
	category : floyd warshall / dfs-bfs /prim	

##Solution 1175 :

	category : bfs

	run the bfs twice, once from jane to every other location .
	insert all the fire into the queue at once and then run the bfs again.		
##Solution 1176 :

	m guys ,6*n tshirts.
	first m nodes are for m guys then next 6*n nodes  are for tshirts .
	suppose 1st guy can wear XL ,M  ,there are n XL nodes and n M nodes.
	so join the first guy node with all these 2*n nodes .similarly
	build the graph for all the guys .
	take a source and destination , connect source with m guys and
	connect all 6*n nodes (tshirts) with destination and run bipartite
	matching .


##solution 1179 :
	
	joshepus problem , 
	wikepedia has good explanation .search !!!

##Solution 1182 :

	counted number of bits set by using __builtin_pop_count() function.

##Solution 1183 :
	
	segment trees, lazy propagation .we have done a lot . :p

##solution 1184 :
	
	maximum bipartite matching ,
	construct the graph by using the given conditions.then run mbm.

##Solution  1186 :
	
	category : nim's game .

	we know the general solution for situation like  :
	suppose there are n piles and 2 players are playing , each can remove any number
	of stones atleast 1 from only one pile at his chance , the last player who is
	unable to remove looses . the solution for this is :

	if xor of all piles are zero at any players chance, he looses .

	similarily ,we can relate our problem to piles problem.in each step a player can move to any position until his oppostion's place. we can assume this as our size of the pile .  and apply xor similarly.


##Solution 1187 :
	
	category : segment trees.
	suppose given array , 0 0 1 3 0 5 . now the last guy says there are
	exactly 5 guys taller than him . so he must be 6 -5 = 1 .
	take an another array 1 2 3 4 5 6 ,and remove 1 from this . 
	new array : 2 3 4 5 6
	next ,the second last guy says there is no one greater than him ,so
	he must be 6 , remove this from array .
	new array : 2 3 4 5
	then the next guy says there are 3 guys taller , so he must be 2.
	then delete 2  , new array : 3 4 5 ...
	similarily ..continue further ...

	i used segment tree to construct the array and to delete each element
	one by one.


##Solution 1189 :

	As the time limit is too low 0.5 sec,if we do bitmasking , it will 
	be timeout .
	if we observe carefully ,
	fact[n] > fact[n-1]  + fact[n-2] + ..... fact[1] + fact[0].
	which means , if , k > fact[n] , and if k is a valid solution , then
	k must contain fact[n] .
	so just we need a single recursive call instead of double call inside 
	the recursive function.

##Solution 1191 :
	
	category : dynamic programming .

	build the dp table yourself to get the recurrence.
	dp[n][k][m] = dp[n-1][k-1][m] + dp[n-2][k-1][m] +... dp[n-m][k-1][m]

	here m is not varying, so we can safely remove third dimension m.
	and dp[n-1][k][m] = dp[n-2][k-1][m] + dp[n-3][k-1][m] +....

	so we can reformulize our equation ,
	dp[n][k] = dp[n-1][k] - dp[n-1-m][k-1] + dp[n-1][k-1] .

##Solution 1192 :

	category : nim game
	this is almost similar to problem no : 1186.

##Solution 1193 :

	category : dynamic programming

	dp[i][j] = 1*dp[i-1][j-1] + 2*dp[i-1][j-2] ..... k*dp[i-1][j-k]

  dp[i-1][j] =                  1*dp[i-1][j-2] ......k-1*dp[i-1][j-k]+  
                                 k *dp[i-1][j-k-1];

    dp[i][j] = dp[i-1][j] + (dp[i-1][j-1] +   dp[i-1][j-2] ...)
    
    see the solution for better understanding.            

##Solution 1198 :

	greedy.

##Solution 1199 :

	sprague grundy numbers.

	find grundy number for all the heap sizes.

	grundy value of non movable states are 0.
	generally, g[0] = 0 .

	g[i] =  minimum number which is not present in the set of all the
	grundy numbers where 'i' can move into.

	answer will be g[n1] ^ g[n2] ^ g[n3] ....		

##Solution 1200 :

	category : Dynamic Programming

	for a weight w, u can keep any object inside the sack whose weight
	is lesser than w.
	the profit obtained is p[i] for ith object.

	func(weight) = maximum profit obtained when the sack size is w.

	programmatically,  
	func(weight) =   MAX  p[i] + func(weight- weig[i]); 

	memoize steps to avoid recalculations.

##Solution 1201 :

	category : dynamic programming .

	when i saw the problem first, i thought this is a simple coloring
	problem . i coded in that manner , i got wrong answer . I opened
	the forum and read some posts and realized this is not that simple as
	just color the nodes and count .

	I solved this by using DP and we can also solve through bipartite
	matching.

	the key idea is => if a node present in the solution , all of its
	neighbours shouldn't , and if a node is not present , all of its neighb
	ours may or may present in the solution .

	find out recurrence for the above idea and memoize it .that simple.	

##Solution 1202 :
	
	category : greedy

	there can be only 3 solutions possible ,
	1,2,impossible .

##Solution 1205 :

	category : dynamic programming 

	inspired from this stackoverflow answer :p
	http://stackoverflow.com/questions/22394257/how-to-count-integers-between-large-a-and-b-with-a-certain-property/22394258#22394258

	the solution in the above link , he  counts only number of palindromic
	integers which are of same size of given Y and <= to Y .
	
	So , I used almost same function and precomputed count of  palindromic
	integers for all the sizes lesser than 22. 

	and the answer is F(b) - F(a-1). 

	note : be careful with corner cases.

<<<<<<< HEAD
##Solution 1210:

	category : scc

	
=======
##Solution 1207 :
	
	category : segment trees/lazy
	
	for all the given posters, update the range of the poster with a new color .
	
	after all posters done , query the color of each position of the wall ,
	and count the unique colors which is our answer.

>>>>>>> 1fd8274f824873a810f9e5dd5f9e7c966c9b9c61

##Solution 1210 :
	category : scc

##Solution 1212 :
	
	category : data structures

	use stl deque :p

##Solution 1213 :

	category : number theory

	we could easily derive  the general formula if we write on a paper for each 
	k = 1,2,3,4 (number of loops).
	spoiler ahead.

	f(n) = k * sum * n ^(k-1).


##Solution 1214 :

	category : division

	as the number is too large, take it as a string.  

##Solution 1215 :

	category : number theory

	brute force for all the factors of l and find the minimum factor which satisfies lcm of (a,b,factor) == l .  


##Solution 1216 :

	category : basic geometry

	vol of truncated cone = 1/3 (pi*h*(r^2 + r2^2+ r*r2));

	the only thing we have to do is  find out the 'r' by using triangle equality. 


##Solution 1217 :

	category : dp

	according to the conditions given in the qsn , either an element can be taken
	or not. suppose , an element is taken , all the neighbours of it cannot be 
	taken . so with this , we can easily find out a recursive solution .

	dp(curr, taken , first) => curr is position , taken says whether it is present in the final answer, first is true if the first element is taken in the answer .

	if(taken == 0)
		we can  either take the next element or not .so, 2 conditions ,
		 max ( dp(curr+1,1,first ) , dp(curr+1,0,first)

	if(taken == 1)
		then we cannot take the next element.
		dp(curr+1,0,first)	 

	Attribute 'first' is used when we reach the last element .
	
	After this, use dp array for memoization  and return the answer if it is 
	already visited. 	


##Solution 1219:
	
	category : dfs and greedy


##Solution 1220:

	category : number theory

	calculate all the non perfect numbers and insert them in an array. And for
	each non perfect number , raise the power until the value lesser than 2^32
	and store in map. similarly , go with negative numbers.  

##Solution 1221 :

	category : bellman ford, floyd warshall

	Read the forum , it has very good explanation :D 

	We can also find negative cycles by using floyd warshall. Run the floyd warshall
	and then 
	if edge[i][i] < 0
		negative cycle exists. 


##Solution 1224 :

	category : Trie tree

	When you insert the string into the trie tree , increment the counter of the node.And also store the height of each node .

	then traverse the node  in a dfs manner, find the maximum value of heigh*countr.


##Solution 1225 :

	category : greedy

##Solution 1227 :

	category : greedy

##Solution 1229 :

	category : sprague grundy thereom

	explanation : http://lbv-pc.blogspot.in/2012/07/treblecross.html

##Solution 1230 :

	category : dynamic programming

	This problem is interesting as it is dp on a tree rather than normal array
	dps. lets go to explanation .

	dp[node][1] = number of nodes to be lightened in the subtree of 'node' when 
				there is a lamppost in current node .

	dp[node][0] = this is same as above but there is no lampost in current node.
	
	Now, the value at dp[node][0] will be , as this node does not contain lampposts
	all its neighbours must contain lamps. which is
	dp[node][0]  +=   dp[neighbour][1].

	but when we keep a lamp in current node , we may or may not be required to keep
	lamps in all of its neighbours. So , in this case we consider min of conditions.
	which is

	dp[node][1]  = min(dp[neighbour][0] , dp[neighbour][1] )

	Along with this answer , we also need number of roads that recieve light from 
	both nodes . this is readers assignment. :p 

##Solution 1231 :

	category : dynamic programming

	basic level.	

##Solution 1232 :
	
	category : dynamic programming

	As time limits are very strict , we cannot write a recursive solution . 
	Instead there is a iterative dp with time complexity O(N*k) and
	space O(k)


##Solution 1233 :

	this one is a good dp problem.I  Built the solution from bottom up manner.
	there are M places and count how many places can we obtain with the given
	coins. 
	what we do is start iterating the array with each coin. make the array 
	value 1,if this value is obtainable. i.e dp[i] =1.
	And at each step ,count the number of same coins used to get this value in
	count[i].
		dp[0] = 1 // coz zero means no coins in hand ,which is possible
		for coin j, 

			dp[i] = 1 , only when dp[i-j] = 1 and count[i-j]+1 < available_coins[j]	

	iterate the array in similar fashion for each coin.		

##Solution 1234 :
	
	category: Number theory

	we cannot have an double array of size 10^8 coz its memory is greater than
	32 mb . instead we can have array of size 10^6.
	In every node of array , store sum of 100 harmonic numbers along with arr[n-1].

	so arr[1]  contains 1/1 + .... 1/100
	and arr[2] = arr[1] + 1/101 +1/102 + .... 1/200

	And queries also can be performed in similar manner .

##Solution 1235 :

	category : Bisection , binary search

	Clearly we have 3^18 subsets which is order of 10 ^ 9. But we can solve
	this through by the approach meet in the middle . 
	divide the array into 2 groups each can be maximum size of 9. Now generate
	all possible values of both groups which is 3^9 subsets. Now for every value
	generated in set2 , find it corresponding value in set1 i.e (K-val) , if we
	found this val, then the answer is YES.

##Solution 1341 :

	category : Number theory

	This problem is equivalent to counting the number of divisors of a that are strictly smaller than sqrt(a) and larger or equal than b.
	The solution generates all the divisors of a that are smaller than sqrt(a) and counts how many are larger or equal than b. The divisors can be generated efficiently after first finding the prime factorization of a.
