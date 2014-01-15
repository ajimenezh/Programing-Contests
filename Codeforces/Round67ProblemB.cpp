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

map<string,int> p;
string s;
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    cin>>n;
    string str;
    getline(cin,str);
    for (int i=0; i<n; i++) {
        getline(cin,str);
        stringstream ss(str);
        string name1;
        ss>>name1;
        string type;
        ss>>type;
        int c = 0;
        if (type[0]=='p') c = 15;
        if (type[0]=='c') c = 10;
        if (type[0]=='l') c = 5;
        string name2;
        ss>>name2;
        if (type[0]!='l') ss>>name2;
        name2 = name2.substr(0,name2.length()-2);
        if (name1!=s) p[name1] += 0;
        if (name2!=s) p[name2] += 0;
        if (name1==s && name2!=s) p[name2] += c;
        if (name2==s && name1!=s) p[name1] += c;
    }

    vector<pair<int,string> > v;
    rep(it, p) v.push_back(make_pair(-(*it).second, (*it).first));
    sort(v.begin(),v.end());
    for (int i=0; i<v.size(); i++) cout<<v[i].second<<"\n";

    return 0;

}
