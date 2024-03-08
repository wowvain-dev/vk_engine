# VK Engine. A useless pile of crap that might render something with enough luck

### How to install

Your guess is as good as mine, everytime I restart the PC I'm worried it might not work anymore.

I'd suggest a `git clone --recursive https://github.com/wowvain-dev/vk_engine`.

Make sure you have installed CMake.
Make sure you have installed the VulkanSDK: https://www.lunarg.com/vulkan-sdk/

Then run this in the root folder:

`cmake.exe -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=<ninja_install_path> -G Ninja -S . -B .\build`

After this a `build` folder should be generated so we can run:

`cmake.exe --build build/ --target Engine && bin/Engine.exe`


This might genuinely work. If it doesn't create an issue and I might read it on the toilet and think of a fix.


### How to use

You open it and look at it. Marvelous.

### Documentation

Good luck reading this: https://docs.vulkan.org/spec/latest/index.html

### Libraries used

- Vulkan - duh

- SDL/SDL2 - Window creation stuff, could probably use GLFW instead
- vma - Simplify vulkan related memory allocations
- fmt - Does formatting of some stuff
- imgui - not used yet, will be the engine's UI
- glm - Linear algebra 
- vkbootstrap - Kinda simplified the process of initializing vulkan's extensions, queues, devices etc.
- stb - not used yet, image importing


If this project actually becomes something I don't know how half of it works so don't ask me.