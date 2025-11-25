/*
【问题描述】

假定平面坐标系有若干(≥2)个点，编写程序实现由若干个点构成的几何图形的平移、缩放、旋转，用坐标值的变化来表征。

【编程要求】

(1) 在《实验指导书》P155综合练习3代码基础上完成；

(2) 用如下结构体类型表征平面坐标系中点的坐标：


    struct point {

        double x;

        double y;

    };

(3) 定义三个函数实现图形操作功能，函数原型及参数说明如下：


    void translation(struct point pt[], double tl_x, double tl_y, int num);

    void scale(struct point pt[], double s_x, double s_y, int num);

    void rotation(struct point pt[], double angle, int num);

     其中，pt表示各点的坐标；tl_x, tl_y分别表示横纵方向的平移位移；s_x, s_y分别表示横纵方向的缩放比例；angel表示旋转角度；num表示点的个数。


【输入输出形式】

输入点的个数、各点的坐标、操作功能选择项、对应功能项的相关参数；输出各点变化后的坐标。

具体格式参考样例输入输出。

【样例输入输出】

说明：红色字体为输入，其他为输出。


请输入坐标个数(>=2)：3
请输入【第1个】点的横x、纵y坐标：1 1
请输入【第2个】点的横x、纵y坐标：2 2
请输入【第3个】点的横x、纵y坐标：3 3
请选择处理方式：平移(t)、缩放(s)、旋转(r)：t
请输入水平及垂直的平移量：2 3
经过【平移】处理后，坐标值如下：
3.000000 4.000000
4.000000 5.000000
5.000000 6.000000
*/
#include<stdio.h>
#include<math.h>

#define MAXN 100001
#define pi 3.1415926
struct POINT{
    double x;
    double y;
}point[MAXN];
int n;

void clear_buffer(){
    char c;
    while((c=getchar())!='\n'&&c!=EOF);
}

void translation(struct POINT point[],double tl_x,double tl_y,int num){
    for(int i=0;i<num;i++){
        point[i].x+=tl_x;
        point[i].y+=tl_y;
    }
}

void scale(struct POINT point[],double s_x,double s_y,int num){
    for(int i=0;i<num;i++){
        point[i].x*=s_x;
        point[i].y*=s_y;
    }
}

void rotation(struct POINT point[],double angle,int num){
    double rad=angle/180.0*pi;
    for(int i=0;i<num;i++){
        double old_x=point[i].x;
        double old_y=point[i].y;
        point[i].x=old_x*cos(rad)-old_y*sin(rad);
        point[i].y=old_x*sin(rad)+old_y*cos(rad);
    }
}

void print(){
    
    do{
        printf("请输入坐标个数(>=2)：");
        scanf("%d",&n);
    }while(n<2);
    
    for(int i=0;i<n;i++){
        printf("请输入【第%d个】点的横x、纵y坐标：",i+1);
        scanf("%lf%lf",&point[i].x,&point[i].y);//检查缓冲区!
    }

    char op;
    do{
        getchar();
        printf("请选择处理方式：平移(t)、缩放(s)、旋转(r)：");
        scanf("%c",&op);
    }while(op!='t'&&op!='s'&&op!='r');

    if(op=='t'){
        double x1,y1;
        printf("请输入水平及垂直的平移量：");
        scanf("%lf%lf",&x1,&y1);
        translation(point,x1,y1,n);

        printf("经过【平移】处理后，坐标值如下：\n");
        for(int i=0;i<n;i++){
            printf("%lf %lf\n",point[i].x,point[i].y);
        }
    }

    else if(op=='s'){
        double s_x,s_y;
        printf("请输入水平及垂直的缩放比例：");
        scanf("%lf%lf",&s_x,&s_y);
        scale(point,s_x,s_y,n);
        
        printf("经过【缩放】处理后，坐标值如下：\n");
        for(int i=0;i<n;i++){
            printf("%lf %lf\n",point[i].x,point[i].y);
        }
    }

    else if(op=='r'){
        double angle;
        printf("请输入旋转角度：");
        scanf("%lf",&angle);

        rotation(point,angle,n);
        printf("经过【旋转】处理后，坐标值如下：\n");
        for(int i=0;i<n;i++){
            printf("%lf %lf\n",point[i].x,point[i].y);
        }
    }

}

int main(){
    print();
    return 0;
}