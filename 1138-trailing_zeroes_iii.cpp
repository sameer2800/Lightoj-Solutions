#include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
 
 using namespace std;
 
 ll arr[100100];
 vector <pair <ll,ll> > v;
 
 ll zeroes(ll k)
 {

 	ll five_pow =5;

 	ll ans =0;
 	while(five_pow <= k) {
 		ans += k/five_pow;
 		five_pow *= 5;
 	}

 	return ans;
 }

ll binary_search(ll val)
{

		ll low = 0;
		ll high = 1e9;
		ll mid;

		while(low <= high){

			mid = low + high;
			mid /= 2;

			ll yo = zeroes(mid);

			if(yo == val) {
				return (mid - mid%5);
			}

			if(yo > val) {
				high = mid-1;
			}else {
				low = mid+1;
			}
		}


		return -1;
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
       
          cin >> n;

         ll ans = binary_search(n);
         
         if(ans != -1)
          cout << "Case " << cases-t << ": "  << ans << endl;
 		else 
 		cout << "Case "	 << cases-t << ": "  << "impossible" << endl;
                     
       
     }
 
 
 
     return 0;
 }