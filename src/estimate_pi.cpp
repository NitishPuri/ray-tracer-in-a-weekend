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
  int runs = 0;

  while (true) {
    runs++;
    auto x = random_double(-1, 1);
    auto y = random_double(-1, 1);
    if (x * x + y * y <= 1) {
      ++inside_circle;
    }

    if (runs % 1000000 == 0) {
      std::cout << "Pi is roughly " << 4.0 * inside_circle / runs << std::endl;
    }
  }

  // std::cout << "Pi is roughly " << 4.0 * inside_circle / N << std::endl;
  return 0;
}