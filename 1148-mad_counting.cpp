#include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
 
 using namespace std;
 
 ll arr[1001000];
 vector <pair <ll,ll> > v;
 

 int main()
 {
     
    #ifndef ONLINE_JUDGE
    freopen("/home/sameer/Documents/sameer/input.sam","r",stdin);
    #endif
 
 
     ios_base::sync_with_stdio(false);
     ll i,j,k,n,m,t,cont,a,b;
   
     cin >> t;
     
     ll cases = t;
 
     while(t--){
       	
       	memset(arr,0,sizeof arr);	
          cin >> n;

          for(i=0;i < n;i++) {
          	cin >> k;
          	arr[k]++;
          }

          ll ans =0;

          for(i=0;i < 1000100;i++) {
          	if(arr[i] !=0) {
          		k = arr[i];
          		ans += (arr[i]/(i+1)) *(i+1);
          		if(arr[i] % (i+1) != 0)
          			ans += (i+1);
          	}	
          }

            cout << "Case " << cases-t << ": "  << ans << endl;
 
                           
     }
 
 
 
     return 0;
 }