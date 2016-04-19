#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <pair <ll, ll> > v;
ll sprague[320], temp[320];

void sprague_grundy()
{
	sprague[0] = 0;
	sprague[1] = 1;

	for (int i = 2; i < 310; i++) {
		memset(temp, 0, sizeof temp);

		for (int j = 1; j <= i; j++) {
			int left = max(0, (j - 1) - 2);
			int right = max(0, (i - j) - 2);
			temp[sprague[left] ^ sprague[right]] = 1;
		}

		int k = 0;

		while (temp[k])k++;

		sprague[i] = k;
	}
}

ll position[320];
set <ll > st;
set <ll> pos;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b;
	cin >> t;
	ll cases = t;
	string str;
	sprague_grundy();

	while (t--) {
		memset(position, 0, sizeof position);
		cin >> str;
		//cout << str << endl;
		st.clear();
		pos.clear();
		ll noanswer  = 0;

		for (i = 0; i < str.size(); i++ ) {
			if (str[i] == 'X')
				pos.insert(i);
		}

		ll zerow = 0, maxiw = str.size() - 1;

		for (i = 0; i < str.size(); i++ ) {
			if (str[i] == 'X') {
				ll minps = max(zerow, i - 1);
				position[minps] = 1;
				minps = max(zerow, i - 2);
				position[minps] = 1;
				minps =  min(maxiw, i + 1);
				position[minps] = 1;
				minps =  min(maxiw, i + 2);
				position[minps] = 1;
			}
		}

		for (i = 0; i < str.length(); i++) {
			string temp = str;

			for (j = 0; j < temp.length() - 2; j++) {
				if (temp[j] == 'X' and temp[j + 1] == 'X' and temp[j + 2] == 'X') {
					noanswer = 1;
					break;
				}
			}
		}

		if (noanswer == 1) {
			cout << "Case " << cases - t << ": "  << "0" << endl;
			continue;
		}

		for (i = 0; i < str.length(); i++) {
			string temp = str;

			if (temp[i] == '.') {
				temp[i] = 'X';

				for (j = 0; j < temp.length() - 2; j++) {
					if (temp[j] == 'X' and temp[j + 1] == 'X' and temp[j + 2] == 'X') {
						st.insert(i + 1);
						break;
					}
				}

				temp = str;
			}
		}

		if (st.size() > 0) {
			cout << "Case " << cases - t << ": "  ;
			set<ll>::iterator it;
			ll sizo = st.size();
			ll tempr = 1;

			for ( it = st.begin(); it != st.end(); it++) {
				if (tempr < sizo) {
					cout << *it <<  " ";
					tempr++;

				} else {
					cout << *it ;
				}
			}

			cout  << endl;
			continue;
		}

		int diff, anso;

		for (i = 0; i < str.length(); i++) {
			if (str[i] == '.' and position[i] == 0 ) {
				pos.insert(i);
				ll curr = 0;
				ll fir = 1;
				ll ans = 0;

				for (set<ll>::iterator it = pos.begin(); it != pos.end(); it++) {
					//cout << *it <<  " ";
					if (fir == 1) {
						diff = *it - curr;
						anso = max(0, diff - 2);
						ans ^= sprague[anso];
						fir = 0;
						curr = *it;

					} else  {
						diff = *it - curr - 1;
						anso = max(0, diff - 4);
						ans ^= sprague[anso];
						curr = *it;
					}
				}

				diff = (str.length() - curr - 1);
				anso = max(0, diff - 2);
				ans ^= sprague[anso];

				if (ans == 0) {
					st.insert(i + 1);
				}

				pos.erase(i);
			}
		}

		if (st.size() != 0) {
			cout << "Case " << cases - t << ": "  ;
			set<ll>::iterator it;
			ll sizo = st.size();
			ll tempr = 1;

			for ( it = st.begin(); it != st.end(); it++) {
				if (tempr < sizo) {
					cout << *it <<  " ";
					tempr++;

				} else {
					cout << *it ;
				}
			}

			cout  << endl;
			continue;

		} else {
			cout << "Case " << cases - t << ": 0" << endl  ;
		}
	}

	return 0;
}