#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> bodyWeight = {};
char symbol = '$';
int g1, g2, g3, g4, g5;


void EnterBodyWeight(int amount)
{
    for (int i=0; i < amount; i++)
    {
        int weight;
        std::cout << "Enter body weight: "; std::cin >> weight;
        bodyWeight.push_back(weight);
        if (weight > 149)
        {
            std::cout << "Body weight over limit";
            break;
        }
    }
}

void SortWeightGroup(int index, int num1, int num2, int &group)
{
    if (bodyWeight[index] <= num1 && bodyWeight[index] >= num2)
    {
        group = group + 1;
    }
}

void SortAndDisplay()
{
   int vecSize = bodyWeight.size();
    
   for (int i = 0; i < vecSize; i++)
   {    

        SortWeightGroup(i, 49, 0, g1);
        SortWeightGroup(i, 69, 50, g2);
        SortWeightGroup(i, 89, 70, g3);
        SortWeightGroup(i, 109, 90, g4);
        SortWeightGroup(i, 149, 110, g5);

   }

    int max = *std::max_element(bodyWeight.begin(), bodyWeight.end());
    int min = *std::min_element(bodyWeight.begin(), bodyWeight.end());

   //Display all the weight groups here
   std::cout << "\n\n0-49: " << std::string(g1, symbol);
   std::cout << "\n50-69: " << std::string(g2, symbol);
   std::cout << "\n70-89: " << std::string(g3, symbol);
   std::cout << "\n90-109: " << std::string(g4, symbol);
   std::cout << "\n110-149: " << std::string(g5, symbol);

   std::cout << "\n\n\nTotal customers: " << vecSize << std::endl;
   std::cout << "Total customers below 70: " << g1 + g2 << std::endl;
   std::cout << "Highest weight: " << max << std::endl;
   std::cout << "Lowest weight: " << min << std::endl;

}


int main()
{
    int amount;
    std::cout << "Enter customer amount: "; std::cin >> amount;

    EnterBodyWeight(amount);
    SortAndDisplay();

    //std::cout << std::string(10, 'A');
}