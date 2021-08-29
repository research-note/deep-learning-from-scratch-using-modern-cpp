/*
 * Build cross_entropy_error lib.
 *
 */

#include "lib/cross_entropy_error.hpp"
#include <iostream>
#include <cmath>

// def cross_entropy_error(y, t):
//     if y.ndim == 1:
//         t = t.reshape(1, t.size)
//         y = y.reshape(1, y.size)
        
//     # 훈련 데이터가 원-핫 벡터라면 정답 레이블의 인덱스로 반환
//     if t.size == y.size:
//         t = t.argmax(axis=1)
             
//     batch_size = y.shape[0]
//     return -np.sum(np.log(y[np.arange(batch_size), t] + 1e-7)) / batch_size


template <typename Y, typename T>
auto cross_entropy_error(Y y, T t) {
    const auto delta = 1e-7;
    T es = std::transform(x.begin(), x.end(), x.begin(), [h](auto v) -> auto {
        return * log( v + h );
    });

    for (auto& [yv, tv] : zip(y, t)) {
        auto tv * log(yv + delta);
    }

    return -std::accumulate(es.begin(), es.end(), decltype(es)::value_type(0));
}
