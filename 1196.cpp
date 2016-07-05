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

ll n, m, cnt;
vector < ll > a, b;

int main(){
    scanf("%lld", &n);
    a.resize(n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    scanf("%lld", &m);
    b.resize(m);
    for(ll i = 0; i < m; ++i) scanf("%lld", &b[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll l = 0;
    for(ll i = 0; i < m; ++i){
        while(l + 1 < n && a[l] < b[i]) ++l;
        cnt += (a[l] == b[i]);
    }
    printf("%lld", cnt);
    return 0;
}
