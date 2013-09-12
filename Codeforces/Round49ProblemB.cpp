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

int h,w;
long long area;
int hf;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>h>>w;
    double t1 = 1.0/0.8;
    double t2 = 1.25;
    area = 0;
    hf = 0;

    for (int i=0; i<30; i++) {
        if ((1<<i)<=h) {
            int tmp = 1.0*(1<<i)*t1;
            tmp = min(tmp,w);
            if (1.0*(1<<i)>t2*tmp) continue;
            if ((long long)tmp*(1LL<<i)>=area) {
                area = (long long)tmp*(1LL<<i);
                hf = max(hf,1<<i);
            }
        }
        if ((1<<i)<=w) {
            int tmp = 1.0*(1<<i)*t2;
            tmp = min(tmp,h);
            if (1.0*(1<<i)>t1*tmp) continue;
            if ((long long)tmp*(1LL<<i)>=area) {
                area = (long long)tmp*(1LL<<i);
                hf = max(hf,tmp);
            }
        }
    }

    cout<<hf<<" "<<area/hf<<endl;

    return 0;

}
