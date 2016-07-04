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
const int lmaxn = (int)2e7 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll n, bad[maxn], c[maxn], u[maxn], u2[maxn], c2[maxn];
string a;
vector < ll > g[maxn], rg[maxn];
vector < ll > all, kill;

ll dfs(ll v, ll p){
    if(u[v]) return c[v] | bad[v];
    u[v] = 1;
    c[v] |= bad[v];
    for(ll i : g[v]){
        if(i == p) continue;
        c[v] |= dfs(i, v);
    }
    return c[v];
}

ll rdfs(ll v, ll p){
    if(u2[v]) return c2[v] | bad[v];
    u2[v] = 1;
    c2[v] |= bad[v];
    for(ll i : rg[v]){
        if(i == p) continue;
        c2[v] |= rdfs(i, v);
    }
    return c2[v];
}

char s[maxn];

int main(){
    scanf("%lld", &n);
    while(true){
        scanf("%s", s);
        if(strcmp(s, "BLOOD") == 0) break;
        ll x = 0, y = 0, pos;
        sscanf(s, "%lld", &x);
        scanf("%lld", &y);
        g[y].pb(x);
        rg[x].pb(y);
    }

    ll num;
    while(scanf("%lld", &num) != EOF)
        bad[num] = 1;
    for(ll i = 1; i <= n; ++i)
        if(!u[i])
            dfs(i, i);
    for(ll i = 1; i <= n; ++i)
        if(!u2[i])
            rdfs(i, i);
    for(ll i = 1; i <= n; ++i)
        if(!c[i] && !c2[i])
            kill.pb(i);
    for(auto i : kill)
        printf("%lld ", i);
    if(kill.empty())
        printf("0");
    return 0;
}
