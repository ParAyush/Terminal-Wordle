#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib> //for rand
#include <ctime> //for time



std::string ranb_word(){
srand(time(NULL)); //plant a seed 
   std::string choose[20] = {"plays", "homes", "zebra", "house", "grade", "tiger", "loose", "moose", "ghost", "gross","mouse","knife","night","dance","froze","gnome","boots","slant"}; 
  int index=rand()%20;
  std::string word=choose[index];
  return word;
}
