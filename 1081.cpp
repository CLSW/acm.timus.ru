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

ll n, k;
ll f[maxn][4];

int main(){
    scanf("%lld %lld", &n, &k);
    f[1][1] = 1, f[1][0] = 1;
    for(ll i = 2; i <= n; ++i){
        f[i][0] = f[i - 1][0] + f[i - 1][1];
        f[i][1] = f[i - 1][0];
    }
    if(f[n][0] + f[n][1] < k){
        printf("-1");
    }
    else{
        vector < ll > ans;
        --k;
        for(ll i = n; i >= 1; --i){
            if(k < f[i][0])
                ans.pb(0);
            else
                ans.pb(1), k -= f[i][0];
        }
        for(auto i : ans)
            printf("%lld", i);
    }

    return 0;
}
