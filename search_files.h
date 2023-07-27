#ifndef SEARCH_FILES_H
#define SEARCH_FILES_H

#include <string>
#include <vector>
#include <thread>

void searchFiles(const std::string& rootDir, const std::string& targetFile, std::vector<std::thread>& threads, bool& found);

#endif // SEARCH_FILES_H
