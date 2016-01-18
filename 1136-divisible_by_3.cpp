 #include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
  
 using namespace std;
  
 ll arr[100100]; 
 vector <ll > vk;
 
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
		cin >> a >> b;

		ll upto_b = b/3;
			upto_b *= 2;		
		if(b % 3 == 2)
			upto_b += 1;




		ll upto_a = (a-1)/3;	  				
     	upto_a *= 2;

     	if((a-1) % 3 == 2)
			upto_a += 1;

		
		 cout << "Case " << cases-t << ": " << upto_b -upto_a << endl;
     	
     }
  
  
  
     return 0;
 }