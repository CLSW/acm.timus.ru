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
bool d[(ll)1e7 + 7];
char a[(ll)1e7 + 7];

void Solve(){
    scanf(" %s", a);
    fill(d, d + (ll)1e7 + 7, 0);
    ll l = strlen(a);
    for(ll i = l; i >= 1; --i)
        a[i] = a[i - 1];
    d[0] = 1;
    for(ll i = 1; i <= l; ++i){
        if(i >= 2){
            if(a[i - 1] == 'i' && a[i] == 'n')
                d[i] |= d[i - 2];
        }
        if(i >= 3){
            if(a[i - 2] == 'o' && a[i - 1] == 'u' && a[i] == 't' || a[i - 2] == 'o' && a[i - 1] == 'n' && a[i] == 'e')
                d[i] |= d[i - 3];
        }
        if(i >= 5){
            if(a[i - 4] == 'i' && a[i - 3] == 'n' && (a[i - 2] == 'p' && a[i - 1] == 'u' && a[i] == 't'))
                d[i] |= d[i - 5];
            if(a[i - 4] == 'p' && a[i - 3] == 'u' && (a[i - 2] == 't' && a[i - 1] == 'o' && a[i] == 'n'))
                d[i] |= d[i - 5];
        }
        if(i >= 6){
            if(a[i - 5] == 'o' && a[i - 4] == 'u' && (a[i - 3] == 't' && a[i - 2] == 'p' && a[i - 1] == 'u') && a[i] == 't')
                d[i] |= d[i - 6];
        }
    }
    if(d[l])
        puts("YES");
    else
        puts("NO");
}

int main(){
    scanf("%lld", &n);
    while(n--){
        Solve();
    }
    return 0;
}
