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

ll ord(char x){
    return (x - '0');
}

ll Happy(string x){
    if((ll)x.size() != 6) return 0;
    ll F = ord(x[0]) + ord(x[1]) + ord(x[2]);
    ll S = ord(x[3]) + ord(x[4]) + ord(x[5]);
    return F == S;
}

string to(ll x){
    stringstream ss;
    ss << x;
    string b;
    ss >> b;
    while(b.size() < 6) b = "0" + b;
    return b;
}

main(){
    ll n;
    cin >> n;
    if(Happy(to(n - 1)) || Happy(to(n + 1)))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
