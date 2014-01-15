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

const int f[6][4] = { {2, 3, 4, 5},
                {1,3,5,6},
                {1,2,4,6},
                {1,3,5,6},
                {1,2,4,6},
                {2,3,4,5} };

string col[6];
int p[6];
string cur[6];
char c[6];
vector<string> sol;

bool equal(string s1, string s2) {
    for (int i=0; i<6; i++) {
        bool bad = 0;
        for (int j=0; j<6; j++) if (s1[(i+j)%6]!=s2[j]) {
            bad = 1;
            break;
        }
        if (!bad) return true;
    }
    return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<6; i++) cin>>col[i];
    for (int i=0; i<6; i++) p[i] = i;

    do {
        for (int i=0; i<6; i++) {
            cur[i] = col[p[i]];
        }
        for (int i=0; i<6; i++) c[i] = cur[i][0];

        string tmp;
        for (int i=0; i<6; i++) tmp += c[i];

        bool bad = 0;
        for (int i=0; i<6; i++) {
            map<char,int> cnt;
            for (int j=1; j<5; j++) cnt[cur[i][j]]++;
            for (int j=0; j<4; j++) {
                if (cnt.find(c[f[i][j]-1])!=cnt.end()) {
                    if (cnt[c[f[i][j]-1]]>0) {
                        cnt[c[f[i][j]-1]]--;
                    }
                    else {
                        bad = 1;
                        break;
                    }
                }
                else {
                    bad = 1;
                    break;
                }
                if (bad) break;
            }
            if (bad) break;
        }

        if (!bad) {
            if (sol.size()>1) break;
            string ans;
            for (int i=0; i<6; i++) ans += c[i];
            if (sol.size()==1) {
                if (!equal(sol[0],ans)) sol.push_back(ans);
            }
            else sol.push_back(ans);
        }

    } while (next_permutation(p,p+6));

    if (sol.size()==0) cout<<"Impossible"<<endl;
    else {
        for (int i=0; i<sol.size(); i++) cout<<sol[i]<<endl;
    }

    return 0;

}

