#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[16];
ll dp[1 << 16];
ll ans = 0;
ll n;

ll lcm(ll a,ll b)
{

	ll yi = __gcd(a,b);
	return (a*b)/yi;
}

void recursive(int curr,int curbit, int mbits)
{

	if(curbit >= mbits){
		return;
	}

	if(dp[curr] != -1)
		return;

	int yo = __builtin_popcount(curr);

	ll temp =1;
	for(int i=0;i < mbits;i++){
		
		if(curr & 1 << i ){
			temp = lcm(arr[i],temp);
		}
	
	}

	if(curr != 0) {
		if(yo % 2 == 1) {
		ans += n/temp;
		}		
		else {
		ans -= n/temp;
		}
	}

	for(int i =0;i < mbits;i++){
		if(!(curr & 1 << i )) {
			recursive(curr | 1 << i ,i,mbits);
		}
	}

	dp[curr] = 1;
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam","r",stdin);
	#endif


	ios_base::sync_with_stdio(false);
	ll i,j,k,m,t,cont;
	
	cin >> t;
	ll cases = t;

	while(t--){

		memset(dp,-1,sizeof dp);
		ans = 0;
		cin >> n >> m;

		for(i =0;i < m;i++)
			cin >> arr[i];		


		recursive(0,0,m);	


		 cout << "Case " << cases - t  << ": " << n-  ans  << endl;
	}



	return 0;
}
