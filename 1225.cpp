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


ll n;
ll dp[46][4];

main(){
    scanf("%lld", &n);
    dp[1][1] = dp[1][3] = 1;
    for(ll i = 2; i <= n; ++i){
        dp[i][1] = dp[i - 1][3] + dp[i - 2][3];
        dp[i][3] = dp[i - 1][1] + dp[i - 2][1];
    }
    printf("%lld", dp[n][1] + dp[n][3]);
    return 0;
}
