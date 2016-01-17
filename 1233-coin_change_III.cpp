#include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
 
 using namespace std;
 
 ll arr[100100];
 vector <pair <ll,ll> > v;
 
ll dp[100100];
ll countr[100100];

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
       
          cin >> n >> m;
          v.clear();

          memset(dp,0,sizeof dp);

          for(i=0;i < n;i++)
            {
                cin >> k;
                v.push_back(make_pair(k,0));

            }  

           for(i=0;i < n;i++) {
                cin >> k;
                v[i].second = k;
           } 

            sort(v.begin(),v.end());

            dp[0] = 1;

            for(j=0;j < v.size();j++) {  
               
                ll   fir= v[j].first;
                ll   sec = v[j].second; 

                memset(countr,0,sizeof countr);

                   
                for(i=1;i <=m;i++) {

                      if(dp[i] == 1){

                      }else {
                        if(i - fir >= 0) {

                            if(dp[i-fir] == 1) {
                                if(countr[i-fir] < sec){
                                    dp[i] = 1;
                                    countr[i] = countr[i-fir]+1;
                                }   

                            }
                       }
                      }  
                }
            }    

            ll ans =0;
            for(i=1;i <=m;i++) {
                if(dp[i] == 1)
                    ans++;
            }

            cout << "Case " << cases-t << ": "  << ans << endl;
 
                     
       
     }
 
 
 
     return 0;
 }