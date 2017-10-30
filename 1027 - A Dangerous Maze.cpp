/*
Suppose in the beginning u r standing in front of maze. Say this state as X.
Now lets say that the expected value of result for this question be E.
If there are n doors, E = Average of expected time taken to take each door.
E = (E1 + E2 + E3 ... + En)/N.
==> If the value of Ai is positive, Ei = Ai coz it will take Ai time to get out of maze.
==> If the value of Ai is negative, Ei = abs(Ai) + E coz u will roam around in the maze
for Ai minutes and then again go back to beginning, i.e. state X.
Now if all the values are negative then we will never be able to get out of the maze.
Then the answer will be infinity.*/


#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector < pii >
#define si set<int>
#define ll long long int
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MOD 1000003
#define MAX 10100

ll gcd ( ll a , ll b )
{
    if (a%b == 0)
        return b;
    return gcd(b,a%b);
}


int main ()
{
    //cout << setprecision(7) << fixed;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int cas=1;
	while (t--){
		cout<<"Case "<<cas++<<": ";
        int n;
        cin>>n;
        int a[n];
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        int numer = 0;
        int denom = n;
        int negetives = 0;
        for (int i=0;i<n;i++){
            numer += abs(a[i]);
            negetives += (a[i] < 0) ? 1 : 0;
        }
        denom -= negetives;
        if (denom == 0)
            cout<<"inf"<<endl;
        else{
            int gc = gcd(numer,denom);
            cout<<numer/gc<<"/"<<denom/gc<<endl;
        }
	}
	return 0;
}


