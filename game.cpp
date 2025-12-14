
#include <iostream>
#include <conio.h>
using namespace std;
void showBoard();
void showPositions();
void input(char);
bool isWinner(char symbol);
bool checkRows(char symbol);
bool checkColumns(char symbol);
bool checkDiagonals(char symbol);
const int gridSize = 3;
char board[gridSize][gridSize] = {{'_', '_', '_'},
                                  {'_', '_', '_'},
                                  {'_', '_', '_'}};
int main()
{
   char winner;
   while (true)
   {
      system("cls");
      showBoard();
      showPositions();
      input('X');
      if (isWinner('X'))
      {
         system("cls");
         showBoard();
         cout << "\n\n\t\tX is winner.";
         cout << "\n\t\tPress any key to continue:";
         getch();
         return 1;
         exit;
      }
      system("cls");
      showBoard();
      showPositions();
      input('0');
      if (isWinner('0'))
      {
         system("cls");
         showBoard();
         cout << "\n\n\t\t0 is winner.";
         cout << "\n\t\tPress any key to continue:";
         getch();
         return 1;
         exit;
      }
   }
}
void showBoard()
{
   cout << "\n\n\n\n\n";
   for (int i = 0; i < gridSize; i++)
   {
      for (int j = 0; j < gridSize; j++)
      {
         cout << "\t\t" << board[i][j] << " ";
      }
      cout << endl
           << endl;
   }
}
void showPositions()
{
   cout << "\n\n\n\t\t1  2  3"
        << "\n\t\t4  5  6"
        << "\n\t\t7  8  9";
}
void input(char character)
{
   cout<<"\n\n\n\t\t"<<character;
   cout << "\n\t\tPlayer " << character << " turn.";
   cout << "\n\t\tPosition:(1-9)";
   cout << "\n\t\tChoice:";
   char position = getch();
   switch (position)
   {
   case '1':
      if (board[0][0] == '_')
         board[0][0] = character;
      break;
   case '2':
      if (board[0][1] == '_')
         board[0][1] = character;
      break;
   case '3':
      if (board[0][2] == '_')
         board[0][2] = character;
      break;
   case '4':
      if (board[1][0] == '_')

         board[1][0] = character;
      break;
   case '5':
      if (board[1][1] == '_')
         board[1][1] = character;
      break;
   case '6':
      if (board[1][2] == '_')
         board[1][2] = character;
      break;
   case '7':
      if (board[2][0] == '_')
         board[2][0] = character;
      break;
   case '8':
      if (board[2][1] == '_')
         board[2][1] = character;
      break;
   case '9':
      if (board[2][2] == '_')
         board[2][2] = character;
      break;
   default:
      cout << "\n\n\t\tWrong position:";
      cout << "\n\n\t\tTry with different position:";
      input(character);
   }
}
bool isWinner(char symbol)
{
   if (checkColumns(symbol) || checkRows(symbol) || checkDiagonals(symbol))
      return true;
   else
      return false;
}
bool checkColumns(char symbol)
{
   for (int col = 0; col < gridSize; col++)
   {
      bool match = true;
      for (int row = 0; row < gridSize; row++)
         if (board[row][col] != symbol)
            match = false;
      if (match)
         return true;
   }
   return false;
}
bool checkRows(char symbol)
{
   for (int row = 0; row < gridSize; row++)
   {
      bool match = true;
      for (int col = 0; col < gridSize; col++)
         if (board[row][col] != symbol)
            match = false;
      if (match)
         return true;
   }
   return false;
}
bool checkDiagonals(char symbol)
{
   bool match = true;
   for (int idx = 0; idx < gridSize; idx++)
      if (board[idx][idx] != symbol)
         match = false;

   if (match)
      return true;
   match = true;

   for (int row = 0, col = 2; row < gridSize; row++, col--)
      if (board[row][col] != symbol)
         match = false;

   if (match)
      return true;
   else
      return false;
}