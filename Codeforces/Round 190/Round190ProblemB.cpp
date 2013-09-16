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

#define INF 100000000

int n,m;
int atk[110];
int v[110];
int w[110];
bool attack[110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        int a;
        cin>>a;
        if (s=="ATK") {
            atk[i] = a;
            attack[i] = 1;
        }
        else atk[i] = -a;
    }
    for (int i=0; i<m; i++) {
        cin>>v[i];
    }

    //Attack everything to make it possible to attack jiro directly
    //For each attacker choose the closest card so that atkJiro<=atkCiel
    //For each defense choose the closest card so that dfsJiro<atkCiel

    bool vis[110];
    for (int i=0; i<m; i++) vis[i] = 0;
    int score = 0;
    for (int i=0; i<n; i++) {
        bool done = 1;
        int best = 10000000;
        int p = -1;
        if (!attack[i]) {
            done = 0;
            for (int j=0; j<m; j++) if (!vis[j]&&v[j]>-atk[i]) {
                if (best>v[j]) {
                    best = v[j];
                    p = j;
                }
                done = 1;
            }
        }

        if (!done) score = -100000000;
        vis[p] = 1;
    }
    for (int i=0; i<n; i++) {
        bool done = 1;
        if (attack[i]) {
            done = 0;
            for (int j=0; j<m; j++) if (!vis[j]&&v[j]>=atk[i]) {
                vis[j] = 1;
                score += v[j]-atk[i];
                done = 1;
                break;
            }
        }
        if (!done) score = -100000000;
    }
    for (int i=0; i<m; i++) if (!vis[i]) score += v[i];

    //The second option is to not attack any defense, it doesnt make sense if you dont want to attack Jiro

    sort(v,v+m);
    reverse(v,v+m);
    int cnt = 0;
    for (int i=0; i<n; i++) if (atk[i]>=0 && attack[i]) w[cnt++] = atk[i];
    n = cnt;
    sort(w,w+n);
    n = min(n,m);
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (v[i]-w[i]>0) sum += v[i]-w[i];
    }

    score = max(score, sum);

    cout<<score<<endl;


    return 0;

}
