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

void signUp();
void signIn();
void removeMember();
void viewAllMembers();
void memberHeader();
void showMember(int idx);
int searchMember();
bool isMemberMatch(int i,string userName);

string checkUserRole(string userName, string userPassword);
void librarionInterface();
void bookManagement();
void memberManagement();
void memberInterface();
void addBook();
void sortBook();
void deleteBook();
void viewAllBooks();
void viewAllAvailableBooks();
void notAvailableBooks();
int searchBook();
bool isBookMatch(int i, string title);
void bookHeader();
void showBook(int idx);

void circulationOfBooks();
void issueBook();
void returnBook();

struct books
{
  int isbn;
  string title;
  string author;
  string category;
  int price;
  bool available;
  int issuedPersonID;
};
books book[100];
struct members
{
  string userName;
  string password;
  string role; // 1 for member 2 for librarion
  bool haveBook;
};
members member[100];
int bookCount = 0, userCout = 0;
int main()
{

  system("cls");
  header();
  int option = 0;
  while (option != 3)
  {
    clearScreen();
    option = mainMenu();
    switch (option)
    {
    case 1:
      signIn();
      break;
    case 2:
    {
      if (userCout < 100)
        signUp();
      else
        cout << "\n\t\tSorry there is no space for new user:" << endl;
      break;
    }
    default:
      cout << "\t\tPress any key to exit main menu:";
      getch();
      return 1;
    }
  }
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
  gotoxy(0, 18);
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
  gotoxy(0, 18);
}
int mainMenu()
{
  int choice;
  cout << "\n============ MAIN MENU ============";
  cout << "\n\n        SELECT ONE";
  cout << "\n        1. for Sign In.";
  cout << "\n        2. for Sign Up.";
  cout << "\n        3. to exit.";
  cout << "\n\n        choice :";
  cin >> choice;
  clearScreen();
  return choice;
}
void librarionInterface()
{
  char choice=' ';
  while(choice!='0')
  {
  clearScreen();
  cout << "\n       ======== LIBRARION MENU ========";
  cout << "\n\n             1.Book Management";
  cout << "\n             2.Member Management";
  cout << "\n             3.Circulation";
  cout << "\n             0.Exit";
  cout << "\n\n             choice :";
  choice = getch();
  switch (choice)
  {
  case '1':
    bookManagement();
    break;
  case '2':
    memberManagement();
    break;
  case '3':
    circulationOfBooks();
    break;
  }
  }
}
void memberInterface()
{
  char choice=' ' ;
  while(choice!='0')
  {
    cout<<"\n\t\t1.View all books:";
    cout<<"\n\t\t2.View available books";
    cout<<"\n\t\t3.Search a book";
    cout<<"\n\t\t0Exit.";
    cout<<"\n\n\t\tChoice";

    choice=getch();
    switch(choice)
    {
      case '1':viewAllBooks();
             break;
      case '2':viewAllAvailableBooks();
        break;
      case '3':searchBook();
          break;
      default:return ;    
    }

  }

}
void addBook()
{
  clearScreen();
  cout << "     ====ADD NEW BOOKS=====" << endl
       << endl;
  cout << "        Enter book ISBN   :";
  cin >> book[bookCount].isbn;
  cout << "        Enter book title  :";
  getline(cin >> ws, book[bookCount].title);
  cout << "        Enter author name :";
  getline(cin >> ws, book[bookCount].author);
  cout << "        Enter book price  :";
  cin >> book[bookCount].price;
  cout << "\n          Select category    :" << endl<<endl;
  cout << "             1.ISLAMIC"
       << "             2.HISTORY    "
       << "             3.GEOGRAPHY"
       << "             4.SCIENCE"
       << "             5.SOCIAL";
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
  book[bookCount].available = true;
  book[bookCount].issuedPersonID=-1;
  sortBook();
  bookCount++;
  clearScreen();

  cout << "\n\n\n              1.Add more books.";
  cout << "\n              0.Exit.\n\t\t";
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
  temp.title = book[bookCount].title;
  temp.isbn = book[bookCount].isbn;
  temp.price = book[bookCount].price;
  temp.author = book[bookCount].author;
  temp.available = book[bookCount].available;
  temp.category = book[bookCount].category;
  temp.issuedPersonID=book[bookCount].issuedPersonID;

  for (int i = 0; i < bookCount; i++)
  {
    if (book[i].title > book[bookCount].title)
    {
      for (int j = bookCount; j > i; j--)
      {
        book[j].title = book[j - 1].title;
        book[j].isbn = book[j - 1].isbn;
        book[j].price = book[j - 1].price;
        book[j].author = book[j - 1].author;
        book[j].available = book[j - 1].available;
        book[j].category = book[j - 1].category;
        book[j].issuedPersonID=book[j-1].issuedPersonID;

      }
      book[i].title = temp.title;
      book[i].isbn = temp.isbn;
      book[i].price = temp.price;
      book[i].author = temp.author;
      book[i].available = temp.available;
      book[i].category = temp.category;
      book[i].issuedPersonID = temp.issuedPersonID;

      flag = 1;
    }
    if (flag == 1)
      break;
  }
}
void deleteBook()
{
  char choice;
  clearScreen();
  int idx = searchBook();
  if (idx < 0)
  {
    cout << "\n\n\t\tBook does not found:";
    cout << "\n\t\tDo you want to search again(y/n)";
    choice = getch();
    if (choice == 'y' || choice == 'Y')
      deleteBook();
    else
      clearScreen();
    return;
  }
  bookHeader();
  showBook(idx);
  cout << "\n\t\tDo you want to delete it:";
  choice = getch();
  if (choice == 'n' || choice == 'N')
    return;

  while (idx < bookCount - 1)
  {
    book[idx].title = book[idx + 1].title;
    book[idx].isbn = book[idx + 1].isbn;
    book[idx].price = book[idx + 1].price;
    book[idx].author = book[idx + 1].author;
    book[idx].available = book[idx + 1].available;
    book[idx].category = book[idx + 1].category;
    book[idx].issuedPersonID=book[idx+1].issuedPersonID;
    idx++;
  }
  bookCount--;
  clearScreen();
  cout << "\n\t\t" << book[idx].title << "  has successfully removed:";
  cout << "\n\n\n\t1.Delete more books.";
  cout << "\n\t0.Main menu.";
  choice = getch();
  clearScreen();
  if (choice == '1')
    deleteBook();
}

