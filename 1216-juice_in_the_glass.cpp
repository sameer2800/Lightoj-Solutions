#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <ll > vk;
double pi = 3.14159265359;


int main()
{
#ifndef ONLINE_JUDGE
	freopen ( "/home/placements2016/input.sam", "r", stdin );
#endif
	//ios_base::sync_with_stdio ( false );
	ll i, j, k, n, m, t, cont, a, b, r1, r2, h, p;
	cin >> t;
	ll cases = t;

	while ( t-- ) {
		cin >> r1 >> r2 >> h >> p;
		double rad =   ( p * ( r1 - r2 ) ) / double ( h )  + r2;
		double vol = pi * p * ( ( r2 * r2 ) + ( rad * rad ) + ( rad * r2 ) );
		vol /= double ( 3.0 );
		cout << "Case " << cases - t << ": " ;
		printf ( "%.8f\n", vol );
	}

	return 0;
}