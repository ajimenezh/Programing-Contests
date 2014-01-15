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
set<int> seq[12];
vector<int> vseq[12];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>m>>n;
    for (int i=0; i<m; i++) {
        int l;
        cin>>l;
        for (int j=0; j<l; j++) {
            int a;
            cin>>a;
            seq[i].insert(a);
            vseq[i].push_back(a);
        }
    }
    for (int i=0; i<n; i++) {
        int l;
        cin>>l;
        vector<int> v;
        for (int j=0; j<l; j++) {
            int a;
            cin>>a;
            v.push_back(a);
        }
        vector<int> ans;
        for (int j=0; j<m; j++) {
            bool good = 1;
            for (int k=0; k<v.size(); k++) {
                if (v[k]>=0 && seq[j].find(v[k])==seq[j].end()) {
                    good = 0;
                    break;
                }
                else {
                    if (seq[j].find(-v[k])!=seq[j].end()) {
                        good = 0;
                        break;
                    }
                }
            }
            if (good) ans.push_back(j);
        }
        cout<<ans.size()<<endl;
        for (int j=0; j<ans.size(); j++) {
            cout<<vseq[ans[j]].size()<<" ";
            for (int k=0; k<vseq[ans[j]].size(); k++) cout<<vseq[ans[j]][k]<<" ";
            cout<<endl;
        }
    }

    return 0;

}
