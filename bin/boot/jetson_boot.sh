# Function to check network connectivity
check_network() 
{
    ping -c 1 8.8.8.8 > /dev/null 2>&1  # Ping Google's DNS server once
}

# Ensure ROS2 Iron has been properly sourced
source /opt/ros/iron/setup.bash

# Boot the Raspberry Pi
bash ssh_rpi.sh &

# All code below is in progress. Need to add docker container stuff.
# cd to the controller workspace
cd /home/$USER/IGVCDev/src/data_collection_ws

# Switch to the main branch of the repo
git switch main

# Check that 'git switch main' has executed without an error
if [$? -ne 0]; then
    echo "Error: Failed to switch to the 'main' branch."
    exit 1
fi

# Check that we have an active network connection
check_network
if [$? -eq 0]; then

    # Pull in the most recent updates
    git pull

    # Check if 'git pull' failed to execute
    if [$? -ne 0]; then
        echo "Error: Failed to pull from remote repository."
        exit 1
    fi
fi

# Build the workspace
colcon build

# Check if colcon build failed to execute
if [$? -ne 0]; then
    echo "Error: Failed to build the workspace."
    exit 1
fi

# Source 'setup.bash'
source install/setup.bash

# Execute the launch file
ros2 launch data launch.py