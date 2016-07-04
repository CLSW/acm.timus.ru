# include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define fi first
#define se second

typedef int ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = (int)1e9 + 7;
const int maxn = (int)1e5 + 7;
const int lmaxn = (int)5e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll readInt () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10ll + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

ll t[lmaxn];


void paint(ll v, ll tl, ll tr, ll l, ll r, ll x){
    if(l > r)
        return;
    ll tm = (tl + tr) >> 1;
    if(tl == l && tr == r){
        t[v] = x;
        return;
    }
    if(t[v]){
        t[v * 2] = t[v];
        t[v * 2 + 1] = t[v];
        t[v] = 0;
    }
    paint(v * 2, tl, tm, l, min(r, tm), x);
    paint(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}

ll get(ll v, ll tl, ll tr, ll pos){
    if(tl == tr)
        return t[v];
    ll tm = (tl + tr) >> 1;
    if(t[v])
        return t[v];
    if(pos <= tm)
        return get(v * 2, tl, tm, pos);
    else
        return get(v * 2 + 1, tm + 1, tr, pos);
}

ll n, q, l[maxn], r[maxn], c[maxn];
vector < ll > p;
vector < ll > all;

int main(){
    n = readInt();
    for(ll i = 1; i <= n; ++i){
        l[i] = readInt(), r[i] = readInt();
        all.pb(l[i]), all.pb(r[i]);
        p.pb(i);
    }
    sort(p.begin(), p.end(), [](ll i, ll j){
        return r[i] - l[i] > r[j] - l[j];
    });
    q = readInt();
    for(ll i = 1; i <= q; ++i){
        c[i] = readInt();
        all.pb(c[i]);
    }
    sort(begin(all), end(all));
    all.resize(unique(begin(all), end(all)) - begin(all));
    for(ll i = 0; i < n; ++i){
        l[p[i]] = lower_bound(all.begin(), all.end(), l[p[i]]) - all.begin() + 1;
        r[p[i]] = lower_bound(all.begin(), all.end(), r[p[i]]) - all.begin() + 1;
        paint(1, 1, 2 * n + q, l[p[i]], r[p[i]], p[i]);

    }
    for(ll i = 1; i <= q; ++i){
        c[i] = lower_bound(begin(all), end(all), c[i]) - begin(all) + 1;
        ll now = get(1, 1, 2 * n + q, c[i]);
        if(!now) now = -1;
        printf("%d\n", now);
    }
    return 0;
}
