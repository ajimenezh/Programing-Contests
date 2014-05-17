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

vector<vector<int> > v;
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    vector<int> tmp;
    tmp.push_back(1);

    v.push_back(tmp);
    v.push_back(tmp);
    n--;
    int k = 2;
    while(true) {
        if (n>=v.size()) {
            n-=v.size();
            int t = k;
            for (int i=0; i<v.size(); i++) {
                v[i].push_back(t++);
            }
            tmp.clear();
            for (int j=k; j<t; j++) {
                tmp.push_back(j);
            }
            k = t;
            v.push_back(tmp);
        }
        else break;
     }

     cout<<v.size()<<endl;
     for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size(); j++) cout<<v[i][j]<<" "; cout<<endl;
     }


    return 0;

}
