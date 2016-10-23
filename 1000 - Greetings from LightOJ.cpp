#include <iostream>
using namespace std;

int main() {
	int t;
	cin >>t;
	int n =1;
	while(n<=t) {
		int a,b;
		cin>>a>>b;
		cout << "Case "<<n<<": "<<a+b<<"\n";
		n++; 
	}
	return 0;
}