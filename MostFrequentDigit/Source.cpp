#include <iostream>

using namespace std;

typedef unsigned long long ulonglong;

int getMostFrequentDigit(ulonglong input)
{
	ulonglong hexDigitsMap = 0;

	while (input != 0) {
		int digit = input % 10;
		input = input / 10;

		hexDigitsMap += (ulonglong)pow(16, digit);
	}

	int mostFrequentDigit = 0;
	int maxFrequency = 0;
	for (int digit = 0; hexDigitsMap != 0; digit++, hexDigitsMap /= 16) {
		int frequency = hexDigitsMap % 16;

		if (frequency > 0 && frequency >= maxFrequency) {
			mostFrequentDigit = digit;
			maxFrequency = frequency;
		}
	}

	return mostFrequentDigit;
}

int main()
{
	cout << "The most frequent digit is " << getMostFrequentDigit(9999999999999999999UL) << endl;
}