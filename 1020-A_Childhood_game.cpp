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

	string s,ans;
	while(t--){

		cin >> k >> s;

		if(s == "Alice"){

			if(k % 3 == 1)
				ans = "Bob";
				else
				ans = "Alice";	

		}else {

			if(k % 3 !=0)
				ans = "Bob";
			else
				ans = "Alice";

		}

		 cout << "Case " << cases - t  << ": "  << ans<< endl;
	}



	return 0;
}
