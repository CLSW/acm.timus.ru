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
ll a[101][101];
vector < ll > ans;

main(){
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    for(ll i = 1; i <= n; ++i)
        for(ll j = 0; j < i; ++j) ans.push_back(a[i - j][j + 1]);
    for(ll i = 2; i <= n; ++i)
        for(ll j = 0; j <= n - i; ++j) ans.push_back(a[n - j][i + j]);
    for(auto i : ans) cout << i << " ";
    return 0;
}
