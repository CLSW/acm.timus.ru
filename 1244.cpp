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

ll s;
int n;
pair < int, int > x[maxn];
int d[101 * 1001], c[101 * 1001];
vector < int > ans;

main(){
    scanf("%d %d", &s, &n);
    d[0] = 1;
    ll sum = 0;
    for(ll i = 1; i <= n; ++i){
        scanf("%d", &x[i].fi);
        sum += x[i].fi;
        x[i].se = i;
    }
    sort(x + 1, x + 1 + n);
    s = sum - s;
    for(ll i = n; i >= 1; --i){
        for(ll j = s; j >= x[i].fi; --j){
            if(d[j - x[i].fi]){
                d[j] += d[j - x[i].fi];
                if(!c[j])
                    c[j] = i;
            }
        }
    }
    if(d[s] > 1){
        printf("-1");
    }
    else if(!d[s]){
        printf("0");
    }
    else{
        ll now = s;
        while(now){
            ans.pb(x[c[now]].se);
            now = now - x[c[now]].fi;
        }
        for(int i : ans)
            printf("%d ", i);
    }
    return 0;
}
