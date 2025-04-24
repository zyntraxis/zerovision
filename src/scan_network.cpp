#include "scan_network.h"
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

namespace zerovuln
{

    std::vector<std::string> scan_network()
    {
        std::vector<std::string> results;
        FILE *pipe = popen("ss -tulnp", "r");
        if (!pipe)
            return {"Failed to run ss"};

        char buffer[512];
        while (fgets(buffer, sizeof(buffer), pipe))
        {
            std::string line(buffer);
            if (line.find("0.0.0.0") != std::string::npos || line.find(":::") != std::string::npos)
            {
                results.push_back("Open port to world: " + line);
            }
        }
        pclose(pipe);
        return results;
    }
}
