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
  std::cout << std::fixed << std::setprecision(12);

  int inside_circle = 0;
  int inside_circle_stratified = 0;
  int sqrt_N = 10000;

  for (int i = 0; i < sqrt_N; i++) {
    for (int j = 0; j < sqrt_N; j++) {
      auto x = random_double(-1, 1);
      auto y = random_double(-1, 1);
      if (x * x + y * y < 1) inside_circle++;

      x = 2 * ((i + random_double()) / sqrt_N) - 1;
      y = 2 * ((j + random_double()) / sqrt_N) - 1;
      if (x * x + y * y < 1) inside_circle_stratified++;
    }
  }

  std::cout << "Regular    Estimate of Pi = "
            << (4.0 * inside_circle) / (sqrt_N * sqrt_N) << '\n'
            << "Stratified Estimate of Pi = "
            << (4.0 * inside_circle_stratified) / (sqrt_N * sqrt_N) << '\n';

  return 0;
}