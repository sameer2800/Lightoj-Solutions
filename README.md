#lightoj-epic-solutions

##solution 1007 :

based on Euler totient function.
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

			
