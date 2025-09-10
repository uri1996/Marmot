#pragma once

#include"Marmot/Layer.h"

namespace Marmot
{
	class MARMOT_API ImguiLayer : public Layer
	{
		float m_time = 0.f;
	public:
		ImguiLayer();
		~ImguiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
	};
}