#include "Light.h"
#include <GL/glew.h>



Light::Light(glm::vec3 position, glm::vec3 scale, glm::vec3 color)
{
	m_Position = position;
	m_Scale = scale;
	m_Color = color;

	m_Vertices = {
			-0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f,
			 0.5f,  0.5f, -0.5f,
			-0.5f,  0.5f, -0.5f,
			-0.5f, -0.5f, 0.5f,
			 0.5f, -0.5f, 0.5f,
			 0.5f,  0.5f, 0.5f,
			-0.5f,  0.5f, 0.5f,
			-0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f, 0.5f,
			-0.5f, -0.5f, 0.5f,
			-0.5f, 0.5f, -0.5f,
			 0.5f, 0.5f, -0.5f,
			 0.5f, 0.5f, 0.5f,
			-0.5f, 0.5f, 0.5f,
			-0.5f, -0.5f, -0.5f,
			-0.5f,  0.5f, -0.5f,
			-0.5f,  0.5f, 0.5f,
			-0.5f,  -0.5f, 0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f,  0.5f, -0.5f,
			0.5f,  0.5f, 0.5f,
			0.5f,  -0.5f, 0.5f
	};

	m_Indices = {
			2, 1, 0,
			0, 3, 2,
			4, 5, 6,
			6, 7, 4,
			8, 9, 10,
			10, 11, 8,
			14, 13, 12,
			12, 15, 14,
			18, 17, 16,
			16, 19, 18,
			20, 21, 22,
			22, 23, 20
	};


	m_vertexArray = new VertexArray();
	m_vertexBuffer = new VertexBuffer(&m_Vertices[0], m_Vertices.size() * sizeof(float));
	m_Layout = new VertexBufferLayout();
	m_Layout->Push<float>(3);
	m_vertexArray->AddBuffer(*m_vertexBuffer, *m_Layout);
	m_IndexBuffer = new IndexBuffer(&m_Indices[0], m_Indices.size());

	m_Shader = new Shader("res/shaders/lightVertex.shader", "res/shaders/lightFrag.shader");
}

void Light::Draw(glm::mat4 view, glm::mat4 projection)
{
	m_Shader->Bind();
	glm::mat4 model(1.0f);
	model = glm::translate(model, m_Position);
	model = glm::scale(model, m_Scale);

	m_Shader->setUniformMat4f("model", model);
	m_Shader->setUniformMat4f("view", view);
	m_Shader->setUniformMat4f("projection", projection);
	m_Shader->setUniform3f("Color", m_Color);

	m_vertexArray->Bind();
	m_IndexBuffer->Bind();
	glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);
}
