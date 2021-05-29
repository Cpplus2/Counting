#include <iostream>
#include <cmath>
#include <limits>

#include "Stack.h"

using namespace std;

double fastExponent(double, int, int);
int factorial(int);
int combinations(int, int);
int permutations(int, int);
bool isPerfectSquare(int);
bool isPrime(int, int);
void PrimeFactorization(int);
int sendFactor(int);

template<class ItemType>
void addValues(ItemType *, int, ItemType);

double fastExponent(double base, int exponent, int accumulator)
{
    if(exponent == 0)
        return accumulator;
    else if(exponent % 2 == 0)
        return fastExponent(base * base, exponent/2, accumulator);

    return fastExponent(base, exponent-1, base * accumulator);
}

int factorial(int n)
{
    if(n==1)
        return n;

    return n*factorial(n-1);
}

int combinations(int n, int k)
{
    if(k==1)
        return n;
    else if(n==k)
        return 1;

    return combinations(n-1,k) + combinations(n-1, k-1);
}

int permutations(int n, int k)
{
    if(n==k)
        return n;

    return permutations(n-1,k) * n;
}

template<class ItemType>
bool BinarySearch(ItemType values[], ItemType item, int left, int right)
{
    if(left > right)
        return false;
    else
    {
        int midpoint = (left + right) / 2;
        if(item < values[midpoint])
            return BinarySearch(values, item, left, midpoint-1);
        else if(item > values[midpoint])
            return BinarySearch(values, item, midpoint, right);
        else
            return true;
    }
}

int main()
{
    cout << "Choose one of the following operations. " << endl;
    cout << "[1] Factorial " << endl;
    cout << "[2] Combination " << endl;
    cout << "[3] Permutations " << endl;
    cout << "[4] Prime Factorization" << endl;
    cout << "[5] Perfect Square Check" << endl;
    cout << "[6] Prime Check" << endl;

    cout << endl << "Enter your choice: "; int choice; cin >> choice;
    cout << endl;

    int n, k; double * p;
    switch(choice)
    {
        case 1:
            cout << "Enter an integer value denoted n to compute its factorial expressed as n!" << endl;
            cout << "Enter n: ";
            cin >> n;
            cout << n << "! = " << factorial(n) << endl;

            break;

        case 2:
            //Order of arrangement is trivial
            cout << "Enter values for n and r to compute nCr as the combination of r arrangements with n elements. " << endl;
            cout << "n < r" << endl;
            cout << "Enter n: "; cin >> n;
            cout << "Enter r: "; cin >> k;

            cout << n << "comb" << k << " = " << combinations(n, k);
            break;

        case 3:
            //Order of arrangement is important
            cout << "Enter values for n and r to compute nPr as the permutation of r arrangement with n elements. " << endl;
            cout << "n < r" << endl;
            cout << "Enter n: "; cin >> n;
            cout << "Enter r: "; cin >> k;

            cout << n << "perm" << k << " = " << permutations(n, k);
            break;

        case 4:
            cout << "Enter a positive whole number: ";
            for(cin >> n; n < 0; cin >> n)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            PrimeFactorization(n);
            cout << endl;
            break;

        case 5:
            cout << "Enter a positive whole number: ";
            cin >> n;
            cout << n << " is " << (isPerfectSquare(n) ? "": "not " ) <<" is a perfect squared. " << endl;
            break;

        case 6:
            cout << "Enter a positive whole number: ";
            cin >> n;
            cout << n << " is " << (isPrime(n, 2) ? "prime.": " composite." ) << endl;
            break;

        case 7:
            cout << "Enter a number of double-precision values and enter 0 when completed. " << endl;

            n=0;
            p = new double[1];
            for(double temp = 1; temp != 0.0; addValues(p, n++, temp) )
            {
                cout << "Enter num" << (n+1) << ": ";
                cin >> temp;
            }

            cout << "Enter the number you're searching for: ";
            cin >> k;
            cout << "The number " << k << " is ";
            if(BinarySearch<double>(p, k, 0, n) );
                cout << "not" << endl;

            cout << " found." << endl;
            break;

        default:
            cout << "Sorry! There is an error in your input. " << endl;
    }
    return 0;
}

bool isPerfectSquare(int num)
{
    for(int count = 1; count < num; count++)
        if(num % count == 0 && num/count == count)
            return true;

    return false;
}

bool isPrime(int num, int i)
{
    if( num <= 2 || num < fastExponent(i,2,1) )       //2nd condition passes divisibility check
        return true;
    else if(num % i == 0)
        return false;

    return isPrime(num, i+1);
}

void PrimeFactorization(int num)
{
    if(isPrime(num, 2))
        cout << "The number is already factorized. " << endl;
    else
    {
        Stack<int> factors;

        for(int n = num; n!=1; n/=(factors.Top()))
            factors.Push(sendFactor(n));

        cout << "is the error here?" << endl;

        for(cout << "Prime Factorization of" << num << ": ["; !factors.IsEmpty(); factors.Pop())
        {
            if(!factors.LastItem())
                cout << factors.Top() << " * ";
            else
                cout << factors.Top() << "]";
        }
    }
}

int sendFactor(int num)
{
    if(num%2 == 0)
        return 2;

    while(!isPrime(num, 2))
    {
        if(isPerfectSquare(num))
            num /= (sqrt(num));
        else
            for(int count = sqrt(num); count >=3; count-=2)
                if(num % count == 0)
                    num/=count;
    }
    return num;
}

template<class ItemType>
void addValues(ItemType * values, int sz, ItemType value)
{
    ItemType * temp = new ItemType[sz];

    for(int count = 0; count < sz; count++)
        temp[count] = values[count];

    temp[sz] = value;

    values = new ItemType[sz];

    for(int count = 0; count < sz; count++)
        values[count] = temp[count];
}

