#include "../include/lib/str.hpp"

namespace nlib {
    /*
NOTE: str_size excluding the null terminator
*/
    int itoa(int val, char *str, int str_size) {
        char arr[MAX_ITOA_PRECISION] = {0};
        int arrIndex = MAX_ITOA_PRECISION - 1;
        if (val == 0) {
            arr[arrIndex] = to_char(0);
        } else {
            while (arrIndex >= 0 && val != 0) {
                arr[arrIndex] = to_char(val % 10);
                val /= 10;
                arrIndex--;
            }
        }
        arrIndex++;
        int i;
        for (i = 0; i < str_size - 1; i++) {
            if (arrIndex > MAX_ITOA_PRECISION - 1)
                break;
            str[i] = arr[arrIndex];
            arrIndex++;
        }
        str[i] = '\0';
        return 0;
    }
}