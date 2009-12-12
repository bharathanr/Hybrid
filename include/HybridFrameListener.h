#ifndef HYBRID_FRAME_LISTENER_H
#define HYBRID_FRAME_LISTENER_H

#include<Ogre.h>

namespace HybridRenderer
{
	class CameraInputHandler;

	class FrameListener: public Ogre::FrameListener
	{
		private:
			Ogre::SceneManager *sceneManager;
			Ogre::SceneNode *camNode;
			CameraInputHandler *camInputHandler;
		public:
			FrameListener(Ogre::SceneManager*, Ogre::SceneNode*, CameraInputHandler*);
			~FrameListener();
			virtual bool frameStarted(const Ogre::FrameEvent &evt);
	};
}

#endif
