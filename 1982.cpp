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

ll n, k, cost;
ll p[101], mark[101];
ll a[101][101];
vector < pair < ll, pll > > e;

ll getp(ll x){
    return (p[x] == x ? x : p[x] = getp(p[x]));
}

void unite(ll x, ll y){
    x = getp(x), y = getp(y);
    if(x == y) return;
    p[y] = x;
}

int main(){
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i <= k; ++i){
        ll x;
        scanf("%lld", &x);
        mark[x] = 1;
    }
    for(ll i = 1; i <= n; ++i){
        p[i] = i;
        for(ll j = 1; j <= n; ++j){
            scanf("%lld", &a[i][j]);
            if(i == j) continue;
        }
    }
    for(ll c = 1; c <= n; ++c){
        pll mn = {-1, -1};
        for(ll i = 1; i <= n; ++i){
            if(mark[i]){
                for(ll j = 1; j <= n; ++j){
                    if(!mark[j] && getp(i) != getp(j)){
                        if(mn.fi == -1 || a[mn.fi][mn.se] > a[i][j])
                            mn = {i, j};
                    }
                }
            }
        }
        if(mn.fi == -1)
            break;
        cost += a[mn.fi][mn.se];
        unite(mn.fi, mn.se);
        mark[mn.fi] = mark[mn.se] = 1;
    }
    printf("%lld", cost);
    return 0;
}
