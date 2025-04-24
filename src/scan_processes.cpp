#include "scan_processes.h"
#include <fstream>
#include <vector>
#include <string>
#include <dirent.h>

namespace zerovuln
{
    std::vector<std::string> scan_processes()
    {
        std::vector<std::string> results;
        DIR *dir = opendir("/proc");
        if (!dir)
            return {"Cannot access /proc"};

        struct dirent *ent;
        while ((ent = readdir(dir)))
        {
            if (!isdigit(ent->d_name[0]))
                continue;
            std::string pid(ent->d_name);
            std::ifstream cmdline("/proc/" + pid + "/cmdline");
            std::string cmd;
            getline(cmdline, cmd);
            if (cmd.find("nc") != std::string::npos || cmd.find("bash") != std::string::npos)
            {
                results.push_back("Suspicious process PID: " + pid);
            }
        }
        closedir(dir);
        return results;
    }

}
