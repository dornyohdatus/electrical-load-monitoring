#include <iostream>
#include <string>
#include <fstream>

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

    double calculateEnergy()
    {
        return (powerRating * usageHours) / 1000;
    }

    void displayAppliance()
    {
        cout << "\nAppliance Name: " << name << endl;
        cout << "Power Rating: " << powerRating << " W" << endl;
        cout << "Usage Hours: " << usageHours << " hrs/day" << endl;
        cout << "Energy Consumption: " << calculateEnergy() << " kWh\n";
    }
    void saveToFile()
    {
        ofstream file("appliances.txt", ios::app);
        file << name << " " << powerRating << " " << usageHours << endl;
        file.close();
    }
};

int main()
{

    Appliance appliances[10];
    int count = 0;
    int choice;
    double totalEnergy = 0;
    double tariff;
    double bill;

    do
    {

        cout << "\n===== Electrical Load Monitoring System =====\n";
        cout << "1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Calculate Total Energy\n";
        cout << "4. Calculate Electricity Bill\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {

        case 1:
            if (count < 10)
            {
                appliances[count].registerAppliance();
                appliances[count].saveToFile();
                count++;
            }
            else
            {
                cout << "Maximum appliances reached!" << endl;
            }
            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                appliances[i].displayAppliance();
            }
            break;

        case 3:
            totalEnergy = 0;

            for (int i = 0; i < count; i++)
            {
                totalEnergy += appliances[i].calculateEnergy();
            }

            cout << "\nTotal Energy Consumption: " << totalEnergy << " kWh\n";
            break;

        case 4:

            totalEnergy = 0;

            for (int i = 0; i < count; i++)
            {
                totalEnergy += appliances[i].calculateEnergy();
            }

            cout << "Enter electricity tariff per kWh: ";
            cin >> tariff;

            bill = totalEnergy * tariff;

            cout << "\n===== BILLING SUMMARY =====\n";
            cout << "Total Energy: " << totalEnergy << " kWh\n";
            cout << "Tariff: " << tariff << " per kWh\n";
            cout << "Total Bill: " << bill << endl;

            break;
        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}