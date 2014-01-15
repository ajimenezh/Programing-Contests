#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

int n;
string s;
int v[100010][2];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        scanf("%d",&n);
        cin>>s;
        int k = 0;
        for (int i=0; i<n; i++) v[i][0] = 0;
        for (int i=0; i<n; i++) {
            if (i==0) {
                if (s[i]=='4') v[k][0] = 1;
                else v[k][0] = -1;
                v[k][1] = 1;
            }
            else {
                if (s[i]==s[i-1]) {
                    if (s[i]=='4') v[k][0]++;
                    else v[k][0]--;
                }
                else {
                    k++;
                    if (s[i]=='4') v[k][0] = 1;
                    else v[k][0] = -1;
                    v[k][1] = i+1;
                }
            }
        }

        int m = k;
        int ans = 0;
        for (int j=0; j<30; j++) {
            int k = 0;
            for (int i=1; i<=m; i++) {
                if (v[i][0]==0) continue;
                if (v[i][0]==v[k][0]) v[k][0]+=v[i][0];
                else v[++k][0] = v[i][0];
            }
            m = k;
            //for (int i=0; i<=m; i++) cout<<v[i][0]<<" "; cout<<endl;
            int sum = 0;
            for (int i=0; i<=m; i++) {
                v[i][1] = sum+1;
                sum += abs(v[i][0]);
            }
            //for (int i=0; i<=m; i++) cout<<v[i][1]<<" "; cout<<endl;
            for (int i=0; i<m; i++) {
                if (v[i][0]>0) {
                    int tmp = min(v[i][0], -v[i+1][0]);
                    int top = v[i][1] + v[i][0] - 1;
                    ans += (top+1)*top/2 - (top-tmp+1)*(top-tmp)/2;
                    v[i][0]-=tmp;
                    v[i+1][0]+=tmp;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;

}