void signUp()
{
  string uN, uP, uS;
  clearScreen();
  cout << "\t\tEnter  user name         :";
  getline(cin >> ws, uN);
  cout << "\t\tEnter user password      :";
  cin >> uP;
  cout << "\n\t\tpress 1 for Librarion:" << endl;
  cout << "\t\tpress 2 for library member:" << endl<<"\t\t";
  cin >> uS;
  if (uS == "2")
    uS = "Member";
  else if (uS == "1")
    uS = "Librarion";
  else
    {
      cout<<"\n\t\tWrong selection.";
      cout<<"\n\t\tTry again.";
      cout<<"\n\t\tPress any key to go previous menu.";
      getch();
      return ;
    }
  string userRole = checkUserRole(uN, uP);
  if (userRole == "not found")
  {
    member[userCout].userName = uN;
    member[userCout].password = uP;
    member[userCout].role = uS;
    member[userCout].haveBook = false;
    userCout++;
    clearScreen();
    cout << "\n\n                 CONGRATULATION..." << endl;
    cout << "                 sign up successfully." << endl;
  }
  else
    cout << "\t\tSorry user already exist." << endl;
  cout << "\t\tpress any key to continue:";
  getch();
  clearScreen();
}
void signIn()
{
  string uN, uP;
  cout << "\n\t\tEnter user name       :";
  cin >> uN;
  cout << "\t\tEnter user Password   :";
  cin >> uP;
  string userRole = checkUserRole(uN, uP);
  clearScreen();
  if (userRole == "Member")
  {
    clearScreen();
    cout << "\n\t\tCONGRATULATION..." << endl;
    cout << "\t\tSigng in successfully." << endl;
    cout << "\n\t\tPress any key to move furthor:";
    getch();
    memberInterface();
  }
  else if (userRole == "Librarion")
  {
    cout << "\n\t\tCONGRATULATION..." << endl;
    cout << "\t\tSing in successfully." << endl;
    cout << "\n\t\tPress any key to move furthor:";
    getch();
    librarionInterface();
  }
  else
    cout << "\t\tSorry user does not found" << endl;
  cout << "\t\tPress any key to go main menu:";
  getch();
}
string checkUserRole(string userName, string userPassword)
{
  for (int i = 0; i < userCout; i++)
  {
    if (member[i].userName == userName && member[i].password == userPassword)
      return member[i].role;
  }
  return "not found";
}

