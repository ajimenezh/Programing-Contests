//Unfinished

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

string tiles[14];

bool solve() {
    bool vis[14];

    //First winning way
    for (int i=0; i<14; i++) vis[i] = 0;
    for (int i=0; i<14; i++) if (!vis[i]) {
        for (int j=i+1; j<14; j++) {
            if (tiles[i]==tiles[j]) {
                vis[i] = 1;
                vis[j] = 1;
            }
        }
    }

    bool good = 1;
    for (int i=0; i<14; i++) if (!vis[i]) good = 0;
    if (good) return 1;

    //Second winning way
    for (int i=0; i<6; i++) vis[i] = 0;
    for (int i=0; i<14; i++) if (tiles[i]=="1m") vis[0] = 1;
    for (int i=0; i<14; i++) if (tiles[i]=="9m") vis[1] = 1;
    for (int i=0; i<14; i++) if (tiles[i]=="1p") vis[2] = 1;
    for (int i=0; i<14; i++) if (tiles[i]=="9p") vis[3] = 1;
    for (int i=0; i<14; i++) if (tiles[i]=="1s") vis[4] = 1;
    for (int i=0; i<14; i++) if (tiles[i]=="19") vis[5] = 1;

    good = 1;
    for (int i=0; i<6; i++) if (vis[i]==0) good = 0;
    for (int i=0; i<14; i++) {
        if (tiles[i]=="1m") continue;
        if (tiles[i]=="9m") continue;
        if (tiles[i]=="1p") continue;
        if (tiles[i]=="9p") continue;
        if (tiles[i]=="1s") continue;
        if (tiles[i]=="9s") continue;
        good = 0;
    }
    if (good) return 1;

    //Third
    bool found = 0;
    for (int i=0; i<14; i++) vis[i] = 0;
    for (int i=0; i<14; i++) {
        for (int j=i+1; j<14; j++) {
            if (tiles[i]==tiles[j]) {
                vis[i] = 1;
                vis[j] = 1;
                found = 1;
                i = 20;
                break;
            }
        }
    }

    if (!found) return 0;

    int cnt = 0;

    for (int i=0; i<14; i++) if (!vis[i]) {
        found = 0;
        for (int j=0; j<14; j++) {
            if (!vis[j] && j!=i) {
                if (tiles[i][1]==tiles[j][1] && int(tiles[i][0])==int(tiles[i][1])-1) {
                    for (int k=0; k<14; k++) {
                        if (!vis[k]&&k!=i && k!=j) {
                            if (tiles[k][1]==tiles[j][1] && int(tiles[j][0])==int(tiles[k][1])-1) {
                                vis[i] = 1;
                                vis[j] = 1;
                                vis[k] = 1;
                                cnt++;
                                found = 1;
                                j = 20;
                                k = 20;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (int j=i+1; j<14; j++) {
            for (int k=j+1; k<14; k++) {
                if (!vis[j] && !vis[k]) {
                    if (tiles[i]==tiles[j] && tiles[j]==tiles[k]) {
                        vis[i] = 1;
                        vis[j] = 1;
                        vis[k] = 1;
                        cnt++;
                        found = 1;
                        j = 20;
                        k = 20;
                        break;
                    }
                }
            }
        }
        if (found) continue;
        for (int j=i+1; j<14; j++) {
            for (int k=j+1; k<14; k++) {
                if (!vis[j] && !vis[k]) {
                    if (tiles[i]==tiles[j] && tiles[j]==tiles[k]) {
                        vis[i] = 1;
                        vis[j] = 1;
                        vis[k] = 1;
                        cnt++;
                        found = 1;
                        j = 20;
                        k = 20;
                        break;
                    }
                }
            }
        }
    }

    if (cnt>=3) return 1;

    return 0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        for (int i=0; i<13; i++) {
            string s;
            cin>>s;
            tiles[i] = s;
        }

        vector<string> sol;
        for (int i=0; i<9; i++) {
            tiles[13] = char(i+'0');
            tiles[13] += "s";
            if (solve()) sol.push_back(tiles[13]);
        }

        if (sol.size()==0) {
            cout<<"Nooten"<<endl;
            continue;
        }
        cout<<sol.size()<<" ";
        for (int i=0; i<sol.size(); i++) cout<<sol[i]<<" ";
        cout<<endl;
    }

    return 0;

}
