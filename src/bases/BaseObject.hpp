#pragma once

#include "ofMain.h"

namespace ofxFSM
{

    class BaseObject
    {
    public:
        virtual ~BaseObject() {};
        virtual void init() = 0;
        virtual void update(const float time = 0) = 0;
        virtual void render(ofEasyCam* cam = nullptr) = 0;

    };

} // namespace ofxFSM