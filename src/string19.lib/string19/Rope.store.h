#pragma once
#include "ADL.h"
#include "Rope.Rope.h"
#include "StringStore.h"

namespace string19 {

template<class T> constexpr auto ropeCount(const T& v) -> size_t { return ropeCount(adl, v); }

/// @returns a StringStore that concats all parts of the Rope
/// usage:
///    constexpr auto rope = Rope{};
///    constexpr auto N = ropeCount(rope);
///    constexpr auto store = ropeStore<N>(rope);
template<size_t N, class... Ts> constexpr auto ropeStore(const Rope<Ts...>& r) -> const StringStore<N> {
    auto result = StringStore<N>{};
    auto* data = result.data;
    ropeAppend(adl, data, r);
    return result;
}

} // namespace string19
