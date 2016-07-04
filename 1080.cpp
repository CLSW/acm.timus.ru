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

int n, x;
int u[maxn], c[maxn];
vector < int > g[maxn];

void Dfs(int v){
    u[v] = 1;
    for(auto i : g[v]){
        if(u[i]){
            if(c[i] == c[v]){
                printf("-1");
                exit(0);
            }
        }
        else{
            c[i] = c[v] ^ 1;
            Dfs(i);
        }
    }
}

main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        while(x){
            g[i].push_back(x);
            g[x].push_back(i);
            scanf("%d", &x);
        }
    }
    for(int i = 1; i <= n; ++i)
        if(!u[i])
            Dfs(i);
    for(int i = 1; i <= n; ++i)
        printf("%d", c[i]);
    return 0;
}
