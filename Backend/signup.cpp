#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

bool check(std::string email){
  std::string line,word;
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
        f.close();
        return true;
      }
    }
    f.close();
    return false;
  }
  else{
    f.close();
    return true;
  }


}

void add(){
    std::string username, email, pass, net, net2;
    std::cin>>username;
    std::cin>>email;
    std::cin>>pass;
    std::ofstream f, flead;
    if(!check(email)){
        f.open("database.txt", std::ios::app);
        flead.open("leaderboard.txt", std::ios::app);
        if(f.is_open() && flead.is_open()){
            net = username+" "+email+" "+pass+"\n";
            net2 = email+" "+username+" 0\n";
            f<<net;
            flead<<net2;
            f.close();
            flead.close();
            std::cout<<"200";
            return;
        }
        else{
            std::cout<<"404";
            return;
        }
        
    }
    else{
        std::cout<<"500";
        return;
    }

}

int main(){
  add();
  return 0;
}