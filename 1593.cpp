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
const int lmaxn = (int)6e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll gcd(ll a, ll b){
    while(b) a %= b, swap(a, b);
    return a | b;
}

ll is_perfect(ll x){
    return ll(sqrt(x)) * ll(sqrt(x)) == x;
}

ll n;

int main(){
    scanf("%lld", &n);
    if(is_perfect(n) == 1){
        printf("1");
        return 0;
    }
    if(is_perfect(n - 1)){
        printf("2");
        return 0;
    }
    ll tmp = n;
    ll ok = 1;
    for(ll i = 2; i * i <= n; ++i){
        ll cnt = 0;
        while(n % i == 0)
            n /= i, ++cnt;
        if(cnt && i % 4 == 3)
            ok &= (cnt % 2 == 0);
    }
    ok &= (n % 4 != 3);
    if(ok){
        printf("2");
        return 0;
    }
    n = tmp;
    while(n % 4 == 0)
        n /= 4;
    if(n % 8 != 7){
        printf("3");
    }
    else{
        printf("4");
    }
    return 0;
}
