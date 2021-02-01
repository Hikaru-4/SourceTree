/*!
@file Player.cpp
@brief �v���C���[�Ȃǎ���
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
		auto& app = App::GetApp();  // �A�v���P�[�V�����I�u�W�F�N�g���擾����

		auto device = app->GetInputDevice();
		const auto& pad = device.GetControlerVec()[0];

		auto transComp = GetComponent<Transform>();
		auto pos = transComp->GetPosition();

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_LEFT)
		{
			// �v���C���[�����Ɉړ�������
			pos += Vec3(-1.0f, 0.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
		{
			// �v���C���[���E�Ɉړ�������
			pos += Vec3(1.0f, 0.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_UP)
		{
			// �v���C���[����Ɉړ�������
			pos += Vec3(0.0f, 1.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_DOWN)
		{
			// �v���C���[�����Ɉړ�������
			pos += Vec3(0.0f, -1.0f, 0.0f);
		}

		transComp->SetPosition(pos);

		// �u���b�N��u��
		if (pad.wPressedButtons & XINPUT_GAMEPAD_A)
		{
			MakeBlock(pos);
		}

		// �X�e�[�W�̃Z�[�u
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

