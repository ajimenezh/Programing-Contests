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
vector<int> v;
vector<int> w;
int dp[210][210][28];
int cost[28][28];
int res[28][28];
vector<pair<int,int> > all[28];

int solve(int i, int j, int k) {
    if (i==j) {
        if (w[i]==k) return 0;
        else return -2;
    }
    if (dp[i][j][k]!=-1) return dp[i][j][k];

    int tmp = -2;

    for (int t=i; t<j; t++) {
        for (int c1=0; c1<all[k].size(); c1++) {
                int sol1 = solve(i,t,all[k][c1].first);
                int sol2 = solve(t+1,j,all[k][c1].second);
                if (sol1!=-2 && sol2!=-2) {
                    int ans = sol1 + sol2 + cost[all[k][c1].first][all[k][c1].second];
                    if (tmp==-2 || ans<tmp) {
                        tmp = ans;
                    }
                }
        }
    }

    dp[i][j][k] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        v.clear();
        for (int i=0; i<n; i++) {
            char c;
            cin>>c;
            v.push_back(c-'a');
            all[c-'a'].clear();
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                string s;
                cin>>s;
                for (int k=0; k<s.length(); k++) if (s[k]=='-') s[k]=' ';
                stringstream ss(s);
                int c;
                ss>>c;
                char to;
                ss>>to;
                res[v[i]][v[j]] = to-'a';
                cost[v[i]][v[j]] = c;
                all[to-'a'].push_back(make_pair(v[i],v[j]));
            }
        }
        int m;
        cin>>m;
        for (int i=0; i<m; i++) {
            string s;
            cin>>s;
            w.clear();
            for (int j=0; j<s.length(); j++) w.push_back(s[j]-'a');
            for (int j=0; j<s.length(); j++) {
                for (int k=j; k<s.length(); k++) {
                    for (int t=0; t<v.size(); t++) {
                        dp[j][k][v[t]] = -1;
                    }
                }
            }
            int best = 1000000000;
            char p = 'A';
            for (int j=0; j<n; j++) {
                int tmp = solve(0,s.length()-1,v[j]);
                if (tmp!=-2 && tmp<best) {
                    best = tmp;
                    p = char(v[j]+'a');
                }
            }
            printf("%d-%c\n",best,p);
        }
        printf("\n");
    }

    return 0;

}
