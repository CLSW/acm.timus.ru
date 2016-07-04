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


ll n;
ll a[maxn], x, y;

int main(){
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    scanf("%lld %lld", &x, &y);
    if(x < y){
        ll s1 = 0, s2 = 0;
        ll mid = (x + y) / 2;
        for(ll i = 1; i <= mid; ++i)
            s1 += a[i];
        for(ll i = mid + 1; i <= n; ++i)
            s2 += a[i];
        printf("%lld %lld\n", s1, s2);
    }
    else if(x > y){
        ll s1 = 0, s2 = 0;
        ll mid = (x + y + 1) / 2;
        for(ll i = mid; i <= n; ++i)
            s1 += a[i];
        for(ll i = 1; i < mid; ++i)
            s2 += a[i];
        printf("%lld %lld\n", s1, s2);
    }
    else{
        ll s1 = 0, s2 = 0;
        for(ll i = 1; i < x; ++i)
            s1 += a[i];
        for(ll i = x + 1; i <= n; ++i)
            s2 += a[i];
        if(s1 < s2) swap(s1, s2);
        s1 += a[x];
        printf("%lld %lld\n", s1, s2);
    }
    return 0;
}
