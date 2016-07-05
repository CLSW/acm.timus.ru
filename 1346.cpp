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

int t[maxn];

void update(int v, int tl, int tr, int pos, int val){
    int tm = (tl + tr) >> 1;
    if(tl == tr){
        t[v] = val;
        return;
    }
    if(pos <= tm)
        update(v * 2, tl, tm, pos, val);
    else
        update(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r){
    int tm = (tl + tr) >> 1;
    if(l > r) return inf;
    if(l == tl && r == tr) return t[v];
    return min(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int a, b;
int f[maxn];
int up[maxn], dn[maxn];
int dp[maxn];

main(){
    scanf("%d %d", &a, &b);
    for(int i = a; i <= b; ++i)
        scanf("%d", &f[i]);
    up[a] = 1, dn[a] = 1;
    for(int i = a + 1; i <= b; ++i){
        up[i] = (f[i] >= f[i - 1] ? up[i - 1] : i);
        dn[i] = (f[i] <= f[i - 1] ? dn[i - 1] : i);
    }
    dp[a] = 1;
    update(1, 1, b, a, 1);
    for(int i = a + 1; i <= b; ++i){
        dp[i] = inf;
        int f = min(up[i], dn[i]) - 1;
        if(!f) dp[i] = 1, ++f;
        dp[i] = min(dp[i], get(1, 1, b, f, i - 1) + 1);
        update(1, 1, b, i, dp[i]);
    }
    printf("%d", dp[b]);
    return 0;
}
