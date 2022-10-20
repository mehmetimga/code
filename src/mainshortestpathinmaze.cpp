//Shortest path in a Binary Maze

#include <iostream>
#include <queue>
using namespace std;
#define COL 10
#define ROW 9

struct Point 
{
    int x;
    int y;
};

struct Node
{
    Point p;
    int dist;
};
int yarr[]={1,0,-1,0};
int xarr[]={0,1,0,-1};
bool isValid(int x, int y){
    if (x>=0 && y>=0 && x<ROW && y<COL )
        return true;
    else   
        return false;
}

int BFS(int mat[][COL],Point src, Point dest)
{
    queue<Node> q;
    Node ntemp={src,0};

    bool visited[ROW][COL];
    memset(visited,0,sizeof(visited));

    q.push(ntemp);
    while(!q.empty())
    {
        Node n=q.front();
        q.pop();
        visited[n.p.x][n.p.y]=1;
        if (n.p.x==dest.x && n.p.y== dest.y)
            return n.dist;

        for(int i=0;i<4;++i)
        {
            Point p;
            p.x=n.p.x+xarr[i];
            p.y=n.p.y+yarr[i];

            if (isValid(p.x,p.y) && !visited[p.x][p.y] && mat[p.x][p.y]==1)
            {
                Node ntemp;
                ntemp.p=p;
                ntemp.dist=n.dist+1;
                q.push(ntemp);
            }
        }
    }

    return -1;
}


int main()
{
    int mat[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 1, 1, 1, 0, 1 }
    };

    Point src={0,0};
    Point dest={8,9};

    int dist= BFS(mat,src,dest);

    cout << "dist=" << dist << endl;
    return 0;
}

