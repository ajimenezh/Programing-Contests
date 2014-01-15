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
#include <fstream>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int t;
int n,m;
int tl;
int scr[26];
int cm[51][51];
int wm[51][51];
int l[51][51];
vector<string> vs[15];
vector<int> v[15];
bool vis[51][51];
string str;
int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};
int bestSol;
pair<int,int> w[178380];
int dp[178380][300];

void _search(int i, int a, int b, int tot, int best) {
    if (i==str.length()) {
        bestSol = max(bestSol,tot*best+(int)str.length());
    }


    for (int j=0; j<8; j++) {
        if (a+dx[j]<0 || a+dx[j]>=n) continue;
        if (b+dy[j]<0 || b+dy[j]>=m) continue;
        if (l[a+dx[j]][b+dy[j]]!=str[i]-'A') continue;
        if (vis[a+dx[j]][b+dy[j]]) continue;

        vis[a+dx[j]][b+dy[j]] = 1;

        _search(i+1,a+dx[j],b+dy[j],tot+scr[str[i]-'A']*cm[a+dx[j]][b+dy[j]],max(best,wm[a+dx[j]][b+dy[j]]));

        vis[a+dx[j]][b+dy[j]] = 0;
    }

    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ifstream input;
    input.open("C:\\Users\\Alex\\Downloads\\boozzle-dict.txt");

    for (int i=0; i<178380; i++) {
        string s;
        input>>s;
        vs[s.length()].push_back(s);
        v[s.length()].push_back(0);
    }




    cin>>t;
    for (int tt=0; tt<t; tt++) {
        string s;
        getline(cin,s);
        getline(cin,s);
        s = s.substr(1,s.length()-2);
        for (int i=0; i<s.length(); i++) if (s[i]==',') s[i] = ' ';
        stringstream ss(s);
        int c = 0;
        while (ss>>s) {
            int ch = s[1]-'A';
            ss>>s;
            scr[ch] = atoi(s.c_str());
        }

        cin>>tl>>n>>m;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
            cin>>s;
            l[i][j] = s[0]-'A';
            if (s[1]=='1') {
                cm[i][j] = s[2]-'0';
                wm[i][j] = 1;
            }
            if (s[1]=='2') {
                wm[i][j] = s[2]-'0';
                cm[i][j] = 1;
            }
        }

        int k = 0;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) vis[i][j] = 0;
        for (int i=0; i<15; i++) for (int j=0; j<vs[i].size(); j++) {
            str = vs[i][j];
            v[i][j] = 0;
            for (int ii=0; ii<n; ii++) for (int jj=0; jj<m; jj++) {
                bestSol = 0;
                _search(0,ii,jj,0,0);
                int p = bestSol;
                v[i][j] = max(p,v[i][j]);
            }
            if (v[i][j]!=0) {
                w[k++] = make_pair(v[i][j],str.length()+1);
                //cout<<str<<" "<<v[i][j]<<endl;
            }

        }

        for (int i=0; i<=tl; i++) for (int j=0; j<k; j++) dp[j][i] = 0;
        for (int i=0; i<k; i++) {
            for (int j=0; j<=tl; j++) {
                if (i==0) {
                    if (j!=0 && j >= w[i].second) {
                        dp[i][j] = w[i].first;
                    }
                }
                else {
                    if (j!=0) {
                        if (j >= w[i].second) {
                            dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i].second]+w[i].first);
                        }
                        else {
                            dp[i][j] = dp[i-1][j];
                        }
                    }
                }
            }
        }

        printf("%d\n",dp[k-1][tl]);

    }

    return 0;

}
