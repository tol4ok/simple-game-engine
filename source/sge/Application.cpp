#include "Application.h"

namespace sge
{
	#define APP_BIND_EVENT_FUNCTION(func) std::bind(&Application::func, this, std::placeholders::_1)

	Application::Application() :
		m_window(IWindow::Create()),
		m_isRunning(true)
	{
		m_window->setEventCallbackFunction(APP_BIND_EVENT_FUNCTION(onEvent));
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		while (m_isRunning)
		{
			m_window->onUpdate();
		}
	}

	void Application::onEvent(IEvent& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowClosedEvent>(APP_BIND_EVENT_FUNCTION(OnWindowClose));

		SGE_CORE_TRACE("{0}", event.toString());
	}

	bool Application::OnWindowClose(WindowClosedEvent& event)
	{
		m_isRunning = false;
		return true;
	}
}