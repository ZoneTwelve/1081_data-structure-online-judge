#include <iostream>
#include <vector>
int priority(char c){
  switch(c){
    case '*':case'/': return 2;
    case '+':case'-': return 1;
    default:          return 0;
  }
}
int main(){
  std::string infix, postfix;
  std::vector<char> op;
  std::cin>>infix;
  for(int i=0;i<infix.length();i++){
    char s = infix[i];
    //std::cout<<i<<" - "<<s<<"\n";
    if(priority(s)==0&&s!='('&&s!=')'){
      postfix+=s;
    }else if(s==')'){
      while(op.back()!='('){
        postfix+=op.back();
        op.pop_back();
      }
      op.pop_back();
    }else if(s=='('){
      op.push_back(s);
    }else{
      int p = priority(s);
      //if(op.size()>0) std::cout<<s<<" vs "<<op.back()<<" = "<<p<<" vs "<<priority(op.back())<<"\n";
      if(op.size()>0&&p<=priority(op.back())){
        postfix+=op.back();
        op.pop_back();
      }
        op.push_back(s);
    }
  }
  while(op.size()!=0){
    if(priority(op.back())>0)
      postfix+=op.back();
    op.pop_back();
  }
  std::cout<<postfix;
}