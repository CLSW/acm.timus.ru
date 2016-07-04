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

struct jedi{
    string name;
    ll a, b, c;
};

ll n, mark[maxn];
jedi f[maxn];
vector < ll > g[maxn];

void go(ll v){
    mark[v] = 1;
    for(ll i : g[v]){
        if(!mark[i])
            go(i);
    }
}

int main(){
    cin >> n;
    for(ll i = 1; i <= n; ++i)
        cin >> f[i].name >> f[i].a >> f[i].b >> f[i].c;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            if(i == j) continue;
            if((f[i].a > f[j].a) + (f[i].b > f[j].b) + (f[i].c > f[j].c) >= 2)
                g[i].pb(j);
        }
    }
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j) mark[j] = 0;
        go(i);
        ll ok = 1;
        for(ll j = 1; j <= n; ++j)
            ok &= mark[j];
        if(ok){
            cout << f[i].name << "\n";
        }
    }
    return 0;
}
