#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll finddigits(ll n,ll digits)
{

	ll	mod = digits % n;
	ll ans =1 ;
	ll tens = 10;
	while(mod != 0){
		mod = ((digits % n * tens % n) % n + mod)% n; 
		ans++;
		tens *=   10;
		tens %= n;
	}

	return ans;

}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam","r",stdin);
	#endif


	//	ios_base::sync_with_stdio(false);
	ll i,j,k,n,m,t,cont,digit;
	
//	cin >> t;
	scanf("%lld",&t);
	ll cases = t;

	while(t--){

		//cin >> n >> digit;

		scanf("%lld %lld",&n,&digit);

		 printf("Case ");
		 printf("%lld: %lld\n",cases-t,finddigits(n,digit));
	}



	return 0;
}
