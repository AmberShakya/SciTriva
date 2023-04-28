#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

void getleaderboard(){
  std::string line,word;
  std::ifstream f;
  std::string result = "",s = "";
  
  f.open("leaderboard.txt",std::ios::in);
  if(f.is_open()){
    while(std::getline(f,line)){
      std::stringstream ss(line);
      ss>>word;
      while(ss>>word){
        s = s+word+"***";

      }
      result = result+s+"&&&";
      s.clear();
    }
    f.close();
    std::cout<<result;
    return;
  }
  else{
    std::cout<<"404";
    return;
  }


}

int main(){
  getleaderboard();
  return 0;
}