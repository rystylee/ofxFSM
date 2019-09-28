#pragma once

#include "ofMain.h"

namespace ofxFSM
{

    class BaseObject
    {
    public:
        virtual ~BaseObject() {};
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void render() = 0;

    };

} // namespace ofxFSM