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
const int maxn = (int)2e5 + 7;
const int lmaxn = (int)1e6 + 7;
const ll linf = (ll)5e18 + 7;

const ld eps = ld(1e-11);

struct node{
    map < char, int > nxt;
    int link, len;
};

node st[maxn];
int d[maxn];
char togo[maxn];
int sz, last;

void init(){
    st[0].link = -1;
    st[0].len = 0;
}

void add_letter(char c){
    int cur = ++sz;
    st[cur].len = st[last].len + 1;
    int p = last;
    for(; p != -1 && !st[p].nxt.count(c); p = st[p].link)
        st[p].nxt[c] = cur;
    if(p == -1){
        st[p].link = 0;
    }
    else{
        int q = st[p].nxt[c];
        if(st[p].len + 1 == st[q].len){
            st[cur].link = q;
        }
        else{
            int clone = ++sz;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            st[clone].nxt = st[q].nxt;
            for(; p != -1 && st[p].nxt[c] == q; p = st[p].link)
                st[p].nxt[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void Go(int v, int flag){
    char ind = '0';
    d[v] = inf;
    for(char i = (flag ? '1' : '0'); i <= '9'; ++i){
        if(!st[v].nxt.count(i)){
            d[v] = 1;
            ind = i;
            break;
        }
        else{
            Go(st[v].nxt[i], 0);
            if(d[v] > d[st[v].nxt[i]] + 1){
                d[v] = d[st[v].nxt[i]] + 1;
                ind = i;
            }
        }
    }
    togo[v] = ind;
}

int n, f;
char a[maxn], b[maxn];

int main(){
    scanf("%s", a);
    init();
    n = strlen(a);
    for(int i = 0; i < n; ++i)
        add_letter(a[i]), f |= (a[i] == '0');
    Go(0, 1);
    ll v = 0;
    while(true){
        printf("%c", togo[v]);
        v = st[v].nxt[togo[v]];
        if(!v)
            break;
    }
    return 0;
}
