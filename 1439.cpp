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
const int lmaxn = (int)2e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

struct node{
    node *l, *r;
    ll val;
    node(){
        l = r = nullptr;
        val = 0;
    }
    ~node(){}
};

struct tree{
    node *root;
    tree(){
        root = new node();
    }
    void upd(node *&v, ll tl, ll tr, ll pos, ll val){
        if(tl == tr){
            v -> val = val;
            return;
        }
        ll tm = (tl + tr) >> 1ll;
        if(v -> l == nullptr) v -> l = new node();
        if(v -> r == nullptr) v -> r = new node();
        if(pos <= tm)
            upd(v -> l, tl, tm, pos, val);
        else
            upd(v -> r, tm + 1, tr, pos, val);
        v -> val = (v -> l) -> val + (v -> r) -> val;
    }
    ll get(node *&v, ll tl, ll tr, ll k){
        ll tm = (tl + tr) >> 1ll;
        if(tl == tr)
            return tl;
        if((v -> l) == nullptr) v -> l = new node();
        if((v -> r) == nullptr) v -> r = new node();

        ll le = (tm - tl + 1) - ((v -> l) -> val);
        if(k <= le)
            return get(v -> l, tl, tm, k);
        else
            return get(v -> r, tm + 1, tr, k - le);
    }
}tr;

ll n, q;

int main(){
    scanf("%lld %lld", &n, &q);
    for(ll i = 1; i <= q; ++i){
        char t;
        scanf(" %c", &t);
        if(t == 'D'){
            ll x;
            scanf("%lld", &x);
            x = tr.get(tr.root, 1, n, x);
            tr.upd(tr.root, 1, n, x, 1);
        }
        else{
            ll x;
            scanf("%lld", &x);
            printf("%lld\n", tr.get(tr.root, 1, n, x));
        }
    }
    return 0;
}
