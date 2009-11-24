/*
 * Author: Bharathan Rajaram
 * This is the class that sets up the Ogre application and the ray trace system.
 */

#include<Ogre.h>

/*
 * Class HybridApplication
 */
class HybridApplication
{
	public:
		HybridApplication();
		~HybridApplication();
		void go();	//Start the application
	protected:
		Ogre::Root mRoot;
		
		void initialiseOgre();
		void createScene();


}
