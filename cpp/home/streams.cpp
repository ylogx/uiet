#include <cstdio>
#include <iostream>

template <typename Test>
void test (Test t)
{
    const clock_t begin = clock();
    t();
    const clock_t end = clock();
    std::cout << (end-begin)/double(CLOCKS_PER_SEC) << " sec\n";
}

void std_io() {
    std::string line;
    unsigned dependency_var = 0;

    while (!feof (stdin)) {
        int c;
        line.clear();
        while (EOF != (c = fgetc(stdin)) && c!='\n')
            line.push_back (c);
        dependency_var += line.size();
    }

    std::cout << dependency_var << '\n';
}

void synced() {
    std::ios_base::sync_with_stdio (true);
    std::string line;
    unsigned dependency_var = 0;
    while (getline (std::cin, line)) {
        dependency_var += line.size();
    }
    std::cout << dependency_var << '\n';
}

void unsynced() {
    std::ios_base::sync_with_stdio (false);
    std::string line;
    unsigned dependency_var = 0;
    while (getline (std::cin, line)) {
        dependency_var += line.size();
    }
    std::cout << dependency_var << '\n';
}

void usage() { std::cout << "one of (synced|unsynced|stdio), pls\n"; }

int main (int argc, char *argv[]) {
    if (argc < 2) { usage(); return 1; }

    if (std::string(argv[1]) == "synced") test (synced);
    else if (std::string(argv[1]) == "unsynced") test (unsynced);
    else if (std::string(argv[1]) == "stdio") test (std_io);
    else { usage(); return 1; }

    return 0;
}
