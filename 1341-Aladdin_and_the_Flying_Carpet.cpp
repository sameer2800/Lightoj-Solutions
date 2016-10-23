#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef pair<ll, int> P;
typedef vector<P> Vp;

const int MAX_PRIME = 1000000;

Vi primes;

void compute_primes() {
    Vi erat(MAX_PRIME + 1, 1);
    for (int i = 2; i*i <= MAX_PRIME; ++i) {
        if (erat[i]) {
            for (int j = i*i; j <= MAX_PRIME; j += i) {
                erat[j] = 0;
            }
        }
    }
    for (int i = 2; i <= MAX_PRIME; ++i) {
        if (erat[i]) {
            primes.push_back(i);
        }
    }
}

ll sq(ll n) {
    return n*n;
}

Vp factor(ll n) {
    Vp res;
    for (int i = 0; i < int(primes.size()) && sq(primes[i]) <= n; ++i) {
        int f = 0;
        while (n%primes[i] == 0) {
            n /= primes[i];
            ++f;
        }
        if (f != 0) {
            res.push_back(P(primes[i], f));
        }
    }
    if (n != 1) {
        res.push_back(P(n, 1));
    }
    return res;
}

int bt(int i, const Vp& v, ll t, ll a, ll b) {
    if (i == int(v.size())) {
        return t >= b ? 1 : 0;
    }
    int res = 0;
    for (int j = 0; j <= v[i].second; ++j) {
        if (t > MAX_PRIME || t*t >= a) {
            break;
        }
        res += bt(i + 1, v, t, a, b);
        t *= v[i].first;
    }
    return res;
}

int main() {
    compute_primes();
    int tcas;
    cin >> tcas;
    for (int cas = 1; cas <= tcas; ++cas) {
        ll a, b;
        cin >> a >> b;
        cout << "Case " << cas << ": ";
        if (a == 1) {
            cout << 0 << endl;
        } else {
            cout << bt(0, factor(a), 1, a, b) << endl;
        }
    }
}
