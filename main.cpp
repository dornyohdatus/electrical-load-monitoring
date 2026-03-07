#include <iostream>
#include <string>

using namespace std;

class Appliance
{
public:
    string name;
    double powerRating;
    double usageHours;

    void registerAppliance()
    {
        cout << "Enter appliance name: ";
        cin >> name;

        cout << "Enter power rating (Watts): ";
        cin >> powerRating;

        cout << "Enter daily usage hours: ";
        cin >> usageHours;
    }

    void displayAppliance()
    {
        cout << "\nAppliance Name: " << name << endl;
        cout << "Power Rating: " << powerRating << " Watts" << endl;
        cout << "Usage Hours: " << usageHours << " hours/day" << endl;
    }
};

int main()
{

    Appliance appliances[10];
    int count = 0;
    int choice;

    do
    {

        cout << "\n===== Electrical Load Monitoring System =====\n";
        cout << "1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            appliances[count].registerAppliance();
            count++;
            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                appliances[i].displayAppliance();
            }
            break;

        case 3:
            cout << "Program exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}