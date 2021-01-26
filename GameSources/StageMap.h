#pragma once
#include "stdafx.h"
# include "StageObject.h"

namespace basecross {
	// ステージの配置を管理するためのクラス
	class StageMap : public GameObject
	{
		std::vector < std::shared_ptr<StageObject>> m_StageObject;

	public : 
		StageMap(const std::shared_ptr<Stage>& stage)
			: GameObject(stage)
		{
		}
	};
}