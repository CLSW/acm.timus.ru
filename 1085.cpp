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

int n, m, k, ans = inf, ind;
vector < int > g[101];
queue < int > q;
vector < int > f;
int d[101][101];

void Bfs(int s){
    int x, y, f;
    scanf("%d %d %d", &x, &y, &f);
    swap(x, y);
    q.push(x);
    d[s][x] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int j : g[v]){
            if(d[s][j] == inf){
                q.push(j);
                d[s][j] = d[s][v] + (f ? 0 : 4);
            }
        }
    }
    for(int j = 1; j <= n; ++j){
        if(d[s][j] > y)
            d[s][j] = inf;
    }
}

main(){
    for(int i = 0; i < 101; ++i)
        for(int j = 0; j < 101; ++j)
            d[i][j] = inf;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i){
        int l, p = -1;
        scanf("%d", &l);
        f.resize(l + 1);
        for(int i = 1; i <= l; ++i)
            scanf("%d", &f[i]);
        for(int i = 1; i <= l; ++i)
            for(int j = i + 1; j <= l; ++j)
                g[f[i]].push_back(f[j]), g[f[j]].push_back(f[i]);
    }
    scanf("%d", &k);
    for(int i = 1; i <= k; ++i)
        Bfs(i);
    for(int i = 1; i <= n; ++i){
        int now = 0, f = 0;
        for(int j = 1; j <= k; ++j)
            now += d[j][i], f |= (d[j][i] == inf);
        if(!f){
            if(ans > now)
                ans = now, ind = i;
        }
    }
    if(ans == inf){
        printf("0");
        return 0;
    }
    printf("%d %d", ind, ans);
    return 0;
}
