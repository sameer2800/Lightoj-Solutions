#include <iostream>
using namespace std;

int main(){

    int t;
    cin >> t;
    int n;

    while(t--){
        cin >> n;

        if(n > 10)
            cout << 10 << " " << n - 10 << endl;
        else
            cout << 0 << " " << n << endl;
    }
}
