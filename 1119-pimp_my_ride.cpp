#include <bits/stdc++.h>
#define ll long long
#define MAX 100100
 
using namespace std;
 
ll arr[16][16]; 
ll dp[1 << 17];
vector <ll > vk;

ll subsets_gener(int num,int maxi)
{
//	cout << num << " " << maxi << endl;

	int len = __builtin_popcount(num);

	if(len == maxi) {
		return 0;
	}

	ll prev ;

	if(dp[num] != -1)
		return dp[num];

	ll mini = INT_MAX;

	for(int i =0;i < maxi;i++){

		if(!(num & (1 << i))) {

			prev =arr[i][i];
			for(int j = 0;j < maxi;j++){
				if(num & (1 << j))	
					prev += arr[i][j];
			}
				
			mini = min(mini, prev + subsets_gener(num | 1 << i, maxi));
		}

	}

	return dp[num] = mini;


}

int main()
{
    
	#ifndef ONLINE_JUDGE
	freopen("/home/placements2016/input.sam","r",stdin);
	#endif
 
 
    ios_base::sync_with_stdio(false);
    ll i,j,k,n,m,t,cont,a,b;
   
    cin >> t;
    ll cases = t;
 
    while(t--){
		cin >> n;


		memset(dp,-1,sizeof dp);

		for(i=0;i < n;i++){
			for(j =0; j < n;j++){
				cin >> arr[i][j];
			}
		}
    	
		 cout << "Case " << cases - t  << ": "  ;
    	
		cout << subsets_gener(0,n) << endl;

    }
 

    return 0;
}