ll q;
int dp[901][8101], pr[901][8101];

inline ll Dp(ll s, ll p){
    if(~dp[s][p]) return dp[s][p];
    dp[s][p] = (int)1e9;
    for(ll k = 1; k <= 9; ++k){
        if(s - k >= 0 && p - (k * k) >= 0){
            ll val = Dp(s - k, p - (k * k)) + 1;
            if(val == dp[s][p]){
                if(k <= pr[s][p])
                    pr[s][p] = k;
            }
            if(val < dp[s][p]){
                dp[s][p] = val;
                pr[s][p] = k;
            }
        }
    }
    return dp[s][p];
}

int main(){
    for(ll i = 0; i < 901; ++i)
        for(ll j = 0; j < 8101; ++j)
            dp[i][j] = -1, pr[i][j] = (int)1e9;
    for(ll i = 1; i <= 9; ++i)
        dp[i][i * i] = 1, pr[i][i * i] = i;
    scanf("%d", &q);
    for(ll i = 1; i <= q; ++i){
        ll x, y;
        scanf("%d %d", &x, &y);
        if(x > 900 || y > 8100){
            printf("No solution\n");
            continue;
        }
        ll len = Dp(x, y);
        if(len > 100){
            printf("No solution\n");
            continue;
        }
        while(len){
            ll now = pr[x][y];
            printf("%d", now);
            x = x - now;
            y = y - now * now;
            --len;
        }
        printf("\n");
    }
    return 0;
}
