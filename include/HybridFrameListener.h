#include<Ogre.h>

namespace HybridRenderer
{
	class FrameListener: public Ogre::FrameListener
	{
		public:
			virtual bool frameStarted(const Ogre::FrameEvent &evt);
	};
}
