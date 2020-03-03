// c++ code-war
/*
issue description

Buying a car

Description

Let us begin with an example:

A man has a rather old car being worth $2000. He saw a secondhand car being worth $8000. 

He wants to keep his old car until he can buy the secondhand one.

He thinks he can save $1000 each month but the prices of his old car and of the new one decrease of 1.5 percent per month. 

Furthermore this percent of loss increases of 0.5 percent at the end of every two months. 

Our man finds it difficult to make all these calculations.

Can you help him?

How many months will it take him to save up enough money to buy the car he wants, and how much money will he have left over?

Parameters and return of function:

parameter (positive int or float, guaranteed) startPriceOld (Old car price)
parameter (positive int or float, guaranteed) startPriceNew (New car price)
parameter (positive int or float, guaranteed) savingperMonth 
parameter (positive float or int, guaranteed) percentLossByMonth

nbMonths(2000, 8000, 1000, 1.5) should return [6, 766] or (6, 766)
Detail of the above example:
end month 1: percentLoss 1.5 available -4910.0
end month 2: percentLoss 2.0 available -3791.7999...
end month 3: percentLoss 2.0 available -2675.964
end month 4: percentLoss 2.5 available -1534.06489...
end month 5: percentLoss 2.5 available -395.71327...
end month 6: percentLoss 3.0 available 766.158120825...
return [6, 766] or (6, 766)
where 6 is the number of months at the end of which he can buy the new car and 766 is the nearest integer to 766.158... (rounding 766.158 gives 766).

Note:

Selling, buying and saving are normally done at end of month. Calculations are processed at the end of each considered month but if, by chance from the start, the value of the old car is bigger than the value of the new one or equal there is no saving to be made, no need to wait so he can at the beginning of the month buy the new car:

nbMonths(12000, 8000, 1000, 1.5) should return [0, 4000]
nbMonths(8000, 8000, 1000, 1.5) should return [0, 0]
*/

#include <vector>
#include <random>

using namespace std;

class BuyCar
{

  public:
  static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth);
};

vector<int> BuyCar::nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth)
{
  int mth = 0;
  double priceOld = static_cast<double>(startPriceOld);
  double priceNew = static_cast<double>(startPriceNew);
  double available = static_cast<double>(startPriceOld);
  while (available < priceNew)
  {
    // at the end of this month
    mth += 1;
    if (mth % 2 == 0)
    {
      percentLossByMonth = percentLossByMonth + 0.5;
    }
    priceOld = priceOld * (100 - percentLossByMonth) / 100;
    priceNew = priceNew * (100 - percentLossByMonth) / 100;
    available = mth * savingperMonth + priceOld;
  }
  vector<int> res = {mth, static_cast<int>(available - priceNew + .5)};
  return res;
}

int main()
{
	vector<int> ans1 = BuyCar::nbMonths(12000, 8000, 1000, 1.5);
	return 0;
}
