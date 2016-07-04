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

ll n, m;
ll a[maxn];
ll has[maxn];

int main(){
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i < n; ++i) has[i] = 2;
    has[0] = 1, has[n] = 1;
    for(ll i = 1; i <= m; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + m);
    for(ll i = 1; i <= m; ++i){
        if(a[i] && has[a[i]] && has[a[i] - 1])
            --has[a[i]], --has[a[i] - 1];
        else if(has[a[i]] && has[a[i] + 1])
            --has[a[i]], --has[a[i] + 1];
        else
            return printf("NO"), 0;
    }
    printf("YES");
    return 0;
}
