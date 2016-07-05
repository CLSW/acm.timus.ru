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

const ld eps = ld(1e-11);

int n;
int a[] = {4, 9, 19, 49, 99, 249, 499, 999, 2001};
string b[] = {"few", "several", "pack", "lots", "horde", "throng", "swarm", "zounds", "legion"};

main(){
    scanf("%d", &n);
    for(int i = 0; i < 9; ++i){
        if(a[i] >= n){
            puts(b[i].c_str());
            return 0;
        }
    }
    return 0;
}
