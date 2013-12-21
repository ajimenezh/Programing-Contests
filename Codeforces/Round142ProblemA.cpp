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

int n,m;
string s[110];
int next[110][30010];
int last[110][30010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>s[i];
    for (int i=0; i<n; i++) s[i] = s[i] + s[i] + s[i];

    for (int i=0; i<n; i++) {
        int tmp = -1;
        for (int j=0; j<3*m; j++) {
            if (s[i][j]=='1') tmp = j;
            last[i][j] = tmp;
        }
        if (tmp==-1) {
            cout<<-1;
            return 0;
        }
        tmp = -1;
        for (int j=3*m-1;j>=0; j--) {
            if (s[i][j]=='1') tmp = j;
            next[i][j] = tmp;
        }
        if (tmp==-1) {
            cout<<-1;
            return 0;
        }
    }

    int best = 100000000;

    for (int i=m; i<2*m; i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            sum += min(next[j][i]-i, i-last[j][i]);
        }
        best = min(best, sum);
    }

    cout<<best<<endl;

    return 0;

}
