#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <pair <ll, ll> > v;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n >> m;
		deque <ll > dq;
		cout << "Case " << cases - t << ":" << endl;
		string str;

		for (i = 0; i < m; i++) {
			cin >> str ;

			if (str == "pushLeft") {
				cin >> k;

				if (dq.size() == n) {
					cout << "The queue is full\n";

				} else {
					dq.push_front(k);
					cout << "Pushed in left: " << k << "\n";
				}

			} else if (str == "pushRight") {
				cin >> k;

				if (dq.size() == n) {
					cout << "The queue is full\n";

				} else {
					dq.push_back(k);
					cout << "Pushed in right: " << k << "\n";
				}

			} else if (str == "popLeft") {
				if (dq.empty())  {
					cout << "The queue is empty\n";
				}

				else {
					k = dq.front();
					dq.pop_front();
					cout << "Popped from left: " << k << endl;
				}

			} else if (str == "popRight") {
				if (dq.empty())  {
					cout << "The queue is empty\n";
				}

				else {
					k = dq.back();
					dq.pop_back();
					cout << "Popped from right: " << k << endl;
				}

			} else {
				cout << "hello-----------------------\n";
			}
		}
	}

	return 0;
}