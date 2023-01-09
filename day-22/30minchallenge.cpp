#include <iostream>
using namespace std;
int collatz_steps(int n) {                           //Function to calculate collatz steps
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }
    return steps;
}

int main() {
    cout << "Enter two numbers ";
    int a, b;
    cin >> a >> b;
    while (a < 1 || a > 10000 || b < 1 || b > 10000 || a > b)       //Constraints
    {           
        cout << "Invalid input. Enter the numbers Again ";
        cin >> a >> b;
    }
    int max_steps = 0;
    int result = 0;
    for (int i = a; i <= b; i++) {
        int steps = collatz_steps(i);
        if (steps > max_steps) {
            max_steps = steps;
            result = i;
        }
    }
    cout << "The number that requires the most steps to transform into 1 is: " << result << std::endl;
    return 0;
}
