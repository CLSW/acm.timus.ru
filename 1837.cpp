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



ll n;
map < string, vector < string > > g;
map < string, ll > d;
set < string > all;
queue < string > q;

void Add(string a, string b){
    g[a].push_back(b);
    g[b].push_back(a);
}

int main(){
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        string a, b, c;
        cin >> a >> b >> c;
        Add(a, b);
        Add(a, c);
        Add(b, c);
        all.insert(a), all.insert(b), all.insert(c);
    }
    q.push("Isenbaev");
    d["Isenbaev"] = 0;
    while(!q.empty()){
        string v = q.front();
        q.pop();
        for(auto i : g[v]){
            if(!d.count(i)){
                d[i] = d[v] + 1;
                q.push(i);
            }
        }
    }
    for(auto i : all){
        cout << i << " " << (!d.count(i) ? "undefined" : to_string(d[i])) << "\n";
    }
    return 0;
}
