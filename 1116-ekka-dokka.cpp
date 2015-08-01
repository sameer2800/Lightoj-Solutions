#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam","r",stdin);
	#endif


	ios_base::sync_with_stdio(false);
	ll i,j,k,n,m,t,cont;
	
	cin >> t;
	ll cases = t;

	while(t--){

		cin >> k;

		if(k % 2 != 0)		
		 cout << "Case " << cases - t  << ": " << "Impossible"  << endl;
		else {

			m = 2;
			n = k/2;

			while(n % 2 == 0){
				n /= 2;
				m *= 2;
			}


			cout << "Case " << cases - t  << ": " <<  n  <<  " " <<  m  <<  endl ;

		}

	}



	return 0;
}
