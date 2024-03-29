#include <iostream>
#include "Hex.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
   Hex game(7);
   
   int moves = 0;
   srand(time(NULL));
   int player;
   int x;
   int y;

/*   while(moves < 49){
      player = rand()%2 + 1;
      if(player == 1){
         x = rand()%7;
         y = rand()%7;
         game.playerMove("B", x, y);         
      }else{
         x = rand()%7;
         y = rand()%7;
         game.playerMove("R", x, y);
      }
      moves++;
   }*/

   game.playerMove("R", 1,1);

   game.playerMove("R", 1,2);
   game.playerMove("R", 1,3);

   game.playerMove("R", 1,4);
   game.playerMove("R", 1,5);

   game.playerMove("R", 1,6);
   game.playerMove("R", 1,7);

   game.printBoard();

//   game.printBoardGraph();

   game.checkWin("R");

   return 0;
}
