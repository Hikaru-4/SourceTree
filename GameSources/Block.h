
#pragma once
#include "StageObject.h"

namespace basecross {
	class Block : public StageObject
	{
	public:
		Block(const shared_ptr<Stage>& stage) 
			: StageObject(stage, L"block")
		{
		}

		void OnCreate() override;
	};
}