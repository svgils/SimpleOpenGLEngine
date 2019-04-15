#include "GameObject.h"
#include "MeshComponent.h"


namespace engine {
	GameObject::GameObject()
	{
		TransformComponent* transform = new TransformComponent();
		m_components.push_back(transform);
	}

	GameObject::GameObject(TransformComponent* transform)
	{
		m_components.push_back(transform);
	}

	GameObject::~GameObject()
	{
		for (auto c : m_components)
		{
			delete c;
		}
	}

	void GameObject::AddComponent(Component* component)
	{
		m_components.push_back(component);
	}

	void GameObject::Render(const CameraComponent& camera)
	{
		MeshComponent* mesh = GetComponent<MeshComponent>();
		if (mesh != nullptr)
		{
			mesh->Render(camera, this);
		}
	}
}
