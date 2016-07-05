

ll n;
ll up[maxN][22], s[maxN][22], tin[maxN], tout[maxN], he[maxN], T;
vector < pll > g[maxN];

void Dfs(ll v, ll p){
    up[v][0] = p;
    he[v] = he[p] + 1;
    tin[v] = ++T;
    for(ll i = 1; i < 22; ++i)
        up[v][i] = max(1ll, up[up[v][i - 1]][i - 1]), s[v][i] = s[v][i - 1] + s[up[v][i - 1]][i - 1];
    for(auto i : g[v]){
        if(i.first != p){
            s[i.first][0] += i.second;
            Dfs(i.first, v);
        }
    }
    tout[v] = ++T;
}

bool Ancestor(ll a, ll b){
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

ll Lca(ll a, ll b){
    if(Ancestor(a, b)) return a;
    if(Ancestor(b, a)) return b;
    if(he[a] < he[b]) swap(a, b);
    for(ll i = 21; i >= 0; --i)
        if(!Ancestor(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

ll Get(ll a, ll b){
    if(a == b) return 0;
    ll sum = 0;
    for(ll i = 21; i >= 0; --i){
        if(!Ancestor(up[b][i], a))
            sum += s[b][i], b = up[b][i];
    }
    sum += s[b][0];
    return sum;
}

int main(){
    scanf("%lld", &n);
    for(ll i = 1; i < n; ++i){
        ll u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        ++u, ++v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    Dfs(1, 1);
    ll q;
    scanf("%lld", &q);
    for(ll i = 1; i <= q; ++i){
        ll u, v;
        scanf("%lld %lld", &u, &v);
        ++u, ++v;
        ll l = Lca(u, v);
        printf("%lld\n", Get(l, u) + Get(l, v));
    }
    return 0;
}
