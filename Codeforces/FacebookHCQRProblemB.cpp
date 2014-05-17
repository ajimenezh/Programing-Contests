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

string s;
char c[501];
int next[501];
int k;
int open,close;

bool dfs(int p, int q) {
    if (c[p]==')') return true;

    for (int i=p+1; i<k; i++) {
        if (next[i]==-1 && dfs(i,p)) {
            next[p] = i;
            next[i] = p;

            return false;
        }
    }
    return false;
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    getline(cin,s);

    for (int tt=0; tt<t; tt++) {
        getline(cin,s);
        int n = s.length();

        open = 0;
        close = 0;
        for (int i=0; i<n-1; i++) {
            if (s[i]==':' && (s[i+1]=='(' || s[i+1] == ')')) {
                s[i+1]=='(' ? open++ : close++;
            }
        }

        k = 0;
        for (int i=0; i<n; i++) {
            if (s[i]=='(' || s[i]==')') {
                c[k++] = s[i];
            }
        }

        for (int i=0; i<k; i++) next[i] = -1;

        for (int i=0; i<k; i++) if (next[i]==-1) {
            dfs(i,-1);
        }

        //cout<<open<<" "<<close<<endl;
        //for (int i=0; i<k; i++) cout<<next[i]<<" "; cout<<endl;

        bool done = false;
        for (int i=0; i<k; i++) {
            if (next[i]==-1) {
                if (c[i]=='(' && open>0) {open--; continue;}
                if (c[i]==')' && close>0) {close--; continue;}
                printf("Case #%d: NO\n",tt+1);
                done = true;
                break;
            }
        }
        if (!done) printf("Case #%d: YES\n",tt+1);

    }

    return 0;

}
