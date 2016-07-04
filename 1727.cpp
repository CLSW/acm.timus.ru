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
const int maxn = (int)3e5 + 7;
const int lmaxn = (int)4e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll n;
vector < pll > all;
vector < ll > ans;

int main(){
    scanf("%lld", &n);
    for(ll i = 1; i < (ll)1e5; ++i){
        ll sum = 0;
        ll tmp = i;
        while(tmp)
            sum += (tmp % 10), tmp /= 10;
        all.pb(mp(sum, i));
    }
    sort(all.begin(), all.end());
    while(n){
        while(all.back().fi > n)
            all.pop_back();
        n -= all.back().fi;
        ans.pb(all.back().se);
        all.pop_back();
    }
    sort(ans.begin(), ans.end());
    printf("%lld\n", (ll)ans.size());
    for(ll i : ans)
        printf("%lld ", i);
    return 0;
}
