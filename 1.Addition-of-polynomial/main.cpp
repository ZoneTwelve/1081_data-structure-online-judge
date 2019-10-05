#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define endl "\n"

template <class T>
void s2val(T &, const std::string &);

class object{
  public:
    object();
    object(long double, int);
    void set(long double, int);
    long double n;
    int p;
};
object::object(){}
object::object(long double num, int pow){
  set(num, pow);
}
void object::set(long double num, int pow){
  n = num;
  p = pow;
}

void display(object);
object create(std::string);
std::vector<object> setup();
int main(){
  std::vector<object> arr2, arr;
  arr = setup();
  arr2 = setup();
  for(int i=0;i<arr2.size();i++){
    int insert = -1;
    bool find = false;
    for(int j=0;j<arr.size()&&!find;j++){
      if(arr[j].p==arr2[i].p){
        insert = j;
        find = true;
      }
      if(arr2[i].p<arr[j].p)
        insert = j;
    }
    if(!find){
      object obj(arr2[i].n, arr2[i].p);
      arr.insert(arr.begin()+insert+1, obj);
    }else{
      arr[insert].n+=arr2[i].n;
    }
  }
  display(arr[0]);
  for(int i=1;i<arr.size();i++){
    if(arr[i].n>0)
      std::cout<<"+";
    display(arr[i]);
  }
}

void display(object obj){
  if(obj.n!=0){
    std::cout<<(obj.n==-1&&obj.p!=0?"-":"");
    if((obj.n!=1&&obj.n!=-1)||obj.p==0)
      std::cout<<obj.n;
    if(obj.p!=0)
      std::cout<<"x^"<<obj.p;
  }
}

std::vector<object> setup(){
  std::vector<object> arr1;
  std::string a;
  std::cin>>a;
  int part = 1, n = 0, p = 0;
  for(int i=0;i<a.length();i++){
    if(i!=0&&(a[i]=='+'||a[i]=='-')){
      object db = create(a.substr(n, i-n));
      arr1.push_back(db);
      n = i;
    }
    if(a[i]=='x')
      p = a[i]=='^'?i+1:i;
  }

  if(n!=a.length()){
    object db = create(a.substr(n, a.length()-n));
    arr1.push_back(db);
  }

  return arr1;
}

object create(std::string str){
  long double num = 1;
  int pow = 0,  p = -1;
  for(int i=0;i<str.length();i++){
    if(str[i]=='x')
      p = i;
  }
  s2val(num, (p==0||((str[0]=='+'||str[0]=='-')&&str[1]=='x')?(str[0]=='-'?"-1":"1"):str.substr(0, p==-1?str.length():p)));
  s2val(pow, p==-1? "0" : ( p+1==str.length()? "1" : ( str.substr(p+2, str.length()-p) ) ));
  object obj(num, pow);
  return obj;
}

template <class T>
void s2val(T &value, const std::string &s){
  std::stringstream ss(s);
  ss >> value;
}