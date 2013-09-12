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

int n;
string str;
char l[4] = {'G', 'H', 'R', 'S'};
string sol[4] = {"Gryffindor","Hufflepuff","Ravenclaw","Slytherin"};
set<vector<int> > s,s2;
bool good[4];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    vector<int> v(4,0);

    cin>>n; cin>>str;

    s.insert(v);
    for (int j=0; j<n; j++) {
        s2.clear();
        if (str[j]!='?') {
            rep(it,s) {
                v = *it;
                for (int k=0;k<4; k++) if (l[k]==str[j]) {
                    v[k]++;
                    s2.insert(v);
                    break;
                }
            }
        }
        else {
            rep(it,s) {
                v = *it;
                int t = 10000000;
                for (int k=0; k<4; k++) t = min(v[k],t);
                for (int k=0; k<4; k++) {
                    if (v[k]==t) {
                        v[k]++;
                        s2.insert(v);
                        v[k]--;
                    }
                }
            }
        }
        s.clear();
        s = s2;
    }
    rep(it,s) {
        v = *it;
        //for (int i=0; i<4; i++) cout<<v[i]<<" "; cout<<endl;
        int t = 10000000;
        for (int k=0; k<4; k++) t = min(v[k],t);
        for (int k=0; k<4; k++) {
            if (v[k]==t) {
                good[k] = 1;
            }
        }
    }
    for (int i=0; i<4; i++) if (good[i]) cout<<sol[i]<<endl;

    return 0;

}
