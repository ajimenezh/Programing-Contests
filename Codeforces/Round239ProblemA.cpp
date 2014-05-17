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

int a, b;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b;

    set<int> all;
    for (int i=0; i<1000; i++) all.insert(i*i);
    double eps = 1.0e-6;

    for (int x = a; x>=-a; x--) {
        int y = a*a - x*x;
        if (x==0) continue;
        if (all.find(y)!=all.end()) {
            y = sqrt(y);
            if (y==0) continue;

            double t = atan2(y,x);
            double xx = b*cos(t+acos(-1.0)/2);
            double yy = b*sin(t+acos(-1.0)/2);

            //cout<<xx<<" "<<yy<<endl;

            if (abs(xx-round(xx))<eps) {
                if (abs(yy-round(yy))<eps) {
                    if (abs(yy-y)<eps || abs(xx-x)<eps) continue;
                    else {
                        cout<<"YES"<<endl;
                        cout<<"0 0"<<endl;
                        cout<<x<<" "<<y<<endl;
                        cout<<(int)(xx*1.000001)<<" "<<(int)(yy*1.000001)<<endl;
                        return 0;
                    }
                }
                else continue;
            }
            else continue;

        }
    }

    cout<<"NO"<<endl;

    return 0;

}
