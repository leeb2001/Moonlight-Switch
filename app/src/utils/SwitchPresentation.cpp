#include "SwitchPresentation.hpp"

#if defined(__SWITCH__) && defined(BOREALIS_USE_DEKO3D)
// Must come first: it refers to libnx's Event, which is ambiguous once another
// header has brought brls::Event in with `using namespace brls`.
#include <borealis/platforms/switch/switch_video.hpp>

#include "Settings.hpp"

void applySwitchPresentationSettings() {
    brls::SwitchVideoContext::framebufferCount =
        Settings::instance().double_buffer() ? 2 : 3;
}
#else
void applySwitchPresentationSettings() {}
#endif
