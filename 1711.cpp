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
string q[21], w[21], e[21];
string a[21][4];
ll p[21];
ll d[21][4], pa[21][4];

void relax(ll i, ll f, ll s){
    if(d[i - 1][s] && a[i][f] > a[i - 1][s])
        d[i][f] = 1, pa[i][f] = s;
}

int main(){
    cin >> n;
    for(ll i = 1; i <= n; ++i)
        cin >> q[i] >> w[i] >> e[i];
    for(ll i = 1; i <= n; ++i){
        cin >> p[i];
        a[i][1] = q[p[i]];
        a[i][2] = w[p[i]];
        a[i][3] = e[p[i]];
    }
    d[1][1] = 1;
    d[1][2] = 1;
    d[1][3] = 1;
    for(ll i = 2; i <= n; ++i){
        for(ll f = 1; f <= 3; ++f){
            for(ll s = 1; s <= 3; ++s)
                relax(i, f, s);
        }
    }
    ll mx = 0;
    for(ll i = 1; i <= 3; ++i){
        if(d[n][i])
            mx = i;
    }
    if(!mx){
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector < string > ans;
    for(ll i = n; i >= 1; --i){
        ans.pb(a[i][mx]);
        mx = pa[i][mx];
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i << "\n";
    return 0;
}
