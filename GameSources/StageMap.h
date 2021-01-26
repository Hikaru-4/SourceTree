#pragma once
#include "stdafx.h"
# include "StageObject.h"

namespace basecross {
	// �X�e�[�W�̔z�u���Ǘ����邽�߂̃N���X
	class StageMap : public GameObject
	{
		std::vector < std::shared_ptr<StageObject>> m_stageObject;

	public : 
		StageMap(const std::shared_ptr<Stage>& stage)
			: GameObject(stage)
		{
		}

		void OnDraw() override;

		template<class T>
		void AddStageObject() 
		{
			ObjectFactory::Create<T>();
			m_stageObjects.push_back();
		}
	};
}