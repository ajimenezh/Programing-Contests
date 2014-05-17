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

int n,b;
int a[110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>b;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    int sum = b;
    for (int i=0; i<n; i++) sum += a[i];

    double c = (double)sum / n;

    vector<double> res;
    for (int i=0; i<n; i++) {
        if ((double)a[i]>c+1.0e-6) {
            cout<<-1<<endl;
            return 0;
        }
        res.push_back(c-a[i]);
    }

    for (int i=0; i<n; i++) printf("%.12lf\n", res[i]);

    return 0;

}
