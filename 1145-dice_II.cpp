#include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
 
 using namespace std;
 
 ll arr[15030];
 vector <pair <ll,ll> > v;
 ll temp[15030];
 ll mod = 1e8+7;


 int main()
 {
     
    #ifndef ONLINE_JUDGE
    freopen("/home/sameer/Documents/sameer/input.sam","r",stdin);
    #endif
 
 
     ios_base::sync_with_stdio(false);
     ll i,j,k,n,m,t,cont,a,b,s;
   
     cin >> t;
     
     ll cases = t;
 
     while(t--){
       	
       	memset(arr,0,sizeof arr);
       	memset(temp,0,sizeof temp);

          cin >> n >> k >> s;
          


          for(i=1;i <=k;i++) {
          	arr[i] = 1;
         }

         for(i=1;i <=s;i++) {
         	temp[i] = temp[i-1] + arr[i];
         	temp[i] %= mod;
         
         }
         	
         for(i=2;i <=n;i++){
         	for(j =1;j <= s;j++) {
         		if(j-k >=0)
         		arr[j] = ((temp[j-1] - temp[j-k-1])) %mod ;
         		else
         			arr[j] = ((temp[j-1] - temp[0])) % mod;
         		
         		if(arr[j] < 0)
         			arr[j] += mod;

         	}
         		for(j=1;j <=s;j++) {
         			temp[j] = (temp[j-1] + arr[j]) % mod;
         			temp[j] %= mod;
         		}

         }

        

            cout << "Case " << cases-t << ": "  << arr[s] << endl;
 
                     
       
     }
 
 
 
     return 0;
 }