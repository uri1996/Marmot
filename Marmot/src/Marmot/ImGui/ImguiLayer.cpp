#include"mmpch.h"
#include"ImguiLayer.h"

#include"imgui.h"
#include"Platform/OpenGL/ImguiOpenGLRenderer.h"
#include"GLFW/glfw3.h"

#include"Marmot/Application.h"

namespace Marmot
{
	ImguiLayer::ImguiLayer()
		: Layer("ImGuiLayer")
	{

	}

	ImguiLayer::~ImguiLayer()
	{

	}

	void ImguiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// TEMPORARY: should eventually use Marmot key codes
		//io.AddKeyEvent(ImGuiKey_Tab, );

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImguiLayer::OnDetach()
	{

	}

	void ImguiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = static_cast<float>(glfwGetTime());
		io.DeltaTime = m_time > 0.f ? time - m_time : (1.f / 60.f);
		m_time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	}

	void ImguiLayer::OnEvent(Event& event)
	{

	}
}