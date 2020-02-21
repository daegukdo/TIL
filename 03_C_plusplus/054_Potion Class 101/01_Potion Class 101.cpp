// c++ code-war
/*
issue description

Potion Class 101

Description
This is your first potion class in Hogwarts and professor gave you a homework to figure out what color potion will turn into if he'll mix it with some other potion. 

All potions have some color that written down as RGB color from [0, 0, 0] to [255, 255, 255]. 

To make task more complicated teacher will do few mixing and after will ask you for final color. 

Besides color you also need to figure out what volume will have potion after final mix.

Task
Based on your programming background you managed to figure that after mixing two potions colors will mix as if mix two RGB colors. 

For example, if you'll mix potion that have color [255, 255, 0] and volume 10 with one that have color [0, 254, 0] and volume 5, 
you'll get new potion with color [170, 255, 0] and volume 15. 

So you decided to create a class Potion that will have two properties: color (a list with 3 integers) and volume (a number), 
and one method mix that will accept another Potion and return a mixed Potion.

Example
felix_felicis       =  Potion([255, 255, 255],  7)
shrinking_solution  =  Potion([ 51, 102,  51], 12)
new_potion          =  felix_felicis.mix(shrinking_solution)

new_potion.color   ==  [127, 159, 127]
new_potion.volume  ==  19
Note: Use ceiling when calculating the resulting potion's color.
*/

#include <array>
#include <cmath>

using namespace std;

class Potion 
{
public:
	std::array<unsigned char, 3> color;
    unsigned int volume;
  
    Potion(const std::array<unsigned char, 3>& color, unsigned int volume);
    
    Potion mix(const Potion& other);
};

Potion::Potion(const std::array<unsigned char, 3>& color, unsigned int volume)
{
	Potion::color = color;
	Potion::volume = volume;

	unsigned int R = color[0] - 0;
	unsigned int G = color[1] - 0;
	unsigned int B = color[2] - 0;

	return;
}

Potion Potion::mix(const Potion& other)
{
	unsigned int volumeSum = Potion::volume + other.volume;

	float ratio1 = Potion::volume / volumeSum;
	float ratio2 = other.volume / volumeSum;

	unsigned int R = (Potion::color[0] - 0) * ratio1 + (other.color[0] - 0) * ratio2;
	unsigned int G = (Potion::color[1] - 0) * ratio1 + (other.color[1] - 0) * ratio2;
	unsigned int B = (Potion::color[2] - 0) * ratio1 + (other.color[2] - 0) * ratio2;

	std::array<unsigned char, 3> r = {0, 0, 0};

	Potion result = Potion(r, 0);

	result.color[0] = R;
	result.color[1] = G;
	result.color[2] = B;
	result.volume = volumeSum;

	return result;
}

int main()
{
	std::array<unsigned char, 3> d1 = {255, 255, 255};
	Potion felix_felicis            =  Potion(d1,  7);
	
	std::array<unsigned char, 3> d2 = {255, 255, 255};
	Potion shrinking_solution       =  Potion(d2, 12);

	Potion new_potion               =  felix_felicis.mix(shrinking_solution);

	return 0;
}
