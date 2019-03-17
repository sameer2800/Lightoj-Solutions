#include<bits/stdc++.h>
#include<set>

using namespace std;

#define pb push_back
#define mp make_pair
#define vi vector<int>
#define f first
#define s second
#define pii pair<int,int>
#define vii vector<pair<int,int> >
#define si stack<int>
#define ll long long int
#define MAX 1000000000010

ll cou;
int prime[1000100];
vector<int> store_prime;
ll n;

void sieve(){
    int sq=sqrt(1000010);
    for(int i=2;i<1000010;i++){
        if(prime[i]==0){
            store_prime.pb(i);
            int num=i+i;
            while(num<=1000010){
                prime[num]=1;
                num+=i;
            }
        }
    }
}

void fun(ll n){
    ll sq=sqrt(n);
    for(ll i=0;i<store_prime.size() && store_prime[i]<=sq;i++){
        ll p1=0;
        ll nn=store_prime[i];
        while(n%nn==0){
            p1++;
            n=n/nn;
        }
        cou=cou*(p1+1);
        sq=sqrt(n);
    }
    if(n>1)
        cou=cou*2;
}

int main()
{
    //freopen("input.txt","r",stdin);

    sieve();

    int t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%lld",&n);
        cou=1;
        fun(n);
        printf("Case %d: %lld\n",i,cou-1);
    }
    return 0;
}

