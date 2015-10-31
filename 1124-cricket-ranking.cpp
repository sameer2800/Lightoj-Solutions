#include <bits/stdc++.h>
#define ll long long
#define MAX 100100
#define mod 100000007 
using namespace std;

ll arr[12];
ll mark[1 << 12];
ll total =0;
ll fact[1000100];
ll ifact[1000100];

ll ncr(ll n,ll r)
{
	if(r > n)
		return 0;

	ll numer = fact[n];

	ll denom = (ifact[r] * ifact[n-r]) % mod;

	return (numer*denom) % mod;
	
}

void recursesubsets(ll curr,ll n,ll r)
{
	ll cnt = __builtin_popcount(curr);	

	if(cnt > r || mark[curr] == 1)
		return ;


	ll n1 = n;

	for(ll i =0;i < r;i++) {
		ll oo =curr & (1 << i);
		if((curr & (1 << i)) != 0) {
			n1 -= arr[i]; 
		}
	}

	if(n1 >= 0){
	if(cnt % 2 == 0) {
		total += ncr(n1 + r-1,r-1);
		total %= mod;
		//cout << "adding : " << n1 << " " << curr << " " <<  ncr(n1 + r-1,r-1) << endl;	

	}else {
		total -= ncr(n1+r-1,r-1);
		total %= mod;
		if(total < 0)
			total += mod;
	//	cout << "substr : " << n1 << " " << curr  << " " <<  ncr(n1 + r-1,r-1) << endl;

	}
	}

	mark[curr] = 1;

	for(ll i =0;i < r;i++) {
		if((curr & (1 << i)) == 0) {
			recursesubsets(curr | (1 << i) , n,r);
		}
	}


}

ll yofunct(ll r,ll n)
{	
	total = 0;

	memset(mark,-1,sizeof mark);

	recursesubsets(0,n,r);

	return total;
}

ll power(ll a,ll b)
{
	if(b==0)
		return 1;

	if(b==1)
		return a;

	ll half = power(a,b/2);

	if(b % 2 != 0){
		return (((half * half) % mod ) * a) % mod;
	}
	else
		return ((half * half) % mod ) ;
		
}

void prefunc()
{

	fact[0] = 1;

	for(int i =1;i < 1000020;i++){ 
		fact[i] = (i * fact[i-1]) % mod;
		fact[i] %= mod;
	}	

	ifact[0] = 1;
	ifact[1] = 1;

	for(int i =2;i < 1000020;i++) {
		ifact[i] = (power(i,mod-2) * ifact[i-1] ) % mod;
		ifact[i] %= mod;
	}

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam","r",stdin);
	#endif

	ll i,j,k,n,a,b,m,t,cont,r;
	
	scanf("%lld",&t);
	ll cases = t;

	prefunc();

	while(t--){

		printf("Case %lld: ",cases-t);

		scanf("%lld %lld",&r,&n);

		for(i =0;i < r;i++) {
            cin >> a >> b;
            arr[i] = b-a+1;
            n -= a;   
		}

		printf("%lld\n",yofunct(r,n));			

	}


	return 0;
}
