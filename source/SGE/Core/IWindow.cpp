#include "sgepch.h"

#include "IWindow.h"

#ifdef SGE_PLATFORM_WINDOWS
	#include "SGE/Platform/Windows/WinWindow.h"
#endif

namespace sge
{
	IWindow* IWindow::Create(const WindowProps& props)
	{
		#ifdef SGE_PLATFORM_WINDOWS
			return new WinWindow(props);
		#else
			return nullptr;
		#endif
	}
}
