#include<iostream>
using namespace std;
#define MaxInt 32767//极大值
#define MvNum 100//最大顶点数
typedef struct
{
    char vexs[MvNum];
    int arcs[MvNum][MvNum];
    int vexnum,arcnum;
} AMGraph;
typedef struct
{
    int front1;
    int rear;
    int que[2][MvNum*MvNum];
    void queueempty()
    {
        front1=rear=0;
        for(int i=0; i<=MvNum*MvNum; i++)
        {
            que[0][i]=-1;
            que[1][i]=-1;
        }
    }
    int judge()
    {
        if(rear==front1)
            return 0;//queue空
        else if(rear==MvNum*MvNum)
            return 1;//queue满
        else
            return -1;//queue可用
    }
    int getrear()
    {
        if(judge()!=0)
            return que[0][rear-1];
        else
            return -1;//no
    }
    int enqueue(int k)
    {
        if(judge()!=1)
        {
            que[0][rear]=k;
            rear++;
            return 1;
        }//ok;}
        else
            return -1;//no
    }
    int dequeue()
    {
        if(judge()!=0)
        {
            front1++;
            return que[0][front1-1];
        }
        else
            return -1;//no
    }

} queue1;
int locate(AMGraph G,char v)
{
    int i=0;
    for(i=0; i<G.vexnum; i++)
        if(G.vexs[i]==v)
            return i;
}
void creatUDN(AMGraph &G)
{
    int i,j;
    char v1,v2;
    cout<<"输入图的的顶点数和边数"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"输入图的顶点集"<<endl;
    for(i=0; i<=G.vexnum-1; i++)
        cin>>G.vexs[i];
    for(i=0; i<=G.vexnum-1; i++)
        for(j=0; j<=G.vexnum-1; j++)
            if(i==j)
                G.arcs[i][j]=1;
            else
                G.arcs[i][j]=0;
    cout<<"输入路径"<<endl;
    for(i=0; i<=G.arcnum-1; i++)
    {
        cin>>v1>>v2;
        G.arcs[locate(G,v1)][locate(G,v2)]=1;
    }
    cout<<"输入完毕"<<endl;
}
void printUDN(AMGraph &G)
{
    int i,j;
    cout<<"打印矩阵"<<endl;
    for(i=0; i<=G.vexnum-1; i++)
        cout<<G.vexs[i]<<' ';
    cout<<endl;
    for(i=0; i<=G.vexnum-1; i++)
    {
        for(j=0; j<=G.vexnum-1; j++)
            cout<<G.arcs[i][j];
        cout<<endl;
    }
    for(i=0; i<=G.vexnum-1; i++)
        for(j=0; j<=G.vexnum-1; j++)
            if(G.arcs[i][j]==1&&i!=j)
                cout<<G.vexs[i]<<' '<<G.vexs[j]<<endl;

}
void BFS(AMGraph G,queue1 &q,int visited[],int v1,int v3,int n)
{
    int v2,front2;
    q.enqueue(v1);
    visited[v1]=1;
    while(q.judge()!=0)
    {
        v1=q.dequeue();
        front2=v1;
        for(v2=0;v2<=n-1;v2++)
            if((G.arcs[v1][v2]==1)&&(visited[v2]!=1))
        {
            visited[v2]=1;
            q.enqueue(v2);
            q.que[1][q.rear-1]=front2;//回溯;
             if(v2==v3)
              return ;
        }
    }
}
main()
{
    AMGraph G;
    creatUDN(G);
    printUDN(G);
    int step[G.vexnum],n=0;
    int visited[G.vexnum],i,j;
    for(i=0; i<=G.vexnum-1; i++)
        visited[i]=0;
    char v1,v3;
    queue1 q;
    q.queueempty();
    cout<<"输入起点和终点"<<endl;
    cin>>v1>>v3;
    i=locate(G,v1);
    j=locate(G,v3);
    BFS(G,q,visited,i,j,G.vexnum);
    q.rear=q.rear-1;
    i=0;
    while(q.rear!=-1)
    {
        step[i]=q.que[0][q.rear];
        i++;
        n++;
        q.rear=q.que[1][q.rear];
    }
    cout<<G.vexs[step[n-1]];
    for(i=n-2; i>=0; i--)
    {
        cout<<"->";
        cout<<G.vexs[step[i]];
    }
}
