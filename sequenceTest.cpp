// FILE: sequenceTest.cpp
// An interactive test program for the sequence class

#include <cctype>      // provides toupper
#include <iostream>    // provides cout and cin
#include <cstdlib>     // provides EXIT_SUCCESS
#include "sequence.h"
#include "Tsequence.h"

namespace seqOfNum  = CS3358_FA2023_A04_sequenceOfNum;
namespace seqOfChar = CS3358_FA2023_A04_sequenceOfChar;
using namespace std;

// PROTOTYPES for functions used by this test program:

void print_menu();
// Pre:  (none)
// Post: A menu of choices for this program is written to cout.
char get_user_command();
// Pre:  (none)
// Post: The user is prompted to enter a one character command.
//       The next character is read (skipping blanks and newline
//       characters), and this character is returned.

template<class T>
void show_list( assignment04::sequence<T> src);
// Pre: (none)
// Post: The items of src are printed to cout (one per line).
int get_object_num();
// Pre:  (none)
// Post: The user is prompted to enter either 1 or 2. The
//       prompt is repeated until a valid integer can be read
//       and the integer's value is either 1 or 2. The valid
//       integer read is returned. The input buffer is cleared
//       of any extra input until and including the first
//       newline character.
double get_number();
// Pre:  (none)
// Post: The user is prompted to enter a real number. The prompt
//       is repeated until a valid real number can be read. The
//       valid real number read is returned. The input buffer is
//       cleared of any extra input until and including the
//       first newline character.
char get_character();
// Pre:  (none)
// Post: The user is prompted to enter a non-whitespace character.
//       The prompt is repeated until a non-whitespace character
//       can be read. The non-whitespace character read is returned.
//       The input buffer is cleared of any extra input until and
//       including the first newline character.

int main(int argc, char *argv[])
{
    assignment04::sequence<int> integers;
    assignment04::sequence<char> characters;

   seqOfNum::sequence s1;  // A sequence of double for testing
   seqOfChar::sequence s2; // A sequence of char for testing

   int objectNum;    // A number to indicate selection of s1 or s2
   double numHold;   // Holder for a real number
   char charHold;    // Holder for a character
   char choice;      // A command character entered by the user

   cout << "An empty sequence of real numbers (s1) and\n"
        << "an empty sequence of characters (s2) have been created."
        << endl;

   do
   {
      if (argc == 1)
         print_menu();
      choice = toupper( get_user_command() );
      switch (choice)
      {
         case '!':
            objectNum = get_object_num();
            if (objectNum == 1)
            {
               integers.start();
               cout << "integers started" << endl;
            }
            else
            {
               characters.start();
               cout << "characters started" << endl;
            }
            break;
         case '&':
            objectNum = get_object_num();
            if (objectNum == 1)
            {
               integers.end();
               cout << "integers ended" << endl;
            }
            else
            {
               characters.end();
               cout << "characters ended" << endl;
            }
            break;
         case '+':
            objectNum = get_object_num();
            if (objectNum == 1)
            {
               if ( ! integers.is_item() )
                  cout << "Can't advance s1." << endl;
               else
               {
                  integers.advance();
                  cout << "Advanced s1 one item."<< endl;
               }
            }
            else
            {
               if ( ! characters.is_item() )
                  cout << "Can't advance characters." << endl;
               else
               {
                  characters.advance();
                  cout << "Advanced characters one item."<< endl;
               }
            }
            break;
         case '-':
            objectNum = get_object_num();
            if (objectNum == 1)
            {
               if ( ! integers.is_item() )
                  cout << "Can't move back integers." << endl;
               else
               {
                  integers.move_back();
                  cout << "Moved integers back one item."<< endl;
               }
            }
            else
            {
               if ( ! characters.is_item() )
                  cout << "Can't move back characters." << endl;
               else
               {
                  characters.move_back();
                  cout << "Moved characters back one item."<< endl;
               }
            }
            break;
         case '?':
            objectNum = get_object_num();
            if (objectNum == 1)
            {
               if ( integers.is_item() )
                  cout << "integers has a current item." << endl;
               else
                  cout << "integers has no current item." << endl;
            }
            else
            {
               if ( characters.is_item() )
                  cout << "characters has a current item." << endl;
               else
                  cout << "characters has no current item." << endl;
            }
            break;
         case 'C':
            objectNum = get_object_num();
            if (objectNum == 1)
            {
               if ( integers.is_item() )
                  cout << "Current item in integers is: "
                       << integers.current() << endl;
               else
                  cout << "integers has no current item." << endl;
            }
            else
            {
               if ( characters.is_item() )
                  cout << "Current item in characters is: "
                       << characters.current() << endl;
               else
                  cout << "characters has no current item." << endl;
            }
            break;
         case 'P':
            objectNum = get_object_num();
            if (objectNum == 1)
            {
               if (integers.size() > 0)
               {
                  cout << "integers: ";
                  show_list(integers);
                  cout << endl;
               }
               else
                  cout << "integers is empty." << endl;
            }
            else
            {
               if (characters.size() > 0)
               {
                  cout << "characters: ";
                  show_list(characters);
                  cout << endl;
               }
               else
                  cout << "characters is empty." << endl;
            }
            break;
         case 'S':
            objectNum = get_object_num();
            if (objectNum == 1)
               cout << "Size of integers is: " << integers.size() << endl;
            else
               cout << "Size of characters is: " << characters.size() << endl;
            break;
         case 'A':
            objectNum = get_object_num();
            if (objectNum == 1)
            {
               numHold = get_number();
               integers.add(numHold);
               cout << numHold << " added to integers." << endl;
            }
            else
            {
               charHold = get_character();
               characters.add(charHold);
               cout << charHold << " added to characters." << endl;
            }
            break;
         case 'R':
            objectNum = get_object_num();
            if (objectNum == 1)
            {
               if ( integers.is_item() )
               {
                  numHold = integers.current();
                  integers.remove_current();
                  cout << numHold << " removed from integers." << endl;
               }
               else
                  cout << "integers has no current item." << endl;
            }
            else
            {
               if ( characters.is_item() )
               {
                  charHold = characters.current();
                  characters.remove_current();
                  cout << charHold << " removed from characters." << endl;
               }
               else
                  cout << "characters has no current item." << endl;
            }
            break;
         case 'Q':
            cout << "Quit option selected...bye" << endl;
            break;
         default:
            cout << choice << " is invalid...try again" << endl;
      }
   }
   while (choice != 'Q');

   cin.ignore(999, '\n');
   cout << "Press Enter or Return when ready...";
   cin.get();
   return EXIT_SUCCESS;
}

