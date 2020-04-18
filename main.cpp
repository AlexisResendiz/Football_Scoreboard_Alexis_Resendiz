//Alexis Resendiz, COSC-1437, 04/17/2020, Dr_T
#include <iostream>
using namespace std;

class Team
{
  private:
    string name;
    int timeout;
    int score;
    string coachName;
    string city;
    bool home;
  public:
    Team()//default constructor  
    {
      score = 0;
      timeout = 0; 
      name = "Steelers";
      coachName = " Coach Tomlin";
      city = "Pittsburgh";
      home = true;
    }  
    void setScore(int s) { score = s; }
    void setTimeout(int t) { timeout = t; }
    void setName(string n) { name = n; }
    void setCoachName(string cN) { coachName = cN; }
    void setCity(string c) { city = c; }
    void setHome(bool h) { home = h; }
    double getScore() const { return score; }
    double getTimeout() const { return timeout; }
    string getName() const { return name; }
    string getCoachName() const { return coachName; }
    string getCity() const { return city; }
    bool getHome() const { return home; }
};

class Scoreboard
{
  private:
    int quarter;
    int down;
    int yards;
    bool poss;
};

int main() 
{


  return 0;  
}