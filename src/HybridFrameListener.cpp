#include <utility>

#include "HybridFrameListener.h"
#include "HybridCameraInputHandler.h"

namespace HybridRenderer
{
	
	FrameListener::FrameListener(Ogre::SceneManager *sceneMgr, \
		       	Ogre::SceneNode *camNd, \
			CameraInputHandler* cih)
	{
		sceneManager = sceneMgr;
		camNode = camNd;
		camInputHandler = cih;
	}

	FrameListener::~FrameListener()
	{
		//No deletions here. Pointers acess shared resources.
	}

	bool FrameListener::frameStarted(const Ogre::FrameEvent& evt)
	{
		std::pair<Ogre::Vector3*, Ogre::Quaternion*> result =  camInputHandler->getTransformations();
		Ogre::Vector3 camMove = *(result.first);
		camNode->translate(camMove * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
		return true;
	}
}
