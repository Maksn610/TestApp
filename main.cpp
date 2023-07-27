#include "search_files.h"
#include <iostream>
#include <vector>
#include <thread>

int main() {
    std::string rootDir = "C:\\";
    std::string targetFile = "target.txt"; // Замініть на ім`я файлу який шукаєте

    bool found = false;
    std::vector<std::thread> threads;

    searchFiles(rootDir, targetFile, threads, found);

    for (auto& thread : threads) {
        thread.join();
    }

    if (!found) {
        std::cout << "File not found!" << std::endl;
    }

    return 0;
}
