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

ll n1, c1, n2, t, c2, n3;
ll n;
ll tot;

int main(){
    cin >> n1 >> c1 >> n2 >> t >> c2 >> n3 >> n;
    for(ll i = 1; i <= n; ++i){
        string lol;
        cin >> lol;
        ll lot = (((lol[0] - '0') * 10) + (lol[1] - '0')) * 60 + ((lol[3] - '0') * 10 + (lol[4] - '0'));
        if(lot <= 6)
            continue;
        tot += (lot + 59) / 60;
    }
    cout << "Basic:     " << tot * c1 + n1 << "\n";
    cout << "Combined:  " << n2 + max(0ll, tot - t) * c2 << "\n";
    cout << "Unlimited: " << n3;
    return 0;
}
