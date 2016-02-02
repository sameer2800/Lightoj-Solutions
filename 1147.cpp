#include <bits/stdc++.h>
#define ll long long
#define MAX 100100
 
using namespace std;
 
vector <ll > v;
map <pair<ll,ll>,ll>mp;
ll dp[503000];
ll mini;
ll as,bs;
#define BIT(n) (1LL<<(n))


 int main()
 {
     
    #ifndef ONLINE_JUDGE
    freopen("/home/sameer/Documents/sameer/input.sam","r",stdin);
    #endif
 
 
     ios_base::sync_with_stdio(false);
     ll i,j,k,n,m,t,cont,a,b;
   
     cin >> t;
     
     ll cases = t,ans;
 
     while(t--){
       
       	v.clear();
       	mp.clear();
       memset(dp,0,sizeof dp);
          cin >> n ;
         
         
          ll sum =0;

          for(i=0;i <n;i++) {
          	cin >> k;
          	v.push_back(k); 
          	sum+= k;
          }
          ll total = sum;
          sum /= 2;

          

          dp[0] =1;

          ll one =1;

          for(i =0;i < v.size();i++) {
          	
          	for(j = sum;j >= v[i];j--) {
          		
          		dp[j] = dp[j] | (dp[j-v[i]] << 1);
          	}

          }

         a = n/2,b = n-a; 
    	for( j= sum+1 ;j >=0;j--){

		//	cout <<j <<" "<< f[j] <<" " << BIT(a) << " " << BIT(b) << endl;
			if ((dp[j] & BIT(a)) || (dp[j] & BIT(b))) ;
				ans = j; break;

			}
		

 
	
            cout << "Case " << cases-t << ": "  << min(ans,total-ans) << " " << max(total-ans,ans) << endl;
 
                     
       
     }
 
 
 
     return 0;
 }