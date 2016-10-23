#include <iostream>
using namespace std;

int main() {
	int no=1;
	int t;
	cin >>t;
	while(t--) {
		long long int a,di,x,y;
		cin >>di;
		cin >>x;
		if(di < x) {
			a = di;
			di = x;
			x = a;	
		}
		cin >> y;
		if(di < y) {
			a = di;
			di = y;
			y = a;
		}
		if((x*x) + (y*y) == (di*di)) cout <<"Case "<<no++<<": yes\n";
		else cout <<"Case "<<no++<<": no\n";
	}
	return 0;
}