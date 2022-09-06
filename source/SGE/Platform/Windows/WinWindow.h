#pragma once

#include "Core/IWindow.h"
#include "Core/Log.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace sge
{
	class SGE_API WinWindow final : public IWindow
	{
	public:
		WinWindow(const WindowProps& props = WindowProps());
		~WinWindow();

		void onUpdate() override;

		inline uint32_t getWidth() const override { return m_Data.width; };
		inline uint32_t getHeight() const override { return m_Data.height; };
		inline bool isVSync() const override { return m_Data.isVSync; };

		void setVSync(bool b) override;

		void setEventCallbackFunction(const std::function<void(IEvent&)>& callback) override;
	private:
		GLFWwindow* m_window;

		void Init(const WindowProps& props);
		void Shutdown();

		struct WindowData
		{
			uint32_t width, height;
			const char* title;
			bool isVSync;
			std::function<void(IEvent&)> callback;
		} m_Data;
	};
}