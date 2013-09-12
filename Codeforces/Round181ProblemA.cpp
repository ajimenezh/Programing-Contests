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

int n;
vector<int> v1,v2,v3;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        cin>>a;
        if (a==0) v3.push_back(0);
        else if (a<0 && v1.size()==0) v1.push_back(a);
        else v2.push_back(a);
    }

    int p = 1;
    bool is = 0;
    for (int i=0; i<v2.size(); i++) p *= v2[i]/abs(v2[i]);
    if (p<0) {
        is = 1;
        for (int i=0; i<v2.size(); i++) {
            if (v2[i]<0) {
                v3.push_back(v2[i]);
                break;
            }
        }
    }

    cout<<v1.size()<<" ";
    for (int i=0; i<v1.size(); i++) cout<<v1[i]<<" "; cout<<endl;
    cout<<v2.size()-is<<" ";
    for (int i=0; i<v2.size(); i++) {
        if (v2[i]<0 && is) is = 0;
        else cout<<v2[i]<<" ";
    }
    cout<<endl;
    cout<<v3.size()<<" ";
    for (int i=0; i<v3.size(); i++) cout<<v3[i]<<" "; cout<<endl;

    return 0;

}
