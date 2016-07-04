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
typedef unsigned long long ull;
typedef long double ld;

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

const ld eps = ld(1e-11);

ld Dist(ld X1, ld Y1, ld X2, ld Y2){
    return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}

int n, p;
double x[maxn], y[maxn], r;
ld ans;

main(){
    scanf("%d %lf", &n, &r);
    for(int i = 1; i <= n; ++i){
        scanf("%lf %lf", &x[i], &y[i]);
    }
    for(int i = 1; i <= n; ++i){
        p = i - 1;
        if(!p) p = n;
        ans += Dist(x[p], y[p], x[i], y[i]);
    }
    printf("%.2f", (double)ans + 2 * r * acos(-1.0));
    return 0;
}
