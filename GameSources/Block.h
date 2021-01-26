
#pragma once
#include "stdafx.h"
#include "StageObject.h"

namespace basecross {
	class Block : public StageObject
	{
	public:
		Block(const std::shared_ptr<Stage>& stage)
			: StageObject(stage, L"block")
		{
		}

		void OnCreate() override;
	};
}