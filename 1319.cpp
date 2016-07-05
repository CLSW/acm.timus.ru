
ll n, now;
ll a[101][101];

main(){
    scanf("%lld", &n);
    for(ll i = n; i >= 1; --i){
        ll x = 1, y = i;
        while(x <= n && y <= n){
            a[x][y] = ++now;
            ++x, ++y;
        }
    }
    for(ll i = 2; i <= n; ++i){
        ll x = i, y = 1;
        while(x <= n && y <= n){
            a[x][y] = ++now;
            ++x, ++y;
        }
    }
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            printf("%lld%c", a[i][j], " \n"[j == n]);
    return 0;
}
