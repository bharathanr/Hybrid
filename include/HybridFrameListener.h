#include<Ogre.h>

class HybridFrameListener: public Ogre::FrameListener
{
	public:
		virtual bool frameStarted(const Ogre::FrameEvent &evt);
};
