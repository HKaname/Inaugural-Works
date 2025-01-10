#pragma once

#include "DxLib.h"
#include "EffekseerForDXLib.h"

class DxLibSetup
{
public:
	DxLibSetup()
	{
		SetOutApplicationLogValidFlag(FALSE);							/*log*/
		SetMainWindowText("game title");								/*�^�C�g��*/
		ChangeWindowMode(TRUE);										/*���\��*/
		SetUseDirect3DVersion(DX_DIRECT3D_11);							/*directX ver*/
		SetGraphMode(640, 480, 32);		/*�𑜓x*/
		SetUseDirectInputFlag(TRUE);									/*DirectInput�g�p*/
		SetDirectInputMouseMode(TRUE);									/*DirectInput�}�E�X�g�p*/
		SetWindowSizeChangeEnableFlag(FALSE, FALSE);			/*�E�C���h�E�T�C�Y���蓮�ύX�s�A�E�C���h�E�T�C�Y�ɍ��킹�Ċg������Ȃ��悤�ɂ���*/
		SetUsePixelLighting(TRUE);									/*�s�N�Z�����C�e�B���O�̎g�p*/
		SetFullSceneAntiAliasingMode(4, 2);				/*�A���`�G�C���A�X*/
		SetEnableXAudioFlag(TRUE);										/*XAudio��p���邩*/
		Set3DSoundOneMetre(1.0f);								/*3D�I�[�f�B�I�̊�����w��*/
		SetWaitVSyncFlag(TRUE);											/*��������*/
		DxLib_Init();													/*�c�w���C�u��������������*/
		Effekseer_Init(8000);									/*Effekseer�̏�����*/
		SetSysCommandOffFlag(TRUE);										/*�^�X�N�X�C�b�`��L���ɂ��邩�ǂ�����ݒ肷��*/
		SetChangeScreenModeGraphicsSystemResetFlag(FALSE);				/*Effekseer�p*/
		Effekseer_SetGraphicsDeviceLostCallbackFunctions();				/*Effekseer�p*/
		SetAlwaysRunFlag(TRUE);											/*background*/
		SetUseZBuffer3D(TRUE);										/*zbufuse*/
		SetWriteZBuffer3D(TRUE);									/*zbufwrite*/
		MV1SetLoadModelPhysicsWorldGravity(-9.8f);						/*�d��*/
		SetWindowSize(640, 480);								/*�\������E�B���h�E�T�C�Y*/
	}

	~DxLibSetup()
	{
		DxLib_End();	// �c�w���C�u�����g�p�̏I������
	}

	//����ʂ̃Z�b�e�B���O
	void SetDraw_Screen(const bool& clear = true)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		if (clear) {
			ClearDrawScreen();
		}
	}

	//����ʂ̃J�������t���Z�b�e�B���O
	void SetDraw_Screen(const VECTOR& campos, const VECTOR& camvec, const VECTOR& camup, const float& fov, const float& near_, const float& far_)
	{
		SetDraw_Screen(true);
		SetCameraNearFar(near_, far_);
		SetupCamera_Perspective(fov);
		SetCameraPositionAndTargetAndUpVec(campos, camvec, camup);
	}
};
