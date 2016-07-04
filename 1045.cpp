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

ll n, s;
ll d[maxn][4];
vector < ll > g[maxn];

void dfs(ll v, ll p){
    for(ll i : g[v]){
        if(i == p) continue;
        dfs(i, v);
        d[v][1] |= !d[i][0];
        d[v][0] |= !d[i][1];
    }
}

int main(){
    scanf("%lld %lld", &n, &s);
    for(ll i = 1; i < n; ++i){
        ll x, y;
        scanf("%lld %lld", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(s, s);
    if(d[s][1]){
        ll mn = linf;
        for(ll i : g[s])
            if(!d[i][0])
                mn = min(mn, i);
        printf("First player wins flying to airport %lld", mn);
    }
    else{
        printf("First player loses");
    }
    return 0;
}
