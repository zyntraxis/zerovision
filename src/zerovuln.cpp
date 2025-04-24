#include "zerovuln.h"
#include "scan_filesystem.h"
#include "scan_network.h"
#include "scan_processes.h"
#include "scan_services.h"
#include <iostream>

namespace zerovuln
{

    void scan_all()
    {
        std::cout << "[*] Starting full vulnerability scan...\n";

        auto fs = scan_filesystem();
        auto ps = scan_processes();
        auto sv = scan_services();
        auto nw = scan_network();

        std::cout << "\n[+] Filesystem issues: " << fs.size() << "\n";
        for (const auto &entry : fs)
            std::cout << "  - " << entry << "\n";

        std::cout << "\n[+] Suspicious processes: " << ps.size() << "\n";
        for (const auto &entry : ps)
            std::cout << "  - " << entry << "\n";

        std::cout << "\n[+] Service issues: " << sv.size() << "\n";
        for (const auto &entry : sv)
            std::cout << "  - " << entry << "\n";

        std::cout << "\n[+] Network issues: " << nw.size() << "\n";
        for (const auto &entry : nw)
            std::cout << "  - " << entry << "\n";
    }

}
