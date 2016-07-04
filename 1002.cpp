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

struct node{
    map < char, int > nxt;
    int id;
    int leaf;
    node(){
        leaf = 0;
        id = 0;
    }
    ~node(){}
};

vector < node > st;

void Add(string f, ll id){
    ll v = 0;
    for(char i : f){
        if(!st[v].nxt.count(i)){
            st.pb(node());
            st[v].nxt[i] = (int)st.size() - 1;
        }
        v = st[v].nxt[i];
    }
    st[v].leaf = true;
    st[v].id = id;
}

ll Go(string f){
    ll v = 0;
    for(char i : f)
        i = st[v].nxt[i];
    return st[v].id;
}

string a[maxn], b;
ll n, d[maxn], p[maxn], part[maxn];
map < char, ll > e;

void Clear(){
    fill(d, d + 100, 0);
    fill(p, p + 100, 0);
    fill(part, part + 100, 0);
    st.clear();
    st.pb(node());
}

bool solve(){
    cin >> b;
    if(b == "-1")
        return false;
    Clear();
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        string tmp(a[i]);
        for(ll j = 0; j < (ll)tmp.size(); ++j)
            tmp[j] = char(e[tmp[j]] + '0');
        Add(tmp, i);
    }
    d[0] = 1;
    for(ll i = 1; i <= (ll)b.size(); ++i){
        ll v = 0;
        for(ll j = i; j <= (ll)b.size(); ++j){
            if(!st[v].nxt.count(b[j - 1])) break;
            v = st[v].nxt[b[j - 1]];
            if(st[v].leaf){
                if(d[i - 1]){
                    if(!d[j] || part[j] > part[i - 1] + 1){
                        d[j] = 1, p[j] = st[v].id;
                        part[j] = part[i - 1] + 1;
                    }
                }
            }
        }
    }
    if(!d[(ll)b.size()]){
        cout << "No solution.\n";
        return true;
    }
    ll ind = (ll)b.size();
    vector < string > ans;
    while(ind > 0){
        ans.pb(a[p[ind]]);
        ind -= (ll)a[p[ind]].size();
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i << " ";
    cout << "\n";
    return true;
}

int main(){
    e['i'] = e['j'] = 1;
    e['g'] = e['h'] = 4;
    e['p'] = e['r'] = e['s'] = 7;
    e['a'] = e['b'] = e['c'] = 2;
    e['k'] = e['l'] = 5;
    e['t'] = e['u'] = e['v'] = 8;
    e['o'] = e['q'] = e['z'] = 0;
    e['d'] = e['e'] = e['f'] = 3;
    e['m'] = e['n'] = 6;
    e['w'] = e['x'] = e['y'] = 9;
    while(solve());
    return 0;
}
