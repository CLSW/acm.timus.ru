# include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define fi first
#define se second

typedef int ll;
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

ll n, m;
char a[3][3001];

int main(){
    scanf("%d %d", &n, &m);
    ll ok = 1;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j)
            scanf(" %c", &a[i % 2][j]);
        if(i == 1) continue;
        for(ll j = 1; j + 1 <= m; ++j){
            if((a[0][j] == '1') + (a[1][j] == '1') + (a[0][j + 1] == '1') + (a[1][j + 1] == '1') == 3)
                ok = 0;
        }
    }

    if(ok)
        printf("Yes");
    else
        printf("No");
    return 0;
}
