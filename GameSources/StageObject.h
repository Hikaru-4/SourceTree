#pragma once
#include "stdafx.h"

namespace basecross {
	class StageObject : public GameObject
	{
		std::wstring name; // オブジェクトの種類名
	public:
		StageObject(const std::shared_ptr<Stage>& stage, const std::wstring& name)
			: GameObject(stage)
		{
		}
	};
}