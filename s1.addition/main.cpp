#include <iostream>
#include <string>
#include <sstream>

template <class T>
void s2val(T &value, const std::string &s){
  std::stringstream ss(s);
  ss >> value;
}

int main(){
  int result = 0, tmp;
  std::string in;
  std::cin>>in;
  for(int i=0,p=0;i<in.length()+1;i++){
    if(in[i]=='+'||i==in.length()){
      s2val(tmp, in.substr(p, i-p));
      result+=tmp;
      p = i;
    }
  }
  std::cout<<result;
}