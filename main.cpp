//Alexis Resendiz, COSC-1437, 04/17/2020, Dr_T, TCC
//Learning how to use class
//I learned how the set and get work from working on this project
#include <iostream>
#include <string>
#include <unistd.h> //for sleep command
#include <iomanip> 
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
      timeout = 3; 
      name = "Steelers";
      coachName = "Tomlin";
      city = "Pittsburgh";
      home = true;
    }  
    void setScore(int s) { score = s; }
    void setTimeout(int t) { timeout = t; }
    void setName(string n) { name = n; }
    void setCoachName(string cN) { coachName = cN; }
    void setCity(string c) { city = c; }
    void setHome(bool h) { home = h; }
    int getScore() const { return score; }
    int getTimeout() const { return timeout; }
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
    Team team1;
    Team team2;
  public:
    Scoreboard()
    {
      quarter = 1;
      down = 1;
      yards = 10;
      poss = true;
    }
    void setQuarter(int q) { quarter = q; }
    void setDown(int d) { down = d; }
    void setYards(int y) { yards = y; }
    void setPoss(bool p) { poss = p; }
    void setTeam1(Team t1) { team1 = t1; }
    void setTeam2(Team t2) { team2 = t2; }
    int getQuarter() const { return quarter; }
    int getDown() const { return down; }
    int getYards() const { return yards; }
    bool getPoss() const { return poss; }
    Team getTeam1() const { return team1; }
    Team getTeam2() const { return team2; }

    void showScoreboard()
    {
      system("clear"); //clear the screen 
       
      //Show Scoreboard
      cout << setw(35) << "|Scoreboard|" << setw(35) << endl;

       cout << "********************************************************"  << endl;
      cout << setw(8) << team1.getCity().substr(0,3) << "|" << team1.getName() << "|" << setw(25) << team2.getCity().substr(0,3) << "|" << team2.getName() << "|" << endl;
      cout << setw(14) << team1.getScore() << setw(35) << team2.getScore() << endl;
      cout << "\n";
      cout << setw(11) << "Coach " << team1.getCoachName() << setw(29) << "Coach " << team2.getCoachName() << endl;
      cout << setw(33) << "Quarter: " << quarter << endl;
      cout << "\n";
      cout << setw(19) << team1.getTimeout() << "|TOL|" << setw(15) << "|TOL|" << team2.getTimeout() << endl;
      cout << "\n";
      cout << setw(19) << getDown() << "|DOWN|" << setw(5) << getYards() << "|YARDS TO GO|" << endl;
      cout << "\n";
      //dealing with Boolean data
      if(poss == true)
      {
        cout << setw(5) << "Home team has the ball" << endl; 
      }
      else
      {
        cout << setw(60) << "Visiting team has the ball" << endl; 
      }
      cout << "********************************************************"  << endl;
    }
};

