#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;
// Game stuff
int knives = 8;
int kLife = 1;
int kDeath = 1;

// Vectors
// - stores all numbers
vector<int> numbers (30);
// - stores "winning" numbers
vector<int> result (30);

// Player input
string command;
int pBet;
int pNum;

// Player resources
int tokens = 50;

// Player stats
int nRounds = 0;
int totalTokensWon = 0;
int totalTokensLost = 0;
int thiccestWin = 0;
int thiccestLoss = 0;

// Fill vector with 0
int resetNumbers(){
  int n = 30;
  do{ 
    numbers[n-1] = 0;
    result[n-1] = 0;
    n--;
  } while(n>0);
  return 0;
}

int bet(int num, int tk){
  if(tk > tokens){ 
    cout << "[HOST] You're betting more tokens than the amount you have right now! I'm assuming this is an all-in ;)" << endl;
    tk = tokens;
  } else if(tk == 0) { cout << "[HOST] You can't bet no tokens ;)" << endl; }
  numbers[num-1] += tk;
  tokens -= tk;
  cout << "[PLAYER] I bet " << tk << " tokens on number " << num << "!" << endl;
  cout << "[HOST] You have bet " << numbers[num-1] << " tokens on number " << num << " so far!" << endl;
  cout << "[HOST] You now have " << tokens << " tokens!" << endl;
  return 0;
}


int explanation(){
  cout << "[HOST] Welcome to this shit game. You have to bet in at least 1 of 30 numbers by typing 'bet <number> <amount>'. You are given 50 tokens to start. Type 'play' to roll the numbers and 'help' to show this once again. And, please, don't fuck this up by inputting something not a number when asked for a number and so on, I'm a shit-tier 'programmer'." << endl;
  cout << "[HOST] There are 10 knives, one of which is a Death Knife and another one which is a Life Knife. If you bet on a number in which a knife landed, you get 2x the bet. If you bet on a number in which a Death Knife landed, you lost 30x the bet. If you bet on a number in which a Life Knife landed, you get 30x the bet. Good luck!" << endl; 
  return 0;
}

// Here, I (apparently and supposedly) randomly assign numbers on which the knives will fall
int play(){
  cout << "============[KNIVES]============" << endl;
  srand(time(0));
  int min = 1;
  int max = 30;
  for(int i = 0; i < knives; i++){
    int r = min + (rand() % static_cast<int>(max - min + 1)); // stolen
    if(result[r-1] == 0) result[r-1] = 1;
    result[r-1] *= 2;
    cout << "- Knife " << i+1 << " landed on " << r << "!" << endl;
  }
  for(int i = 0; i < kDeath; i++){
    int r = min + (rand() % static_cast<int>(max - min + 1)); // stolen
    result[r-1] -= 30;
    cout << "- Death Knife landed on " << r << "!" << endl;
  }
  for(int i = 0; i < kLife; i++){
    int r = min + (rand() % static_cast<int>(max - min + 1)); // stolen
    result[r-1] += 30;
    cout << "- Life Knife landed on " << r << "!" << endl;
  }
  cout << "============[KNIVES]============" << endl;
  return 0;
}

int stats(){
  cout << "============[Player Stats]============" << endl;
  cout << "Rounds 'survived': " << nRounds << endl;
  cout << "Tokens won (total): " << totalTokensWon << endl;
  cout << "Tokens lost (total): " << totalTokensLost << endl;
  cout << "Biggest win within a round: " << thiccestWin << " tokens" << endl;
  cout << "Biggest loss within a round: " << thiccestLoss << " tokens" << endl;
  cout << "============[Player Stats]============" << endl;
  return 0;
}

int calculateGains(){
  int gains = 0;
  for(int i = 0; i < 30; i++){
    if(result[i] != 0 && numbers[i] != 0){
      int v = result[i] * numbers[i];
      gains += v;
      if(v < 0){
         cout << "[HOST] You've just LOST " << abs(v) << " tokens by betting in number " << i+1 << "!" << endl;
      } else {
        cout << "[HOST] You've just RECEIVED " << v << " tokens by betting in number " << i+1 << "!" << endl;
      }
    }
  }      
  if(gains == 0){
    cout << "[HOST] You've neither won nor lost anything this round." << endl;
  }
  if(gains > 0){
    totalTokensWon += gains;
    if(gains > thiccestWin) thiccestWin = gains;
  }
  if(gains < 0){
    totalTokensLost += gains;
    if(gains < thiccestLoss) thiccestLoss = gains;
  } 
  tokens += gains;
  cout << "[HOST] You now have " << tokens << " tokens!" << endl;
  return 0;
}

int main(){
  resetNumbers();
  explanation();
  while(tokens > 0){
    cout << ">> ";
    while(cin >> command){
      if(command == "play"){
        break;
      } else if(command == "bet"){
        // This command was originally inverted; it'll stay as now is for better clarity, as in "bet(ting) 20 (tokens in number) 30"
        cin >> pBet >> pNum;  
        bet(pNum, pBet);
        cout << ">> ";
      } else if(command == "help"){
        explanation();
        cout << ">> ";
      } else if(command == "stats"){
        stats();
        cout << ">> ";
      } else {
        cout << "[HOST] You fucked up!" << endl;
        cout << "[HOST] Type either 'bet <amount> <number>', 'play' or 'stats' or 'help'!" << endl;
        cin.ignore();
        cout << ">> ";
      }
    }
    play();
    calculateGains();
    if(tokens <= 0){
      cout << "[HOST] You're out of tokens, dear! That's G A M E O V E R for you, sucker!" << endl;
      break;
    }
    nRounds++;
    resetNumbers();
    cout << "[HOST] The board has been wiped! You can now 'bet' again!" << endl;
  }
  cout << "Game has ended! Thanks for playing ;)" << endl;
  return 0;
}
