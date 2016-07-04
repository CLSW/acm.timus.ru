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
const int lmaxn = (int)2e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

const ll MX = (ll)5e4;

struct tree{
    ll t[maxn];
    void upd(ll v, ll tl, ll tr, ll pos, ll val){
        ll tm = (tl + tr) >> 1ll;
        if(tl == tr){
            t[v] = val;
            return;
        }
        if(pos <= tm)
            upd(v * 2, tl, tm, pos, val);
        else
            upd(v * 2 + 1, tm + 1, tr, pos, val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
    ll get(ll v, ll tl, ll tr, ll l, ll r){
        if(l > r) return 0;
        if(l == tl && r == tr) return t[v];
        ll tm = (tl + tr) >> 1ll;
        return max(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
}tr;

ll n;
ll l[maxn], r[maxn];
vector < ll > ord;

int main(){
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i){
        scanf("%lld %lld", &l[i], &r[i]);
        ord.pb(i);
    }
    sort(ord.begin(), ord.end(), [](ll i, ll j){
        return (r[i] == r[j] ? l[i] > l[j] : r[i] > r[j]);
    });
    for(ll i : ord){
        ll mx = max(tr.get(1, 1, MX, l[i], l[i]), tr.get(1, 1, MX, r[i] + 1, MX) + 1);
        tr.upd(1, 1, MX, l[i], mx);
    }
    printf("%lld", tr.get(1, 1, MX, 1, MX));
    return 0;
}
