#include <iostream>

using namespace std;

int main() {

    int n;
    cin>>n;
    if (n%3==0) cout<<2*(n/3)<<endl;
    else if (n%3==1) cout<<2*((n-1)/3)<<endl;
    else cout<<2*((n-2)/3)+1<<endl;

    return 0;

}
