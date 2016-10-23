#include <iostream>
using namespace std;

int values[100005];
int a,b,c,d,e,f, n;
int t;

int func(int i){

        values[0] = a;
        values[1] = b;
        values[2] = c;
        values[3] = d;
        values[4] = e;
        values[5] = f;

        for(int n = 6; n <= i; n++)
            values[n] = values[n-1] + values[n-2] + values[n-3] + values[n-4] + values[n-5] + values[n-6];

    return values[i] % 10000007;
}
int main(){
    cin >> t;
    int count = 1;
    while(t--){
        cin >> a >> b >> c >> d >> e >> f >> n;
        cout << "Case " << count << ": " << func(n) << endl;
        count++;
    }
}
