/*
 * Build obj linking with cc_library Simplenet Class.
 *
 * Copyright Bazel organization
 *
 */

#include <stdexcept>
#include <utility>
#include <random>

template <typename T>
Simplenet<T>::Simplenet(size_t width, size_t height)
    : mWidth(width)
    , mHeight(height)
{
    mCells.resize(mWidth);
    for (auto& column : mCells) {
        column.resize(mHeight);
    }
}

template <typename T>
void randomize()
{
    random_device seeder;
    const auto seed = seeder.entropy() ? seeder() : time(nullptr);
    mt19937 eng(static_cast<mt19937::result_type>(seed));
    normal_distribution<T> dist(0.0, 1.0);
    auto gen = bind(dist, eng);
    // for (auto& column : mCells) {
    //     for (auto& row : column) {
    //         row = gen();
    //         std::cout << ' ' << row << std::end;
    //     }
    //     std::cout << std::end;
    // }
}

template <typename T>
void Simplenet<T>::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight) {
        throw std::out_of_range("");
    }
}

template <typename T>
const std::optional<T>& Simplenet<T>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

template <typename T>
std::optional<T>& Simplenet<T>::at(size_t x, size_t y)
{
    return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}