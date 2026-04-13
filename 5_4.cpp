//Homework 5 Problem 4

#include <iostream>

using namespace std; 

class PrimeNumber {
    private: 
        int prime; 

        bool isPrime(int n){
            if (n < 2){
                return false;
            }
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    return false;
                }
            }
            return true;
        }

        int nextPrime(int n){
            int num = n + 1;
            while (!isPrime(num)) {
                num++;
            }
            return num;
        }

        int previousPrime(int n){
            if (n <= 2){
                return 1;
            }
            int num = n -1; 
            while(!isPrime(num)) {
                num--;
            }
            return num;
        }

    public:
        PrimeNumber() {
            prime = 1;
        }
        PrimeNumber(int p){
            prime = p;
        }

        int getPrime() {
            return prime;
        }

        PrimeNumber operator++() {
            prime = nextPrime(prime);
            return *this;
        }

        PrimeNumber operator++(int) {
            PrimeNumber temp(prime);
            prime = nextPrime(prime);
            return temp;
        }

        PrimeNumber operator--() {
            prime = previousPrime(prime);
            return *this;
        }

        PrimeNumber operator--(int) {
            PrimeNumber temp(prime);
            prime = previousPrime(prime);
            return temp;
        }
};

int main() {
    PrimeNumber p1;          // default constructor
    PrimeNumber p2(13);      // constructor with value

    cout << "Default prime: " << p1.getPrime() << endl;       // 1
    cout << "Initial p2:    " << p2.getPrime() << endl;       // 13

    p2++;
    cout << "After p2++:    " << p2.getPrime() << endl;       // 17

    p2--;
    cout << "After p2--:    " << p2.getPrime() << endl;       // 13

    ++p2;
    cout << "After ++p2:    " << p2.getPrime() << endl;       // 17

    --p2;
    cout << "After --p2:    " << p2.getPrime() << endl;       // 13

    return 0;
}