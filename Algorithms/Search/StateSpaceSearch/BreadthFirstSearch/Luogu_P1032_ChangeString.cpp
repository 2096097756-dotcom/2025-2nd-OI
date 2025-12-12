#include<bits/stdc++.h>
using namespace std;
const int MAXN=10;

string prev_str,target_str;
struct CHANGE{
    string prev,target;
}Change,change_string[MAXN];
int cnt,ans;
map<string,int> dist;//超级数组？可以用任意下标的数组,下标类型+数组类型

int bfs(){
    queue<string> new_str;
    new_str.push(prev_str);
    dist[prev_str]=1;
    while(!new_str.empty()){
        string vector_str=new_str.front();
        new_str.pop();
        if(dist[vector_str]>11) continue;


        for(int i=0;i<cnt;i++){
            size_t pos=vector_str.find(change_string[i].prev);
            while(pos!=std::string::npos){//返回下标!
                string latest_string=vector_str.substr(0,pos)+change_string[i].target+vector_str.substr(pos+change_string[i].prev.length());//之前的所有pos，起始下标！+.length正好完成!
                if(dist[latest_string]==0){//没有被访问过
                    
                    dist[latest_string]=dist[vector_str]+1;//防止dist[latest_string]变回去,记录步长！然后注意：这里应当是上一步+1！，不需要一个专门的cnt
                    int level=dist[latest_string]-1;
                    if(level>10) continue;
                    if(latest_string==target_str){
                        return level;
                    }
                    new_str.
                    push(latest_string);

                }
                pos=vector_str.find(change_string[i].prev,pos+1);//从下一个下标开始找;
                //写在外面！因为如果被访问过，那么就一直为真导致循环
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>prev_str>>target_str;
    while(cin>>change_string[cnt].prev>>change_string[cnt].target) cnt++;
    
    ans=bfs();
    if(ans==-1) cout<<"NO ANSWER!"<<endl;
    else cout<<ans<<endl;

    return 0;
}