#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <chrono>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: touch <file1> [file2 ...] [--force] [--update]\n";
        return 1;
    }

    bool force = false;
    bool update = false;
    std::vector<std::string> filenames;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--force")
            force = true;
        else if (arg == "--update")
            update = true;
        else
            filenames.push_back(arg);
    }

    if (filenames.empty()) {
        std::cerr << "Error: no filenames provided.\n";
        return 1;
    }

    for (const auto& name : filenames) {
        fs::path file_path = name;

        try {
            if (fs::exists(file_path)) {
                if (force) {
                    std::ofstream(file_path).close();
                    std::cout << "Existing file overwritten: " << file_path.string() << std::endl;
                } 
                else if (update) {
                    auto now = fs::file_time_type::clock::now();
                    fs::last_write_time(file_path, now);
                    std::cout << "Modification time updated: " << file_path.string() << std::endl;
                } 
                else {
                    std::cerr << "Warning: file '" << file_path.string()
                              << "' already exists. Use --force to overwrite it or --update to update its timestamp.\n";
                }
            } 
            else {
                std::ofstream(file_path).close();
                std::cout << "File created: " << file_path.string() << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error processing '" << file_path.string()
                      << "': " << e.what() << std::endl;
        }
    }

    return 0;
}
