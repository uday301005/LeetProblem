class Solution {
public:

    long long countCommas(long long n) {
        if(n < 1000)
            return 0;
        if(n < 1000000)
            return n - 999;
        if(n < 1000000000LL)
            return 2LL * (n - 999999) + 999000;
        if(n < 1000000000000LL)
            return 3LL * (n - 999999999) + 1998999000LL;
        if(n < 1000000000000000LL)
            return 4LL * (n - 999999999999LL) + 2998998999000LL;
        return 3998998998999005LL;
    }
};