void scoreboardControls()
{
  Scoreboard s; //instantiate the the scoreboard object s
  Team tOneMain; //team Object that will become a member of scoreboard S
  Team tTwoMain; //team Object that will become a member of scoreboard S
  char decision = '\0';
  int newScore = 0;
  int newTimeout = 0;
  int newQuarter = 0;
  int newDown = 0;
  int newYards = 0;
  string newName = "";
  string newCity = "";
  string newCoach = "";

  s.setTeam1(tOneMain); // placed update Team1 object in s
  s.setTeam1(tTwoMain); // placed update Team2 object in s

  //Accessing the data outside of the class
  /*cout << "\nPeriod here " << s.getPeriod() << endl;
  cout << "\nTeam 1 initial name: " << s.getTeam1().getName() << endl;
*/

  //work with the scoreboard and menu 
  do
  {
   
        //show the scoreboard and clear the screen each time 
        s.showScoreboard();
       
       //Menu options for the user
        cout << "Menu: " << endl; 
        cout << "A. Update Team 1 Score" << endl; 
        cout << "B. Update Team 1 Name" << endl;
        cout << "C. Update Team 1 Timeouts Remaining" << endl;
        cout << "D. Update Team 1 City" << endl;
        cout << "E. Update Team 1 Coach name" << endl;
        cout << "F. Update Team 2 Score" << endl;
        cout << "G. Update Team 2 Name" << endl;
        cout << "H. Update Team 2 Timeouts Remaining" << endl;
        cout << "I. Update Team 2 City" << endl;
        cout << "J. Update Team 2 Coach Name" << endl;
        cout << "K. Update the Quarter" << endl;
        cout << "L. Update the Downs" << endl;
        cout << "M. Update the Yards" << endl;
        cout << "X. To Exit" << endl; 
        cin >> decision; 

        if(decision == 'a' || decision == 'A')
        {
          cout << "Team 1 score update. \n";
          cout << "What is the new score? -> ";
          cin >> newScore; 
          tOneMain.setScore(newScore);
          cout << "\nUpdating new score for Team1 to..." << tOneMain.getScore() << endl;   
          sleep(3); //pause 3 seconds. 
          
        }
        else if(decision == 'b' || decision == 'B')
        {
          cout << "Team 1 NAME update. \n";
          cout << "What is the new Name? -> ";
          cin >> newName; 
          tOneMain.setName(newName);
          cout << "\nUpdating new name for Team1 to..." << tOneMain.getName() << endl;
          sleep(3); //pause 3 seconds. 
          
        }
        else if (decision == 'c' || decision == 'C')
        {
          cout << "Team 1 timeouts remaining \n";
          cout << "What is the new amount remaining? -> ";
          cin >> newTimeout; 
          tOneMain.setTimeout(newTimeout);
          cout << "\nUpdating new timeouts remaining for Team1 to..." << tOneMain.getTimeout() << endl;   
          sleep(3); //pause 3 seconds.

        }
        else if(decision == 'd' || decision == 'D')
        {
          cout << "Team 1 CITY update. \n";
          cout << "What is the new CITY? -> ";
          cin >> newCity; 
          tOneMain.setCity(newCity);
          cout << "\nUpdating new city for Team1 to..." << tOneMain.getCity() << endl;
          sleep(3); //pause 3 seconds. 
          
        }
        else if(decision == 'e' || decision == 'E')
        {
          cout << "Team 1 COACH NAME update. \n";
          cout << "What is the new COACH Name? -> ";
          cin >> newCoach; 
          tOneMain.setCoachName(newCoach);
          cout << "\nUpdating new coach name for Team1 to..." << tOneMain.getCoachName() << endl;
          sleep(3); //pause 3 seconds. 
          
        }
        else if(decision == 'f' || decision == 'F')
        {
          cout << "Team 2 score update. \n";
          cout << "What is the new score? -> ";
          cin >> newScore; 
          tTwoMain.setScore(newScore);
          cout << "\nUpdating new score for Team2 to..." << tTwoMain.getScore() << endl;   
          sleep(3); //pause 3 seconds.

        }
        else if(decision == 'g' || decision == 'G')
        {
          cout << "Team 2 NAME update. \n";
          cout << "What is the new Name? -> ";
          cin >> newName; 
          tTwoMain.setName(newName);
          cout << "\nUpdating new name for Team2 to..." << tTwoMain.getName() << endl;
          sleep(3); //pause 3 seconds. 
          
        }
        else if (decision == 'h' || decision == 'H')
        {
          cout << "Team 2 timeouts remaining \n";
          cout << "What is the new amount remaining? -> ";
          cin >> newTimeout; 
          tTwoMain.setTimeout(newTimeout);
          cout << "\nUpdating new timeouts remaining for Team2 to..." << tTwoMain.getTimeout() << endl;   
          sleep(3); //pause 3 seconds.

        }
        else if(decision == 'i' || decision == 'I')
        {
          cout << "Team 2 CITY update. \n";
          cout << "What is the new CITY? -> ";
          cin >> newCity; 
          tTwoMain.setCity(newCity);
          cout << "\nUpdating new city for Team2 to..." << tTwoMain.getCity() << endl;
          sleep(3); //pause 3 seconds. 
          
        }
        else if(decision == 'j' || decision == 'J')
        {
          cout << "Team 2 COACH NAME update. \n";
          cout << "What is the new COACH Name? -> ";
          cin >> newCoach; 
          tTwoMain.setCoachName(newCoach);
          cout << "\nUpdating new coach name for Team2 to..." << tTwoMain.getCoachName() << endl;
          sleep(3); //pause 3 seconds. 
          
        }
        else if(decision == 'k' || decision == 'K')
        {
          cout << "Update the QUARTER. \n";
          cout << "What is the new quarter? -> ";
          cin >> newQuarter; 
          s.setQuarter(newQuarter);
          cout << "\nUpdating new quarter..." <<s.getQuarter() << endl;   
          sleep(3); //pause 3 seconds. 
          
        }
        else if(decision == 'l' || decision == 'L')
        {
          cout << "Update the DOWNS. \n";
          cout << "What is the new down? -> ";
          cin >> newDown; 
          s.setDown(newDown);
          cout << "\nUpdating new down..." <<s.getDown() << endl;   
          sleep(3); //pause 3 seconds. 
          
        }
        else if(decision == 'm' || decision == 'M')
        {
          cout << "Update the YARDS. \n";
          cout << "What is the new yards to go? -> ";
          cin >> newYards; 
          s.setYards(newYards);
          cout << "\nUpdating new yards to go..." <<s.getYards() << endl;   
          sleep(3); //pause 3 seconds. 
          
        }
        else if(decision == 'x' || decision == 'X')
        {
          cout << "\nThe program has ended.(T_T) " << endl; 
        }

      s.setTeam1(tOneMain); //setTeam1 to the latest data 
      s.setTeam2(tTwoMain); //setTeam2 to the latest data 
      
  }while(decision != 'x' && decision != 'X');     

}

int main() 
{
  scoreboardControls();

  return 0;  
}