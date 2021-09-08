/*
 * Build obj linking with cc_library file template.
 *
 * Copyright Paran Lee
 *
 */

#include <stdexcept>
#include <utility>

template <typename T>
Cuboid<T>::Cuboid(size_t width, size_t height, size_t depth)
    : mWidth(width)
      , mHeight(height)
	  , mDepth(depth)
{
    mCells.resize(mWidth);
    for (auto& column : mCells) {
        column.resize(mHeight);
        for (auto& row : column) {
            row.resize(depth);
        }
        
    }
}

template <typename T>
void Cuboid<T>::verifyCoordinate(size_t x) const
{
    if (x >= mWidth) {
        throw std::out_of_range("");
    }
}

template <typename T>
void Cuboid<T>::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight) {
        throw std::out_of_range("");
    }
}

template <typename T>
void Cuboid<T>::verifyCoordinate(size_t x, size_t y, size_t z) const
{
    if (x >= mWidth || y >= mHeight || z >= mHeight) {
        throw std::out_of_range("");
    }
}


template <typename T>
const std::optional<T>& Cuboid<T>::at(size_t x, size_t y, size_t z) const
{
    verifyCoordinate(x, y, z);
    return mCells[x][y][z];
}

template <typename T>
std::optional<T>& Cuboid<T>::at(size_t x, size_t y, size_t z)
{
    return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y, z));
}


template <typename T>
const std::vector<std::optional<T>>& Cuboid<T>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

template <typename T>
std::vector<std::optional<T>>& Cuboid<T>::at(size_t x, size_t y)
{
    return const_cast<std::vector<std::optional<T>&>>(std::as_const(*this).at(x, y));
}


template <typename T>
const std::vector<std::vector<std::optional<T>>>& Cuboid<T>::at(size_t x) const
{
    verifyCoordinate(x);
    return mCells[x];
}

template <typename T>
std::vector<std::vector<std::optional<T>>>& Cuboid<T>::at(size_t x)
{
    return const_cast<std::vector<std::vector<std::optional<T>&>>>(std::as_const(*this).at(x));
}
