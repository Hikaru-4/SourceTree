/*!
@file Player.cpp
@brief プレイヤーなど実体
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross{
	void Player::OnCreate()
	{
		auto drawComp = AddComponent<PNTStaticDraw>();
		drawComp->SetMeshResource(L"DEFAULT_CUBE");
		drawComp->SetDiffuse(Col4(1.0f, 1.0f, 2.0f, 0.25f));

		SetAlphaActive(true);
	}

	void Player::OnUpdate()
	{
		auto& app = App::GetApp();  // アプリケーションオブジェクトを取得する

		auto device = app->GetInputDevice();
		const auto& pad = device.GetControlerVec()[0];

		auto transComp = GetComponent<Transform>();
		auto pos = transComp->GetPosition();

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_LEFT)
		{
			// プレイヤーを左に移動させる
			pos += Vec3(-1.0f, 0.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
		{
			// プレイヤーを右に移動させる
			pos += Vec3(1.0f, 0.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_UP)
		{
			// プレイヤーを上に移動させる
			pos += Vec3(0.0f, 1.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_DOWN)
		{
			// プレイヤーを下に移動させる
			pos += Vec3(0.0f, -1.0f, 0.0f);
		}

		transComp->SetPosition(pos);

		// ブロックを置く
		if (pad.wPressedButtons & XINPUT_GAMEPAD_A)
		{
			MakeBlock(pos);
		}

		// ステージのセーブ
		if (pad.wPressedButtons & XINPUT_GAMEPAD_START)
		{
			{
				auto stage = dynamic_pointer_cast<GameStage>(GetStage());
				if (!stage) {
					return;
				}

				auto stageMap = stage->GetStageMap();
				auto path = App::GetApp()->GetDataDirWString();
				stageMap->SaveTextFile(path + L"c:\\stage.txt");
				stageMap->SaveBinaeyFile(path + L"stage.stg");
			}
		}
	}
		void Player::MakeBlock(const Vec3 & position)
		{
			auto stage = dynamic_pointer_cast<GameStage>(GetStage());
			if (!stage) 
			{
				return;
			}

			auto stageMap = stage->GetStageMap();
			stageMap->AddStageObject<Block>(position);
		}
	}
//end basecross

