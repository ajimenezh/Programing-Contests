#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n,m,k;
char a[401][401];
int sum[401][401];
int cnt[28];

int partial (int i, int ii, int j, int jj) {
    int p = sum[ii][jj];
    if (i>0) p -= sum[i-1][jj];
    if (j>0) {
        p -= sum[ii][j-1];
        if (i>0) p += sum[i-1][j-1];
    }
    return p;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<n; i++) {
        scanf("%s",&a[i]);
    }

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        sum[i][j] = a[i][j]=='a';
        if (i>0 && j>0) sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        else if (j==0 && i>0) sum[i][j] += sum[i-1][j];
        else if (j>0 && i==0) sum[i][j] += sum[i][j-1];
    }

    int res = 0;
    for (int i=0; i<n; i++) for (int ii=i+1; ii<n; ii++) {
        int j = 0;
        while (j<m && a[i][j]!=a[ii][j]) j++;
        for (int c=0; c<27; c++) cnt[c] = 0;
        cnt[a[i][j]-'a']++;
        for (int jj=j+1; jj<m; jj++) {
            while (j<jj && partial(i,ii,j,jj)>k) {
                if (a[i][j]==a[ii][j]) cnt[a[i][j]-'a']--;
                j++;
            }
            if (a[i][jj]==a[ii][jj]) {
                //cout<<i<<" "<<ii<<" "<<j<<" "<<jj<<" "<<cnt[a[i][jj]-'a']<<endl;
                //cout<<partial(i,ii,j,jj)<<endl;
                res += cnt[a[i][jj]-'a'];
                cnt[a[i][jj]-'a']++;
            }
        }
        //cout<<i<<" "<<ii<<" "<<res<<endl;
    }

    cout<<res<<endl;

    return 0;

}
