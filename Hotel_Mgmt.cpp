#include <iostream>
using namespace std;

int main() {
    int quantity;
    int choice;

    int Qrooms=0,Qpasta=0,Qpizza=0,Qburger=0,Qsandwich=0; // Quantity of items
    int Srooms=0,Spasta=0,Spizza=0,Sburger=0,Ssandwich=0; // Sold of items
    int Trooms=0,Tpasta=0,Tpizza=0,Tburger=0,Tsandwich=0; // Total price
    // int total=0;

    cout << "\n\t Quantity of items we have: ";
    cout << "\n\t 1. Rooms: available ";
    cin >> Qrooms;
    cout << "\n\t 2. Pasta: available ";
    cin >> Qpasta;
    cout << "\n\t 3. Pizza: available ";
    cin >> Qpizza;
    cout << "\n\t 4. Burger: available ";
    cin >> Qburger;
    cout << "\n\t 5. Sandwich: available ";
    cin >> Qsandwich;

    while (true) {
        cout << "\n\t Welcome to the hotel: ";
        cout << "\n\t Please select from the menu options: ";
        cout << "\n\t 1. Rooms: ";
        cout << "\n\t 2. Pasta: ";
        cout << "\n\t 3. Pizza: ";
        cout << "\n\t 4. Burger: ";
        cout << "\n\t 5. Sandwich: ";
        cout << "\n\t 6. Details regarding sales and collection: ";
        cout << "\n\t 7. Exit: ";

        cout << "\n\t Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\n\t Enter the quantity of rooms you want: ";
                cin >> quantity;
                if(Qrooms-Srooms >= quantity) {
                    Srooms += quantity;
                    Trooms += quantity * 1000; // let the price of room be 1000
                    cout << "\n\t Rooms successfully alloted to you!";
                } else {
                    cout << "\n\t Only " << Qrooms-Srooms << " rooms are available!";
                }
                break;
            case 2: 
                cout << "\n\t Enter the quantity of pasta you want: ";
                cin >> quantity;
                if(Qpasta-Spasta >= quantity) {
                    Spasta += quantity;
                    Tpasta += quantity * 200; // let the price of pasta be 200
                    cout << "\n\t Pasta successfully alloted to you!";
                } else {
                    cout << "\n\t Only " << Qpasta-Spasta << " pasta are available!";
                }
                break;  
            case 3:
                cout << "\n\t Enter the quantity of pizza you want: ";
                cin >> quantity;
                if(Qpizza-Spizza >= quantity) {
                    Spizza += quantity;
                    Tpizza += quantity * 300; // let the price of pizza be 300
                    cout << "\n\t Pizza successfully alloted to you!";
                } else {
                    cout << "\n\t Only " << Qpizza-Spizza << " pizza are available!";
                }
                break;  
            case 4:
                cout << "\n\t Enter the quantity of burger you want: ";
                cin >> quantity;
                if(Qburger-Sburger >= quantity) {
                    Sburger += quantity;
                    Tburger += quantity * 150; // let the price of burger be 150
                    cout << "\n\t Burger successfully alloted to you!";
                } else {
                    cout << "\n\t Only " << Qburger-Sburger << " burger are available!";
                }
                break;  
            case 5:
                cout << "\n\t Enter the quantity of sandwich you want: ";
                cin >> quantity;
                if(Qsandwich-Ssandwich >= quantity) {
                    Ssandwich += quantity;
                    Tsandwich += quantity * 100; // let the price of sandwich be 100
                    cout << "\n\t Sandwich successfully alloted to you!";
                } else {
                    cout << "\n\t Only " << Qsandwich-Ssandwich << " sandwich are available!";
                    cout<<"....................";
                }
                break;  
            case 6:
                cout << "\n\t Details regarding sales and collection: ";
                cout << "\n\t 1. No. of Rooms we had: " << Qrooms << " \n No. of rooms sold: " << Srooms << "\n Remaining rooms: " << Qrooms-Srooms << "\n\n Total collection: " << Trooms;
                cout << "\n\t 2. No. of Pasta we had: " << Qpasta << "\n No. of pasta sold: " << Spasta << "\n Remaining pasta: " << Qpasta-Spasta << "\n\n Total collection: " << Tpasta;
                cout << "\n\t 3. No. of Pizza we had: " << Qpizza << "\n No. of pizza sold: " << Spizza << "\n Remaining pizza: " << Qpizza-Spizza << "\n\n Total collection: " << Tpizza;
                cout << "\n\t 4. No. of Burger we had: " << Qburger << "\n No. of burger sold: " << Sburger << "\n Remaining burger: " << Qburger-Sburger << "\n\n Total collection: " << Tburger;
                cout << "\n\t 5. No. of Sandwich we had: " << Qsandwich << "\n No. of sandwich sold: " << Ssandwich << "\n Remaining sandwich: " << Qsandwich-Ssandwich << " \n\n Total collection: " << Tsandwich;
                break;  
            case 7:
                cout << "\n\t Thank you for visiting!";
                return 0;
            default:
                cout << "\n\t Please enter a valid choice!";
        }
    }
    return 0;
}