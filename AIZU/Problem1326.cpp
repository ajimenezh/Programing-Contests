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

int cnt[11];
int c1[11][2], c2[11][2], c3[11][2];
int p,q;
int ans[11];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>p>>q && p!=0) {
        vector<string> vs;
        for (int i=0; i<p; i++) {
            string s;
            cin>>s;
            vs.push_back(s);
        }
        for (int i=0; i<p; i++) {
            int k = 0;
            cnt[i] = 0;
            c1[i+1][0] = 0;
            c2[i+1][0] = 0;
            c3[i+1][0] = 0;
            if (i!=0) {
                c1[i+1][0] = c1[i][0];
                c2[i+1][0] = c2[i][0];
                c3[i+1][0] = c3[i][0];
            }
            while (k<vs[i].size() && vs[i][k++]=='.') cnt[i]++;
            for (int k=0; k<vs[i].length(); k++) {
                if (vs[i][k]=='(') c1[i+1][0]++;
                if (vs[i][k]==')') c1[i+1][0]--;
                if (vs[i][k]=='{') c2[i+1][0]++;
                if (vs[i][k]=='}') c2[i+1][0]--;
                if (vs[i][k]=='[') c3[i+1][0]++;
                if (vs[i][k]==']') c3[i+1][0]--;
            }
        }
        vs.clear();
        for (int i=0; i<q; i++) {
            string s;
            cin>>s;
            vs.push_back(s);
        }
        for (int i=0; i<q; i++) {
            int k = 0;
            c1[i+1][1] = 0;
            c2[i+1][1] = 0;
            c3[i+1][1] = 0;
            if (i!=0) {
                c1[i+1][1] = c1[i][1];
                c2[i+1][1] = c2[i][1];
                c3[i+1][1] = c3[i][1];
            }
            for (int k=0; k<vs[i].length(); k++) {
                if (vs[i][k]=='(') c1[i+1][1]++;
                if (vs[i][k]==')') c1[i+1][1]--;
                if (vs[i][k]=='{') c2[i+1][1]++;
                if (vs[i][k]=='}') c2[i+1][1]--;
                if (vs[i][k]=='[') c3[i+1][1]++;
                if (vs[i][k]==']') c3[i+1][1]--;
            }
        }
        for (int i=0; i<q; i++) ans[i] = -1;
        int r = 0, s = 0, c = 0;
        for (int rr=1; rr<=20; rr++) {
            for (int cc=1; cc<=20; cc++) {
                for (int ss=1; ss<=20; ss++) {
                    bool good = 1;
                    for (int i=0; i<p; i++) {
                        if (cnt[i]!=rr*c1[i][0]+cc*c2[i][0]+ss*c3[i][0]) {
                            good = 0;
                            break;
                        }
                    }
                    if (good) {
                        for (int i=0; i<q; i++) {
                            int tmp = rr*c1[i][1]+cc*c2[i][1]+ss*c3[i][1];
                            if (ans[i]==-1) ans[i] = tmp;
                            else if (ans[i]!=tmp) ans[i] = -2;
                        }
                    }
                }
            }
        }
        for(int i=0;i<q; i++)
            cout << ((ans[i]<0)?-1:ans[i]) << ((i==q-1)?"\n":" ");
    }

    return 0;

}
