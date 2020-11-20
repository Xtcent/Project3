#pragma once
#include <iostream>
#include <SDL.h>
#include "../Other/Error.h"
#include "Shader.h"
#include "include/glew.h"
#include <glm/glm.hpp>
#include "../Other/Camera.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"

class Display {
private:
	
	
public:
	SDL_Window* window;
	void init_display(int width,int height, const char* title) {

		

		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
		SDL_GLContext ctx = SDL_GL_CreateContext(window);
		SDL_GL_SetSwapInterval(0);
		glewInit();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//SDL_ShowCursor(SDL_DISABLE);
		glClearColor(0, 0.5f, 1.0f, 1.0f);
		
		// This part of the code initiliazes imgui
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui::StyleColorsDark();
		ImGui_ImplSDL2_InitForOpenGL(window, ctx); //ctx = sdl_gl_context
		ImGui_ImplOpenGL3_Init((char*)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));
		// imgui init end

		



	}
	void clear_display() {
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void present_display() {
		SDL_GL_SwapWindow(window);
	}
};