#pragma once
#include "stdafx.h"
# include "Block.h"

namespace basecross {
	// �X�e�[�W�̔z�u���Ǘ����邽�߂̃N���X
	class StageMap : public GameObject
	{
		std::vector < std::shared_ptr<Block>> blocks;

	public : 
		StageMap(const std::shared_ptr<Stage>& stage)
			: GameObject(stage)
		{
		}
	};
}