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
