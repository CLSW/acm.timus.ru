# include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = (int)1e9 + 7;
const int maxn = (int)6e5 + 7;
const int lmaxn = (int)5e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ld a, b, c;

int main(){
    cin >> a >> b >> c;
    /*
    x1 * a = x2 * b
    x2 * b = x3 * c
    x1 + x2 + x3 = 1000

    x1 + (x1 * a) / b + (x1 * a) / c = 1000
    x1 + x1 * (a / b) + x1 * (a / c) = 1000
    x1 * (1 + (a / b) + (a / c)) = 1000
    x1 = (1000) / (1 + (a / b) + (a / c))
    */
    ld x1 = (1000.0) / (1.0 + (a / b) + (a / c));
    cout << ll(x1 * a + 0.5);
    return 0;
}
