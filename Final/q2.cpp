#include "q2.h"

void displayMenu();
void displayNEO(NEO *n);



int main()
{
    NEO *head = new NEO;
    NEO *current = head;
    head->setID(1);

    int menuSel;
    double temp =0;
    while (menuSel != 3)
    {
        displayMenu();
        cin >> menuSel;

        switch (menuSel)
        {
            case 1:
                cout << "You selected menu item " << menuSel <<".\n\n";
                while (current != NULL)
                    current = current->retNext();

                cout << "Please input the time in HOURS SINCE LAST DISCOVERY (eg. 5)\n";
                cin >> temp;
                current->setTime(temp);

                cout << "\nPlease input the distance in MILLIONS OF MILES FROM EARTH (eg. 132)\n";
                cin >> temp;
                current->setDist(temp);

                cout << "\nPlease input the AZIMUTH ANGLE of the NEO (eg. 222)\n";
                cin >> temp;
                current->setAzimuth(temp);

                cout << "\nPlease input the ELEVATION ANGLE of the NEO (eg. 155)\n";
                cin >> temp;
                current->setElevation(temp);

                cout << "\nPlease input the VECTOR X VALUE of the NEO (eg. 7)\n";
                cin >> temp;
                current->setXvector(temp);

                cout << "\nPlease input the VECTOR Y VALUE of the NEO (eg. 7)\n";
                cin >> temp;
                current->setYvector(temp);

                cout << "\nPlease input the VECTOR Z VALUE of the NEO (eg. 7)\n";
                cin >> temp;
                current->setZvector(temp);

                current->makeNext();

                break;

            case 2:
                cout << "You selected menu item " << menuSel <<". Displaying all known NEO's\n\n";
                break;

            case 3:
                cout << "You selected menu item " << menuSel <<". Exiting NNETS\n\n";
                break;

            default:
                cout << "You selected " << menuSel <<". Invalid selection, please input valid selection.\n\n";
                break;
        }
    }

    delete head;
    delete current;
    return 0;

}

///====================================================
void displayMenu()
{
    cout << "Welcome to the NORAD Near Earth Tracking System (NNETS)\n"
        << "Please select one of the below options:\n"
        <<"1. Log a Near Earth Object (NEO)\n"
        <<"2. View current listing of all Near Eath Objects (NEOs)\n"
        <<"3. Exit Tracking System\n";

}
///====================================================

///====================================================
void displayNEO(NEO *n)
{
    NEO *curr = new NEO;
    curr = n;

    cout << curr->retID() << "\t"
        << curr->retTime() << "\t"
        << curr->retDist() << ", "
        << curr->retAzimuth() << ", "
        << curr->retElevation() << "\t"
        << curr->retXvector() << "\t"
        << curr->retYvector() << "\t"
        << curr->retZvector() << "\n";

}
///====================================================
