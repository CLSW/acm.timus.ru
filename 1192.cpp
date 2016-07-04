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

double V;
int alpha;
double k;

const ld PI = acos(-1.0);

main(){
    cin >> V >> alpha >> k;

    if(alpha == 0){
        cout << "0.00\n";
        return 0;
    }

    double tmp = sin(2 * alpha * PI / 180);
    double dist = tmp * V * V / 10;
    double diff = 0.0015;
    while(V >= eps){
            V = V / sqrt(k);
            diff = tmp * V * V /10;
            dist += diff;
    }
    cout << fixed << setprecision(2) << dist;
    return 0;
}
