#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <ll > vk;

int main()
{
#ifndef ONLINE_JUDGE
	freopen ( "/home/placements2016/input.sam", "r", stdin );
#endif
	ios_base::sync_with_stdio ( false );
	ll i, j, k, n, m, t, cont, a, b;
	cin >> t;
	ll cases = t;
	string str;

	while ( t-- ) {
		cin >> str >> m;
		reverse ( str.begin(), str.end() );
		ll mul = 1;
		ll bigi = 0;
		ll mod = m;
		ll size = str.length();

		if ( str[size - 1] == '-' ) {
			size--;
		}

		for ( i = 0; i < size; i++ ) {
			bigi = ( bigi +  ( ( ( str[i] - '0' ) * mul ) % mod ) ) % mod;
			mul = ( mul * 10 ) % mod;
		}

		if ( bigi == 0 ) {
			cout << "Case " << cases - t << ": divisible\n";

		} else {
			cout << "Case " << cases - t << ": not divisible\n";
		}
	}

	return 0;
}