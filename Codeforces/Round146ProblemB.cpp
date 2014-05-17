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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
double p[100010];

double expe[100010];


int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>p[i];

    expe[0] = 0;

    double sol = 0.0;

    for (int i=0; i<n; i++) {
        sol += p[i]*(2*expe[i] + 1.0);
        expe[i+1] = (expe[i]+1.0)*p[i];
        //cout<<sol<<" "<<expe[i+1]<<endl;;
    }

    printf("%.8f",sol);


	return 0;

}
