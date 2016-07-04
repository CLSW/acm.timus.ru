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
const int lmaxn = (int)6e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll gcd(ll a, ll b){
    while(b) a %= b, swap(a, b);
    return a | b;
}

ll n, m;
map < ll, ll > d;

void F(ll x, map < ll, ll > &a, ll e){
    for(ll i = 2; i * i <= x; ++i){
        while(x % i == 0){
            x /= i;
            a[i] += e;
        }
    }
    if(x > 1)
        a[x] += e;
}

int main(){
    scanf("%lld %lld", &n, &m);
    for(ll i = 2; i <= n; ++i)
        F(i, d, 1);
    for(ll i = 2; i <= m; ++i)
        F(i, d, -1);
    for(ll i = 2; i <= n - m; ++i)
        F(i, d, -1);
    ll ans = 0;
    for(auto i : d)
        if(i.se)
            ++ans;
    printf("%lld", ans);
    return 0;
}
