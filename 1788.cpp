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

ll n, m, ans;
ll a[maxn], b[maxn];

int main(){
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; ++i) scanf("%lld", &a[i]), ans += a[i];
    for(ll i = 1; i <= m; ++i) scanf("%lld", &b[i]);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    for(ll cnt = 1; cnt <= min(n, m); ++cnt){
        ll now = 0;
        for(ll i = 1; i <= max(0ll, n - cnt); ++i)
            now += a[i];
        for(ll i = 1; i <= max(0ll, m - cnt); ++i)
            now += b[i] * cnt;
        ans = min(ans, now);
    }
    printf("%lld", ans);
    return 0;
}
