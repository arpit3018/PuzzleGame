#include<bits/stdc++.h>
using namespace std;

struct node {
 string data;
 struct node *left;
 struct node *right;
 int freq;
};
string getMagic(struct node* Node, string key, string som) 
{ 
    if (Node == NULL) 
        return ""; 
  
    if (Node->data == key) 
        return som; 
 
    string res1 = getMagic(Node->left, key, som+"0");   
    string res2 = getMagic(Node->right, key,som+"1"); 
  	
    if(res1 == "")
	return res2;
    else return res1;
} 

node * createNode(string data, node* l, node* r, int freq){
	node* temp = new node();
	temp->data = data;
	temp->freq = freq;
	temp->left = l;
	temp->right = r;
	return temp;
}

int main() {
	vector< pair <int,string> > val;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string a;
		int b;
		cin>>a>>b;
		val.push_back({b,a});	
	}
	sort(val.begin(),val.end());
	int i = 0;
	node * l = NULL;
	node * r = NULL;
	vector<node*> res;
	for(auto t:val){
		node * temp = createNode(t.second,NULL,NULL,t.first);
		res.push_back(temp);	
	}
	int jj = res.size();

	while(jj!=1){
		node * temp = createNode("X",res[i],res[i+1],res[i]->freq + res[i+1]->freq);

		res.erase(res.begin());
		res.erase(res.begin());
		int k = 0;
		int flag = 0;
		for(auto my : res) {
			if(my->freq > temp->freq)
			{
				res.insert(res.begin()+k, temp);
				flag = 1;
				break;
			}
		k++;		
		}	
		if(flag == 0) res.push_back(temp);		
		jj = res.size();
	}
	node * root = res[0];
	vector< pair <int,string> > ans = val;
	string som = ""; 
	for(auto vall : ans)
	cout<<vall.second<<" "<<getMagic(root,vall.second,som)<<endl;
}
