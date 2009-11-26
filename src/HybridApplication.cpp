#include"HybridApplication.h"

using namespace Ogre;

HybridApplication::HybridApplication()
	: mRoot(0)
{
}

HybridApplication::~HybridApplication()
{
	//Delete the Ogre root.-- if it exists
	delete mRoot;
}

void HybridApplication::initialiseOgre()
{
	mRoot = new Ogre::Root();
}

bool HybridApplication::go()
{
	initialiseOgre();
	initialiseResources();
	if(!setupRenderSystem())
		return false;
	createRenderWindow();
	createScene();

	//Set the default number of mipmaps.
	TextureManager::getSingleton().setDefaultNumMipmaps(5);
	//Resource loading -- Do this with a little more care later.
	ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	startRenderLoop();
	return true;
}

bool HybridApplication::setupRenderSystem()
{
	if (!mRoot->restoreConfig() && !mRoot->showConfigDialog())
		return false;
	//This else is for intent more than anything else.
	else
		return true;
}

void HybridApplication::createScene()
{
	//Refactoring needed. Think carefully.
        SceneManager *mgr = mRoot->createSceneManager(ST_GENERIC, "Default SceneManager");
	Camera *cam = mgr->createCamera("Camera");
	Viewport *vp = mRoot->getAutoCreatedWindow()->addViewport(cam);

}

void HybridApplication::createRayTraceScene()
{
}

void HybridApplication::createRenderWindow()
{
	mRoot->initialise(true, "Tutorial Render Window");
}

void HybridApplication::initialiseResources()
{
	//Define Resources
	
	//Handle with more care later.
        String secName, typeName, archName;
	ConfigFile cf;
	cf.load("resources.cfg");
        ConfigFile::SectionIterator seci = cf.getSectionIterator();
        while (seci.hasMoreElements())
        {
	        secName = seci.peekNextKey();
	        ConfigFile::SettingsMultiMap *settings = seci.getNext();
	        ConfigFile::SettingsMultiMap::iterator i;
	        for (i = settings->begin(); i != settings->end(); ++i)
	        {
	        	typeName = i->first;
			archName = i->second;
			ResourceGroupManager::getSingleton().\
				addResourceLocation(archName, typeName, secName); 
		}
   	}

}

void HybridApplication::startRenderLoop()
{
	//Improve this later
	mRoot->startRendering();
}
