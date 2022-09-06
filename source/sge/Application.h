#pragma once>

#include "SGE/Core/Defines.h"
#include "SGE/Platform/Windows/WinWindow.h"
#include "SGE/Events/WindowEvent.h"
#include "SGE/Core/LayerStack.h"

namespace sge
{
	class SGE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void run();
		void onEvent(IEvent& event);

		void pushLayer(ILayer* layer);
		void pushOverlay(ILayer* layer);

		void popLayer(ILayer* layer);
		void popOverlay(ILayer* layer);
	private:
		IWindow* m_window;
		bool m_isRunning;

		LayerStack m_layerStack;

		bool OnWindowClose(WindowClosedEvent& event);
	};

	Application* CreateApplication();
}
