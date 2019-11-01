#include <iostream>
#include <vector>

class point{
  public:
    int x,y,w,sx,sy;
    point(){point(-1, -1);sx=-1;sy=-1;}
    point(int a,int b){x = a;y = b;sx = -1;sy = -1;w = 0;}
    point(int a, int b, int c){set(a,b,c);}
    void set(int a,int b){x=a;y=b;}
    void set(int a, int b, int c){x=a;y=b;w=c;}
    void print(){std::cout<<(x+1)<<" "<<(y+1)<<"\n";}
};

int main(){
  std::vector<point> path;
  point start(0, 0, 1);
  path.push_back(start);
  int row, col, tmp;
  std::cin>>row>>col;
  point map[row][col];
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      std::cin>>tmp;
      map[i][j].x = i;
      map[i][j].y = j;
      map[i][j].w = (tmp==1?-1:tmp);
    }
  
  while(path.size()!=0){
    point cur = path.front();
    path.erase(path.begin());
    map[cur.x][cur.y].w = cur.w;
    
    
    for(int x=-1;x<2;x++){
      for(int y=-1;y<2;y++){
        if(!(x==0&&y==0)&&cur.x+x>-1&&cur.x+x<row&&cur.y+y>-1&&cur.y+y<col&&map[cur.x+x][cur.y+y].w==0){
          map[cur.x+x][cur.y+y].sx = cur.x;
          map[cur.x+x][cur.y+y].sy = cur.y;
          map[cur.x+x][cur.y+y].w = cur.w+1;
          //point np(cur.x+x, cur.y+y, cur.w+1);
          path.push_back(map[cur.x+x][cur.y+y]);
        }
      }
    }
  }
  std::vector<point> result;
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++)
      std::cout<<map[i][j].w<<"\t";
    std::cout<<"\n";
  }
  result.push_back(map[row-1][col-1]);
  for(int i=0;i<map[row-1][col-1].w-1;i++){
    point p = result[i];
    result.push_back(map[p.sx][p.sy]);
  }
  for(int i=result.size()-1;i>-1;i--)
    result[i].print();
}