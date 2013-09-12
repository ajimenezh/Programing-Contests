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

string s;
pair<string,pair<int,int> > v[11];
int n;
int c[2001][2001][10];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    cin>>n;

    for (int i=0; i<n; i++) {
        string tmp;
        int l,r;
        cin>>tmp>>l>>r;
        v[i] = make_pair(tmp,make_pair(l,r));
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<v[i].first.length(); j++) {
            int last = 0;
        }
    }

    cout<<res<<endl;


    return 0;

}
