#include <string>
#include <vector>
#include <iostream>

class Move {
private:
    std::string name;
    int power;

public:
    Move(std::string moveName, int movePower) {
        name = moveName;
        power = movePower;
    }

    std::string getName() const {
        return name;
    }

    int getPower() const {
        return power;
    }
};

struct Pokemon {
    std::string name;
    int attack;
    int health;
    std::vector<Move> moveset;

    Pokemon(std::string pokemonName, int pokemonAttack, int pokemonHealth) {
        name = pokemonName;
        attack = pokemonAttack;
        health = pokemonHealth;
    }

    void addMove(Move move) {
        moveset.push_back(move);
    }

    void useMove(Pokemon& otherPokemon, int moveIndex) {
        Move move = moveset[moveIndex];

        int damage = attack * move.getPower() / 100;

        otherPokemon.health -= damage;

        std::cout << name << " used " << move.getName() << "!" << std::endl;
    }
};