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

int n, q, a[maxn];
map < int, vector < int > > t;

main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), t[a[i]].pb(i);
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i){
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        auto it = lower_bound(t[x].begin(), t[x].end(), l);
        if(it != end(t[x]) && *it <= r)
            putchar('1');
        else
            putchar('0');
    }
    return 0;
}
