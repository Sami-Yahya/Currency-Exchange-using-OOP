#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:

    static void Swap(int & Num1, int & Num2)
    {
        int Temp;

        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(double& Num1, double& Num2)
    {
        double Temp;

        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(string& S1, string& S2)
    {
        string Temp;

        Temp = S1;
        S1 = S2;
        S2 = Temp;
    }

    static void Swap(clsDate &Date1, clsDate &Date2)
    {
        clsDate::Swap2Dates(Date1, Date2);
    }

    static bool CheckPrime(int Number)
    {
        int M = round(Number / 2);

        for (int Counter = 2; Counter <= M; Counter++)
        {
            if (Number % Counter == 0)
                return false;
        }

        return true;
    }

    static void PrintPrimeNumbersFrom1toN(int Number)
    {
        cout << "\n" << "Prime Numbers from 1 to " << Number << " are: \n";

        for (int i = 2; i <= Number; i++)
        {
            if (CheckPrime(i))
            {
                cout << i << ", ";
            }
        }

        cout << endl;
    }

    static bool isPerfectNumber(int Number)
    {
        int Sum = 0;

        for (int Counter = 1; Counter < Number; Counter++)
        {
            if (Number % Counter == 0)
            {
                Sum += Counter;
            }
        }

        return Number == Sum;
    }

    static void PrintDigits(int Number)
    {
        int Remainder = 0;
        cout << "\n";

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            cout << Remainder << endl;
        }
    }

    static int SumOfDigits(int Number)
    {
        int Remainder = 0, Sum = 0;
        cout << "\n";

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Sum += Remainder;
        }

        return Sum;
    }

    static int GetFrequency(int Number, int DigitToCheck) 
    {
        int Reminder = 0, Freq = 0;

        while (Number != 0) 
        {
            Reminder = Number % 10;
            Number = Number / 10;

            if (Reminder == DigitToCheck) 
            {
                Freq++;
            }
        }

        return Freq;
    }

    static int ReverseNumber(int Number)
    {
        int Remainder = 0, Number2 = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Number2 = Number2 * 10 + Remainder;
        }

        return Number2;
    }

    static int CountDigitFrequency(short DigitToCheck, int Number)
    {
        int Remainder = 0, Counter = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;

            if (Remainder == DigitToCheck)
            {
                Counter++;
            }
        }

        return Counter;
    }

    static bool IsPalindromeNumber(int Number)
    {
        return Number == ReverseNumber(Number);
    }

    static string EncryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }

        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }

        return Text;
    }

    static void Srand()
    {
        //Seeds the random number generatorin C++, called only once
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;

        return randNum;
    }

    enum enCharType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, MixChars = 4, SpecialCharacter = 5};

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);
        }

        switch (CharType)
        {
        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string word = "";

        for (int i = 1; i <= Length; i++)
        {
            word = word + GetRandomCharacter(CharType);
        }

        return word;
    }

    static string GenerateKey(enCharType CharType)
    {
        string Key = "";

        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }

    static void PrintArray(int arr[100], short arrLength)
    {
        for (short i = 0; i < arrLength; i++)
        {
            cout << arr[i] << "\t";
        }

        cout << "\n";
    }

    static void PrintArray(string arr[100], short arrLength)
    {
        for (short i = 0; i < arrLength; i++)
        {
            cout << arr[i] << "\t";
        }

        cout << "\n";
    }

    static void PrintVector(vector<int> vNumbers)
    {
        for (int& n : vNumbers)
        {
            cout << n << "\t";
        }

        cout << "\n";
    }

    static void PrintVector(vector<string> vString)
    {
        for (string& s : vString)
        {
            cout << s << "\t";
        }

        cout << "\n";
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short WordLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateWord(CharType, WordLength);
        }
    }

    static void FillArrayWithRandomKeys(string arr[100], int NumberOfKeys, enCharType CharType)
    {
        for (int i = 0; i < NumberOfKeys; i++)
        {
            arr[i] = GenerateKey(CharType);
        }
    }

    static void FillVectorWithRandomNumbers(vector<int> &vNumbers, int VectorLength, int From, int To)
    {
        for (int i = 0; i < VectorLength; i++)
        {
            vNumbers.push_back(RandomNumber(From, To));
        }
    }

    static void FillVectorWithRandomWords(vector<string>& vWords, int VectorLength, enCharType CharType, short WordLength)
    {
        for (int i = 0; i < VectorLength; i++)
        {
            vWords.push_back(GenerateWord(CharType, WordLength));
        }
    }

    static void FillVectorWithRandomKeys(vector<string>& vKeys, int VectorLength, enCharType CharType)
    {
        for (int i = 0; i < VectorLength; i++)
        {
            vKeys.push_back(GenerateKey(CharType));
        }
    }

    static int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }

        return Max;
    }

    static int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = 0;
        Min = arr[0];

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min;
    }

    static int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;

        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }
        return Sum;
    }

    static float ArrayAverage(int arr[100], int arrLength)
    {
        return (float)SumArray(arr, arrLength) / arrLength;
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void ShuffleVector(vector<int>& V1, int vectorLength)
    {
        for (int i = 0; i < vectorLength; i++)
        {
            Swap(V1[RandomNumber(1, vectorLength) - 1], V1[RandomNumber(1, vectorLength) - 1]);
        }
    }

    static void ShuffleVector(vector<string>& V1, int vectorLength)
    {
        for (int i = 0; i < vectorLength; i++)
        {
            Swap(V1[RandomNumber(1, vectorLength) - 1], V1[RandomNumber(1, vectorLength) - 1]);
        }
    }

    static string Tabs(short NumberOfTabs)
    {
        string Tab = "";

        for (short i = 1; i <= NumberOfTabs; i++)
        {
            Tab = Tab + "\t";
        }

        return Tab;
    }

    static void ResetScreen()
    {
        system("cls");
        system("color 0F");
    }

    static int EvenCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    static int OddCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 != 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    static int PositiveCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] >= 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    static int NegativeCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    static bool GetRandomBoolean()
    {
        return bool(RandomNumber(0, 1));
    }

    static string NumberToText(int Number)
    {
        if (Number >= 0 && Number <= 19)
        {
            string arr1[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight",
            "Nine", "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen",
            "Seventeen","Eighteen","Nineteen" };

            return arr1[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty",
            "Seventy","Eighty","Ninety" };

            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToText(Number % 1000000000);
        }

        else
        {
            return NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
        }
    }

};
