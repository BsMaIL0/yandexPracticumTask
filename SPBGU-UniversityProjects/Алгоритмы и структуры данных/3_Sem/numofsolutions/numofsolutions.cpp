#include <iostream>

unsigned long long num_of_solutions(int n, unsigned long long mod);

static constexpr int pent[] = {
    1,    2,    5,    7,    12,   15,   22,   26,   35,   40,   51,   57,
    70,   77,   92,   100,  117,  126,  145,  155,  176,  187,  210,  222,
    247,  260,  287,  301,  330,  345,  376,  392,  425,  442,  477,  495,
    532,  551,  590,  610,  651,  672,  715,  737,  782,  805,  852,  876,
    925,  950,  1001, 1027, 1080, 1107, 1162, 1190, 1247, 1276, 1335, 1365,
    1426, 1457, 1520, 1552, 1617, 1650, 1717, 1751, 1820, 1855, 1926, 1962,
    2035, 2072, 2147, 2185, 2262, 2301, 2380, 2420, 2501, 2542, 2625, 2667,
    2752, 2795, 2882, 2926, 3015, 3060, 3151, 3197, 3290, 3337, 3432, 3480,
    3577, 3626, 3725, 3775, 3876, 3927, 4030, 4082, 4187, 4240, 4347, 4401,
    4510, 4565, 4676, 4732, 4845, 4902, 5017, 5075, 5192, 5251, 5370, 5430,
    5551, 5612, 5735, 5797, 5922, 5985, 6112, 6176, 6305, 6370, 6501, 6567,
    6700, 6767, 6902, 6970, 7107, 7176, 7315, 7385, 7526, 7597, 7740, 7812,
    7957, 8030, 8177, 8251, 8400, 8475, 8626, 8702, 8855, 8932, 9087, 9165,
    9322, 9401, 9560, 9640, 9801, 9882};

const int pent_size = 162;

int main() {
  int n = 0;
  unsigned long long mod;
  std::cin >> n >> mod;
  std::cout << num_of_solutions(n, mod) << "\n";
  return 0;
}

// реализую через пентагональную теорему Эйлера
unsigned long long num_of_solutions(int n, unsigned long long mod) {
  if (mod == 0) {
    return 0;
  }

  unsigned long long *dp = new unsigned long long[n + 1];
  dp[0] = 1;

  for (int cur = 1; cur <= n; ++cur) {
    dp[cur] = 0;
    for (int i = 0; i < pent_size && pent[i] <= cur; ++i) {
      if (i % 4 <= 1) {
        dp[cur] = (dp[cur] + dp[cur - pent[i]]) % mod;
      } else {
        dp[cur] = (dp[cur] - dp[cur - pent[i]] + mod) % mod;
      }
    }
  }

  unsigned long long result = dp[n] % mod;
  delete[] dp;

  return result;
}
