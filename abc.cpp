#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
void gotox(int x);
void gotoxy(int x, int y);
int mainMenu();
void header();
void clearScreen();
void singUp();
void signIn();
int checkUserIdx(string userName, string o);
void librarionInterface();
void bookManagement();
int memberInterface();
void addBook();
void sortBook();
void deleteBook();
void viewAllBooks();
int findBook(string book);
struct books
{
  int isbn;
  string title;
  string author;
  string category;
  int price;
  bool available;
};
books book[100];
struct members
{
  string userName;
  string password;
  int role;//1 for member 2 for librarion
  bool haveBook;
};
members member[100];


int bookCount = 0, userCout = 0;
int main()
{

  int option = 0;
  while (option != 3)
  {
    system("cls");
    header();
    option = mainMenu();
    switch (option)
    {
    case 1:
      signIn();
      break;
    case 2:
    {
      if (userCout < 100)
        singUp();
      else
        cout << "Sorry there is no space for new user:" << endl;
    }
    default:
      cout << "Press any key to exit main menu:";
      getch();
    }
  }
}
  void gotox(int x)
  {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    COORD pos;
    pos.X = x;
    pos.Y = csbi.dwCursorPosition.Y;
    SetConsoleCursorPosition(hConsole, pos);
  }
  void gotoxy(int x, int y)
  {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
  }

  void header()
  {
    cout << "            #################################################################################" << endl;
    cout << "            #################################################################################" << endl
         << endl;

    cout << "                       LLL              MMMM          MMMM              SSSSSSSSS       " << endl;
    cout << "                       LLL             MM  MM        MM  MM            SS       SS      " << endl;
    cout << "                       LLL             MM   MM      MM   MM            SS               " << endl;
    cout << "                       LLL             MM    MM    MM    MM             SSSSSSSSS       " << endl;
    cout << "                       LLL             MM     MM  MM     MM                     SS        " << endl;
    cout << "                       LLL             MM      MMMM      MM            SS       SS      " << endl;
    cout << "                       LLLLLLLLLL      MM       MM       MM             SSSSSSSSS     " << endl
         << endl;

    cout << "            #################################################################################" << endl;
    cout << "            #################################################################################" << endl
         << endl
         << endl
         << endl
         << endl;
  }
  void clearScreen()
  {
    gotoxy(0, 14);
    cout << "                                                                                                                                 ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    cout << "\n                                                                                                                               ";
    gotoxy(0, 14);
  }

  int mainMenu()
  {
    int choice;
    cout << "\n========== MAIN MENU    s==========";
    cout << "\n\n      SELECT ONE";
    cout << "\n      1. for Sign In.";
    cout << "\n      2. for Sign Up.";
    cout << "\n      3. to exit.";
    cout << "\n\n      choice :";
    cin >> choice;
    clearScreen();
    return choice;
  }
  void librarionInterface()
  {
    system("cls");
    cout << "\n==== LIBRARION MENU ====";
    cout << "\n\n 1.Book Management";
    cout << "\n 2.Member Management";
    cout << "\n 3.Circulation";
    cout << "\n 0.Exit";
    char choice = getch();
    switch (choice)
    {
    case '1':
      bookManagement();
      break;
    case '2':
      deleteBook();
      break;
    default:
      cout << "do nothing";
    }
  }
  void addBook()
  {
    clearScreen();
    cout<<"     ====ADD NEW BOOKS====="<<endl<<endl;
    cout << "        Enter book ISBN   :";
    cin >> book[bookCount].isbn;
    cout << "        Enter book title  :";
    getline(cin >> ws, book[bookCount].title);
    cout <<         "Enter author name :";
    getline(cin >> ws, book[bookCount].author);
    cout << "       Select category    :" << endl;
    cout << "               1.ISLAMIC"
         << "             \n2.HISTORY    "
         << "             \n3.GEOGRAPHY"
         << "             \n4.SCIENCE\n"
         << "               5.SOCIAL\n";
    char choice = getch();
    switch (choice)
    {
    case '1':
      book[bookCount].category = "ISLAMIC";
    case '2':
      book[bookCount].category = "HISTORY";
    case '3':
      book[bookCount].category = "GEOGRAPHY";
    case '4':
      book[bookCount].category = "SCIENCE";
    case '5':
      book[bookCount].category = "SOCIAL";
    default:
      book[bookCount].category = "SOCIAL";
    }
    cout << "Enter book price:";
    cin >> book[bookCount].price;
    book[bookCount].available = true;
    sortBook();
    bookCount++;

    cout << "\n\n\n          1.Add more books.";
    cout << "\n              0.Exit.";
    choice = getch();
    if (choice == '1')
      addBook();
    if (choice == '0')
      librarionInterface();
  }
  void sortBook()
  {
    int flag = 0;
    books temp;
   temp.title= book[bookCount].title;
   temp.isbn= book[bookCount].isbn;
   temp.price= book[bookCount].price;
   temp.author= book[bookCount].author;
   temp.available= book[bookCount].available;
   temp.category= book[bookCount].category;

    
    for (int i = 0; i < bookCount; i++)
    {
      if (book[i].title > book[bookCount].title)
      {
        for (int j = bookCount; j > i; j--)
        {
            book[j].title= book[j-1].title;
            book[j].isbn= book[j-1].isbn;
            book[j].price= book[j-1].price;
            book[j].author= book[j-1].author;
            book[j].available= book[j-1].available;
            book[j].category= book[j-1].category;

        }
            book[i].title=temp.title;
            book[i].isbn= temp.isbn;
            book[i].price= temp.price;
            book[i].author= temp.author;
            book[i].available= temp.available;
            book[i].category= temp.category;

        flag = 1;
      }
      if (flag == 1)
        break;
    }
  }

  void deleteBook()
  {
    cout << "\nEnter the book name.";
    string name;
    getline(cin >> ws, name);
    int idx = findBook(name);
    while (idx < bookCount)
    {
      for (int k = 0; k < 6; k++)
        books[idx][k] = books[idx + 1][k];
      idx++;
    }
    bookCount--;
    cout << "\n1.Delete more books.";
    cout << "\n2.Main menu.";
    char choice = getch();
    if (choice == '1')
      deleteBook();
    if (choice == '2')
      bookManagement();
  }

  int findBook(string book)
  {
    for (int i = 0; i < bookCount; i++)
    {
      if (book == books[i][1])
      {
        return i;
      }
    }
    cout << "\nThe entered books is not found.";
    cout << "\n Enter book name with correct spellings.";
    deleteBook();
    return -1;
  }
  void singUp()
  {
    string uN, uP;
    int uS;
    clearScreen();
    cout << "      Enter  user name:" << endl;
    cin >> uN;
    cout << "      Enter o:" << endl;
    cin >> uP;
    cout << "      press 1 for library member:" << endl;
    cout << "      press 2 for Librarion:" << endl;
    cin >> uS;
    int idx = checkUserIdx(uN, uP);
    if (idx == -1)
    {
      member[userCout].userName=uN;
      member[userCout].password=uP;
      member[userCout].role=uS;
      userCout++;
      clearScreen();
      cout << "\n\n             CONGRATULATION..." << endl;
      cout << "                 sign up successfully." << endl;
    }
    else
      cout << "Sorry user already exist." << endl;
    cout << "press any key to continue:";
    getch();
    clearScreen();
  }
  void signIn()
  {
    string uN, uP;
    cout << "        Enter user name:";
    cin >> uN;
    cout << "       Enter user Passward:";
    cin >> uP;
    int check = checkUserIdx(uN, uP);
    if (check == 1)
    {
      cout << "      CONGRATULATION..." << endl;
      cout << "      sing in successfully." << endl;
      cout<<"\n       Press any key to move furthor:";
      getch();
    }
    else if (check == 2)
    {
      cout << "          CONGRATULATION..." << endl;
      cout << "          Sing in successfully." << endl;
      cout<<"\n            Press any key to move furthor:";
      getch();
      librarionInterface();
    }
    else
      cout << "Sorry user does not found" << endl;
     cout<<"Press any key to go main menu:";
    getch();
  }
  int checkUserIdx(string userName, string userPassword)
  {
    for (int i = 0; i < userCout; i++)
    {
      if (member[i].userName == userName && member[i].password == userPassword)
        return member[i].role;
    }
    return -1;
  }

  void bookManagement()
  {
    cout << "\n         ====== BOOK MENU ======";
    cout << "\n          \n 1.Add new books ";
    cout << "\n           2.Delete book.";
    cout << "\n           3.View all books. ";
    cout << "\n           4.View all available books.";
    cout << "\n           5.Find a specific book.";
    cout << "\n           0.Exit the menu.\n";
    char choice = getch();
    switch (choice)
    {
    case '1':
      addBook();
    case '2':
      deleteBook();
    case '3':
      viewAllBooks();
    }
  }
  void viewAllBooks()
  {
    cout << "ISBN\tTITLE\tAUTHOR\tCATEGORY\tPRICE\tSTATUS";
    for (int i = 0; i < bookCount; i++)
    {
      for (int k = 0; k < 5; k++)
      {
        cout << books[i][k];
      }
      if (books[i][5] == "1")
        cout << "Available" << endl;
      else
        cout << "Not Available" << endl;
    }
  }
