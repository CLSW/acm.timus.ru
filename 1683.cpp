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

ll n;
vector < ll > ans;

int main(){
    scanf("%lld", &n);
    while(n > 1){
        ans.pb(n / 2);
        n = n - n / 2;
    }
    printf("%lld\n", (ll)ans.size());
    for(auto i : ans)
        printf("%lld ", i);
    return 0;
}
