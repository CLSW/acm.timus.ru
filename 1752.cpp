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
const int maxn = (int)1e5 + 7;
const int lmaxn = (int)2e7 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll gcd(ll a, ll b){
    while(b) a %= b, swap(a, b);
    return a | b;
}

ll n, q, d[maxn], h[maxn], tin[maxn], tout[maxn], T, up[maxn][21];
vector < ll > g[maxn];

void dfs(ll v, ll p){
    h[v] = h[p] + 1;
    up[v][0] = p;
    tin[v] = ++T;
    for(ll i = 1; i < 21; ++i)
        up[v][i] = max(1ll, up[up[v][i - 1]][i - 1]);
    for(ll i : g[v]){
        if(i == p) continue;
        dfs(i, v);
    }
    tout[v] = ++T;
}

bool ancestor(ll a, ll b){
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

ll lca(ll a, ll b){
    if(ancestor(a, b)) return a;
    if(ancestor(b, a)) return b;
    if(h[a] < h[b]) swap(a, b);
    for(ll i = 20; i >= 0; --i)
        if(!ancestor(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

ll dist(ll a, ll b){
    return h[a] + h[b] - 2 * h[lca(a, b)];
}

ll getkth(ll v, ll k){
    for(ll i = 0; i < 21; ++i)
        if((k >> i) & 1)
            v = up[v][i];
    return v;
}

ll bfs(ll s){
    queue < ll > q;
    fill(d + 1, d + 1 + n, -1);
    q.push(s);
    d[s] = 0;
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        for(ll i : g[v]){
            if(d[i] == -1){
                d[i] = d[v] + 1;
                q.push(i);
            }
        }
    }
    return max_element(d + 1, d + 1 + n) - d;
}

pll get(){
    pll ans;
    ans.fi = bfs(1);
    ans.se = bfs(ans.fi);
    return ans;
}

int main(){
    scanf("%lld %lld", &n, &q);
    for(ll i = 1; i < n; ++i){
        ll x, y;
        scanf("%lld %lld", &x, &y);
        g[x].pb(y), g[y].pb(x);
    }
    dfs(1, 1);
    pll far = get();
    while(q--){
        ll x, w;
        scanf("%lld %lld", &x, &w);
        if(dist(x, far.fi) < dist(x, far.se))
            swap(far.fi, far.se);

        if(dist(x, far.fi) < w){
            printf("0\n");
            continue;
        }
        ll l = lca(x, far.fi);
        if(dist(l, x) >= w){
            printf("%lld\n", getkth(x, w));
        }
        else{
            if(ancestor(x, far.fi)){
                w = dist(x, far.fi) - w;
                printf("%lld\n", getkth(far.fi, w));
                continue;
            }
            w = dist(l, far.fi) - (w - dist(l, x));
            printf("%lld\n", getkth(far.fi, w));
        }
    }

    return 0;
}
