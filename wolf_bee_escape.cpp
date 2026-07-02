#include <iostream>
#include <cstdlib>
#include <ctime>

int randomEvent() {
    return std::rand() % 3;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int stamina = 5;
    int distance = 0;

    std::cout << "=== Wolf Trail Escape ===\n";

    while (stamina > 0 && distance < 60) {
        std::cout << "\nPress Enter to move forward...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        int event = randomEvent();

        if (event == 0) {
            std::cout << "Safe trail.\n";
            distance += 15;
        } else if (event == 1) {
            std::cout << "You hear the wolf nearby!\n";
            stamina--;
            distance += 8;
        } else {
            std::cout << "You found a resting spot.\n";
            stamina++;
            distance += 5;
        }

        std::cout << "Distance: " << distance << "\n";
        std::cout << "Stamina: " << stamina << "\n";
    }

    if (distance >= 60)
        std::cout << "\nYou escaped the forest!\n";
    else
        std::cout << "\nThe journey has ended.\n";

    return 0;
}
