#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned factTail(unsigned, unsigned result = 1);
unsigned fibTail(unsigned, unsigned x = 0, unsigned y = 1);
unsigned multTail(unsigned, unsigned, unsigned result = 0);
unsigned powerTail(unsigned, unsigned, unsigned result = 1);
unsigned productTail(unsigned, unsigned, unsigned result = 1);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << multTail(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << powerTail(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << productTail(8, 15) << endl;
    cout << "10! = " << factTail(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fibTail(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

unsigned factTail(unsigned n, unsigned result) {
    // base cases (combined)
    if (n <= 1) {
        return result;
    }

    // recursive case
    return factTail(n - 1, n * result);
}

unsigned fibTail(unsigned n, unsigned x, unsigned y) {
    // base case 1
    if (n == 0) {
        return x;
    }

    // base case 2
    else if (n == 1) {
        return y;
    }

    // recursive case
    return fibTail(n - 1, y, x + y);
}

unsigned multTail(unsigned x, unsigned y, unsigned result) {
    // base case
    if (y == 0) {
        return result;
    }

    // recursive case
    /************************************************************************
    * had issues with this function and needed help with this and found
    * out this function doesn't guarantee tail recursion by the compiler
    *************************************************************************/
    if(y % 2 == 0){
        return multTail(x + x, y / 2, result); 
    }
    else {
        return multTail(x, y - 1, result + x);
    }
}

unsigned powerTail(unsigned x, unsigned y, unsigned result) {
    // base case
    if (y == 0) {
        return result;
    }

    // recursive case
    return powerTail(x, y - 1, result * x);
}

unsigned productTail(unsigned x, unsigned y, unsigned result) {
    // base case
    if (x > y) {
        return result;
    }

    // recursive case
    return productTail(x + 1, y, result * x);
}
