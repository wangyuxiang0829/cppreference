#include <iostream>

namespace compile {
template <unsigned long N> struct binary {
    static const unsigned value = binary<N / 10>::value * 2 + N % 10;
};

template <> struct binary<0> { static const unsigned value = 0; };
} // namespace compile

namespace runtime {
unsigned binary(unsigned long N) {
    return N == 0 ? 0 : N % 10 + 2 * binary(N / 10);
}
} // namespace runtime

int main() {
    const unsigned one = compile::binary<1>::value;
    const unsigned three = compile::binary<11>::value;
    const unsigned five = runtime::binary(101);
    std::cout << one << " " << three << " " << five << std::endl;
    return 0;
}
