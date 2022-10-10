#include "sgepch.h"

#include "SGE/Application.h"

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
		delete m_window;
	}

	void Application::run()
	{
		while (m_isRunning)
		{
			m_window->onUpdate();

			glBegin(GL_TRIANGLES);
			glVertex2f(-0.5f,  0.5f);
			glVertex2f( 0.5f,  0.5f);
			glVertex2f(-0.5f, -0.5f);
			glEnd();

			for (auto it = m_layerStack.end(); it != m_layerStack.begin();)
			{
				(*--it)->onUpdate();
			}
		}
	}

	void Application::onEvent(IEvent& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowClosedEvent>(APP_BIND_EVENT_FUNCTION(OnWindowClose));

		for (auto it = m_layerStack.end(); it != m_layerStack.begin();)
		{
			(*--it)->onEvent(event);
		}

		SGE_CORE_TRACE("{0}", event.toString());
	}

	void Application::pushLayer(ILayer* layer)
	{
		m_layerStack.push(layer);
	}

	void Application::pushOverlay(ILayer* layer)
	{
		m_layerStack.pushOver(layer);
	}

	void Application::popLayer(ILayer* layer)
	{
		m_layerStack.pop(layer);
	}

	void Application::popOverlay(ILayer* layer)
	{
		m_layerStack.popOver(layer);
	}

	bool Application::OnWindowClose(WindowClosedEvent& event)
	{
		m_isRunning = false;
		return true;
	}
}