
#pragma once
#include "stdafx.h"

namespace basecross {
	class Block : public GameObject
	{
	public:
		Block(const std::shared_ptr<Stage>& stage)
			: GameObject(stage)
		{
		}

		void OnCreate() override;
	};
}