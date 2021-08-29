/*
 * Build obj linking with cc_library file example.
 *
 * Copyright Bazel organization
 *
 */

#ifndef CH04_SIMPLENET_H_
#define CH04_SIMPLENET_H_

#include <cstddef>
#include <vector>
#include <optional>

using namespace std;

template <typename T>
class Simplenet
{
public:
	explicit Simplenet(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	virtual ~Simplenet() = default;

	// 복제 생성자와 대입 연산자를 명시적으로 디폴트로 지정한다.
	Simplenet(const Simplenet& src) = default;
	Simplenet<T>& operator=(const Simplenet& rhs) = default;

	// 이동 생성자와 대입 연산자를 명시적으로 디폴트로 지정한다.
	Simplenet(Simplenet&& src) = default;
	Simplenet<T>& operator=(Simplenet&& rhs) = default;

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::optional<T>>> mCells;
	size_t mWidth, mHeight;
};

#include "Simplenet.cc"

#endif  // CH04_SIMPLENET_H_
