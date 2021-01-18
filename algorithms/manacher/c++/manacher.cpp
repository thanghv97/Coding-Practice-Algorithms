#include <iostream>
#include <vector>

void manacher(std::string str) {
    int n = str.length();
    std::vector<int> f(2 * n + 1);

    // create new string by add character # between characters of base string
    // example base string aabc => new string #a#a#b#c# 
    std::string p = "#";
    for (int i = 0; i < n; i++) {
        p = p + str[i] + '#';
    }

    int center = 0, right_most = 0;
    int rs = 0, id = 0; 

    for (int i = 1; i < 2*n+1; i++) {
        // set longest palindromes length at i base on symmetric point i_mirror though center point and right_most
        int i_mirror = 2 * center - i;
        f[i] = (i < right_most) ? std::min(right_most - i, f[i_mirror]) : 0;

        // expand longest palindromes length at i 
        while (i - f[i] - 1 >= 0 && i + f[i] + 1 < 2*n+1 && p[i - f[i] - 1] == p[i + f[i] + 1]) f[i]++;

        // check is longest palindromes substring to save position i
        if (f[i] > rs) {
            rs = f[i];
            id = (i - 1) / 2;  // index of string str
        }

        // update right_most and center
        if (i + f[i] > right_most) {
            right_most = i + f[i];
            center = i;
        }
    }

    std::cout << "longest palindromes substring: " << str.substr(id - (rs - 1) / 2, rs) << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./manacher_cpp string" << std::endl;
        return 1;
    }

    std::string str = argv[1];

    manacher(str);

    return 0;
}