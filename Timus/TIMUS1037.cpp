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

int w[80001];
int n;
string s;
vector<int> v[65001];
int q[80000];
int in,fn;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while(getline(cin,s) && s!="") {
        //cout<<s<<endl;
        stringstream ss(s);
        int t;
        ss>>t;
        ss>>s;
        if (s!=".") {
            v[t].push_back(-1);
        }
        else {
            int a;
            ss>>a;
            v[t].push_back(a);
        }
    }

    for (int i=0; i<65001; i++) {
        if (v[i].size()==0) continue;
        else {
            in = 0; fn=0;
            for (int j=0; j<n; j++) {
                if (i-w[j]>=600) {
                    w[j] = -1;
                    q[fn++] = j;
                }
                else if (w[j]==-1) {
                    q[fn++] = j;
                }
            }
            for (int j=0; j<v[i].size(); j++) {
                //cout<<i<<" "<<v[i][j]<<endl;
                if (v[i][j]==-1) {
                    if (in<fn) {
                        int p = q[in++];
                        w[p] = i;
                        printf("%d\n",p+1);
                    }
                    else {
                        int p = n++;
                        w[p] = i;
                        printf("%d\n",p+1);
                    }
                }
                else {
                    if (v[i][j]>n ) printf("-\n");
                    else {
                        if (w[v[i][j]-1]!=-1) {
                            printf("+\n");
                            w[v[i][j]-1] = i;
                        }
                        else
                            printf("-\n");
                    }
                }
            }
        }
    }

    return 0;

}
