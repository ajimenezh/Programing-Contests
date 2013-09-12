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

int t;
int n,m;
string vs[1001];
bool mat[1001][1001];
int next[1001][1001];
int num[4010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while (t--) {
        cin>>n>>m;
        for (int i=0; i<n; i++) cin>>vs[i];
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) mat[i][j] = vs[i][j]=='.';

        for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
            if (mat[i][j]) {
                if (i==0) next[i][j] = 1;
                else next[i][j] = 1 + next[i-1][j];
            }
            else next[i][j] = 0;
        }

        for (int i=0; i<2*(n+m+1); i++) num[i] = 0;

        for (int i=0; i<n; i++) {
            vector<int> h;
            vector<int> x;
            for (int j=0; j<m; j++) {
                if (!mat[i][j]) {
                    h.clear();
                    x.clear();
                    continue;
                }
                int now = j;
                while (!x.empty() && h.back()>next[i][j]) {
                    now = x.back();
                    x.pop_back();
                    h.pop_back();
                }

                if (x.empty() || j-now+1+next[i][j]>j-x.back()+1+h.back()) {
                    h.push_back(next[i][j]);
                    x.push_back(now);
                }

                num[2*(j-x.back()+1+h.back())]++;
            }
        }

        for (int i=0; i<2*(n+m+1); i++) if (num[i]>0) {
            cout<<num[i]<<" x "<<i<<endl;
        }
    }

    return 0;

}
