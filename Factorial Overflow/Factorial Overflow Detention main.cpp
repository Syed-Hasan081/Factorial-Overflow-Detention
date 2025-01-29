/*
Program Name: Factorial Overflow Detention 
Date: 04/26/2024
Author: Syed Hasan
Module Purpose
This program computes factorials for different unsigned integer types until an arithmetic overflow occurs, timing the calculations for performance analysis.
*/

include <chrono>
#include <limits>
#include <locale>

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
using namespace chrono;

template <class TypeMultiply>
bool isSafeMultiply(TypeMultiply mult01, TypeMultiply mult02, TypeMultiply &multResult) {
  if (mult01 == 0 || mult02 == 0) {
    multResult = 0;
    return true;
  }
  multResult = mult01 * mult02;
  return mult01 == multResult / mult02;
}

template <class TypeMultiply>
TypeMultiply factorialRecursiveFunc(TypeMultiply multiplier, TypeMultiply factorialResult, bool &safe) {
  safe = isSafeMultiply(multiplier, factorialResult, factorialResult);
  if (!safe) {
    return multiplier; // We return the last safe multiplier value before overflow.
  }
  cout << setw(3) << multiplier << setw(27) << factorialResult << endl;
  return factorialRecursiveFunc(static_cast<TypeMultiply>(multiplier + 1), factorialResult, safe);
}

template <class TypeMultiply>
void calculateTimeFactorialLoopFunc() {
  auto timeStart = steady_clock::now();

  TypeMultiply multiplier = 1;
  TypeMultiply factorialResult = 1;
  bool safe = true;

  while (safe) {
    cout << setw(3) << multiplier << setw(27) << factorialResult << endl;
    safe = isSafeMultiply(multiplier, factorialResult, factorialResult);
    multiplier++;
  }

  auto timeEnd = steady_clock::now();
  auto timeElapsed = duration_cast<nanoseconds>(timeEnd - timeStart);

  cout << setw(22) << left << "Unsigned overflow at :" << setw(5) << right << multiplier << endl;
  cout << setw(22) << left << "Time Elapsed (nano)  :" << setw(10) << right << timeElapsed.count() << endl;
}

template <class TypeMultiply>
void calculateTimeFactorialRecursiveFunc() {
  auto timeStart = steady_clock::now();

  bool safe;
  TypeMultiply multiplier = 1;
  TypeMultiply lastMultiplier = factorialRecursiveFunc(multiplier, TypeMultiply(1), safe);

  auto timeEnd = steady_clock::now();
  auto timeElapsed = duration_cast<nanoseconds>(timeEnd - timeStart);

  cout << setw(22) << left << "Unsigned overflow at :" << setw(5) << right << lastMultiplier << endl;
  cout << setw(22) << left << "Time Elapsed (nano)  :" << setw(10) << right << timeElapsed.count() << endl;
}

template <typename TYPESIZE>
class FactorialCalculationClass {
private:
  unsigned typeSizeBits;

public:
  FactorialCalculationClass(unsigned typeSize) : typeSizeBits(typeSize) {}

  void executeFactorialForType() {
    cout << typeSizeBits << " bit unsigned Factorial Loop" << endl;
    cout << "------------------------------" << endl;
    calculateTimeFactorialLoopFunc<TYPESIZE>();
    cout << endl;

    cout << typeSizeBits << " bit unsigned Factorial Recursion" << endl;
    cout << "-----------------------------------" << endl;
    calculateTimeFactorialRecursiveFunc<TYPESIZE>();
    cout << endl;
  }
};

int main() {
  cout.imbue(locale(""));

  FactorialCalculationClass<uint16_t> factorialCalculateUint16Obj(16);
  FactorialCalculationClass<uint32_t> factorialCalculateUint32Obj(32);
  FactorialCalculationClass<uint64_t> factorialCalculateUint64Obj(64);

  factorialCalculateUint16Obj.executeFactorialForType();
  factorialCalculateUint32Obj.executeFactorialForType();
  factorialCalculateUint64Obj.executeFactorialForType();

  cout << "Press enter key once or twice to end..." << endl; 
  cin.ignore();
  cin.get();

  return 0;
}
