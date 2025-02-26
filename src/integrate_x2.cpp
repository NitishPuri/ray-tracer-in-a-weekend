#include <iomanip>
#include <iostream>
#include <random>

// inline double random_double() { return rand() / (RAND_MAX + 1.0); }
inline double random_double() {
  static thread_local std::mt19937 generator;
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  return distribution(generator);
}

inline double random_double(double min, double max) {
  return min + (max - min) * random_double();
}

int main() {
  int a = 0;
  int b = 2;
  int N = 1000000;
  auto sum = 0.0;

  for (int i = 0; i < N; i++) {
    auto x = random_double(a, b);
    sum += x * x;
  }

  std::cout << std::fixed << std::setprecision(12);
  std::cout << "I = " << (b - a) * (sum / N) << '\n';
}