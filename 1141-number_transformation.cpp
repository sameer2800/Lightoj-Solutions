#include <bits/stdc++.h>
#define ll long long
#define MAX 100100
 
 using namespace std;
 
 ll arr[1100];
 vector <ll > v;
 queue <pair<ll,ll> > q;
ll mark[1100][1100];

 ll prime_factors(ll n)
 {
 	ll temp =n;

 	for(int i =2;i*i <= n;i++){
 		if(n % i ==0) {
 			v.push_back(i);

 			while(n % i ==0){
 				n /= i;
 			}
 		}
 	}

 	if(temp != n and temp != 1){
 		v.push_back(n);
 	}

 }

ll bfs(int n,int m)
{
	while(!q.empty())	
		q.pop();

	memset(mark,0,sizeof mark);

	q.push(make_pair(n,0));

	ll ans = MAX;
	while(!q.empty()) {


		pair <ll,ll> p  = q.front();
		q.pop();

		//cout << p.first << " " << p.second << endl;

		if(p.first > m){
			continue;
		}
		
		if(mark[p.first][p.second])
			continue;

		mark[p.first][p.second] = 1;

		
		if(p.first == m){
			ans = min(p.second,ans);
			
		}

		int temp =p.first;
		for(int i =2;i*i <= temp;i++){
 			if(temp % i ==0) {
 				q.push(make_pair(p.first+i,p.second+1));

 				while(temp % i ==0){
 					temp /= i;
 				}
 			}
 		}

 	if(temp != p.first and temp != 1){
 	//	cout << "hekk " << p.first << " " << temp << endl;
 		q.push(make_pair(p.first+temp,p.second+1));

 	}

	}	

	if(ans >= MAX)
	return -1;
	else
		return ans;

}

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
        
          for(i =0;i < m+5;i++) {
          	
          	arr[i] = MAX;
          }

          v.clear();

          prime_factors(n);
        

        	ll ans = bfs(n,m);	
         
            cout << "Case " << cases-t << ": "  << ans << endl;
                
       
     }
 
 
 
     return 0;
 }