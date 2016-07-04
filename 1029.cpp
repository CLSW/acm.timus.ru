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

ll n, m;
ll d[2001][2001], a[2001][2001];
pll p[2001][2001];

int main(){
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j)
            scanf("%lld", &a[i][j]);
    }
    for(ll i = 1; i <= m; ++i)
        d[1][i] = a[1][i];
    for(ll i = 2; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            d[i][j] = d[i - 1][j] + a[i][j];
            p[i][j] = mp(1, 0);
            ll sum = a[i][j];
            for(ll l = j - 1; l >= 1; --l){
                sum += a[i][l];
                if(d[i][j] > sum + d[i - 1][l]){
                    d[i][j] = sum + d[i - 1][l];
                    p[i][j] = mp(2, l);
                }
            }
            sum = a[i][j];
            for(ll r = j + 1; r <= m; ++r){
                sum += a[i][r];
                if(d[i][j] > sum + d[i - 1][r]){
                    d[i][j] = sum + d[i - 1][r];
                    p[i][j] = mp(2, r);
                }
            }
        }
    }
    ll id = min_element(d[n] + 1, d[n] + 1 + m) - d[n];
    vector < ll > ans;
    for(ll i = n; i > 1; --i){
        if(p[i][id].fi == 1){
            ans.pb(id);
            continue;
        }
        if(id >= p[i][id].se){
            for(ll j = id; j >= p[i][id].se; --j)
                ans.pb(j);
        }
        else{
            for(ll j = id; j <= p[i][id].se; ++j)
                ans.pb(j);
        }
        id = p[i][id].se;
    }
    ans.pb(id);
    reverse(ans.begin(), ans.end());
    for(auto i : ans)
        printf("%lld ", i);
    return 0;
}
