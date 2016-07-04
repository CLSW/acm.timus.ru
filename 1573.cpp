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

int b, r, y, k;
ll c[101][101];
map < string, int > cnt;

main(){
    for(int i = 1; i <= 100; ++i){
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; ++j)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    cin >> b >> r >> y >> k;
    for(int i = 1; i <= k; ++i){
        string x;
        cin >> x;
        for(auto &i : x) i = tolower(i);
        ++cnt[x];
    }
    cout << c[b][cnt["blue"]] * c[r][cnt["red"]] * c[y][cnt["yellow"]];
    return 0;
}
