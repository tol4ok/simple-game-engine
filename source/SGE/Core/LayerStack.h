#pragma once
#include "sgepch.h"

#include "SGE/Layers/ILayer.h"

namespace sge
{
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void push(ILayer* layer);
		void pop(ILayer* layer);

		void pushOver(ILayer* layer);
		void popOver(ILayer* layer);

		std::vector<ILayer*>::iterator begin();
		std::vector<ILayer*>::iterator end();
	private:
		std::vector<ILayer*> m_layers;
		std::vector<ILayer*>::iterator m_layerInsert;
	};
}