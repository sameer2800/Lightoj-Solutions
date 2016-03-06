#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[22];
ll facto[22];
vector <pair <ll, ll> > v;

void fact()
{
	facto[0] = 1;

	for (int i = 1; i < 21; i++)
		facto[i] = i * facto[i - 1];
}

ll yes ;
ll indx;

void recursive(ll num,  ll pos)
{
//	cout << num << endl;
	if (num == 0 )
	{
		yes = 1;
		return;
	}

	if (pos == -1)
		return;

	if (num >= facto[pos]) {
		arr[indx] = pos;
		indx++;
		recursive(num - facto[pos], pos - 1 );
		return;
	}

	recursive(num, pos - 1);
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b;
	cin >> t;
	ll cases = t;
	fact();

	while (t--) {
		cin >> n ;
		yes = 0;
		indx = 0;
		memset(arr, 0, sizeof arr);
		recursive(n,  20);
		cout << "Case " << cases - t << ": "  ;

		if (yes == 1) {
			for (i = indx - 1; i >  0; i--)
				cout << arr[i] << "!+";

			cout << arr[0] << "!\n";

		} else {
			cout << "impossible\n";
		}
	}

	return 0;
}