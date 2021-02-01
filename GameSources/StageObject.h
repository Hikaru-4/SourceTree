#pragma once
#include "stdafx.h"

namespace basecross {
	class StageObject : public GameObject
	{
		std::wstring m_name; // �I�u�W�F�N�g�̎�ޖ�
	public:
		enum Type
		{
			Block, Grass
		};

	public:
		StageObject(const std::shared_ptr<Stage>& stage, const std::wstring& name)
			: GameObject(stage), m_name(name)
		{
		}

		const std::wstring& GetName() const
		{
			return m_name;
		}
	};
}