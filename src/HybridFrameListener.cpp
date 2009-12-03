#include "HybridFrameListener.h"
#include<pair>

namespace HybridRenderer
{
	
	FrameListener::FrameListener(Ogre::SceneManager *sceneMgr, \
		       	Ogre::SceneNode *camNd, \
			CameraInputHandler* cih)
	{
		sceneManager = sceneMgr;
		cameNode = camNd;
		camInputHandler = cih;
	}

	FrameListener::~FrameListener()
	{
		//No deletions here. Pointers acess shared resources.
	}

	bool FrameListener::frameStarted(const Ogre::FrameEvent& evt)
	{
		result =  camInputHandler.getTransformations();
		camMove = result.first;
		camNode->translate(camMove,Ogre::Node::TS_LOCAL);
		return true;
	}
}
