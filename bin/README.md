# bin
The 'bin' folder contains utilites used directly by users and other programs.

## List of Utilities
### Boot Utilities
* jetson_boot.sh
* rpi_boot.sh
* ssh_rpi.sh

## Boot Utilities
### Run at Boot
The boot utilities are designed to be executed by the system at boot. This ensures that the system is ready for use once the AutoNav system if powered on. Perform the steps below to configure your system to execute a shell script at boot.

1. Open a teminal window
2. Type the command `crontab -e`
3. If prompted to choose an editor, select your preferred choice
4. Navigate to the bottom of the file below all the comments
5. Add the following line to the file: `@reboot </path/to/your/script.sh>`
    * If the root directory is the user home folder, the following line should work: `@reboot /home/$(whoami)/AutoNav/bin/boot/<boot_file.sh>`
6. Save the file
7. Reboot and test

### jetson_boot.sh
Author: Duncan Clark  
Date: 6/6/2024  
Purpose: Shell script designed to execute on the Nvidia Jetson at startup  
How to Use: Perform the steps outlined under the 'Run at Boot' section above  

### rpi_boot.sh
Author: Duncan Clark  
Date: 6/6/2024  
Purpose: Shell script designed to execute on the Raspberry PI at startup  
How to Use: Perform the steps outlined under the 'Run at Boot' section above  

### ssh_rpi.sh
Author: Duncan Clark  
Date: 6/6/2024  
Purpose: To ssh into the raspberry pi and launch the ROS workspace  
How to Use: This function is used by jetson_boot.sh  