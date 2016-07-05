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


string a;
map < char, ll > cost;
ll total;

main(){
    cost['a'] = cost['d'] = cost['g'] = cost['j'] = cost['m'] = cost['p'] = cost['s'] = cost['v'] = cost['y'] = cost['.'] = cost[' '] = 1;
    cost['b'] = cost['e'] = cost['h'] = cost['k'] = cost['n'] = cost['q'] = cost['t'] = cost['w'] = cost['z'] = cost[','] = 2;
    getline(cin, a);
    for(auto i : a){
        if(!cost.count(i)) total += 3;
        else total += cost[i];
    }
    cout << total;
    return 0;
}
