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

string a;
set < string > s;

int main(){
    cin >> a;
    s.insert(a);
    while(true){
        cin >> a;
        if(a == "#") break;
        ll pos = a.find('-');
        s.insert(a.substr(0, pos));
        s.insert(a.substr(pos + 1, (ll)a.size() - pos));
    }
    cout << (ll)s.size() - 1;
    return 0;
}
