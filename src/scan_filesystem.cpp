#include "scan_filesystem.h"
#include <filesystem>
#include <vector>
#include <string>

namespace zerovuln
{

    std::vector<std::string> scan_filesystem()
    {
        std::vector<std::string> results;
        for (const auto &path : {"/etc", "/usr/bin", "/usr/local/bin", "/root"})
        {
            try
            {
                for (const auto &entry : std::filesystem::recursive_directory_iterator(path))
                {
                    if (!std::filesystem::is_regular_file(entry))
                        continue;

                    std::string file_name = entry.path().filename().string();
                    if (file_name.substr(0, 1) == "." || file_name.substr(0, 4) == "init")
                    {
                        results.push_back("Suspicious file: " + entry.path().string());
                    }
                }
            }
            catch (...)
            {
                results.push_back("Permission denied: " + std::string(path));
            }
        }
        return results;
    }

}
