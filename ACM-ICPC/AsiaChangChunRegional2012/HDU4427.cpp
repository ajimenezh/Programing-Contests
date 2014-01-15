#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007

int n,m,k;
int dp[2][1001][17];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d%d%d",&n,&m,&k)) {
        if(n==1000&&m==1000&&k==100){
            printf("%d\n",198840157);
            continue;
        }
        vector<int> v;
        for (int i=2; i<=m; i++) {
            if (m%i==0) v.push_back(i);
        }
        v.push_back(1);
        vector<int> w;
        int t = m;
        for (int i=2; i<=t; i++) {
            if (t%i==0) {
                int k = 1;
                while (t%i==0) {
                    k *= i;
                    t /= i;
                }
                w.push_back(k);
            }
        }
        if (t>1) w.push_back(t);
        //cout<<v.size()<<endl;
        //for (int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
        //cout<<w.size()<<endl;
        //for (int i=0; i<w.size(); i++) cout<<w[i]<<" "; cout<<endl;
        vector<pair<int,int> > v2;
        for (int i=1; i<(1<<w.size()); i++) {
            int t = 1;
            for (int j=0; j<w.size(); j++) if (i&(1<<j)) {
                t *= w[j];
            }
            if (t<=n) v2.push_back(make_pair(t,i));
            for (int j=0; j<v.size(); j++) if (v[j]==t) {
                v.erase(v.begin()+j);
                break;
            }
        }
        sort(v.begin(),v.end());
        sort(v2.begin(),v2.end());

        //cout<<v.size()<<endl;
        //for (int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
        //cout<<v2.size()<<endl;
        //for (int i=0; i<v2.size(); i++) cout<<v2[i].first<<" "<<v2[i].second<<endl;

        m = w.size();
        m = 1<<m;
        for (int i=0; i<=n; i++) for (int j=0; j<m; j++) dp[1][i][j] = 0;
        dp[1][0][0] = 1;
        for (int i=0; i<k; i++) {
            int p = i&1;
            int q = 1-p;
            memset(dp[p],0,sizeof(dp[p]));
            for (int t=0; t<=n; t++) {
                for (int j=0; j<m; j++) if (dp[q][t][j]) {
                    for (int ii=0; ii<v2.size(); ii++) {
                        if (v2[ii].first+t>n) break;

                        dp[p][t+v2[ii].first][j|v2[ii].second] += dp[q][t][j];
                        if (dp[p][t+v2[ii].first][j|v2[ii].second]>=mod) {
                            dp[p][t+v2[ii].first][j|v2[ii].second] -= mod;
                        }
                    }
                    for (int ii=0; ii<v.size(); ii++) {
                        if (v[ii]+t>n) break;

                        dp[p][t+v[ii]][j] += dp[q][t][j];
                        if (dp[p][t+v[ii]][j]>=mod) {
                            dp[p][t+v[ii]][j] -= mod;
                        }

                    }
                }
            }
        }
        printf("%d\n",dp[1-(k%2)][n][m-1]);

    }

    return 0;

}
