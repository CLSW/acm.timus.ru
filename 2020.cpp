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

string a, b;
ll now;

int main(){
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while(!a.empty() && !b.empty()){
        char a1 = a.back(), b1 = b.back();
        if(a1 != 'L' || b1 == 'L')
            a.pop_back();
        if(b1 != 'L' || a1 == 'L')
            b.pop_back();
        ++now;
    }
    printf("%lld", now + (ll)a.size() + (ll)b.size());
    return 0;
}
