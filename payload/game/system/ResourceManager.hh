#pragma once

#include <egg/core/eggHeap.hh>

namespace System {

class ResourceManager {
public:
    ResourceManager();

    void createMenuHeaps(u32 count, s32 heapIdx);
    void preloadCourseAsync(u32 courseId);

    static REPLACE ResourceManager *CreateInstance();
    static ResourceManager *Instance() { return s_instance; }

private:
    void loadGlobe(u8 **dst);

    REPLACE static void LoadGlobeTask(void *arg);

    u8 _000[0x60c - 0x000];
    bool m_globeLoadingIsBusy;
    u8 _60d[0x614 - 0x60d];
    EGG::Heap *m_globeHeap;
    u8 _618[0x61c - 0x618];
    u8 *m_globe;

    static ResourceManager *s_instance;
};
static_assert(sizeof(ResourceManager) > 0x61c);

} // namespace System
