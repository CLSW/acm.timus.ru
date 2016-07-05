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

int n, x, y, c[maxn], u[maxn], ans;
vector < int > g[maxn];
int d[maxn][3];

void Dfs(int v){
    u[v] = 1;
    d[v][1] = c[v];
    for(int i : g[v]){
        if(!u[i]){
            Dfs(i);
            d[v][1] = max(d[v][1], d[v][1] + d[i][0]);
            d[v][0] = max(d[v][0], d[v][0] + max(d[i][0], d[i][1]));
        }
    }
}

main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &c[i]);
    }
    scanf("%d %d", &x, &y);
    while(x && y){
        g[y].pb(x);
        scanf("%d %d", &x, &y);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) d[j][0] = d[j][1] = u[j] = 0;
        Dfs(i);
        ans = max(ans, max(d[i][0], d[i][1]));
    }
    printf("%d", ans);
    return 0;
}
