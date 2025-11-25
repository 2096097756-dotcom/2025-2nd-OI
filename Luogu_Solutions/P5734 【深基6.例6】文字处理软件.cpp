#include<iostream>
#include<string>
using namespace std;
string str_now;
int main(){
	int n;
	cin>>n;
	cin>>str_now;
	for(int i=0;i<n;i++){
		int a;
		string inp;
		cin>>a;
		/*while(ss>>token){
			parts[num]=token;
			num++;
		}*/
		if(a==1){
			cin>>inp;
			str_now=str_now+inp;
			cout<<str_now<<endl;
		}
		else if(a==2){
			int c,d;
			cin>>c>>d; 
            str_now=str_now.substr(c,d);
            cout<<str_now<<endl;
		}
		else if(a==3){
			int e;
			cin>>e;
			cin>>inp;
			str_now.insert(e,inp);//^^^
			cout<<str_now<<endl;
		}
		else if(a==4){
			string inp;
			cin>>inp;
			int pos=str_now.find(inp);
			cout<<pos<<endl;
		}
	}
	return 0;
}