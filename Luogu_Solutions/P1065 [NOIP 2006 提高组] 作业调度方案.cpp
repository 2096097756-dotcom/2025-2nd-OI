#include<bits/stdc++.h>
using namespace std;
struct item{
    int machine;
    int time;
}Item[25][25];
bool timeline_machine[25][10005];
int last_end_time[25];
int num[25];
int order[405];
int main(){
    memset(timeline_machine,1,sizeof(timeline_machine));
    memset(last_end_time,0,sizeof(last_end_time));
    memset(num,0,sizeof(num));
    int n,m;
    cin>>m>>n;
    for(int i=0;i<m*n;i++){
        cin>>order[i];
        order[i]--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Item[i][j].machine;
            Item[i][j].machine--;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Item[i][j].time;
        }
    }
    int max_finish_time=0;
    for(int i=0;i<m*n;i++){
        int spare_now=order[i];
        int step_now=num[spare_now];
        int machine_now=Item[spare_now][step_now].machine;
        int time_now=Item[spare_now][step_now].time;
        num[spare_now]++;
        int earliest_start=last_end_time[spare_now]+1;
        for(int start_time=earliest_start;;start_time++){//至少从允许的工件的第k-1步之后搜索，这也就避免了同一个零件时间线上的重叠！ 
            bool can_assign=true;
            if(start_time+time_now-1>10000)break;
            for(int t=start_time;t<start_time+time_now;t++){
                if(!timeline_machine[machine_now][t]){
                    can_assign=false;
                    break;
                }
            }
            if(can_assign){
                for(int t=start_time;t<start_time+time_now;t++){
                    timeline_machine[machine_now][t]=false;
                }
                last_end_time[spare_now]=start_time+time_now-1;
                max_finish_time=max(max_finish_time,last_end_time[spare_now]);
                break;
            }
        }
    }
    cout<<max_finish_time<<endl;
    return 0;
}//原来的代码没有判断“后一个工件必须在前一个弓箭被加工之后”
/*
比方讲：A:0 0 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 0(X工件的第一步）
        B:1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 (x工件的第二step，自动占用前面的项数）
*/
/*
#include<bits/stdc++.h>
using namespace std;
struct item{
	int machine;
	int time;
}Item[1000][1000];
bool timeline_machine[1000][10001];//机器,时间
bool timeline_spare[1000][10001];//工件时间轴
int time_maxm_machine[1000];//机器最大工作时间
int num[1000];
int order[1000];
bool judge(int spare_now,int time_first,int time_now){
	for(int t=time_first;t<=time_first+time_now-1;t++){
		if(timeline_spare[spare_now][t]==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	memset(timeline_machine,1,sizeof(timeline_machine));//0为边界
	memset(timeline_spare,1,sizeof(timeline_spare));
	memset(time_maxm_machine,0,sizeof(time_maxm_machine));
	memset(num,0,sizeof(num));
	int n,m;//n个零件，m个机器，m个工序
	cin>>m>>n;
	for(int i=0;i<m*n;i++){
		cin>>order[i];
		order[i]--;
	}
	for(int i=0;i<n;i++){//i零件
		for(int j=0;j<m;j++){//j号工序
			cin>>Item[i][j].machine;
			Item[i][j].machine--;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>Item[i][j].time;
		}
	}
	cout<<endl;
	for(int i=0;i<m*n;i++){//整个order
		int spare_now=order[i];
		int machine_now=Item[order[i]][num[order[i]]].machine;
		int time_now=Item[order[i]][num[order[i]]].time;//num[order[i]]从0开始！搞清楚下标！
		num[order[i]]++;//(同步处理目标零件当前是第几步)
		//cout<<machine_now<<' '<<time_now<<endl;
		bool flag=0;
		int cnt=0,time_first=0;
		for(int j=1;j<=10000;j++){//一直在搜索插入时间点
			if(timeline_machine[machine_now][j]==1&&flag==0){
				flag=1;
				time_first=j;
			}
			if(timeline_machine[machine_now][j]==0){
				flag=0;
				cnt=0;/*确保清零？
			}
			if(flag==1){
				cnt++;
			}else{
				cnt=0;
			}
			if(cnt>=time_now){
				if(judge(spare_now,time_first,time_now)){
					for(int t=time_first;t<=time_first+time_now-1;t++){
						timeline_machine[machine_now][t]=0;
						timeline_spare[spare_now][t]=0;
					}
					time_maxm_machine[machine_now]=max(time_maxm_machine[machine_now],time_first+time_now-1);
					cout<<time_maxm_machine[machine_now]<<endl;
					break;
				}
			}
		}
	}
	int maxm_time=1;
	for(int i=0;i<m;i++){
		maxm_time=max(maxm_time,time_maxm_machine[i]);//机器视角的时间最大值
	}
	cout<<maxm_time<<endl;
	return 0;
}*/
