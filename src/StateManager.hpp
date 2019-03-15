#pragma once

#include <vector>
#include <memory>

#include "BaseState.hpp"

namespace ofxFSM
{

    class StateManager
    {
    public:
        StateManager()
        : mIndex(0)
        {}
        
        void init(const int w, const int h)
        {
            for (auto& state : mStates)
            {
                state->init(w, h);
            }
            mStates[0]->start();
        }
        
        void update()
        {
            mStates[mIndex]->updateContexts();
            mStates[mIndex]->update();
        }
        
        void draw()
        {
            mStates[mIndex]->draw();
        }
        
        void drawGui(const float x, const float y)
        {
            mStates[mIndex]->drawGui(x, y);
        }
        
        void keyPressed(int key)
        {
            mStates[mIndex]->keyPressed(key);
        }

        void changeState(const int index)
        {
            if (index > mStates.size() - 1)
                return;

            stop();
            mIndex = index;
            start();
        }

        template<typename T>
        void addState()
        {
            mStates.emplace_back(std::make_unique<T>());
        }
    
    private:
        void start()
        {
            mStates[mIndex]->start();
        }
        
        void stop()
        {
            mStates[mIndex]->stop();
        }
    
        std::vector<std::unique_ptr<BaseState>> mStates;
        int mIndex;
    };

} // namespace ofxFSM