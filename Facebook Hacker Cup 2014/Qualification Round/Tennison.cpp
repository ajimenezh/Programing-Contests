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

int K;
double ps, pr, pi, pu, pw, pd, pl;
double p[250][2]; //probabilty of sun with i wins on day t;
double s[250][2];
double r[250][2];
int m;

double approximate() {
    vector<int> moves;
    int sum = 0;

    m++;

    while (sum<K) {
        int t = rand()%2;
        t = 1;
        moves.push_back(t);
        if (t) sum++;
    }

    double ss = pi;
    double pp = 1.0;

    for (int i=0; i<moves.size(); i++) {
        if (moves[i]) {
            pp = pp*(ss*ps + (1.0-ss)*pr);
            ss += pw*pu;
        }
        else {
            pp = pp*(ss*(1.0-ps) + (1.0-ss)*(1.0-pr));
            ss -= pd*pl;
        }
        if (ss>1.0) ss = 1.0;
        if (ss<0.0) ss = 0.0;
    }
    cout<<moves.size()<<" "<<pp<<endl;
    return pp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int maxCases;
    cin>>maxCases;
    for (int cas=1; cas<=maxCases; cas++) {
        cin>>K>>ps>>pr>>pi>>pu>>pw>>pd>>pl;

        for (int j=0; j<=5; j++) {
            p[j][1] = 0.0;
        }

        s[0][0] = pi;
        p[0][0] = 1.0;

        double ans = 0;
        for (int day = 1; day<=2*K; day++) {
            for (int j=0; j<=day; j++) {
                p[j][day%2] = 0.0;
                s[j][day%2] = 0.0;
            }

            for (int j=0; j<min(day,K); j++) {
                p[j+1][day%2] += p[j][1-day%2]*ps*s[j][1-day%2];
                p[j][day%2] += p[j][1-day%2]*(1.0-ps)*s[j][1-day%2];
                p[j+1][day%2] += p[j][1-day%2]*pr*(1.0-s[j][1-day%2]);
                p[j][day%2] += p[j][1-day%2]*(1.0-pr)*(1.0-s[j][1-day%2]);

                s[j+1][day%2] += (p[j][1-day%2]*ps*s[j][1-day%2] + p[j][1-day%2]*pr*(1.0-s[j][1-day%2]))*(s[j][1-day%2] + pw*pu);
                s[j][day%2] += (p[j][1-day%2]*(1.0-ps)*s[j][1-day%2]+p[j][1-day%2]*(1.0-pr)*(1.0-s[j][1-day%2]))*(s[j][1-day%2] - pd*pl);

            }

            for (int j=0; j<=min(day,K); j++) {
                //cout<<p[j][day%2]<<endl;;
                if (j>=K && (day-j)<K) {
                    ans += p[j][day%2];
                    //cout<<p[j][day%2]<<endl;;
                }
                s[j][day%2] = min(1.0, s[j][day%2]);
                s[j][day%2] = max(0.0, s[j][day%2]);
            }
        }

        printf("Case #%d: %.6f\n",cas, ans);

        m = 0;
        ans = 0.0;
        //for (int i=0; i<10; i++) ans += approximate();
        //ans /= m;

        //printf("Case #%d: %.6f\n",cas, ans);
    }

    return 0;

}
