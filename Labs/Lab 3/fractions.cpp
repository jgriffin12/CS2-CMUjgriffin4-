#include "fractions.h"

// Can only modify this file

//Constructor
fractions::Fraction::Fraction(int numerator, int denominator)
{
    int num, denom; 
    if (denominator == 0)
    {
        cout << "Enter a numerator: "; 
        cin >> num; 
        cout << "Enter a denominator: ";
        cin >> denom; 
        
        //Associate variables
        _numerator = num;
        _denominator = denom; 
    }
    else                 //default 0/1
    {
    _numerator = numerator; 
    _denominator = denominator; 
    }
} 

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{

    //Find the numerator and denominator 
    int numerator =  (_numerator * frac._denominator) + (frac._numerator * _denominator); //cross multiply and add
    int denominator = (_denominator * frac._denominator); //multiply denominator of both fractions

    //Simplify Fraction 
    fractions::Fraction simplifiedFrac(numerator,denominator); 

    simplifiedFrac.simplify(); 
    return simplifiedFrac; 
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    //Find the numerator and denominator 
    int numerator = (_numerator * frac._denominator) - (frac._numerator * _denominator); //cross multiply and subtract
    int denominator = (_denominator * frac._denominator); //multiply denominator of both fractions

    //Simplify Fraction
    fractions::Fraction simplifiedFrac(numerator,denominator); 

    simplifiedFrac.simplify(); 
    return simplifiedFrac; 
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    //Find the numerator and denominator 
    int numerator = (_numerator * frac._numerator); //multiply across
    int denominator = (_denominator * frac._denominator); //multiply denominator of both fractions
    
    //Simplify franction
    fractions::Fraction simplifiedFrac(numerator,denominator); 

    simplifiedFrac.simplify(); 
    return simplifiedFrac; 
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{

    //Find the numerator and denominator
    int numerator = (_numerator * frac._denominator);  //donut multiply
    int denominator = (_denominator * frac._numerator); 
    
    fractions::Fraction simplifiedFrac(numerator,denominator); 

    simplifiedFrac.simplify(); 
    return simplifiedFrac; 
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
     //Takes both num and denom an divides by GCD 
    int greatest_com = fractions::Fraction::gcd(frac._numerator, frac._denominator);

    int num = (frac._numerator / greatest_com);
    int denom = (frac._denominator / greatest_com);

    return Fraction(num, denom);
}

void fractions::Fraction::simplify()
{
    //Takes both num and denom an divides by GCD 
    int greatest_com = fractions::Fraction::gcd(_numerator, _denominator); 

    _numerator = (_numerator / greatest_com); 
    _denominator = (_denominator / greatest_com); 
}

int fractions::Fraction::gcd(int a, int b)
{
    int find_min, gcd_found; 
    find_min = min(a,b);

    // See if find_min is divisible evenly
    for (int i = 1; i <= find_min; i++) 
    {
        if (a % i == 0 && b % i == 0)
        {
            // GCD found
            gcd_found = i; 
        }
    }
    return gcd_found; 
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    if (_numerator == frac._numerator)
    {
        if (_denominator == frac._denominator)
        {
            return true; 
        }
    }
    else
    {
    return false;
    }
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    os << frac._numerator << "/" << frac._denominator; 
    return os;
}



