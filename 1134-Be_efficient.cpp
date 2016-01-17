#include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
 
 using namespace std;
 
 ll arr[100100];
 ll sum[100100];
 ll countr[100100];

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
       	
     	memset(countr,0,sizeof countr);
     	memset(arr,0,sizeof arr);
     	memset(sum,0,sizeof sum);

          cin >> n >> m;
          v.clear();

         for(i=0;i < n;i++) {
         	cin >> arr[i];
         }	

         sum[0] = arr[0] % m;

         for(i=1;i < n;i++) {
         	sum[i] = (sum[i-1] + arr[i]) % m;
         }

         for(i =0;i <n;i++) {
         	countr[sum[i]]++;
         }

        		
         ll ans = 0;

         ans += countr[0];


         for(i=0;i < m;i++) {
         	ans += (countr[i]*(countr[i]-1))/2; //nc2 ways
         }	


        cout << "Case " << cases-t << ": "  << ans << endl;
 
                     
       
     }
 
 
 
     return 0;
 }