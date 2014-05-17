#include <algorithm>
#include <stdio.h>

using namespace std;

pair<long long,int> v[50010];
int n,m;
char id[50010][35];

int main() {

    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        long long val;
        scanf("%lld",&val);
        v[i] = make_pair(-(long long)(i+1)*val,i);
        scanf("%s",&id[i]);
    }
    sort(v,v+n);
    for (int i=0; i<m; i++) {
        printf("%s\n",id[v[i].second]);
    }

    return 0;

}
