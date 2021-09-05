/*
 * Build obj linking with cc_library file template.
 *
 * Copyright Paran Lee
 *
 */

#ifndef TEMPLATE_FOR_CLASS_LIB_CUBOID_HPP_
#define TEMPLATE_FOR_CLASS_LIB_CUBOID_HPP_

#pragma once

#include <cstddef>
#include <vector>
#include <optional>

template <typename T>
class Cuboid
{
public:
    explicit Cuboid(size_t width = kDefaultWidth,
                size_t height = kDefaultHeight,
                size_t depth = kDefaultDepth);
    virtual ~Cuboid() = default;

    // 복제 생성자와 대입 연산자를 명시적으로 디폴트로 지정한다.
    Cuboid(const Cuboid& src) = default;
    Cuboid<T>& operator=(const Cuboid& rhs) = default;

    // 이동 생성자와 대입 연산자를 명시적으로 디폴트로 지정한다.
    Cuboid(Cuboid&& src) = default;
    Cuboid<T>& operator=(Cuboid&& rhs) = default;

    std::optional<T>& at(size_t x, size_t y, size_t z);
    const std::optional<T>& at(size_t x, size_t y, size_t z) const;

    size_t getWidth() const { return mWidth; }
    size_t getHeight() const { return mHeight; }
    size_t getDepth() const { return mDepth; }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;
    static const size_t kDefaultDepth = 10;

private:
    void verifyCoordinate(size_t x, size_t y, size_t z) const;

    std::vector<std::vector<std::vector<std::optional<T>>>> mCells;
    size_t mWidth, mHeight, mDepth;
};

#include "Cuboid.cc"

#endif  // TEMPLATE_FOR_CLASS_LIB_CUBOID_HPP_
