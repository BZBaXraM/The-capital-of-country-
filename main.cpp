#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <cstdlib>

enum class MENU {
    ADD = 1, REMOVE = 2, WATCH = 3, GAME = 4, EXIT = 5
};

using namespace std;

void add(map<string, string> &m, string capital, string country);

void remove(map<string, string> &m, string capital);

void showCounties(map<string, string> &m);

void Game(map<string, string> counties);

int main() {
    int menu{};

    map<string, string> myMap = {
            {"Kiev",       "Ukraine"},
            {"Baku",       "Azerbaijan"},
            {"Ankara",     "Turkey"},
            {"Washington", "USA"},
            {"Moscow",     "Russia"}


    };
    do {
        cout << "\n\n";
        cout <<
             "1. Add country and capital\n"
             "2. Remove country and capital\n"
             "3. View the list of Countries - capitals\n"
             "4. Play\n"
             "5. Exit\n"
             "Your choice: " << endl;
        cout << ">>> ";

        cout << "\n";

        string capital;
        string country;
        cin >> menu;
        switch (menu) {
            case static_cast<int>(MENU::ADD):
                cout << "Enter capital and country: ";
                cin >> capital >> country;
                add(myMap, capital, country);
                break;
            case static_cast<int>(MENU::REMOVE):
                cout << "Enter capital and country for remove: ";
                cin >> capital;
                remove(myMap, capital);
                break;

            case static_cast<int>(MENU::WATCH):
                showCounties(myMap);
                break;
            case static_cast<int>(MENU::GAME):
                Game(myMap);
                break;
            case static_cast<int>(MENU::EXIT):
                exit(0);


        }
    } while (true);
    return 0;
}

void add(map<string, string> &m, string capital, string country) {
    m.emplace(capital, country);
}

void remove(map<string, string> &m, string capital) {
    try {
        m.erase(m.find(capital));
    } catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
    }
}

void showCounties(map<string, string> &m) {
    for (const auto&[capital, country]: m) {
        cout << capital << " - " << country << endl;
    }
}

void Game(map<string, string> counties) {
    int points = 40;
    string country;

    cout << "Welcome to my game! " << endl;


    while (!counties.empty()) {
        if (points == 0) {
            cout << "You lose :(" << endl;

            exit(0);
        }

        auto itr = counties.begin();

        cout << "Which country's capital is " << itr->first << "?: ";
        cin >> country;

        if (country == itr->second) {
            points += 10;

            cout << "Right!\nYour score is: " << points << std::endl;
            counties.erase(itr);
        } else {
            points -= 10;

            cout << "Wrong!\nYour score is: " << points << endl;
            counties.erase(itr);
        }
    }

    cout << "You win!" << endl;
}