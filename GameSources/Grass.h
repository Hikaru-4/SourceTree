
/*!
@file Grass.h
@brief �u���b�N
*/

#pragma once
#include "StageObject.h"

namespace basecross {
	class Grass : public StageObject
	{
	public:
		Grass(const shared_ptr<Stage>& stage)
			:StageObject(stage, L"grass")
		{
		}

		void OnCreate() override;
	};
}