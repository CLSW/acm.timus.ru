#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <climits>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <utility>
#include <sstream>
#include <numeric>
#include <functional>
#include <bitset>
#include <deque>

using namespace std;

#if __cplusplus >= 201103
    #include <unordered_map>
    #include <future>
    #include <atomic>
    #include <chrono>
    #include <unordered_set>
    #include <array>
    #include <random>
    #include <mutex>
#endif

#define pii pair<int, int>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define f first
#define s second

typedef long long ll;
typedef long double ld;

const int inf = (int)1e9 + 7;
const int linf = (int)1e16 + 7;
const int maxn = (int)4e5 + 7;

const ld eps = ld(1e-11);


# define int long long

int t[maxn];

void update(int v, int tl, int tr, int pos, int val){
    int tm = (tl + tr) >> 1;
    if(tl == tr){
        t[v] += val;
        return;
    }
    if(pos <= tm)
        update(v * 2, tl, tm, pos, val);
    else
        update(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r){
    int tm = (tl + tr) >> 1;
    if(l > r) return 0;
    if(l == tl && r == tr) return t[v];
    return max(get(v * 2, tl, tm, l, min(r, tm)),
               get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}


int n, q, sz;
int x, y, ve, in, now;
int pos[maxn], ind[maxn], head[maxn], s[maxn];
int tin[maxn], tout[maxn], h[maxn], up[maxn][21], tim;
char f;

vector < int > g[maxn];

void dfs(int v, int p){
    h[v] = h[p] + 1;
    s[v] = 1;
    tin[v] = ++tim;
    up[v][0] = p;
    for(int i = 1; i <= 20; ++i)
        up[v][i] = max(1ll, up[up[v][i - 1]][i - 1]);
    for(int i : g[v]){
        if(i == p) continue;
        dfs(i, v);
        s[v] += s[i];
    }
    tout[v] = ++tim;
}

inline int ancestor(int a, int b){
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

inline int lca(int a, int b){
    if(ancestor(a, b)) return a;
    if(ancestor(b, a)) return b;
    if(h[a] < h[b]) swap(a, b);
    for(int i = 20; i >= 0; --i){
        if(!ancestor(up[a][i], b))
            a = up[a][i];
    }
    return up[a][0];
}

void hld(int v, int p){
    pos[v] = ++sz;
    ind[v] = now;
    if(!head[now])
        head[now] = v;
    int mx = 0;
    for(int i : g[v]){
        if(i == p) continue;
        if(!mx || s[i] > s[mx])
            mx = i;
    }
    if(!mx) return;
    hld(mx, v);
    for(int i : g[v]){
        if(i == p || i == mx) continue;
        ++now;
        hld(i, v);
    }
}

inline int query(int a, int b){
    int ans = 0;
    while(true){
        if(ind[a] == ind[b]){
            ans = max(ans, get(1, 1, sz, pos[a], pos[b]));
            break;
        }
        ans = max(ans, get(1, 1, sz, pos[head[ind[b]]], pos[b]));
        b = head[ind[b]];
        b = up[b][0];
    }
    return ans;
}

inline int Query(int a, int b){
    int l = lca(a, b);
    return max(query(l, a), query(l, b));
}

main(){
    scanf("%lld", &n);
    for(int i = 1; i < n; ++i){
        scanf("%lld %lld", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 1);
    hld(1, 1);
    scanf("%lld", &q);
    for(int i = 1; i <= q; ++i){
        scanf(" %c", &f);
        if(f == 'I'){
            scanf("%lld %lld", &ve, &in);
            update(1, 1, sz, pos[ve], in);
        }
        else{
            scanf("%lld %lld", &ve, &in);
            printf("%lld\n", Query(ve, in));
        }
    }
    return 0;
}
