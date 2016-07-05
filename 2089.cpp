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

ll n, m;
ll x[maxn], y[maxn], deg[maxn], u[maxn], lol[maxn], u2[maxn];
vector < ll > win[maxn];
set < pll > s;

int main(){
    scanf("%lld %lld", &m, &n);
    for(ll i = 1; i <= m; ++i){
        scanf("%lld %lld", &x[i], &y[i]);
        win[x[i]].pb(i), win[y[i]].pb(i);
        ++deg[x[i]], ++deg[y[i]];
    }
    for(ll i = 1; i <= n; ++i)
        s.insert(mp(deg[i], i));
    while(!s.empty()){
        ll v = (*s.begin()).se;
        s.erase(mp(deg[v], v));
        ll mx = 0, id = 0;
        for(ll j : win[v]){
            if(u[j]) continue;
            ll other = (x[j] == v ? y[j] : x[j]);
            if(!id || mx < deg[other])
                id = j, mx = deg[other];
        }
        if(!id)
            continue;
        u2[v] = 1;
        ll other = (x[id] == v ? y[id] : x[id]);
        if(!u2[other]){
            s.erase(s.find(mp(deg[other], other)));
            deg[other]--;
            s.insert(mp(deg[other], other));
        }
        deg[v] = linf;
        lol[id] = v;
        u[id] = 1;
    }
    set < ll > ss;
    for(ll j = 1; j <= m; ++j){
        ss.insert(lol[j]);
        if(!lol[j]){
            printf("No");
            return 0;
        }
    }
    if(ss.size() != m){
        printf("No");
        return 0;
    }
    printf("Yes\n");
    for(ll i = 1; i <= m; ++i)
        printf("%lld\n", lol[i]);
    return 0;
}
