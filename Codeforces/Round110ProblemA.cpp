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


int main() {

    string s1,s2;
    cin>>s1>>s2;
    string s = s1;

    for (int i=0; i<=s2.length(); i++) s = '#' + s;
    for (int i=0; i<=s2.length(); i++) s = s + '#';

    int n = 10000;
    for (int i=0; i<s.length()-s2.length(); i++)
    {
        int c = 0;
        for (int j=0; j<s2.length(); j++) if (s[i+j]!=s2[j]) c++;
        n = min(n,c);
    }

    cout<<n<<endl;


	return 0;

}
