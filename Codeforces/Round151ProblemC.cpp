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

int n,k;
int a[51];
set<int> s;
map<int, vector<int> > m;

int main() {

    cin>>n>>k;
    fo(i,n) cin>>a[i];

    int c = 0;
    for (int i=0; i<n; i++)
    {
        if (c>=k) break;
        set<int> s2;
        for (set<int>::iterator it = s.begin(); it!=s.end(); it++)
        {
            if (c>=k) break;
            if (s.find(*it+a[i])==s.end() && s2.find(*it+a[i])==s2.end())
            {
                cout<<m[*it].size()+1<<" "<<a[i]<<" ";
                for (int j=0; j<m[*it].size(); j++) cout<<m[*it][j]<<" ";
                cout<<endl;
                s2.insert(*it+a[i]);
                m[*it+a[i]] = m[*it];
                m[*it+a[i]].push_back(a[i]);
                c++;
            }
        }

        for (set<int>::iterator it = s2.begin(); it!=s2.end(); it++) s.insert(*it);

        if (s.find(a[i])==s.end() && c<k)
        {
            cout<<1<<" "<<a[i]<<endl;
            s.insert(a[i]);
            m[a[i]] = vector<int> (0,0);
            m[a[i]].push_back(a[i]);
            c++;
        }

    }


	return 0;

}
