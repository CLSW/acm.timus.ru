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
const int lmaxn = (int)1e7 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll gcd(ll a, ll b){
    while(b) a %= b, swap(a, b);
    return a | b;
}

ll n, x, a[maxn];

int main(){
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    for(ll i = 2; i <= n; ++i)
        a[i] = __gcd(a[i], a[i - 1]);
    printf("%lld", a[n]);
    return 0;
}
