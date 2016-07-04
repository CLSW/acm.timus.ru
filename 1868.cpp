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

vector < string > m[4];
string a;
ll cnt[maxn];
ll n;

pair < string, ll > Parse(string b){
    ll pos = a.find(':');
    string team = "";
    for(ll j = pos - 2; j >= 0; --j)
        team += b[j];
    reverse(team.begin(), team.end());
    string med = "";
    for(ll j = pos + 2; j < (ll)b.size(); ++j)
        med += b[j];
    if(med == "gold")
        return mp(team, 1);
    if(med == "silver")
        return mp(team, 2);
    else
        return mp(team, 3);
}

int main(){
    for(ll i = 1; i <= 3; ++i){
        for(ll j = 1; j <= 4; ++j){
            getline(cin, a);
            m[i].pb(a);
        }
    }
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        ll f;
        cin >> f;
        getchar();
        for(ll j = 1; j <= f; ++j){
            getline(cin, a);
            pair < string, ll > pp = Parse(a);
            if(find(m[pp.se].begin(), m[pp.se].end(), pp.fi) != m[pp.se].end())
                ++cnt[i];
        }
    }
    ll mx = *max_element(cnt + 1, cnt + 1 + n);
    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
       if(cnt[i] == mx)
            ans += 5;

    }
    cout << ans;
    return 0;
}
