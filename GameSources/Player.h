/*!
@file Player.h
@brief ƒvƒŒƒCƒ„[‚È‚Ç
*/

#pragma once
#include "stdafx.h"

namespace basecross{
	class Player : public GameObject
	{
	public :
		Player(const std::shared_ptr<Stage>& stage)
			: GameObject(stage)
		{
		}

		void OnCreate() override;
		void OnUpdate() override;

		private : 
		void MakeBlock(const Vec3& position);
	};

}
//end basecross

