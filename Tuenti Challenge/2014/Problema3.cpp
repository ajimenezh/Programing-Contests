#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h> 
#include <set>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	
	//freopen("students.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  for (int i=0; i<t; i++) {
		int a,b;
		cin>>a>>b;
		
		double c = sqrt(a*a + b*b);
		
		int d = (int) round(c*100 + 1.0e-8);
		
		if (d%100==0) {
			cout<<d/100<<"\n";
		}
		else printf("%.2lf\n", c);
	}
	
	return 0;
    
}
