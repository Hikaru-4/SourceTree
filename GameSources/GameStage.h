/*!
@file GameStage.h
@brief ゲームステージ
*/

#pragma once
#include "stdafx.h"
#include"StageMap.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	//	ゲームステージクラス
	//--------------------------------------------------------------------------------------
	class GameStage : public Stage {
		//ビューの作成
		void CreateViewLight();

		// ステージマップオブジェトへのポインタ
		std::shared_ptr<StageMap> m_stageMap;

	public:
		//構築と破棄
		GameStage() :Stage() {}
		virtual ~GameStage() {}
		//初期化
		virtual void OnCreate()override;

		std::shared_ptr<StageMap>& GetStageMap()
		{
			return m_stageMap;
		}
	};


}
//end basecross

