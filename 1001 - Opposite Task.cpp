#include <iostream>
using namespace std;

int main() {
	int t;
	cin >>t;
	int n =1;
	while(n<=t) {
		int a;
		cin>>a;
		if(a>10) {
			cout<<a-10<<" "<<10<<"\n";
		} else cout << 0 <<" "<<a<<"\n";
		n++; 
	}
	return 0;
}