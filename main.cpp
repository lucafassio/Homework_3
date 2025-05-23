#include <iostream>
#include <limits>
using namespace std;

//esto esta sacado de internet, es para limpiar la terminal nomas.
void clearScreen();
void clearScreen(){
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

int main(){
    try{
        while(true){
            clearScreen();
            cout << "===================== Homework 3 =====================" << endl;
            cout << "Choose an exercise to run:" << endl;
            cout << "1. Flight Data" << endl;
            cout << "2. Figures" << endl;
            cout << "3. JSON Constructor" << endl;
            cout << "0. Exit" << endl;
            cout << "> ";
            int choice;
            cin >> choice;
            while (!cin.good() || choice < 0 || choice > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Select a valid option.\n> ";
                cin >> choice;
            }
            switch (choice){
                case 0: return 0;
                case 1: system("cd Ej1 && make serial"); system("cd Ej1 && make deserial"); break;
                case 2: system("cd Ej2 && make"); break;
                case 3: system("cd Ej3 && make"); break;
            }
            cout << "Press enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }
    catch (const exception& e){
        cout << "Something bad happened :( - " << e.what() << endl;
    }
}