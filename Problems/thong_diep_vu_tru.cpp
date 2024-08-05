#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
using namespace std;

// Function to check if a number is prime
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Function to check if m is a divisor of n
bool check_isDivisor(long long n, long long m) {
    return (n % m == 0);
}

// Function to convert a number to a corresponding character 'A' to 'Z'
char is_character(int n) {
    return 'A' + (n % 26 + 1);
}

int main() {
    long long N;
    cin >> N;

    vector<char> characters;

    // Check divisors from 1 to sqrt(N)
    for (long long i = 1; i * i <= N; i++) {
        if (check_isDivisor(N, i)) {
            if (isPrime(i)) {
                characters.push_back(is_character(i - 1)); // Convert i-1 to character
            }
            if (i != N / i && isPrime(N / i)) {
                characters.push_back(is_character(N / i - 1)); // Convert N/i - 1 to character
            }
        }
    }

    // Sort characters in ascending order
    sort(characters.begin(), characters.end());

    // Output the sorted characters
    for (char c : characters) {
        cout << c;
    }
    cout << endl;

    return 0;
}
