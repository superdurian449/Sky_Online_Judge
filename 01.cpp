#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int d1,d2;
	int count = 0;
	int repeat_flag = 0;
	char tmp;
	string input;
	map<int,int>ans;
	map<int,int>dividend;
	map<int,int>::iterator iter;
	
	while(getline(cin,input)){
		stringstream ss(input);
		ss>>d1;
		ss>>tmp;
		ss>>d2;
		
		if(d1 == 0){
			cout << "0" << endl;
			continue;
		}
		if(d1 > 0 && d2 < 0){
			d2 = -d2;
			cout << "-";
		}
		else if(d1 < 0 && d2 > 0){
			d1 = -d1;
			cout << "-";
		}
		else if(d1 < 0 && d2 < 0){
			d1 = -d1;
			d2 = -d2;
		}
		
		if(d1 > d2){
			cout << d1/d2;
			d1 =  d1%d2;
			if(d1 == 0){
				cout << endl;
				continue;
			}
		}
		else{
			cout << "0";
		}
		
		do{
			dividend.insert(pair<int,int>(d1,count));
			ans.insert(pair<int,int>(count++,(d1 * 10)/ d2));
			d1 = (d1 * 10) % d2;
			if(d1 == 0){
				repeat_flag = 1;
				break;
			}
			iter = dividend.find(d1);
		}
		while(iter == dividend.end());
		
		cout << ".";
		for(int i = 0; i < count ; i++){
			if(i == dividend[d1] && !repeat_flag){
				cout << "(";
			}
			cout << ans[i];
		}
		if(!repeat_flag){
			cout << ")";
		}
		cout << endl;
		repeat_flag = 0;
		dividend.clear();
		ans.clear();
		count = 0;
	}
	return 0;
}
