#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

int n,m;
int c[110];
pair<int,int> w[110];
vector<int> v;

int main() {

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        int t;
        scanf("%d",&t);
        c[t-1] += 2;
    }
    for (int i=0; i<m; i++) w[i] = make_pair(c[i],i);
    sort(w, w+m);
    reverse(w, w+m);

    if (w[0].first>n) {
        cout<<n-(w[0].first-n)<<endl;
        for (int i=0; i<(w[0].first-n); i++) cout<<w[0].second+1<<" "<<w[0].second+1<<"\n";
        w[0].first -= 2*(w[0].first-n);
    }
    else cout<<n<<endl;
    for (int i=0; i<m; i++) for (int j=0; j<w[i].first; j++) v.push_back(w[i].second);

    for (int i=0; i<v.size()/2; i++) {
        if (i%2==0) cout<<v[i]+1<<" "<<v[v.size()/2+i]+1<<"\n";
        else cout<<v[v.size()/2+i]+1<<" "<<v[i]+1<<"\n";
    }

	return 0;
}
