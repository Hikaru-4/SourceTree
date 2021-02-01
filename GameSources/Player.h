/*!
@file Player.h
@brief ƒvƒŒƒCƒ„[‚È‚Ç
*/

#pragma once
#include "stdafx.h"

namespace basecross {
	class Player : public GameObject
	{
	public:
		Player(const std::shared_ptr<Stage>& stage)
			:GameObject(stage)
		{
		}

		void OnCreate() override;
		void OnUpdate() override;

	private:
		template<class T>
		void MakeBlock(const Vec3& position)
		{
			auto stageMap = GetStageMap();
			stageMap->AddStageObject<T>(position);
		}

		std::shared_ptr<StageMap>& GetStageMap()
		{
			auto stage = dynamic_pointer_cast<GameStage>(GetStage());
			return stage->GetStageMap();
		}
	};

}
//end basecross

