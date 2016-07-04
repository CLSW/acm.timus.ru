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
char a[1500][1500];
ll u[1500][1500], d[1500][1500];
ll cnt[3];

int main(){
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            scanf(" %c", &a[i][j]);
        }
    }
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            d[i][j] = 1;
        }
    }
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            if(a[i][j] == a[i - 1][j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
            cnt[a[i][j] == 's' ? 1 : 2] = max(cnt[a[i][j] == 's' ? 1 : 2], d[i][j]);
        }
    }
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            d[i][j] = 1;
    for(ll i = 1; i <= n; ++i){
        for(ll j = n; j >= 1; --j){
            if(a[i][j] == a[i - 1][j + 1]) d[i][j] = d[i - 1][j + 1] + 1;
            cnt[a[i][j] == 's' ? 1 : 2] = max(cnt[a[i][j] == 's' ? 1 : 2], d[i][j]);
        }
    }
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            d[i][j] = 1;
    for(ll i = n; i >= 1; --i){
        for(ll j = 1; j <= n; ++j){
            if(a[i][j] == a[i + 1][j]) d[i][j] = d[i + 1][j] + 1;
            cnt[a[i][j] == 's' ? 1 : 2] = max(cnt[a[i][j] == 's' ? 1 : 2], d[i][j]);
        }
    }
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            d[i][j] = 1;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            if(a[i][j] == a[i][j - 1]) d[i][j] = d[i][j - 1] + 1;
            cnt[a[i][j] == 's' ? 1 : 2] = max(cnt[a[i][j] == 's' ? 1 : 2], d[i][j]);
        }
    }
    if(cnt[1] == cnt[2]){
        printf("?\n");
    }
    if(cnt[1] > cnt[2]){
        printf("s\n");
    }
    if(cnt[2] > cnt[1]){
        printf("S\n");
    }
    printf("%lld", max(cnt[1], cnt[2]));
    return 0;
}
