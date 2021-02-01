/*!
@file Player.cpp
@brief �v���C���[�Ȃǎ���
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {
	void Player::OnCreate()
	{
		auto drawComp = AddComponent<PNTStaticDraw>();
		drawComp->SetMeshResource(L"DEFAULT_CUBE");
		drawComp->SetDiffuse(Col4(1.0f, 1.0f, 1.0f, 0.25f));

		SetAlphaActive(true);
	}

	void Player::OnUpdate()
	{
		auto& app = App::GetApp(); // �A�v���P�[�V�����I�u�W�F�N�g���擾����

		// �Q�[���p�b�h�̎Q�Ƃ��擾����
		auto device = app->GetInputDevice();
		const auto& pad = device.GetControlerVec()[0];

		auto transComp = GetComponent<Transform>();
		auto pos = transComp->GetPosition(); // �v���C���[�̍��W���擾����

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_LEFT)
		{
			// �v���C���[�����Ɉړ�������
			pos += Vec3(-1.0f, 0.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
		{
			// �v���C���[���E�Ɉړ�������
			pos += Vec3(+1.0f, 0.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_UP)
		{
			// �v���C���[����Ɉړ�������
			pos += Vec3(0.0f, +1.0f, 0.0f);
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
			MakeBlock<Block>(pos);
		}

		// �n�ʃu���b�N��u��
		if (pad.wPressedButtons & XINPUT_GAMEPAD_B)
		{
			MakeBlock<Grass>(pos);
		}

		// �X�e�[�W�̃Z�[�u
		if (pad.wPressedButtons & XINPUT_GAMEPAD_START)
		{
			auto stageMap = GetStageMap();

			auto& app = App::GetApp();
			auto path = app->GetDataDirWString();

			stageMap->SaveTextFile(path + L"stage.txt");
			stageMap->SaveBinaryFile(path + L"stage.stg");

		}


		// �X�e�[�W�ɒǉ�����Ă���S�ẴI�u�W�F�N�g���������
		if (pad.wPressedButtons & XINPUT_GAMEPAD_BACK)
		{
			auto stageMap = GetStageMap();
			stageMap->Clear();
		}
	}

}
//end basecross

