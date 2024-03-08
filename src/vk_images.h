//
// Created by wowva on 3/8/2024.
//

#ifndef VK_IMAGES_H
#define VK_IMAGES_H

#include <vulkan/vulkan.h>

namespace vkutil {
    void transition_image(VkCommandBuffer cmd, VkImage image, VkImageLayout currentLayout, VkImageLayout newLayout);


}


#endif //VK_IMAGES_H
