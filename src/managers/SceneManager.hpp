#pragma once

#include <vector>
#include <memory>

#include "../bases/BaseScene.hpp"

namespace ofxFSM
{

    class SceneManager
    {
    public:
        SceneManager()
            : mIndex(0)
        {}
        
        void init(const int w, const int h)
        {
            for (auto& Scene : mScenes)
            {
                Scene->init(w, h);
            }
            mScenes[0]->start();
        }
        
        void update()
        {
            mScenes[mIndex]->updateContexts();
            mScenes[mIndex]->update();
        }
        
        void render()
        {
            mScenes[mIndex]->render();
        }
        
        void renderGui(const float x, const float y)
        {
            mScenes[mIndex]->renderGui(x, y);
        }
        
        void keyPressed(int key)
        {
            mScenes[mIndex]->keyPressed(key);
        }

        void changeScene(const int index)
        {
            if (index > mScenes.size() - 1)
                return;

            stop();
            mIndex = index;
            start();
        }

        template<typename T>
        void addScene()
        {
            mScenes.emplace_back(std::make_unique<T>());
        }
    
    private:
        void start()
        {
            mScenes[mIndex]->start();
        }
        
        void stop()
        {
            mScenes[mIndex]->stop();
        }
    
        std::vector<std::unique_ptr<BaseScene>> mScenes;
        int mIndex;
    };

} // namespace ofxFSM