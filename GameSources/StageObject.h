#pragma once
#include "stdafx.h"

namespace basecross {
	class StageObject : public GameObject
	{
	public:
		StageObject(const std::shared_ptr<Stage>& stage)
			: GameObject(stage)
		{
		}
	};
}