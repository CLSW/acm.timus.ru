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

# define pii pair<int, int>

# define pb push_back
# define eb emplace_back
# define mp make_pair

# define f first
# define s second

typedef long long ll;
typedef long double ld;

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

const ld EPS = ld(1e-11);

inline int gcd(int a, int b){
    if(!a || !b)
        return max(a, b);
    return __gcd(a, b);
}

struct node{
    int val;
    node *l, *r;
    node(){
        l = r = nullptr;
        val = 0;
    }
};

inline int GetVal(node *&v){
    return (v == nullptr ? 0 : v -> val);
}

inline void Update(node *&v, int tl, int tr, int pos, int val){
    int tm = tl + (tr - tl) / 2;
    if(v == nullptr)
        v = new node();
    if(tl == tr){
        v -> val = val;
        return;
    }
    if(pos <= tm)
        Update(v -> l, tl, tm, pos, val);
    else
        Update(v -> r, tm + 1, tr, pos, val);
    v -> val = gcd(GetVal(v -> l), GetVal(v -> r));
}

inline int Get(node *&v, int tl, int tr, int l, int r){
    int tm = tl + (tr - tl) / 2;
    if(l > r)
        return 0;
    if(v == nullptr)
        v = new node();
    if(tl == l && r == tr)
        return GetVal(v);
    return gcd(Get(v -> l, tl, tm, l, min(r, tm)), Get(v -> r, tm + 1, tr, max(l, tm + 1), r));
}

node *root = new node();

int q, y;
char x;
map < int, int > cnt;

int main(){
    scanf("%d", &q);
    while(q--){
        scanf(" %c %d", &x, &y);
        if(x == '+'){
            if(!cnt[y])
                Update(root, 1, inf, y, y);
            ++cnt[y];
        }
        else{
            if(cnt[y] == 1)
                Update(root, 1, inf, y, 0);
            --cnt[y];
        }
        printf("%d\n", max(1, Get(root, 1, inf, 1, inf)));
    }
    return 0;
}
