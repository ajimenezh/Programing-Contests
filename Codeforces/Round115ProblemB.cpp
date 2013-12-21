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

int n;
map<string,int> tot;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        string s;
        int p;
        cin>>s>>p;
        tot[s] = max(tot[s],p);
    }
    int k = 0;
    cout<<tot.size()<<endl;
    n = tot.size();
    vector<pair<int,string> > v;
    rep(it,tot) v.push_back(make_pair((*it).second, (*it).first));
    sort(v.begin(),v.end());
    int i = 0;
    while (i<n) {
        int j = i;
        while (j<n && v[j].first==v[i].first) {
            k++;
            j++;
        }
        string str;
        if (k*100<50*n) str = "noob";
        else if (k*100<80*n) str = "random";
        else if (k*100<90*n) str = "average";
        else if (k*100<99*n) str = "hardcore";
        else str = "pro";

        while (i!=j) {
            cout<<v[i].second<<" "<<str<<"\n";
            i++;
        }
    }

    return 0;

}
