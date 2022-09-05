#pragma once>

#include "Core/Defines.h"
#include "Platform/Windows/WinWindow.h"
#include "Events/WindowEvent.h"

namespace sge
{
	class SGE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void run();
		void onEvent(IEvent& event);
	private:
		IWindow* m_window;
		bool m_isRunning;

		bool OnWindowClose(WindowClosedEvent& event);
	};

	Application* CreateApplication();
}
