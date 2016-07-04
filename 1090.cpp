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
const int lmaxn = (int)6e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll gcd(ll a, ll b){
    while(b) a %= b, swap(a, b);
    return a | b;
}


ll n, m, ans[maxn], a[maxn], t[maxn];


void inc(ll v){
    for(ll i = v; i <= 10000; i += i & -i)
        ++t[i];
}

ll get(ll v){
    ll sum = 0;
    for(ll i = v; i >= 1; i -= i & -i)
        sum += t[i];
    return sum;
}

int main(){
    scanf("%lld %lld", &n, &m);
    swap(n, m);
    for(ll i = 1; i <= n; ++i){
        fill(t, t + maxn, 0);
        for(ll j = 1; j <= m; ++j)
            scanf("%lld", &a[j]);
        for(ll j = 1; j <= m; ++j){
            ans[i] += get(m) - get(a[j]);
            inc(a[j]);
        }
    }
    ll id = 1;
    for(ll i = 1; i <= n; ++i)
        if(ans[i] > ans[id])
            id = i;
    printf("%lld", id);
    return 0;
}
