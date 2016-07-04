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

ll n, k;
ll c[501], d[501][501];

int main(){
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i <= n; ++i) scanf("%lld", &c[i]);
    for(ll i = 0; i <= n; ++i)
        for(ll j = 0; j <= k; ++j)
            d[i][j] = linf;
    d[0][0] = 0;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= min(k, i); ++j){
            ll b = 0, w = 0;
            for(ll s = i; s >= 1; --s){
                if(c[s])
                    ++b;
                else
                    ++w;
                d[i][j] = min(d[i][j], d[s - 1][j - 1] + b * w);
            }
        }
    }
    printf("%lld", d[n][k]);
    return 0;
}
