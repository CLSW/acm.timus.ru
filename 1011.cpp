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

ld p, q;

ll good(ll x){
    for(ll j = 1; j <= x; ++j){
        ld ep = (j * 100.0) / ld(x);
        if(ep > p && ep < q)
            return 1;
    }
    return 0;
}

int main(){
    cin >> p >> q;
    for(ll i = 1; ; ++i){
        if(good(i)){
            printf("%lld", i);
            return 0;
        }
    }
    return 0;
}
