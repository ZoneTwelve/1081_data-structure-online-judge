#include <iostream>
#include <vector>

#define enl "\n"

class item{
  public:
    item(int e, int row, int col){el=e;r=row;c=col;}
    int el;//element
    int r, c;//row, col
};


class matrix{
  public:
    int r, c;
    std::vector<item> data;
    void setup();
    void setup(int row, int col, bool read);
    void display();
};
void matrix::setup(){
  int row, col;
  std::cin>>row;
  std::cin>>col;
  setup(row, col, true);
}
void matrix::setup(int row, int col, bool read){
  int e = 0;
  r = row;
  c = col;
  //if(read)dd
  for(int i=0;i<r;i++)
    for(int j=0;j<c;j++){
      if(read)
        std::cin>>e;
      if(e!=0||!read){
        item obj(e, j, i);
        data.push_back(obj);
      }
    }

}
void matrix::display(){
  int p = 0;// matrix position(index)
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(data[p].c==i&&data[p].r==j)
        std::cout<<data[p++].el;
      else
        std::cout<<0;
      if(j+1!=c)
        std::cout<<" ";
    }
    std::cout<<enl;
  }
}

int main(){
  matrix m1, m2;
  matrix result;

  m1.setup();
  m2.setup();
  result.setup(m1.r, m2.c, false);

  for(int i=0,sj=0;i<m1.data.size();i++){
    for(int j=0;j<m2.data.size();j++){
      //item e1 = m1.data[i], e2 = m2.data[j];
      if(m1.data[i].r==m2.data[j].c){
        result.data[m2.data[j].r+m1.data[i].c*result.c].el+=m1.data[i].el*m2.data[j].el;
      }
    }
  }
  result.display();
}