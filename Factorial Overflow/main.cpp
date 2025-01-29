#include <chrono>
#include <limits>
#include <locale>

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
using namespace chrono;

template <class TypeMultiply>
bool isSafeMultiply (TypeMultiply mult01, TypeMultiply mult02, TypeMultiply &multResult) {

/*$$
add code to check if mult01 or mult02 = 0
if so, set multResult to 0 and leave with a true
*/

/*$$
calculate the multResult from mult01 and mult02
check if mult01 is equal to the multResult divided by mult02
if mult01 is equal to the multResult divided by mult02 then leave with a true
if not equal then leave with a false
*/

}
template <class TypeMultiply>
void calculateTimeFactorialLoopFunc(void) {

  //$$ set time start to clock now() 

  TypeMultiply multiplier      = 1,
               factorialResult = 1;

  while ( 1 /*$$ invoke isSafeMultiply with multiplier and factorialResult) */ ) {
    // display the multiplier and the factorialresult using field wdths of 3 and 27 respectively
    // increment the multiplier
  }

  // calculate timeElapsed as described in the assignment
  
  cout << endl;
  /*$$
  Display "Unsigned overflow at : " using setw() to display multiplier
  Display "Time Elapsed (nano)  : " using setw() to display timeElapsed.count()
  */

}//calculateTimeFactorialLoopFunc

 //------------------------------------------
template <class TypeMultiply>
void factorialRecursiveFunc (TypeMultiply &multiplier, TypeMultiply factorialResult) {

  if ( 1 /*$$ invoke isSafeMultiply <TypeMultiply> with multiplier and factorial result)*/ ) {
    cout << setw(3) << multiplier << setw(27) << factorialResult << endl;
    //$$ invoke factorialRecursiveFunc with ++multiplier and factorialResult
  }
  return;

}//factorialRecursive

 //------------------------------------------  
template <class TypeMultiply>
void calculateTimeFactorialRecursiveFunc() {

  //$$ set time start to clock now() 

  TypeMultiply mult01 = 1;
  factorialRecursiveFunc <TypeMultiply> (mult01, 1);

  // calculate timeElapsed as described in the assignment

  cout << endl;
  /*$$
  Display "Unsigned overflow at : " using setw() to display multiplier
  Display "Time Elapsed (nano)  : " using setw() to display timeElapsed.count()
  */

}//calculateTimeFactorialRecursiveFunc()

template <typename TYPESIZE> 
class FactorialCalculationClass {

private:
  unsigned typeSizeBits;

public:
  // Constructor
  FactorialCalculationClass(unsigned typeSize) {
    //$$ set typeSizeBits to typeSize;
  }

  void executeFactorialForType() {

    cout <<
      typeSizeBits <<
      " bit unsigned Factorial Loop" << endl <<
      "------------------------------" << endl;
    calculateTimeFactorialLoopFunc <TYPESIZE>();
    cout << endl << endl;

    cout <<
      typeSizeBits <<
      " bit unsigned Factorial Recursion" << endl <<
      "-----------------------------------" << endl;
    calculateTimeFactorialRecursiveFunc <TYPESIZE>();
    cout << endl << endl;

  }

};// template <class TYPESIZE> class factorialCalculationClass

int main() {
  // condition cout set to local digit separation comas (USA)
  cout.imbue(locale(""));

  /*$$
  create an object of FactorialCalculationClass <uintnn_t> called factorialCalculateUintnnObj(nn)
  where nn is the size in bits for the tempalte type uintnn_t, the object name 
  factorialCalculateUintnnObj and the nn for the argument (nn) to the constructor
  nn must equal nn = 16, 32 and 64 to make the 3 objects
  */

  /*$$
  for each of the 3 nn objects factorialCalculateUintnnObj
  invoke the executeFactorialForType()
  */

  /*$$
    display Press enster key once or twice to end and hold th screen
    */


  return 0;
}
