#include <numeric>
#include <vector>

template<typename T>
T OR(T x1, T x2) {
    std::vector<T> x = {x1, x2};
    std::vector<T> w = {0.5, 0.5};
    T b = -0.2;
    T tmp = std::inner_product(x.begin(), x.end(),
        w.begin(), b);

    if (tmp <= 0)
        return 0;
    else
        return 1;
}