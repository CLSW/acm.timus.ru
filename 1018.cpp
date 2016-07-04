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

ll n, k, d[201][201];
vector < pll > g[201];

void dfs(ll v, ll p){
    ll f = -1, cf = -1, s = -1, cs = -1;
    for(pll i : g[v]){
        if(i.fi == p) continue;
        dfs(i.fi, v);
        if(f == -1)
            f = i.fi, cf = i.se;
        else
            s = i.fi, cs = i.se;
    }
    if(f == -1 && s == -1)
        return;
    else if(s == -1){
        for(ll fq = 1; fq <= n; ++fq)
            d[v][fq] = d[f][fq - 1] + cf;
    }
    else{
        for(ll c1 = 1; c1 <= n; ++c1)
            d[v][c1] = max(d[v][c1], d[f][c1 - 1] + cf);
        for(ll c2 = 1; c2 <= n; ++c2)
            d[v][c2] = max(d[v][c2], d[s][c2 - 1] + cs);
        for(ll c1 = 1; c1 <= n; ++c1){
            for(ll c2 = 1; c2 <= n; ++c2){
                if(c1 + c2 >= n) continue;
                d[v][c1 + c2] = max(d[v][c1 + c2], d[f][c1 - 1] + cf +  d[s][c2 - 1] + cs);
            }
        }
    }
}

main(){
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i < n; ++i){
        ll x, y, w;
        scanf("%lld %lld %lld", &x, &y, &w);
        g[x].pb(mp(y, w));
        g[y].pb(mp(x, w));
    }
    dfs(1, 1);
    printf("%lld", d[1][k]);
    return 0;
}
