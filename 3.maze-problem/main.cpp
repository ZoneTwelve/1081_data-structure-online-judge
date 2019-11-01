/* https://judge.zonetwelve.io */
#include <iostream>
#include <vector>

class point{
  public:
    int x, y;
    point(int X, int Y){x=X;y=Y;}
    void print(){std::cout<<x+1<<" "<<y+1<<"\n";}
};

int main(){
  std::vector<point> path;
  point defp(0, 0);
  path.push_back(defp);
  int row, col;
  std::cin>>row>>col;
  int map[row][col];
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      std::cin>>map[i][j];
    }
  }
  //path[0].print();
  while(path.size()!=0){
    point cur = path.back(); //current point
    if(cur.x+1==row&&cur.y+1==col){
      //std::cout<<"find da way\n";
      break;
    }
    path.pop_back();
    /*
      -1-1 -1 0 -1 1
       0-1  0 0  0 1
       1-1  1 0  1 1
       
      1 -1 0 
      2 -1 1
      3  0 1
      4  1 1
      5  1 0
      6  1-1
      7  0 1
      8 -1-1

      1  0-1
      2  1-1
      3  1-0
      4  1 1
      5  0 1
      6 -1 1
      7 -1 0
      8 -1-1
    */
    map[cur.x][cur.y] = 1;
    if(               cur.y-1>=0   && map[ cur.x ][cur.y-1]==0){  // 1 0  -1
      path.push_back(cur);
      point newp = point(cur.x, cur.y-1);
      path.push_back(newp);
    }else if(cur.x-1>=0   && cur.y+1<col && map[cur.x-1][ cur.y ]==0){  // 2 -1  1
      path.push_back(cur);
      point newp = point(cur.x-1, cur.y+1);
      path.push_back(newp);
    }else if(               cur.y+1<col && map[ cur.x ][cur.y+1]==0){   // 3 0   1
      path.push_back(cur);
      point newp = point(cur.x, cur.y+1);
      path.push_back(newp);
    }else if(cur.x+1<row && cur.y+1<col && map[cur.x+1][cur.y+1]==0){   // 4 1    1
      path.push_back(cur);
      point newp = point(cur.x+1, cur.y+1);
      path.push_back(newp);
    }else if(cur.x+1<row &&                 map[cur.x+1][ cur.y ]==0){  // 5 1    0
      path.push_back(cur);
      point newp = point(cur.x+1, cur.y);
      path.push_back(newp);
    }else if(cur.x+1<row && cur.y-1>=0   && map[cur.x+1][cur.y-1]==0){  // 6 1   -1
      path.push_back(cur);
      point newp = point(cur.x+1, cur.y-1);
      path.push_back(newp);
    }else if(cur.x-1>=0   &&                map[cur.x-1][ cur.y ]==0){  // 7 -1  0
      path.push_back(cur);
      point newp = point(cur.x-1, cur.y);
      path.push_back(newp);
    }else if(      cur.x-1>=0   && cur.y-1>=0   && map[cur.x-1][cur.y-1]==0){ // 8 -1 -1
      path.push_back(cur);
      point newp = point(cur.x-1, cur.y-1);
      path.push_back(newp);
    }
    //std::cout<<"size: "<<path.size()<<", path:";
    //path[path.size()-1].print();
  }
  for(int i=0;i<path.size();i++)
    path[i].print();
}
