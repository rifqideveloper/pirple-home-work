#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <ios>
#include <limits>
using namespace std;
float totalPremium = 0.f,
      basePremium = 0.f,
      actualPremium = 0.f;
class dog
{
private:
public:
    string name;
    short age;
    short weight;
    void BasePremium(short weight, short Risk_weight, float low_Risk_weight, float hi_Risk_weight)
    {
        if (weight < Risk_weight)
        {
            basePremium = low_Risk_weight;
            actualPremium = basePremium;
        }
        else if (weight > Risk_weight)
        {
            basePremium = hi_Risk_weight;
            actualPremium = basePremium;
        }
    }
    void ActualPremium(bool senior_discount, float weight)
    {
        if (senior_discount)
            if (age > 12)
            {
                actualPremium = actualPremium + (basePremium * 20.0f / 100);
            }
        if (weight > 50)
        {
            actualPremium += actualPremium + (basePremium * 25.0f / 100);
        }
    }
};
class pitbul : public dog
{
public:
    const short Risk_weight = 20;
    const float low_Risk_weight = 30.20f,
                hi_Risk_weight = 35.15f;
    const bool senior_discount = false;
};
class Doberman : public dog
{
public:
    const short Risk_weight = 35;
    const float low_Risk_weight = 28.16,
                hi_Risk_weight = 30.00;
    const bool senior_discount = true;
};
class Rottweiler : public dog
{
public:
    const short Risk_weight = 45;
    const float low_Risk_weight = 28.00,
                hi_Risk_weight = 29.75;
    bool senior_discount = false;
};
class German_Shepherrd : public dog
{
public:
    const short Risk_weight = 30;
    const float low_Risk_weight = 27.50,
                hi_Risk_weight = 29.75;
    const bool senior_discount = true;
};
class Chow_Chow : public dog
{
public:
    const short Risk_weight = 24;
    const float low_Risk_weight = 25.10,
                hi_Risk_weight = 27.50;
    const bool senior_discount = true;
};
class Great_Dane : public dog
{
public:
    const short Risk_weight = 55;
    const float low_Risk_weight = 25.10,
                hi_Risk_weight = 25.20;
    const bool senior_discount = true;
};
class presa_Canario : public dog
{
public:
    const short Risk_weight = 45;
    const float low_Risk_weight = 20.01,
                hi_Risk_weight = 20.55;
    const bool senior_discount = false;
};
class Akit : public dog
{
public:
    const float premium_price = 19.75;
    bool senior_discount = false;
    void calculation()
    {
        actualPremium = premium_price;
    }
};
class Alaskan_Malamunte : public dog
{
public:
    const short Risk_weight = 38;
    const float low_Risk_weight = 15.50,
                hi_Risk_weight = 18.15;
    const bool senior_discount = true;
};
class Husky : public dog
{
public:
    const short Risk_weight = 20;
    const float low_Risk_weight = 9.95,
                hi_Risk_weight = 12.00;
    const bool senior_discount = true;
};
class Other_Breed : public dog
{
public:
    const short Risk_weight = 35;
    const float low_Risk_weight = 4.95,
                hi_Risk_weight = 8.95;
    const bool senior_discount = true;
};
class Wooffur
{
protected:
    const char Pitbul = 'p',
               doberman = 'd',
               rottweiler = 'r',
               german_Shepherrd = 'g',
               chow_Chow = 'e',
               great_Dane = 't',
               Presa_Canario = 's',
               akit = 'k',
               alaskan_Malamunte = 'm',
               husky = 'h',
               other_Breed = 'b';

public:
    void test(char breedcode, string dogname, short age, short weight)
    {
        if (breedcode == Pitbul)
        {
            pitbul *mydog = new pitbul();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->BasePremium(mydog->weight, mydog->hi_Risk_weight, mydog->low_Risk_weight, mydog->hi_Risk_weight);
            mydog->ActualPremium(mydog->senior_discount, mydog->weight);
            totalPremium += actualPremium;
            delete mydog;
            cout << totalPremium;
        }
        else if (breedcode == Pitbul)
        {
            Doberman *mydog = new Doberman();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->BasePremium(mydog->weight, mydog->hi_Risk_weight, mydog->low_Risk_weight, mydog->hi_Risk_weight);
            mydog->ActualPremium(mydog->senior_discount, mydog->weight);
            totalPremium += actualPremium;
            delete mydog;
        }
        else if (breedcode == rottweiler)
        {
            Rottweiler *mydog = new Rottweiler();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->BasePremium(mydog->weight, mydog->hi_Risk_weight, mydog->low_Risk_weight, mydog->hi_Risk_weight);
            mydog->ActualPremium(mydog->senior_discount, mydog->weight);
            totalPremium += actualPremium;
            delete mydog;
        }
        else if (breedcode == german_Shepherrd)
        {
            German_Shepherrd *mydog = new German_Shepherrd();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->BasePremium(mydog->weight, mydog->hi_Risk_weight, mydog->low_Risk_weight, mydog->hi_Risk_weight);
            mydog->ActualPremium(mydog->senior_discount, mydog->weight);
            totalPremium += actualPremium;
            delete mydog;
        }
        else if (breedcode == chow_Chow)
        {
            Chow_Chow *mydog = new Chow_Chow();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->BasePremium(mydog->weight, mydog->hi_Risk_weight, mydog->low_Risk_weight, mydog->hi_Risk_weight);
            mydog->ActualPremium(mydog->senior_discount, mydog->weight);
            totalPremium += actualPremium;
            delete mydog;
        }
        else if (breedcode == great_Dane)
        {
            Great_Dane *mydog = new Great_Dane();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->BasePremium(mydog->weight, mydog->hi_Risk_weight, mydog->low_Risk_weight, mydog->hi_Risk_weight);
            mydog->ActualPremium(mydog->senior_discount, mydog->weight);
            totalPremium += actualPremium;
            delete mydog;
        }
        else if (breedcode == Presa_Canario)
        {
            presa_Canario *mydog = new presa_Canario();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->BasePremium(mydog->weight, mydog->hi_Risk_weight, mydog->low_Risk_weight, mydog->hi_Risk_weight);
            mydog->ActualPremium(mydog->senior_discount, mydog->weight);
            totalPremium += actualPremium;
            delete mydog;
        }
        else if (breedcode == akit)
        {
            Akit *mydog = new Akit();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->calculation();
            totalPremium += actualPremium;
            delete mydog;
        }
        else if (breedcode == alaskan_Malamunte)
        {
            Alaskan_Malamunte *mydog = new Alaskan_Malamunte();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->BasePremium(mydog->weight, mydog->hi_Risk_weight, mydog->low_Risk_weight, mydog->hi_Risk_weight);
            mydog->ActualPremium(mydog->senior_discount, mydog->weight);
            totalPremium += actualPremium;
            delete mydog;
        }
        else if (breedcode == husky)
        {
            Husky *mydog = new Husky();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->BasePremium(mydog->weight, mydog->hi_Risk_weight, mydog->low_Risk_weight, mydog->hi_Risk_weight);
            mydog->ActualPremium(mydog->senior_discount, mydog->weight);
            totalPremium += actualPremium;
            delete mydog;
        }
        else if (breedcode == other_Breed)
        {
            Other_Breed *mydog = new Other_Breed();
            mydog->name = dogname;
            mydog->age = age;
            mydog->weight = weight;
            mydog->BasePremium(mydog->weight, mydog->hi_Risk_weight, mydog->low_Risk_weight, mydog->hi_Risk_weight);
            mydog->ActualPremium(mydog->senior_discount, mydog->weight);
            totalPremium += actualPremium;
            delete mydog;
        }
        else
        {
            printf("Sorry. That is not a valid breed code. Please re- enter this dog’s information.");
        }
    }
};
class input : protected Wooffur
{
private:
    short dogCount = 0,
          weight,
          age;
    char breedcode;
    string dogname;

public:
    short input1()
    {
        cout << "Please enter the number of dogs in your household" << endl;
        cin >> dogCount;
        return dogCount;
    }
    string input2(short i)
    {
        cout << "enter the name of dog#" << i + 1 << endl;
        cin >> dogname;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return dogname;
    }
    char input3()
    {

        cout << "enter the breed code for " << dogname << endl;
        cin >> breedcode;
        if (breedcode == Pitbul)
        {
            cout << dogname << " is a Pitbul" << endl;
        }
        else if (breedcode == doberman)
        {
            cout << dogname << " is a doberman" << endl;
        }
        else if (breedcode == rottweiler)
        {

            cout << dogname << " is a rottweiler" << endl;
        }
        else if (breedcode == german_Shepherrd)
        {
            cout << dogname << " is a german_Shepherrd" << endl;
        }
        else if (breedcode == chow_Chow)
        {
            cout << dogname << " is a chow_Chow" << endl;
        }
        else if (breedcode == great_Dane)
        {
            cout << dogname << " is a great_Dane" << endl;
        }
        else if (breedcode == Presa_Canario)
        {
            cout << dogname << " is a Presa_Canario" << endl;
        }
        else if (breedcode == akit)
        {
            cout << dogname << " is a akit" << endl;
        }
        else if (breedcode == alaskan_Malamunte)
        {
            cout << dogname << " is a alaskan_Malamunte" << endl;
        }
        else if (breedcode == husky)
        {
            cout << dogname << " is a Husky" << endl;
        }
        else if (breedcode == other_Breed)
        {
            cout << dogname << " is a other_Breed" << endl;
        }
        else
        {
            printf("Sorry. That is not a valid breed code. Please re- enter this dog’s information.");
            input3();
        }

        return breedcode;
    }
    short input4()
    {
        cout << "enter the current age for " << dogname << ":";
        cin >> age;
        return age;
    }
    short input5()
    {
        cout << "enter the weight for " << dogname << " (nearest kg):";
        cin >> weight;

        return weight;
    }
};

int main()
{
    cout << setiosflags(ios::fixed);
    cout << setprecision(2);
    string dogname;
    short dogcount,
        weight,
        age;
    char breedcode;
    Wooffur mydog;
    input input_;
    dogcount = input_.input1();
    for (short i = 0; i < dogcount; i++)
    {
        dogname = input_.input2(i);
        breedcode = input_.input3();
        age = input_.input4();
        weight = input_.input5();
        mydog.test(breedcode, dogname, age, weight);
        cout << " The monthly premium for " << dogname << " is " << actualPremium << endl;
    }

    cout << endl
         << "The total monthly premium for all dogs is " << totalPremium;

    return 0;
}
