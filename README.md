SImple Setup Guide For PX4Avd
=================

# Px4avd
Simple Obstacle Avoidance System Using RPLidar A2 and Pixhawk, ROS  
Created By 이승찬, Korea Science Academy of KAIST 19th.  
Developed Since 2020.10 ~  

## Requirements   
### **Drone**  
**FC** : Holybro Pixhawk 4 (FMUv4)  
Just Recommended. Other FC can connected with Linux device with MAVLink can be used.  
**FrameWheel** : DJI F450, 2212 920kv, 4cell Lipo  
Just Recommended, But 450-sized frame is best.  
(Because bigger frame doesn't match purpose for obstacle avoidance, and smaller frame cannot carry Linux device and other modules.)  
**RC** : I used FrSky Taranis Q7 & x8R  
### **System**  
**Linux Device** : Raspberry Pi 3B+ or higher. (Banana PI, Rock PI also good for this system)  
If you  use lower spec device, you might experience frequent freezing when setting up the environment.  
I think using ubuntu server image can solve this problem.  
**Linux OS** : Ubuntu 18.04 LTS  
I used Ubuntu Mate 18.04 armhf. ***Do not use arm64 version. Using 64-bit OS can cause library compile error.***  
**LiDAR** : Slamtec RPLiDAR A2M8  
## Hardware Setup

