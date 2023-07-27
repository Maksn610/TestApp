#include "search_files.h"
#include <filesystem>
#include <iostream>
#include <vector>
#include <thread>

namespace fs = std::filesystem;

void searchFiles(const std::string& rootDir, const std::string& targetFile, std::vector<std::thread>& threads, bool& found) {
    if (found) return;

    for (const auto& entry : fs::directory_iterator(rootDir)) {
        const auto& path = entry.path();
        if (fs::is_directory(path)) {
            threads.emplace_back(searchFiles, path.string(), targetFile, std::ref(threads), std::ref(found));
        } else if (fs::is_regular_file(path) && path.filename().string() == targetFile) {
            found = true;
            std::cout << "File found: " << path.string() << std::endl;
            break;
        }
    }
}
