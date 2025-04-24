#include "scan_services.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

namespace zerovuln
{

    std::vector<std::string> scan_services()
    {
        std::vector<std::string> results;
        FILE *pipe = popen("systemctl list-units --type=service --state=running", "r");
        if (!pipe)
            return {"Failed to run systemctl"};

        char buffer[256];
        while (fgets(buffer, sizeof(buffer), pipe))
        {
            std::string line(buffer);
            if (line.find("fail") != std::string::npos || line.find("error") != std::string::npos)
            {
                results.push_back("Problematic service: " + line);
            }
        }
        pclose(pipe);
        return results;
    }

}
