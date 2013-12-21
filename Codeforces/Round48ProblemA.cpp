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
set<vector<int> > all;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        string s1,s2,s3;
        cin>>s1>>s2;
        if (i!=n-1) cin>>s3;
        vector<int> v1,v2,v3,v4;
        v1.push_back(s1[0]-'0');
        v1.push_back(s1[1]-'0');
        v1.push_back(s2[1]-'0');
        v1.push_back(s2[0]-'0');

        v2.push_back(s1[1]-'0');
        v2.push_back(s2[1]-'0');
        v2.push_back(s2[0]-'0');
        v2.push_back(s1[0]-'0');

        v3.push_back(s2[1]-'0');
        v3.push_back(s2[0]-'0');
        v3.push_back(s1[0]-'0');
        v3.push_back(s1[1]-'0');

        v4.push_back(s2[0]-'0');
        v4.push_back(s1[0]-'0');
        v4.push_back(s1[1]-'0');
        v4.push_back(s2[1]-'0');

        all.insert(min(min(v1,v2),min(v3,v4)));
    }

    cout<<all.size();


    return 0;

}
