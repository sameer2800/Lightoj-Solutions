#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr1[10], arr2[20];
set <ll> set1;
ll n, k;

ll glob;
void recursive_generate(ll val, ll ind)
{
	set1.insert(val);

	if (ind == n / 2)
		return;

	recursive_generate(val + 0 , ind + 1);
	recursive_generate(val + arr1[ind] , ind + 1);
	recursive_generate(val + 2 * arr1[ind] , ind + 1);
}

ll flag = 0;

void find_and_recursive2(ll val, ll ind)
{
	if (set1.find(k - val) != set1.end()) {
		flag = 1;
		return;
	}

	if (flag == 1)
		return;

	if (ind == n)
		return;

	find_and_recursive2(val, ind + 1);
	find_and_recursive2(val + arr2[ind] , ind + 1);
	find_and_recursive2(val + 2 * arr2[ind] , ind + 1);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, m, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		set1.clear();
		cin >> n >> k;
		flag = 0;

		for (i = 0; i < n / 2; i++)
			cin >> arr1[i];

		for (; i < n ; i++)
			cin >> arr2[i];

		recursive_generate(0, 0);
		find_and_recursive2(0, n / 2);

		if (flag == 1 )
			cout << "Case " << cases - t << ": "  << "Yes" << endl;
		else
			cout << "Case " << cases - t << ": "  << "No" << endl;
	}

	return 0;
}
