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
    std::string winnerName = "";

    Fighter* first;
    Fighter* second;

    if(firstAttacker == fighter1->getName())
    {
        first = fighter1;
        second = fighter2;
    }
    else
    {
        first = fighter2;
        second = fighter1;
    }

    int dmg = 0;
    int hp = 0;

    while(true)
    {
        dmg = first->getDamagePerAttack();
        hp = second->getHealth();

        second->setHealth(hp-dmg);

        if(second->getHealth() <= 0)
        {
            winnerName = first->getName();
            break;
        }

        dmg = second->getDamagePerAttack();
        hp = first->getHealth();

        first->setHealth(hp-dmg);

        if(first->getHealth() <= 0)
        {
            winnerName = second->getName();
            break;
        }
    }

    return winnerName;
}