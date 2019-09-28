#pragma once

namespace ofxFSM
{

    class BaseScene
    {
    public:
        virtual ~BaseScene() {};
        virtual void init(const int w, const int h) = 0;
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void update() = 0;
        virtual void updateContexts() = 0;
        virtual void render() = 0;
        virtual void renderGui() = 0;
        virtual void keyPressed(const int key) = 0;
    };

} // namespace ofxFSM