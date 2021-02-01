
/*!
@file Grass.h
@brief ƒuƒƒbƒN
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