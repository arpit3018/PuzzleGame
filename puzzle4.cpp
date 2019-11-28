#include<bits/stdc++.h>
using namespace std;

vector<int> func(int dx, int dy, int x, int y, int Pk) {
    if(Pk >= 0) 
    {
        Pk = Pk + 2*dy - 2*dx;
        x += 1;
        y += 1;
    } 
    else {
        Pk = Pk + 2*dy;
        x += 1;
    }
    vector<int> ret = {x,y,Pk};
    return ret;
}


int main() {
	int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int dx = abs(x1-x2);
    int dy = abs(y1-y2);
    float m = (float)dy/dx;
    int x,y,Pk;
    
    x = x1;
    y = y1;
    
    if(m < 1) {
        Pk = 2*dy - dx;
        while(x != x2 || y!= y2 ) {
            vector<int> ot = func(dx,dy,x,y,Pk); 
            x = ot[0];
            y = ot[1];
            Pk = ot[2];
        }
       
    }
    else {
        Pk = 2*dx- dy;
        while(x != x2 || y!= y2 ) {
            vector<int> ot = func(dy,dx,y,x,Pk); 
            y = ot[0];
            x = ot[1];
            Pk = ot[2];
        }
    }
}
