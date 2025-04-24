#!/bin/bash

SCRIPT_PATH="scan_vulns.sh"

sudo cp "$SCRIPT_PATH" /usr/local/bin/scan_vulns

sudo chmod +x /usr/local/bin/scan_vulns

echo "Setup complete! You can now run the scan_vulns script from anywhere using 'scan_vulns'."
