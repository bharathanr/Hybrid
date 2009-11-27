#include"HybridApplication.h"

using namespace Ogre;

HybridApplication::HybridApplication()
	: mRoot(0)
{
}

HybridApplication::~HybridApplication()
{
	//Delete the Ogre root.
	delete mRoot;
}

void HybridApplication::initialiseOgre()
{
	mRoot = new Ogre::Root();
}

bool HybridApplication::go()
{
	//1. Create Ogre root. Rely on the default plugin loading mechanism.
	initialiseOgre();
	//2.Initialise resources from resources.cfg - For now!
	initialiseResourcePaths();
	//3.Try to initialise a render system.
	//Uses the config dialog and ogre.cfg restoration for now.
	if(!setupRenderSystem())
		return false;
	//4.Create the render window using mRoot->initialise
	createRenderWindow();
	//5.Create a scene.
	createScene();
	//6.Set the default no. of mipmaps and initialise resources as needed.
	initialiseResources();
	//7.Keep looping until exit.
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

void HybridApplication::chooseSceneManager()
{
        sceneManager = mRoot->createSceneManager(ST_GENERIC, "HybridSceneManager");
}


void HybridApplication::createScene()
{
	chooseSceneManager();
	Camera *cam = sceneManager->createCamera("Camera");
	Viewport *vp = mRoot->getAutoCreatedWindow()->addViewport(cam);
}

void HybridApplication::createRayTraceScene()
{
}

void HybridApplication::createRenderWindow()
{
	mRoot->initialise(true, "Tutorial Render Window");
}

void HybridApplication::initialiseResourcePaths()
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

void HybridApplication::initialiseResources()
{
	//Set the default number of mipmaps.
	TextureManager::getSingleton().setDefaultNumMipmaps(5);
	//Resource loading -- Change this to initialise only the resources
	//needed later.
	ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void HybridApplication::startRenderLoop()
{
	//Improve this later
	mRoot->startRendering();
}
