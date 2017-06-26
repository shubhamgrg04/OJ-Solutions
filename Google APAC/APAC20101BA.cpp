#include <iostream>
#include <vector>
#include <stdlib.h>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}

struct Dir {
	string dirname;
	vector<struct Dir *> children;
};

struct Dir *createDir(string dirname){
	struct Dir *newdir = new Dir();
	newdir->dirname = dirname;
	return newdir;
}

int addtotree(string path, struct Dir *root){
	int commands = 0;
	string dirname;
	for(int i=1; i<path.size(); i++){
		if(path[i]!='/' && i!=path.size()-1)
			dirname.push_back(path[i]);
		else {
			if(i==path.size()-1) 
				dirname.push_back(path[i]);
			bool exist = false;
			for(int j=0; j<root->children.size(); j++){
				struct Dir *current = root->children[j];
				if(dirname.compare(current->dirname)==0) {
					root = current;
					exist = true;
					break;
				}
			}
			if(!exist) {
				struct Dir *newdir = createDir(dirname);
				root->children.push_back(newdir);
				root = newdir;
				commands++;
			}
			dirname.clear();
		}
	}
	return commands;
}

int main(){
	ios::sync_with_stdio(false);
	int t = in();
	for(int a=1; a<=t; a++){
		int n=in(), m=in(), ans = 0;
		struct Dir *root = createDir("");
		for(int i=0; i<n; i++) {
			string path;
			cin >> path;
			addtotree(path, root);
		}
		for(int i=0; i<m; i++){
			string path;
			cin >> path;
			ans += addtotree(path, root);
		}
		cout << "Case #" << a << ": " << ans << "\n";
	}
	return 0;
}