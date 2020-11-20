#include <iostream>
#include "Engine/Graphics/Graphics.h"
#include "Engine/Graphics/TextureManager.h"
#include "Engine/Input/InputManager.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"

int main(int argc, char* argv[]) {
	
	bool show_demo_window = false;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	bool Show_grid = false;

	//TextureManager texture;
	InputManager input;
	Display display;
	

	
	display.init_display(1280, 720, " ");
	

	while (!input.hasQuit) {
	
		input.pollEvents();
		display.clear_display();
		ImGui_ImplOpenGL3_NewFrame();

		ImGui_ImplSDL2_NewFrame(display.window);
		ImGui::NewFrame();


		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)& clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}
		// Main menu bar
		{
			ImGui::BeginMainMenuBar();
			if (ImGui::BeginMenu("File"))
			{	
				if (ImGui::MenuItem("New","Create new level")) {/*Create new level*/ }
				if (ImGui::MenuItem("Open")) { /* Level file loading implementation */ }
				if (ImGui::MenuItem("Save")) { /* Level file saving implementation */ }
				if (ImGui::MenuItem("Save as..")) {/*Level save as implementation*/ }
				if (ImGui::MenuItem("Close","Close level")) {/* Close level file */ }
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Edit"))
			{
				if(ImGui::MenuItem("Undo","Ctrl+Z")){/*Undo implementation*/}
				if (ImGui::MenuItem("Redo","Ctrl+Y")){/*Redo implementation*/}
					ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}

		// Imgui Sprite menu
		{
			ImGui::Begin("");
			ImGui::BeginMenuBar();
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("New", "Create new level")) {/*Create new level*/ }
				if (ImGui::MenuItem("Open")) { /* Level file loading implementation */ }
				if (ImGui::MenuItem("Save")) { /* Level file saving implementation */ }
				if (ImGui::MenuItem("Save as..")) {/*Level save as implementation*/ }
				if (ImGui::MenuItem("Close", "Close level")) {/* Close level file */ }
				ImGui::EndMenu();
			}
			ImGui::Checkbox("Show grid:", &Show_grid);
			ImGui::End();
			// imgui code
		}



		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		display.present_display();
		
		
	}
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();

	ImGui::DestroyContext();
	return 0;
}