#ifndef MAX44009_H
#define MAX44009_H

namespace ootb 
{
    class MAX44009
    {
    public:
        MAX44009();
        MAX44009(int sda, int scl);
        float lux() const;
    };
}
#endif
