#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100010];
ll dp[100010];


ll recursedp(ll curr,ll max,ll dist)
{

	if( max- curr < 2)
		return INT_MAX;


	if(arr[max]- arr[curr] <= 2*dist)
		return 1;


	if(dp[curr] != 0)
	return dp[curr];

	ll mini = INT_MAX;

	for(int j= curr+2; j <= max;j++){
			if(arr[j]- arr[curr] <= 2*dist){

				mini = min(mini,1+ recursedp(j+1,max,dist));	
			}
			else
				break;


	}	


	dp[curr] = mini;

	return dp[curr];






}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam","r",stdin);
	#endif


	ios_base::sync_with_stdio(false);
	ll i,j,k,n,m,t,cont;
	
	cin >> t;
	ll cases = t;

	while(t--){

		memset(dp,0,sizeof dp);
		cin >> n >> k;

		for(i =0;  i < n;i++)
			cin >> arr[i];


		sort(arr,arr+n);

		ll ans = recursedp(0,n-1,k);

			if(ans < INT_MAX)
		 cout << "Case " << cases - t  << ": "  << ans << endl;
		else
		cout << "Case " << cases - t  << ": "  << "-1" << endl;
			
	}



	return 0;
}
