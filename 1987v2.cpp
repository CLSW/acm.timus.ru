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
const int lmaxn = (int)5e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll n, q, l[maxn], r[maxn];
vector < ll > p;
set < pair < pll, ll > > s;

int main(){
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i){
        scanf("%lld %lld", &l[i], &r[i]);
        p.pb(i);
    }
    sort(begin(p), end(p), [](ll i, ll j){
        return r[i] - l[i] > r[j] - l[j];
    });
    for(auto i : p){
        auto it = s.lower_bound(mp(mp(l[i], -1), -1));
        if(it == end(s)){
            s.insert(mp(mp(r[i], l[i]), i));
            continue;
        }
        ll lp = (*it).fi.se;
        ll rp = (*it).fi.fi;
        ll id = (*it).se;
        s.erase(it);
        if(l[i] > lp)
            s.insert(mp(mp(l[i] - 1, lp), id));
        if(r[i] < rp)
            s.insert(mp(mp(rp, r[i] + 1), id));
        s.insert(mp(mp(r[i], l[i]), i));
    }
    ll q;
    scanf("%lld", &q);
    while(q--){
        ll c;
        scanf("%lld", &c);
        auto it = s.lower_bound(mp(mp(c, -1), -1));
        if(it == end(s) || !((c <=(*it).fi.fi) && (c >= (*it).fi.se)))
            printf("-1\n");
        else
            printf("%lld\n", (*it).se);
    }
    return 0;
}
