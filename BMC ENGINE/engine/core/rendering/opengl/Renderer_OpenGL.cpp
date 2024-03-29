#include "Renderer_OpenGL.h"

void Renderer_OpenGL::calculateWidthMultiplier()
{
	int width;
	int height;

	glfwGetWindowSize(window, &width, &height);

	int newWidth = width;
	int newHeight = static_cast<int>(width * 9.0 / 16.0);
	if (newHeight > height) {
		newHeight = height;
		newWidth = static_cast<int>(height * 16.0 / 9.0);
	}

	//cout << "diff is " << ((height - newHeight) / 2) / (((width - newWidth) / 2) + 1) << endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	int newWidth = width;
	int newHeight = static_cast<int>(width / 2.0);
	if (newHeight > height) {
		newHeight = height;
		newWidth = static_cast<int>(height * 2.0);
	}
	glViewport((width - newWidth) / 2, (height - newHeight) / 2, newWidth, newHeight);

#if SETTINGS_ANTIALIASING
	glEnable(GL_MULTISAMPLE);
#endif
}

Renderer_OpenGL::Renderer_OpenGL(Window* win)
{
	window = win->getWindow();
	fmanager = new FileManager();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Renderer_OpenGL::assignVars(float verts[], float vs)
{
	// Load files
	vertexShaderStr = fmanager->ReadFile("./resources/shaders/default/vertexShader.vert");
	fragmentShaderStr = fmanager->ReadFile("./resources/shaders/default/fragmentShader.frag");
	vertexShaderSource = vertexShaderStr.c_str();
	fragmentShaderSource = fragmentShaderStr.c_str();
	vertices = verts;
	vertSize = vs;
	size_t arraySize = vs / sizeof(vertices[0]);
	vertAmount = (int)(arraySize / 3);
}

void Renderer_OpenGL::render()
{
	glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]);
	glClear(GL_COLOR_BUFFER_BIT);

#if USE_BETA_MENU
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	NewFrame();
#endif

	if (useImprovedRendering) {
		calculateWidthMultiplier();
	}

	if (rendererEnabled) {
		glUseProgram(shaderProgram);
		glUniform1f(glGetUniformLocation(shaderProgram, "zoom"), zoom);
		glUniform1f(glGetUniformLocation(shaderProgram, "widthMultiplier"), widthMultiplier);
		glUniform1f(glGetUniformLocation(shaderProgram, "improvedRenderer"), useImprovedRendering);
		glUniform4f(glGetUniformLocation(shaderProgram, "color"), pentagonColor[0], pentagonColor[1], pentagonColor[2], pentagonColor[3]);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, vertAmount);
		glBindVertexArray(0);
	}

#if USE_BETA_MENU
	Begin("Beta Options");
	Text("Hello! Welcome to the BMC Engine Beta!\nThis menu allows you to pick from some beta test options.");

	Text("\nToggles:");
	Checkbox("Renderer Enabled", &rendererEnabled);
	Checkbox("Improved Scaling Support (broken)", &useImprovedRendering);

	Text("\nColors:");
	ColorEdit4("Pentagon Color", pentagonColor);
	ColorEdit4("Background Color", bgColor);

	Text("\nSliders:");
	SliderFloat("Zoom", &zoom, 0.0f, 5.0f);

	End();
	Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#endif
}

void Renderer_OpenGL::createShaders()
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Renderer_OpenGL::makeVAOandVBO()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertSize, vertices, GL_STATIC_DRAW);
}

void Renderer_OpenGL::setup(float vs[], float vss)
{
	assignVars(vs, vss);
	createShaders();
	makeVAOandVBO();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Renderer_OpenGL::cleanup()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	DestroyContext();
}
