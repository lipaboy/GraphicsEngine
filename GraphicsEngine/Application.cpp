#include "Application.h"
#include "GraphicsEngine/Directory.h"
#include "GraphicsEngine/PlatformApi/Platform.h"

#ifdef PLATFORM_LINUX
#include <unistd.h>
#include <string.h>
#include <QDir>
#endif

Application & Application::Instance()
{
	// TODO: ѕереписать все Singleton подобным образом
	// Ёто нужно, чтобы вызывались деструкторы
	static Application app;
	
	return app;
}

Application::Application()
{
	argv = NULL;
	
	if (Directory::Exists("./Shaders"))
	{
		// Application is run by exe-file
		m_shadersDirectory	= "./Shaders/";
		m_dataDirectory		= "./Data/";
	}
	else
	{
		// Application is run from IDE (i.e. Visual Studio)
//#ifdef PLATFORM_LINUX
//        char cwd[1024];
//        //chdir("/path/to/change/directory/to");
//        getcwd(cwd, sizeof(cwd));
//        strcat(cwd, "/");
//        m_shadersDirectory = QDir::currentPath().toStdString() + "/";
//                //"./../Sources/GraphicsEngine/Shaders/";
//#else
		m_shadersDirectory	= "../Sources/GraphicsEngine/Shaders/";
//#endif
		m_dataDirectory		= "../Data/";
	}
}

Application::~Application()
{
	
}

GraphicsEngineContext * Application::GetContext()
{
	return m_pContext;
}

void Application::SetContext(GraphicsEngineContext * pContext)
{
	m_pContext = pContext;
}

Scene & Application::GetScene()
{
	return m_scene;
}

const std::string & Application::GetShadersDirectory()
{
	return m_shadersDirectory;
}

const std::string & Application::GetDataDirectory()
{
	return m_dataDirectory;
}
