#pragma once

#include "Settings.hpp"

#if defined(__SWITCH__) && defined(BOREALIS_USE_DEKO3D)
#include <borealis.hpp>
#include <borealis/platforms/switch/switch_video.hpp>

// Applied on the next frame, so it is safe to call at any point on the UI thread.
inline void applySwitchPresentationSettings() {
    auto* context = static_cast<brls::SwitchVideoContext*>(
        brls::Application::getPlatform()->getVideoContext());
    context->setFramebufferCount(Settings::instance().double_buffer() ? 2 : 3);
}
#else
inline void applySwitchPresentationSettings() {}
#endif