void bookManagement()
{
  char choice = ' ';
  while (choice != '0')
  {
    clearScreen();
    cout << "\n         ======== BOOKS MANAGEMENT ========";
    cout << "\n\n           1.Add new books ";
    cout << "\n           2.Delete book.";
    cout << "\n           3.View all books. ";
    cout << "\n           4.Find a specific book.";
    cout << "\n           0.Exit the menu.\n";
    cout << "\n           choice :";
    choice = getch();
    switch (choice)
    {
    case '1':
      addBook();
      break;
    case '2':
      deleteBook();
      break;
    case '3':
      viewAllBooks();
      break;
    case '4':
      searchBook();
      break;
    case '0':
    {
      cout << "\n\t\tPress any key to exit book management menu:";
      getch();
    }
    }
  }
}
void viewAllBooks()
{
  clearScreen();
  bookHeader();
  for (int i = 0; i < bookCount; i++)
  {
    showBook(i);
  }
 cout<<"\n\n\t\tPress any key to return:";
  getch();
  clearScreen(); 
}
void viewAllAvailableBooks()
{
  clearScreen();
  bookHeader();
  for (int i = 0; i < bookCount; i++)
  {
    if (book[i].available)
      showBook(i);
  }
  cout<<"\n\n\t\tPress any key to return:";
  getch();
}
void notAvailableBooks()
{
  clearScreen();
  bookHeader();
  for (int i = 0; i < bookCount; i++)
  {
    if (book[i].available==false)
      showBook(i);
  }
  cout<<"\n\n\t\tPress any key to return:";
  getch();
  clearScreen();
}

int searchBook()
{
  string title = "";
  while (true)
  {
    int desiredBookIdx = -1;
    cout << "Enter book name:" << title;
    title = title + char(getch());
    clearScreen();
    bookHeader();
    for (int i = 0; i < bookCount; i++)
    {
      bool check = isBookMatch(i, title);
      if (check)
      {
        showBook(i);
        desiredBookIdx = i;
      }
    }
    cout << "\n\t\t Book found? (Y/N)";
    char choice = getch();
    if (choice == 'y' || choice == 'Y')
    {
      clearScreen();
      return desiredBookIdx;
    }
  }
}

bool isBookMatch(int i, string title)
{
  for (int j = 0; j < title.length(); j++)
    if (title[j] != book[i].title[j])
      return false;
  return true;
}
void showBook(int idx)
{
  cout << left << setw(15) << " " << setw(10) << book[idx].isbn << setw(25) << book[idx].title << setw(25) << book[idx].author << setw(10) << book[idx].price << setw(10) << book[idx].category;
  if (book[idx].available)
    cout << "     Available    ";
  else
    cout << "     Not available";
  cout << endl;
}
void bookHeader()
{
  cout << "               ________________________________________________________________________________________" << endl;
  cout << left << setw(15) << " " << setw(10) << "ISBN" << setw(25) << "TITLE" << setw(25) << "AUTHOR" << setw(10) << "PRICE" << setw(10) << "CATEGORY" << "     STATUS      " << endl;
  cout << "               ----------------------------------------------------------------------------------------" << endl;
}

void memberManagement()
{
  char choice = ' ';
  while (choice != 0)
  {
    clearScreen();
    cout << "    \t======MEMBER MANAGEMENT======\n\n";
    cout << "\t\t1.Show all existing members.";
    cout << "\n\t\t2.Find member.";
    cout << "\n\t\t3.Add new member.";
    cout << "\n\t\t4.Remove existing member.";
    cout << "\n\t\t0.Exit.";
    cout << "\n\n\t\tchoice:";
    choice = getch();
    switch (choice)
    {
    case '1':
      viewAllMembers();
      break;
    case '2':
    {
      clearScreen();
      searchMember();
      break;
    }
    case '3':
      signUp();
      break;
    case '4':
      removeMember();
      break;
    case '0':
    {
      cout << "\n\n\t\tPress any key to exit menu:";
      getch();
      break;
    }
    }
  }
}
void removeMember()
{
  char choice = 'n';
  clearScreen();
  int idx = searchMember();
  if (idx < 0)
  {
    cout << "\n\t\tUser does't found.";
    cout << "\n\t\tPress any key to go previous menu:";
    getch();
    return;
  }
  memberHeader();
  showMember(idx);
  cout << "\n\t\tDo you want to remove:\n";
  cout << "\n\t\t Y.  Yes";
  cout << "\n\t\t N.  No";
  choice = getch();
  if (choice == 'y' || choice == 'Y')
  {
    while (idx < userCout - 1)
    {
      member[idx].userName = member[idx + 1].userName;
      member[idx].password = member[idx + 1].password;
      member[idx].role = member[idx + 1].role;
      member[idx].haveBook = member[idx + 1].haveBook;
      idx++;
    }
    userCout--;
    cout << "\n\t\t" << member[idx].userName << " has been successfully removed from record.";
    cout << "\n\t\tDo you want to remove an other member(Y/N)";
    choice = getch();
    if (choice == 'y' || choice == 'Y')
      removeMember();
  }
}
void viewAllMembers()
{
  clearScreen();
  memberHeader();
  for (int i = 0; i < userCout; i++)
    showMember(i);
  cout << "\n\t\tPress any key to move previous menu:";
  getch();
  clearScreen();
}
void memberHeader()
{
  cout << "               ___________________________________________________________________________" << endl;
  cout << left << setw(15) << " " << setw(20) << "USER NAME" << setw(18) << "PASSWORD" << setw(15) << "   ROLE" << "BOOK STATUS" << endl;
  cout << "               ----------------------------------------------------------------------------" << endl;
}
void showMember(int idx)
{
  cout << left << setw(15) << " " << setw(20) << member[idx].userName << setw(18) << member[idx].password << setw(15) << member[idx].role << endl;
  if (member[idx].role == "Member")
  {
    if (member[idx].haveBook)
      cout << "Issued";
    else
      cout << "Not Issued";
  }
  cout << endl;
}
int searchMember()
{
  string userName = "";
  while (true)
  {
    int desiredMemberIdx = -1;
    cout << "\n\t\tEnter user name:" << userName;
    userName = userName + char(getch());
    clearScreen();
    memberHeader();
    for (int i = 0; i < userCout; i++)
    {
      bool check=isMemberMatch(i,userName);
      if (check)
      {
        showMember(i);
        desiredMemberIdx = i;
      }
    }

    cout << "\n\t\t Member found? (Y/N)";
    char choice = getch();
    if (choice == 'y' || choice == 'Y')
    {
      clearScreen();
      return desiredMemberIdx;
    }
  }
}
bool isMemberMatch(int i,string userName)
{
  for (int j = 0; j < userName.length(); j++)
        if (userName[j] != member[i].userName[j])
          return false;
       return true;   
}

