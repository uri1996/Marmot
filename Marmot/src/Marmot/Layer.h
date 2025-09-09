#pragma once

#include"Marmot/Core.h"
#include"Marmot/Events/Event.h"

namespace Marmot
{
	class MARMOT_API Layer
	{
	protected:
		std::string m_debugName;

	public:
		Layer(const std::string& name = "layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_debugName; }
	};
}