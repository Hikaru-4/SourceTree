/*!
@file GameStage.h
@brief �Q�[���X�e�[�W
*/

#pragma once
#include "stdafx.h"
#include"StageMap.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	//	�Q�[���X�e�[�W�N���X
	//--------------------------------------------------------------------------------------
	class GameStage : public Stage {
		//�r���[�̍쐬
		void CreateViewLight();

		// �X�e�[�W�}�b�v�I�u�W�F�g�ւ̃|�C���^
		std::shared_ptr<StageMap> m_stageMap;

	public:
		//�\�z�Ɣj��
		GameStage() :Stage() {}
		virtual ~GameStage() {}
		//������
		virtual void OnCreate()override;

		std::shared_ptr<StageMap>& GetStageMap()
		{
			return m_stageMap;
		}
	};


}
//end basecross

