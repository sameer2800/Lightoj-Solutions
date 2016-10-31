#include <iostream>
using namespace std;
 
long long int a[10005];
#define M 10000007
int main() {
    int t;
    cin>>t;
    int n=1;
    while(n<=t) {
        cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
        long long int sum = (a[0]+a[1]+a[2]+a[3]+a[4]+a[5])%10000007;
        int ac;
        cin>>ac;
        for(int i=6;i<=ac;i++) {
            a[i] = ((a[i-1]%M) + (a[i-2]%M) + (a[i-3]%M) + (a[i-4]%M) + (a[i-5]%M) + (a[i-6]%M)) % M;
        }
        cout <<"Case "<<n<<": "<<a[ac]%M<<"\n";
        n++;
    }
    return 0;
}