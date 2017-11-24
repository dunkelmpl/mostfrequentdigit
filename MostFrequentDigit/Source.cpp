#include <iostream>

using namespace std;

typedef unsigned long long ulonglong;

//////////////////////////////////////////////////////////////////////////
// Gets most frequent digit
//
// This method first builds map of base 20 to store number of every digit
// in a single number. The position of a digit in a map (0...n) relates to
// the digit from the input number.
// For example map = A2090 means:
//        1. 0 of digit 0
//        2. 9 of digit 1
//        3. 0 of digit 2
//        4. 2 of digit 3
//        5. 10 of digit 4
// 20-base map is used for storing counter of up to 19 for every digit,
// since the biggest number with biggest quantity of same digits is
// 9999999999999999999UL (19 of 9-digit)
// After building the map we check every 20-base digit in the map and find
// the biggest one.
//
// @var ulonglong input -- number to find the most frequent digit in
//
// @return int
//////////////////////////////////////////////////////////////////////////
int getMostFrequentDigit(ulonglong input)
{
    const int mapBase = 20;
    ulonglong twentyBaseDigitsMap = 0;

    while (input != 0) {
        int digit = input % 10;
        input = input / 10;

        twentyBaseDigitsMap += (ulonglong)pow(mapBase, digit);
    }

    int mostFrequentDigit = 0;
    int maxFrequency = 0;
    for (int digit = 0; twentyBaseDigitsMap != 0; digit++, twentyBaseDigitsMap /= mapBase) {
        int frequency = twentyBaseDigitsMap % mapBase;

        if (frequency > 0 && frequency >= maxFrequency) {
            mostFrequentDigit = digit;
            maxFrequency = frequency;
        }
    }

    return mostFrequentDigit;
}

int main()
{
    // Simple random test
    ulonglong input1 = 87776908767;
    _ASSERT(7 == getMostFrequentDigit(input1));

    // Test that for equal (5) quantity of 7 and 8, the bigger one is picked
    ulonglong input2 = 88778769087687;
    _ASSERT(8 == getMostFrequentDigit(input2));

    // Test that the biggest possible quantity of same digits (19 of 9-digit) can be handled
    ulonglong input3 = 9999999999999999999UL;
    _ASSERT(9 == getMostFrequentDigit(input3));

    cout << "All tests passed" << endl;
}