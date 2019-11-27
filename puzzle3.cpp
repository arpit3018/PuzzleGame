#include<bits/stdc++.h>
using namespace std;

int main() {
	int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int delX = abs(x1-x2);
    int delY = abs(y1-y2);
    int steps = max(delX,delY);
    float Xinc = (float)delX/steps;
    float Yinc = (float)delY/steps;

    float x = x1,y = y1;
    int plottingX = x1, plottingY = y1;
    while(x != x2 || y != y2) {
        x += Xinc;
        y += Yinc;
        plottingX = round(x);
        plottingY = round(y);
    }
}
