 #include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
  
 using namespace std;
  
 ll arr[100];
 ll dp[210][12][22]; 
 ll epicdp[12][22];
 vector <ll > vk;
 ll n;

ll modl(ll a,ll b)
{
	if(a < 0) {
       int k =b-((-a)%b);
       if(k == b)
        return 0;

        return k;
   }

       
	return a% b;
}

 ll rundp(ll a,ll b)
 {

  memset(epicdp,0,sizeof epicdp);

 	for(int j=0;j < 12;j++) {
 		for(int k =0;k < 22;k++) {
 			dp[0][j][k] = 0; 
 		}
 	}
 	
 	for(int i=1;i <= n;i++) {
 	    
       ll temp[25][25];
        memset(temp,0,sizeof temp);

  	for(int j=1;j < 12;j++) {
 			if(j > i)
          break;

      for(int k=0;k <22;k++) {
 	
        if(j==1) {
 				 dp[i][j][modl(arr[i-1], b)] = 1;
          temp[j][modl(arr[i-1], b)]++;
          break;
         } else {
 				
        	if(k >= arr[i-1]) {
 						ll yoo = modl(k-arr[i-1],b);
 					
 				  dp[i][j][k] = epicdp[j-1][yoo]; 
        
          temp[j][k] = epicdp[j-1][yoo];
 					}else {
 						ll newtemp = k-arr[i-1] + b;
 						if(newtemp < 0)
 							newtemp = b- ((-newtemp)%b);

            dp[i][j][k] = epicdp[j-1][newtemp%b];
          
 				   temp[j][k] = epicdp[j-1][newtemp%b];

 					}
 				
            }

 			}

      
      
 		}

  

    for(ll kim =0;kim < 22;kim++){
       for(ll klo = 0;klo < 22;klo++)
        epicdp[kim][klo] += temp[kim][klo];
      }

 	}
    



 	ll ans =0;

 	for(int i =1;i <= n;i++) {
 	//	cout << dp[i][a][0] << " ";
 		ans += dp[i][a][0];
 	}

 // cout << "epic dp " << epicdp[a][0] << endl;
 	return ans;

 }

 int main()
 {
     
 	#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam","r",stdin);
	#endif
  

     ll i,j,k,m,t,cont,a,b;
    

     scanf("%lld\n", &t);
     ll cases = t;
  
     while(t--){
 	
 		printf("Case %lld:\n",cases-t );
 		
 		scanf("%lld %lld",&n,&k);

 		for(i =0;i < n;i++) {
 			scanf("%lld" ,&arr[i]);
 		
 		}	

 		for(i =0;i < k;i++) {
 			scanf("%lld %lld",&a,&b);

 			memset(dp,0,sizeof dp);
 			ll lo = rundp(b,a);

       
 			printf("%lld\n", lo);
 		}

     	
     }
  

  
     return 0;
 }

