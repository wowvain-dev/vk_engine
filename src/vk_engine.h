//
// Created by wowva on 3/6/2024.
//

#ifndef VULKANENGINE_VK_ENGINE_H
#define VULKANENGINE_VK_ENGINE_H

#include "vk_types.h"

struct FrameData {
    VkCommandPool _commandPool;
    VkCommandBuffer _mainCommandBuffer;
    VkSemaphore _swapchainSemaphore, _renderSemaphore;
    VkFence _renderFence;
};

constexpr unsigned int FRAME_OVERLAP = 2;

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
    VkSwapchainKHR _swapchain;
    VkFormat _swapchainImageFormat;

    std::vector<VkImage> _swapchainImages;
    std::vector<VkImageView> _swapchainImageViews;
    VkExtent2D _swapchainExtent;

    struct SDL_Window* _window { nullptr };

    FrameData _frames[FRAME_OVERLAP];

    FrameData& get_current_frame() { return _frames[_frameNumber % FRAME_OVERLAP]; }

    VkQueue _graphicsQueue;
    uint32_t _graphicsQueueFamily;

private:
    void init_vulkan();
    void init_swapchain();
    void init_commands();
    void init_sync_structures();
    void create_swapchain(uint32_t width, uint32_t height);
    void destroy_swapchain();


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
