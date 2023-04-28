#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

void postleaderboard(){
  std::string line,word,score,net,email;
  std::ifstream fin;
  std::ofstream fout,fnew;
  std::vector<std::string> s,res;
  s.resize(3);
  std::cin>>score;
  std::cin>>email;
  fin.open("leaderboard.txt",std::ios::in);
  
  fnew.open("leaderboard.txt",std::ios::app);
  if(fin.is_open() && fnew.is_open()){
    while(std::getline(fin,line)){
      std::stringstream ss(line);
      int i = 0;

      while(ss>>word){
        s[i] = word;
        i++;

      }
      if(s[0] == email){
        int o = std::stoi(s[2]);
        int y = std::stoi(score);
        int g = (o>y)?o:y;
        net = email+" "+s[1]+" "+std::to_string(g)+"\n";
        res.push_back(net);

      }
      else{
        line = line+"\n";
        res.push_back(line);
      }
    }
    fin.close();
    fout.open("leaderboard.txt",std::ios::out);
    fout<<"";
    fout.close();
    for(int i = 0; i<res.size(); i++){
        fnew<<res[i];
    }
    fnew.close();
    std::cout<<"200";
    return;
  }
  else{
    std::cout<<"404";
    return;
  }


}

int main(){
  postleaderboard();
  return 0;
}