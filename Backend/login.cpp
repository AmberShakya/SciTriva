#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

void check(){
  std::string email, pass, line,word;
  std::cin>>email;
  std::cin>>pass;
  std::ifstream f;
  std::vector<std::string> s;
  s.resize(3);
  
  f.open("database.txt", std::ios::in);
  if(f.is_open()){
    bool flag = false;
    while(std::getline(f,line)){
      std::stringstream ss(line);
      int i = 0;
      while(ss>>word){
        s[i] = word;
        i++;
      }
      if(s[1] == email){
        flag = true;
        if(s[2] == pass){
          std::cout<<"200";
          f.close();
          return;
        }
        else{
          std::cout<<"300";
          f.close();
          return;
        }

      }
    }
    std::cout<<"500";
    f.close();
    return;
  }
  else{
    std::cout<<"404";
    return;
  }


}

int main(){
  check();
  return 0;
}
