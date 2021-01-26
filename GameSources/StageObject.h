#pragma once
#include "stdafx.h"

namespace basecross {
	class StageObject : public GameObject
	{
		std::wstring name; // �I�u�W�F�N�g�̎�ޖ�
	public:
		StageObject(const std::shared_ptr<Stage>& stage, const std::wstring& name)
			: GameObject(stage)
		{
		}
	};
}