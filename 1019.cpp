#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <climits>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <utility>
#include <sstream>
#include <numeric>
#include <functional>
#include <bitset>
#include <deque>

using namespace std;

#if __cplusplus >= 201103
    #include <unordered_map>
    #include <future>
    #include <atomic>
    #include <chrono>
    #include <unordered_set>
    #include <array>
    #include <random>
    #include <mutex>
#endif

#define pii pair<int, int>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define f first
#define s second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

const ld eps = ld(1e-11);

struct node{
    node *l, *r;
    ll f, sum;

    node(){
        f = -1, sum = 0;
        l = nullptr, r = nullptr;
    }

    ~node(){}
};

struct tree{
    node *root;

    tree(){
        root = new node();
    }

    void push(node *&v, ll tl, ll tr){
        ll tm = (tl + tr) >> 1ll;
        if(v -> l == nullptr) v -> l = new node();
        if(v -> r == nullptr) v -> r = new node();
        if(v -> f != -1){
            (v -> l) -> sum = (tm - tl + 1) * v -> f;
            (v -> r) -> sum = (tr - tm) * v -> f;
            (v -> l) -> f = (v -> r) -> f = v -> f;
            (v -> f) = -1;
        }
    }

    void paint(node *&v, ll tl, ll tr, ll l, ll r, ll x){
        ll tm = (tl + tr) >> 1ll;
        if(l > r) return;
        push(v, tl, tr);
        if(l == tl && r == tr){
            v -> sum = x * (r - l + 1);
            v -> f = x;
            return;
        }
        paint(v -> l, tl, tm, l, min(r, tm), x);
        paint(v -> r, tm + 1, tr, max(l, tm + 1), r, x);
        v -> sum = (v -> l) -> sum + (v -> r) -> sum;
    }

    ll get(node *&v, ll tl, ll tr, ll l, ll r){
        ll tm = (tl + tr) >> 1ll;
        if(l > r) return 0;
        push(v, tl, tr);
        if(l == tl && r == tr)
            return v -> sum;
        return get(v -> l, tl, tm, l, min(r, tm)) + get(v -> r, tm + 1, tr, max(l, tm + 1), r);
    }
}t;

const ll MX = (ll)1e9;

ll n;
set < ll > s;
map < ll, ll > cw;

ll getLeft(ll l){
    ll lf = 1, rg = l - 1;
    while(rg - lf > 1){
        ll mid = (lf + rg) >> 1ll;
        if(t.get(t.root, 1, MX, mid, l - 1) == l - mid)
            rg = mid;
        else
            lf = mid;
    }
    if(t.get(t.root, 1, MX, lf, l - 1) == l - lf)
        return lf;
    else
        return rg;
}

ll getRight(ll r){
    ll lf = r, rg = MX;
    while(rg - lf > 1){
        ll mid = (lf + rg) >> 1ll;
        if(t.get(t.root, 1, MX, r + 1, mid) == mid - r)
            lf = mid;
        else
            rg = mid;
    }
    if(t.get(t.root, 1, MX, r + 1, rg) == rg - r)
        return rg;
    else
        return lf;
}

main(){
    scanf("%lld", &n);
    s.insert(1);
    t.paint(t.root, 1, MX, 1, MX, 1);
    for(ll i = 1; i <= n; ++i){
        ll l, r;

        char c;
        scanf("%lld %lld %c", &l, &r, &c);
        ++l;
        if(c == 'w'){
            if(l > 1 && t.get(t.root, 1, MX, l - 1, l - 1) == 1)
                l = getLeft(l);
            if(t.get(t.root, 1, MX, r + 1, r + 1) == 1)
                r = getRight(r);
            t.paint(t.root, 1, MX, l, r, 1);
            if(s.lower_bound(l) != s.end())
                s.erase(s.lower_bound(l), s.upper_bound(r));
            s.insert(l);
            cw[l] = r - l + 1;
        }
        else{
            if(s.lower_bound(l) != s.end())
                s.erase(s.lower_bound(l), s.upper_bound(r));
            t.paint(t.root, 1, MX, l, r, 0);
            ll pos;
            if(l > 1 && t.get(t.root, 1, MX, l - 1, l - 1) == 1){
                pos = getLeft(l);
                cw[pos] = l - pos;
                s.insert(pos);
            }
            if(t.get(t.root, 1, MX, r + 1, r + 1) == 1){
                pos = getRight(r);
                cw[r + 1] = pos - r;
                s.insert(r + 1);
            }
        }
    }
    ll mx = 0;
    for(ll i : s)
        if(cw[mx] < cw[i])
            mx = i;
    printf("%lld %lld", mx - 1, mx + cw[mx] - 1);
    return 0;
}
