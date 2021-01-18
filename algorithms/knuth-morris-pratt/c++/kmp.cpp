#include <string>
#include <iostream>
#include <vector>

void kmp(std::string str, std::string pat) {
    int N = str.length();
    int M = pat.length();

    // lps at i denotes the longest substring suffix end at i as same as prefix start at 0
    std::vector<int> lps(M);
    int len = 0;
    lps[0] = 0;
    for (int i = 1; i < M; i++) {
        while (len > 0 && pat[len] != pat[i]) len = lps[len-1];
        if (pat[len] == pat[i]) len++;
        lps[i] = len;
    }

    len = 0;
    for (int i = 0; i < N; i++) {
        while (len > 0 && pat[len] != str[i]) len = lps[len-1];
        if (str[i] == pat[len]) len++;
        if (len == M) {
            std::cout<<i-M+1<<" ";
            len = lps[len-1];
        }
    }

    std::cout<<std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: ./kmp_cpp string pattern" << std::endl;
        return 1;
    }

    std::string str = argv[1];
    std::string pat = argv[2];

    kmp(str, pat);    

    return 0;
}