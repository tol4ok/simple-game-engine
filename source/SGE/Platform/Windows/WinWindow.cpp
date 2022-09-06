#include "WinWindow.h"

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/WindowEvent.h"

namespace sge
{
	static bool s_isGLFWinitialized = false;

	WinWindow::WinWindow(const WindowProps& props)
	{
		Init(props);
	}

	WinWindow::~WinWindow()
	{
		Shutdown();
	}

	void WinWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WinWindow::setVSync(bool b)
	{
		glfwSwapInterval(b ? 1 : 0);
		m_Data.isVSync = b;
	}

	void WinWindow::setEventCallbackFunction(const std::function<void(IEvent&)>& callback)
	{
		m_Data.callback = callback;
	}

	void WinWindow::Init(const WindowProps& props)
	{
		m_Data.width = props.width;
		m_Data.height = props.height;
		m_Data.title = props.title;

		if (!s_isGLFWinitialized)
		{
			int glfwStatus = glfwInit();

			assert("Cant intialize GLFW!", glfwStatus);
			SGE_CORE_INFO("GLFW initialized!");

			s_isGLFWinitialized = true;
		}

		m_window = glfwCreateWindow(props.width, props.height, props.title, nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_Data);
		setVSync(true);

		int gladStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		assert("Cant intialize GLAD!", gladStatus);

		SGE_CORE_INFO("Initialized Windows Window \"{0}\" ( {1} {2} ) ", props.title, props.width, props.height);

		glfwSetErrorCallback([](int error, const char* desc)
			{
				SGE_CORE_ERROR("GLFW error {0}: {1}", error, desc);
			});

		glfwSetWindowSizeCallback(m_window,
			[](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;
				
				WindowResizedEvent resizeEvent(width, height);
				data.callback(resizeEvent);
			});

		glfwSetWindowCloseCallback(m_window,
			[](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowClosedEvent closeEvent;
				data.callback(closeEvent);
			});

		glfwSetKeyCallback(m_window,
			[](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				KeyEvent* keyEvent= nullptr;

				switch (action)
				{
				case GLFW_PRESS:
					keyEvent = new KeyPressedEvent(key, false);
					break;
				case GLFW_RELEASE:
					keyEvent = new KeyReleasedEvent(key);
					break;
				case GLFW_REPEAT:
					keyEvent = new KeyPressedEvent(key, true);
					break;
				default:
					break;
				}

				if (keyEvent)
				{
					data.callback(*keyEvent);
					delete keyEvent;
				}
			});

		glfwSetMouseButtonCallback(m_window,
			[](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseButtonEvent* mouseEvent = nullptr;

				switch (action)
				{
				case GLFW_PRESS:
					mouseEvent = new MouseButtonPressedEvent(button);
					break;
				case GLFW_RELEASE:
					mouseEvent = new MouseButtonReleasedEvent(button);
					break;
				default:
					break;
				}

				if (mouseEvent)
				{
					data.callback(*mouseEvent);
					delete mouseEvent;
				}
			});

		glfwSetScrollCallback(m_window,
			[](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent scrollEvent((float)xOffset, (float)yOffset);

				data.callback(scrollEvent);
			});

		glfwSetCursorPosCallback(m_window,
			[](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent moveEvent((float)xPos, (float)yPos);
			
				data.callback(moveEvent);
			});
	}

	void WinWindow::Shutdown()
	{
		glfwDestroyWindow(m_window);
	}
}