#pragma once

namespace ofxFSM
{

    class BaseState
    {
    public:
        virtual ~BaseState() {};
        virtual void init(const int w, const int h) = 0;
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void update() = 0;
        virtual void updateContexts() = 0;
        virtual void draw() = 0;
        virtual void drawGui(const float x, const float y) = 0;
        virtual void keyPressed(const int key) = 0;
    };

} // namespace ofxFSM