#pragma once

#include "Core/Defines.h" 
#include "Events/IEvent.h"

#include <functional>

namespace sge
{
	struct WindowProps
	{
		const char* title;
		uint32_t width;
		uint32_t height;

		WindowProps(uint32_t _width = 800, uint32_t _height = 600, const char* _title = "untitled") :
			width(_width), height(_height), title(_title) {}

	};

	class IWindow
	{
	public:
		virtual ~IWindow() = default;

		virtual void onUpdate() = 0;

		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;
		
		virtual bool isVSync() const = 0;
		virtual void setVSync(bool) = 0;

		virtual void setEventCallbackFunction(const std::function<void(IEvent&)>& callback) = 0;
		
		static IWindow* Create(const WindowProps& props = WindowProps());
	};
}

