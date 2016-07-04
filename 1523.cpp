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
const int maxn = (int)2e5 + 7;
const int lmaxn = (int)1e6 + 7;

const int mod = (int)1e9;

const ld eps = ld(1e-11);

int n, k;
int a[maxn];

struct tree{
    int t[maxn];
    void Inc(int v, int p){
        for(; v <= n; v += v & -v)
            t[v] = (t[v] + p) % mod;
    }
    int Get(int v){
        int ans = 0;
        for(; v > 0; v -= v & -v)
            ans += t[v], ans %= mod;
        return ans;
    }

    int Get(int l, int r){
        return (Get(r) - Get(l - 1) + mod) % mod;
    }
}t[11];

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        t[1].Inc(a[i], 1);
        for(int j = 2; j <= k; ++j)
            t[j].Inc(a[i], t[j - 1].Get(a[i] + 1, n));
    }
    printf("%d", t[k].Get(n));
    return 0;
}
