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

int full[101];
int id[101];
vector<pair<int,int> > all;
int done[101];
int m, t;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t>>m;
    int tot = 1;
    all.push_back(make_pair(-1,-1));
    for (int i=0; i<t; i++) {
        string s;
        cin>>s;
        if (s[0]=='a') {
            int n;
            cin>>n;
            bool cando = 0;
            for (int j=0; j<m-n+1; j++) {
                bool good = 1;
                for (int k=0; k<n; k++) if (full[k+j]) {
                    j = k+j;
                    good = 0;
                    break;
                }
                if (good) {
                    for (int k=0; k<n; k++) id[j+k] = tot;
                    all.push_back(make_pair(tot, n));
                    done[tot] = 0;
                    cout<<tot<<endl;
                    tot++;
                    for (int k=0; k<n; k++) full[j+k] = 1;
                    cando = 1;
                    break;
                }
            }
            if (!cando) cout<<"NULL"<<endl;
        }
        else if (s[0]=='d') {
            for (int i=m-1; i>=1; i--) {
                if (full[i-1]==0 && full[i]==1) {
                    for (int j=i-1; j<m-1; j++) {
                        full[j] = full[j+1];
                        id[j] = id[j+1];
                    }
                    full[m-1] = 0;
                    id[m-1] = 0;
                }
            }
        }
        else {
            long long n;
            cin>>n;
            if (n<1 || n>=tot || done[n]) cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
            else {
                done[n] = 1;
                for (int j=0; j<m; j++) if (id[j]==n) {
                    id[j] = 0;
                    full[j] = 0;
                }
            }
        }
    }

    return 0;

}
