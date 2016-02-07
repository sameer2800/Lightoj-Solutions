#include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
 
 using namespace std;
 
 ll arr[250][250];
 vector <ll > v1,v2;
 ll m,n,src,dest;
 ll visited[250];
 ll parent[250];

 int bfs()
 {

 	queue < ll> q;

 	q.push(src);

 	memset(visited,0,sizeof visited);
 	memset(parent,-1,sizeof parent);

 	visited[src] = 1;

 	while(!q.empty()) {
 		ll fr = q.front();
 		q.pop();

 		if(fr == dest)
 			return 1;

 		for(int i =0;i <= dest;i++) {
 			if(arr[fr][i] > 0 and visited[i] == 0) {
 				q.push(i);
 				parent[i] =fr;
 				visited[i] =1;
 			}
 		}	
 	}

 	return 0;

 }


 ll max_biparitite_matching()
 {


 	ll ans =0;

 	ll temp =0;

 	while(bfs()) {

 		ll curr = dest;
 		ll min_edge= INT_MAX;

 		while(curr != src) {

 			min_edge = min(min_edge,arr[parent[curr]][curr]);
 			curr = parent[curr];
 		}	

 		 curr = dest;

 		while(parent[curr] != -1) {
 			arr[parent[curr]][curr] -= min_edge;
 			arr[curr][parent[curr]]  += min_edge;
 			curr = parent[curr];
 		}	

 		ans++;
 	}

 	return ans;
 }


 int main()
 {
     
    #ifndef ONLINE_JUDGE
    freopen("/home/sameer/Documents/sameer/input.sam","r",stdin);
    #endif
 

     ll i,j,k,t,cont,a,b;
  
     scanf("%lld",&t);	

     ll cases = t;
 
     while(t--){
       memset(arr,0,sizeof arr);
       v1.clear(),v2.clear();
        scanf("%lld",&n);

         for(i=0;i < n;i++) {
         	scanf("%lld",&k);
         	v1.push_back(k);
         }
         	
         scanf("%lld",&m);
         for(i =0;i < m;i++){
         	scanf("%lld",&k);
         	v2.push_back(k);
         }

         for(i =0;i < n;i++) {
         	for(j =0;j < m;j++) {
         		if(v2[j] %v1[i] == 0)
         			arr[i][j+n] = 1;
         	}
         }

          src = m+n+1 ;
          dest = m +n+2;

         for(i =0;i < n;i++) {
         	arr[m+n+1][i] = 1;
         } 

         for(j =0;j <m;j++ ) {
         	arr[j+n][m+n+2] = 1;
         }

        ll ans = max_biparitite_matching();

        printf("Case %lld: %lld\n",cases-t,ans);
         
        
     }
 
 
 
     return 0;
 }