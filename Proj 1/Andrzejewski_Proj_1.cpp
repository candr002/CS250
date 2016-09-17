#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "complexStuff.h"

using namespace std;







 int main()
  {
      bool fileUpdated = false;
      /// Used to track if a file was loaded for use

      string fileName;
      /// DUH....

      ifstream numListFile;
      ///File

      int choice = 0;
      ///For the menu

      complexNums numlist;
      complexNums *header = &numlist;
      complexNums *current = NULL;
      ///Pointers for the number list


      while (choice !=5 )
    /// While loop for the user to do multiple things in one go
        {
            displayMenu();
            cin >> choice;
            switch (choice)
            {
                case 1:
        ///Used for building the list
                    {
                    cout << "\n\nYou have chosen " << choice << " I shall do my best to help...\n\n";
                    cout << "Please tell me the NAME of the FILE you want me to load from\n\n";
                    /// Taking filename as input from user
                    cin.clear();
                    cin.sync();
                    getline(cin, fileName);
                    cin.clear();
                    cin.sync();
                    ///using input to open requested file
                    numListFile.open(fileName.c_str());
                        if (!numListFile)
                        ///  Error Checking file access
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cerr << "\n\nInvalid FILE NAME please try again!\n\n";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                            break;
                        }
                    current = header;
                    ///  Creating a usable pointer so header isn't messed with
                    numlist.inputStuff(numListFile, current);
                    fileUpdated = true;
                    break;
                    };
                case 2:
        ///Used for displaying the list
                    {
                    if (fileUpdated == true)
                        {
                        cout << "\n\nYou have chosen " << choice << " I shall do my best to help...\n";
                        current = header;
                        numlist.displayStuff(current);
                        break;
                        }
                    else
                        {
                        errorMsg();
                        break;
                        }
                    };
                case 3:
            ///Used for summing the numbers in the list
                    {
                    if (fileUpdated == true)
                        {
                        cout << "\n\nYou have chosen " << choice << " I shall do my best to help...\n";
                        current = header;
                        numlist.sumStuff(current);
                        break;
                        }
                    else
                        {
                        errorMsg();
                        break;
                        }
                    };
                case 4:
        ///Used for multiplying the list
                    {
                    if (fileUpdated == true)
                        {
                        cout << "You have chosen " << choice << " I shall do my best to help...\n";
                        current->multiplyStuff(current);
                        break;
                        }
                    else
                        {
                        errorMsg();
                        break;
                        }
                    };
                case 5:
        ///Used for exiting
                    {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    cout << "\n\nYou have chosen " << choice << ". Goodbye! I will miss you :( \n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                    return 0;
                    };
                default :
        ///Used for input error
                    {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "\n\nThat is not a valid number silly! Please try again...\n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    };
            }
        };
    numListFile.close();
    return 0;
  };
