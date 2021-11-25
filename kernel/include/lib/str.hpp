#ifndef STR_HPP
#define STR_HPP

namespace nlib {
    constexpr int MAX_ITOA_PRECISION = 50;

    int itoa(int val, char *str, int str_size);
    /*
    to_char() only accepts num from 0 to 9
    */
    template<class T>
    constexpr char to_char(T num) {
        if (num > 9)
            return 0;
        return static_cast<char>(num + '0');
    }
    template<class T>
    constexpr T to_num(char c) {
        return static_cast<T>(c - '0');
    }
}

#endif /* STR_HPP */