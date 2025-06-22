#pragma once

#include "imgui.h"
#include <nvrhi/nvrhi.h>

bool ImGui_ImplNVRHI_Init(nvrhi::IDevice* device);
void ImGui_ImplNVRHI_RenderDrawData(ImDrawData* draw_data, nvrhi::IFramebuffer* buffer);
bool ImGui_ImplNVRHI_UpdateFontTexture();

void ImGui_ImplNVRHI_Shutdown();
