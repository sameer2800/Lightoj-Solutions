#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];



int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	ll i, j, k, n, m, t, cont, a, b;
	scanf("%lld", &t);
	ll cases = t;
	string s, sa;

	while (t--) {
		char str[100];
		scanf("%s", str);
		int len = strlen(str);
		int flag = 0;

		for (i = 0, j = len - 1; i <= j; i++, j--) {
			if (str[i] != str[j])
				flag = 1;
		}

		printf("Case %lld: ", cases - t);

		if (flag == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}/*
Case 1: Yes
Case 2: No
Case 3: Yes
Case 4: No
Case 5: Yes
*/