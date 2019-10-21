// c++ code-war
/*
issue description

Create a function that returns the name of the winner in a fight between two fighters.

Each fighter takes turns attacking the other and whoever kills the other first is victorious. Death is defined as having health <= 0.

Each fighter will be a Fighter object/instance. See the Fighter class below in your chosen language.

Both health and damagePerAttack (damage_per_attack for python) will be integers larger than 0. You can mutate the Fighter objects.

Example:
class Fighter
{
private:
    std::string name;

    int health;

    int damagePerAttack;

public:
    Fighter(std::string name, int health, int damagePerAttack)
    {
        this->name = name;
        this->health = health;
        this->damagePerAttack = damagePerAttack;
    }

    ~Fighter() { };

    std::string getName()
    {
        return name;
    }

    int getHealth()
    {
        return health;
    }

    int getDamagePerAttack()
    {
        return damagePerAttack;
    }

    void setHealth(int value)
    {
        health = value;
    }
};
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fighter
{
private:
    std::string name;

    int health;

    int damagePerAttack;

public:
    Fighter(std::string name, int health, int damagePerAttack)
    {
        this->name = name;
        this->health = health;
        this->damagePerAttack = damagePerAttack;
    }

    ~Fighter() { };

    std::string getName()
    {
        return name;
    }

    int getHealth()
    {
        return health;
    }

    int getDamagePerAttack()
    {
        return damagePerAttack;
    }

    void setHealth(int value)
    {
        health = value;
    }
};

std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker);

int main()
{

    return 0;
}

std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker)
{
 // Number of blows each fighter can survive:
 int n1 = (fighter1->getHealth() - 1) / fighter2->getDamagePerAttack();
 int n2 = (fighter2->getHealth() - 1) / fighter1->getDamagePerAttack();
 
 return n1 > n2 ? fighter1->getName()
      : n1 < n2 ? fighter2->getName()
      :           firstAttacker;
}