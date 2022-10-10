#include "sgepch.h"

#include "SGE/Core/LayerStack.h"

namespace sge
{
	LayerStack::LayerStack()
	{
		m_layerInsert = m_layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (ILayer* layer : m_layers)
		{
			delete layer;
		}
	}

	void LayerStack::push(ILayer* layer)
	{
		m_layers.emplace(m_layerInsert, layer);
	}

	void LayerStack::pop(ILayer* layer)
	{
		auto it = std::find(begin(), end(), layer);

		if (it != end())
		{
			m_layers.erase(it);
			m_layerInsert--;
		}
	}

	void LayerStack::pushOver(ILayer* layer)
	{
		m_layers.emplace_back(layer);
	}

	void LayerStack::popOver(ILayer* layer)
	{
		auto it = std::find(begin(), end(), layer);

		if (it != end())
		{
			m_layers.erase(it);
		}
	}

	std::vector<ILayer*>::iterator LayerStack::begin()
	{
		return m_layers.begin();
	}

	std::vector<ILayer*>::iterator LayerStack::end()
	{
		return m_layers.end();
	}
}