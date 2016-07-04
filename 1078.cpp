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
const int maxn = (int)3e5 + 7;
const int lmaxn = (int)4e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll n, dp[501], p[501];
vector < pll > e;
vector < ll > g[501];

ll get(ll x){
    if(~dp[x]) return dp[x];
    dp[x] = 1;
    for(ll i : g[x]){
        if(get(i) + 1 > dp[x]){
            dp[x] = get(i) + 1;
            p[x] = i;
        }
    }
    return dp[x];
}

int main(){
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i) dp[i] = -1;
    e.resize(n + 1);
    for(ll i = 1; i <= n; ++i)
        scanf("%lld %lld", &e[i].fi, &e[i].se);
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            if(i == j) continue;
            if(e[i].fi < e[j].fi && e[j].se < e[i].se)
                g[i].pb(j);
        }
    }
    ll mx = 1;
    for(ll i = 1; i <= n; ++i){
        if(get(i) > get(mx))
            mx = i;
    }
    printf("%lld\n", get(mx));
    vector < ll > ans;
    for(; mx; mx = p[mx])
        ans.pb(mx);
    reverse(ans.begin(), ans.end());
    for(auto i : ans)
        printf("%lld ", i);
    return 0;
}
