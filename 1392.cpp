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
#include <complex>

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

#define pii pair<ll, ll>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;
typedef long double ld;

const int inf = (int)1e9 + 7;
const int maxn = (int)2e5 + 7;
const int lmaxn = (int)1e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

struct star{
    int x, y, z, r;
};

int n, m, p[maxn];
star a[maxn];
set < int > roots;
vector < int > all[maxn];

inline int sqr(int x){
    return x * x;
}

inline int dist(star a, star b){
    return sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z);
}

inline int intersect(star a, star b){
    return dist(a, b) < sqr(a.r + b.r);
}

inline int findp(int v){
    return (p[v] == v ? v : p[v] = findp(p[v]));
}

inline void unite(int a, int b){
    a = findp(a), b = findp(b);
    if(a == b) return;
    if(a > b) swap(a, b);
    p[b] = a;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d %d %d %d", &a[i].x, &a[i].y, &a[i].z, &a[i].r);
    for(int i = 1; i <= n; ++i) p[i] = i;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if(intersect(a[i], a[j]))
                unite(i, j);
        }
    }
    for(int i = 1; i <= n; ++i)
        roots.insert(findp(i));
    for(int i = 1; i <= n; ++i)
        all[findp(i)].pb(i);
    for(int i : roots){
        int f = -1;
        for(int j : all[i]){
            if(~f)
                printf(", ");
            printf("%d", --j);
            f = 1;
        }
        printf("\n");
    }
    return 0;
}
