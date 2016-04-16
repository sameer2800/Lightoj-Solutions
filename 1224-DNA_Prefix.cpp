#include <bits/stdc++.h>
#define ll long long
#define null NULL
#define MAX 100100

using namespace std;

vector <ll > vk;
map < char, int> mp;

struct node {
	int end;
	int height, countr;
	struct node* links[4];
};

struct node *head;

struct node* initilizer()
{
	struct node * naah = new node();
	naah -> end = -1;
	naah -> countr = 0;

	for ( int i = 0; i < 4; i++ ) {
		naah -> links[i] = NULL;
	}

	return naah;
}

void addtotrie ( struct node* curr, string s, int index , int heigh)
{
	curr -> countr = curr -> countr + 1;
	curr -> height  = heigh;

	if ( index == s.size() )
		return;

	int num = mp[s[index]];

	if ( curr -> links[num] == NULL ) {
		curr -> end = 0;
		curr -> links[num] = initilizer();
		return addtotrie ( curr -> links[num], s, index + 1, heigh + 1 );

	} else {
		return	addtotrie ( curr -> links[num], s, index + 1 , heigh + 1);
	}
}

void freememory ( struct node* curr )
{
	if ( curr != NULL ) {
		for ( int i = 0; i < 4; i++ ) {
			if ( curr -> links[i] != NULL ) {
				freememory ( curr -> links[i] );
			}
		}

		free ( curr );
	}
}

int traverser(node* curr)
{
	if (curr == NULL)
		return 0;

	int score = curr-> height * curr -> countr;

	for (int i = 0; i < 4; i++) {
		score =  max(score, traverser(curr -> links[i]));
	}

	return score;
}




int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio ( false );
	ll i, j, k, n, m, t, cont, a, b;
	cin >> t;
	ll cases = t;
	string s, sa;
	int flg = 0;
	mp['A'] = 0, mp['C'] = 1, mp['G'] = 2, mp['T'] = 3;

	while ( t-- ) {
		cin >> n;
		head = initilizer();
		flg = 0;

		for ( i = 0; i < n; i++ ) {
			cin >> s;
			addtotrie ( head, s, 0, 0);
		}

		ll ans = traverser(head);
		cout << "Case " << cases - t  << ": "  << ans << endl;
		freememory ( head );
	}

	return 0;
}