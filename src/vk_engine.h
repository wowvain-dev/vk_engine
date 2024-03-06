//
// Created by wowva on 3/6/2024.
//

#ifndef VULKANENGINE_VK_ENGINE_H
#define VULKANENGINE_VK_ENGINE_H

#include "vk_types.h"

class VulkanEngine {
public:
    bool _isInitialized { false };
    int _frameNumber {0};
    bool stop_rendering { false };
    VkExtent2D _windowExtent { 1700, 900 };

    VkInstance _instance;
    VkDebugUtilsMessengerEXT _debug_messenger;
    VkPhysicalDevice _chosenGPU;
    VkDevice _device;
    VkSurfaceKHR _surface;

    struct SDL_Window* _window { nullptr };

private:
    void init_vulkan();
    void init_swapchain();
    void init_commands();
    void init_sync_structures();

public:
    static VulkanEngine& Get();

    // Initializes everything in the engine
    void init();

    // Shuts down the engine
    void cleanup();

    // Draw loop
    void draw();

    // Run main loop
    void run();
};


#endif //VULKANENGINE_VK_ENGINE_H
