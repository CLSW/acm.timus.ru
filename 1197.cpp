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
string F;

main(){
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        cin >> F;
        ll x = F[0] - 'a' + 1;
        ll y = F[1] - '0';
        ll ans = 0;
        ans += (x - 2 >= 1 && y - 1 >= 1);
        ans += (x - 2 >= 1 && y + 1 <= 8);
        ans += (x - 1 >= 1 && y + 2 <= 8);
        ans += (x + 1 <= 8 && y + 2 <= 8);
        ans += (x + 2 <= 8 && y + 1 <= 8);
        ans += (x + 2 <= 8 && y - 1 >= 1);
        ans += (x + 1 <= 8 && y - 2 >= 1);
        ans += (x - 1 >= 1 && y - 2 >= 1);
        /*
            . . . . . . .
            . . Y . Y . .
            . Y . . . Y .
            . . . X . . .
            . Y . . . Y .
            . . Y . Y . .
            . . . . . . .
        */
        cout << ans << "\n";
    }
    return 0;
}
