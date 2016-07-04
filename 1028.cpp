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

const int inf = (int)1e9 + 7;
const int linf = (int)1e16 + 7;
const int maxn = (int)4e5 + 7;

const ld eps = ld(1e-11);

int t[32002];

int n, x[maxn], y[maxn], cnt[maxn];

void inc(int v){
    for(int i = v; i <= 32001; i |= (i + 1))
        ++t[i];
}

int get(int v){
    int ans = 0;
    for(int i = v; i >= 0; i = (i & (i + 1)) - 1)
        ans += t[i];
    return ans;
}

main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d %d", &x[i], &y[i]);
        ++cnt[get(x[i])];
        inc(x[i]);
    }
    for(int i = 0; i < n; ++i)
        printf("%d\n", cnt[i]);
    return 0;
}
