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

int t, cycle;
int n, a[maxn], c[maxn];
vector < int > g[maxn];

void Dfs(int v){
    c[v] = 1;
    for(int i : g[v]){
        if(c[i] == 1)
            cycle = 1;
        if(!c[i])
            Dfs(i);
    }
    c[v] = 2;
}

main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            g[i].clear(), c[i] = 0;
            cycle = 0;
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            ans += !a[i];
            if(a[i])
                g[a[i]].pb(i);
        }
        if(!ans || ans > 1){
            printf("NO\n");
            continue;
        }
        for(int i = 1; i <= n; ++i){
            if(!c[i])
                Dfs(i);
        }
        if(cycle)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