void circulationOfBooks()
{
  char choice = ' ';
  while(choice!='0')
  {
  clearScreen();
  cout << "\n\n\t======= CIRCULATION =======";
  cout << "\n\t\t1.Issue a Book";
  cout << "\n\t\t2.Return a book";
  cout << "\n\t\t3.View Issued Books";
  cout << "\n\t\t4.View available Books";
  cout << "\n\t\t0.Exit Menu";
  cout << "\n\n\t\tchoice :";
  choice = getch();

  switch (choice)
  {
  case '1':
    issueBook();
    break;
  case '2':
     returnBook(); 
     break;
  case '3':
     notAvailableBooks(); 
     break;
  case '4':
      viewAllAvailableBooks();        
  }
}
}
void issueBook()
{
  int bookIdx=searchBook();
  int memberIdx=searchMember();
  if(bookIdx<0 )
  {
    cout<<"\n\t\tBook does not found: ";
    cout<<"\n\t\tPress any key to exit:";
    getch();
    return ;
  }
  if(memberIdx<0 )
  {
    cout<<"\n\t\tMember does not found: ";
    cout<<"\n\t\tPress any key to exit:";
    getch();
    return ;
  }
  cout<<"\n\n\n\t\tDo you want to issue :"<<book[bookIdx].title<<"  to  "<<member[memberIdx].userName<<"  ( y/n):";
  char choice=getch();
  if(choice=='y' || choice=='Y')
  {
  member[memberIdx].haveBook==true;
  book[bookIdx].available=false;
  book[bookIdx].issuedPersonID=memberIdx;
  cout<<"\n\n\t\tBook has been successfully issued:";
  cout<<"\n\t\tPress any key to continue:";
  getch();
  return ;
  }
}
void returnBook()
 {
   int bookIdx=searchBook();
   int borrowerIdx=book[bookIdx].issuedPersonID;
   if(bookIdx<0 )
  {
    cout<<"\n\t\tBook does not found: ";
    cout<<"\n\t\tPress any key to exit:";
    getch();
    return ;
  }
  if(borrowerIdx<0 )
  {
    cout<<"\n\t\tBook is not issued to: "<<member[borrowerIdx].userName;
    cout<<"\n\t\tPress any key to exit:";
    getch();
    return ;
  }
   cout<<"\n\t\t"<<book[bookIdx].title <<" is issued to " <<member[borrowerIdx].userName;
   cout<<"\n\t\tPress any key to confirm.";
   getch();
   member[borrowerIdx].haveBook=false;
   book[bookIdx].available=true;
   book[bookIdx].issuedPersonID=-1;
	cout<<"\n\t\tBook has been successfully recovered.";
   cout<<"\n\t\tPress any key to go previous menu";
   getch();
   clearScreen();
  
 }