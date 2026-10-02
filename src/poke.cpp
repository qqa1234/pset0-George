#include "poke.h"

int main() {
    Move M1("M1", 90);
    Move M2("M2", 40);
    Move M3("M3", 90);
    Move M4("M4", 40);

    Pokemon a("a", 55, 120);
    Pokemon b("b", 52, 130);

    a.addMove(M1);
    a.addMove(M2);

    b.addMove(M3);
    b.addMove(M4);

    a.useMove(b, 0);
    std::cout << "b health: " << b.health << std::endl;

    b.useMove(a, 0);
    std::cout << "a health: " << a.health << std::endl;

    a.useMove(b, 1);
    std::cout << "b health: " << b.health << std::endl;

    b.useMove(a, 1);
    std::cout << "a health: " << a.health << std::endl;

    return 0;
}