void print_menu()
{
   cout << endl;
   cout << "The following choices are available:\n";
   cout << "  !  Activate the start() function\n";
   cout << "  &  Activate the end() function\n";
   cout << "  +  Activate the advance() function\n";
   cout << "  -  Activate the move_back() function\n";
   cout << "  ?  Print the result from the is_item() function\n";
   cout << "  C  Print the result from the current() function\n";
   cout << "  P  Print a copy of the entire sequence\n";
   cout << "  S  Print the result from the size() function\n";
   cout << "  A  Add a new item with the add(...) function\n";
   cout << "  R  Activate the remove_current() function\n";
   cout << "  Q  Quit this test program" << endl;
}

char get_user_command()
{
   char command;

   cout << "Enter choice: ";
   cin >> command;

   cout << "You entered ";
   cout << command << endl;
   return command;
}

template<class T>
void show_list(assignment04::sequence<T> src)
{
   for ( src.start(); src.is_item(); src.advance() )
      cout << src.current() << "  ";
}

int get_object_num()
{
   int result;

   cout << "Enter object # (1 = s1, 2 = s2) ";
   cin  >> result;
   while ( ! cin.good() )
   {
      cerr << "Invalid integer input..." << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Re-enter object # (1 = s1, 2 = s2) ";
      cin  >> result;
   }
   // cin.ignore(999, '\n');

   while (result != 1 && result != 2)
   {
      cin.ignore(999, '\n');
      cerr << "Invalid object # (must be 1 or 2)..." << endl;
      cout << "Re-enter object # (1 = s1, 2 = s2) ";
      cin  >> result;
      while ( ! cin.good() )
      {
         cerr << "Invalid integer input..." << endl;
         cin.clear();
         cin.ignore(999, '\n');
         cout << "Re-enter object # (1 = s1, 2 = s2) ";
         cin  >> result;
      }
      // cin.ignore(999, '\n');
   }

   cout << "You entered ";
   cout << result << endl;
   return result;
}

double get_number()
{
   double result;

   cout << "Enter a real number: ";
   cin  >> result;
   while ( ! cin.good() )
   {
      cerr << "Invalid real number input..." << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Re-enter a real number ";
      cin  >> result;
   }
   // cin.ignore(999, '\n');

   cout << "You entered ";
   cout << result << endl;
   return result;
}

char get_character()
{
   char result;

   cout << "Enter a non-whitespace character: ";
   cin  >> result;
   while ( ! cin )
   {
      cerr << "Invalid non-whitespace character input..." << endl;
      cin.ignore(999, '\n');
      cout << "Re-enter a non-whitespace character: ";
      cin  >> result;
   }
   // cin.ignore(999, '\n');

   cout << "You entered ";
   cout << result << endl;
   return result;
}
