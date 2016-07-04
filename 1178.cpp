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

ll n, x, y;
vector < pair < pll, ll > > v;

int main(){
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i){
        scanf("%lld %lld", &x, &y);
        v.pb(mp(mp(x, y), i));
    }
    sort(begin(v), end(v));
    for(ll i = 0; i < (ll)v.size(); i += 2)
        printf("%lld %lld\n", v[i].se, v[i + 1].se);
    return 0;
}
