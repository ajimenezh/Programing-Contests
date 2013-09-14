#include <algorithm>
#include <stdio.h>
#include <queue>
#include <math.h>

using namespace std;

int n;
priority_queue<unsigned int> q;
unsigned int a;
int i;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&n);
    for (i=0; i<(n/2)+1; i++) {
        scanf("%d",&a);
        q.push(a);
    }
    for(;i<n; i++) {
        scanf("%d",&a);
        q.push(a);
        q.pop();
    }
    a = q.top();
    q.pop();
    if (n%2==0) {
        if ((a+q.top())%2==0) {
            printf("%d.0\n",(a+q.top())/2);
        }
        else {
            printf("%d.5\n",(a+q.top())/2);
        }
    }
    else printf("%d.0\n",a);

    return 0;

}
