#include <utility>

#include "HybridFrameListener.h"
#include "HybridCameraInputHandler.h"

namespace HybridRenderer
{
	
	FrameListener::FrameListener(Ogre::SceneManager *sceneMgr)
	{
		sceneManager = sceneMgr;
	}

	FrameListener::~FrameListener()
	{
		//No deletions here. Pointers acess shared resources.
	}

	bool FrameListener::frameStarted(const Ogre::FrameEvent& evt)
	{
		return true;
	}
}
