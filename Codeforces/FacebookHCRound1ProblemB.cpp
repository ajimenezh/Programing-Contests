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

int m;
string k1;
string k2;
set<int> e[100];

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=0; t<tt; t++) {
        cin>>m;
        cin>>k1;
        cin>>k2;

        int n = k1.length()/m;

        for (int i=0; i<100; i++) e[i].clear();

        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                bool good = true;
                for (int k=0; k<k1.length()/m; k++) {
                    if (k1[i*n+k]=='?' || k2[j*n+k]=='?') continue;
                    else {
                        if (k1[i*n+k]!=k2[j*n+k]) good = false;
                    }
                }
                if (good) e[i].insert(j);
            }
        }

        bool pass = false;
        for (int i=0; i<m; i++) {
            if (e[i].size()==0) {
                printf("Case #%d: ",t+1);
                cout<<"IMPOSSIBLE"<<endl;
                pass = true;
                m = -1;
            }
        }


        for (int i=0; i<m; i++) {
            bool done = false;
            for (int j=0; j<m; j++) {
                if (e[j].size()==1) {
                    for (int k=0; k<k1.length()/m; k++) {
                        if (k1[j*n+k]=='?' && k2[*(e[j].begin())*n+k]=='?') {
                            k1[j*n+k] = 'a';
                            continue;
                        }
                        if (k1[j*n+k]=='?') {
                            k1[j*n+k] = k2[*(e[j].begin())*n+k];
                        }
                    }
                    int r = *(e[j].begin());
                    for (int k=0; k<m; k++) e[k].erase(r);
                    e[j].clear();
                    break;
                    done = true;
                }
            }

            if (done) continue;
            else {

                int r = 1000;
                for (int j=0; j<m; j++) if (e[j].size()!=0) r = min((int)e[j].size(),r);


                for (int j=0; j<m; j++) {
                    if (e[j].size()==r) {
                        string k3 = k1;
                        string k4;
                        int p = -1;
                        rep(it,e[j]) {
                            k3 = k1;
                            for (int k=0; k<k1.length()/m; k++) {
                                if (k3[j*n+k]=='?' && k2[(*it)*n+k]=='?') {
                                    k3[j*n+k] = 'a';
                                    continue;
                                }
                                if (k3[j*n+k]=='?') {
                                    k3[j*n+k] = k2[(*it)*n+k];
                                }
                            }
                            if (p==-1 || k4>k3) {
                                k4 = k3;
                                p = (*it);
                            }
                        }
                        for (int k=0; k<k1.length()/m; k++) {
                            if (k1[j*n+k]=='?' && k2[p*n+k]=='?') {
                                k1[j*n+k] = 'a';
                                continue;
                            }
                            if (k1[j*n+k]=='?') {
                                k1[j*n+k] = k2[p*n+k];
                            }
                        }
                        int r = p;
                        for (int k=0; k<m; k++) e[k].erase(r);
                        e[j].clear();
                        break;
                        done = true;
                    }
                }

            }
        }


        //cout<<k1<<endl;
        if (!pass) {
            printf("Case #%d: ",t+1);
            bool done = true;
            for (int i=0; i<k1.length(); i++) {
                if (k1[i]=='?') done = false;
            }
            if (!done) cout<<"IMPOSSIBLE"<<endl;
            else cout<<k1<<endl;
        }
    }


    return 0;

}
