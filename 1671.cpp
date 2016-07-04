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
typedef long double ld;

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

const ld eps = ld(1e-11);

int n, m, q, now;
int x[maxn], y[maxn];
int p[maxn], r[maxn];
int t[maxn], u[maxn];
int ans[maxn];

inline int Find(int x){
    return (p[x] == x ? x : p[x] = Find(p[x]));
}

inline void Union(int x, int y){
    x = Find(x), y = Find(y);
    if(x == y)
        return;
    if(r[x] < r[y]) swap(x, y);
    p[y] = x;
    r[x] += r[y];
}

main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        p[i] = i, r[i] = 1;
    now = n;
    for(int i = 1; i <= m; ++i)
        scanf("%d %d", &x[i], &y[i]);
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i){
        scanf("%d", &t[i]);
        u[t[i]] = 1;
    }
    for(int i = 1; i <= m; ++i){
        if(!u[i]){
            now -= (Find(x[i]) != Find(y[i]));
            Union(x[i], y[i]);
        }
    }
    for(int i = q; i >= 1; --i){
        ans[i] = now;
        now -= (Find(x[t[i]]) != Find(y[t[i]]));
        Union(x[t[i]], y[t[i]]);
    }
    for(int i = 1; i <= q; ++i)
        printf("%d ", ans[i]);
    return 0;
}
