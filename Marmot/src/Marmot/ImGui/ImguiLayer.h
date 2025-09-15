#pragma once

#include"Marmot/Layer.h"

#include<Marmot/Events/KeyEvent.h>
#include<Marmot/Events/MouseEvent.h>
#include<Marmot/Events/ApplicationEvent.h>

namespace Marmot
{
	class MARMOT_API ImguiLayer : public Layer
	{
		bool m_blockEvents = true;

	public:
		ImguiLayer();
		~ImguiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_blockEvents = block; }
	};
}