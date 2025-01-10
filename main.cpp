#include "DxLib_Setup.h"
#include "Effekseer.h"
#include <memory>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�R�s�[���Ă͂����Ȃ��ꍇunique_ptr���g����
	auto draw = std::make_unique<DxLibSetup>();
	//
	std::vector<EffekseerEffectHandle> effHndle;	/*�G�t�F�N�g���\�[�X*/
	std::vector<Effects> effects;					/*�G�t�F�N�g�Ǘ�*/
	//���O�p��
	/*�G�t�F�N�g���\�[�X�̓ǂݍ���*/
	effHndle.resize(effHndle.size() + 1);
	effHndle.back() = EffekseerEffectHandle::load("test.efk");
	/*���C�����[�v�Ŏg�p����ۂ̊Ǘ��N���X�̗p��*/
	effects.resize(effHndle.size());

	while (ProcessMessage() == 0) {
		/*���Z*/
		{
			//�X�y�[�X�������Ă���Ƃ��G�t�F�N�g��ݒ肷��
			if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
				effects[0].set(VGet(0.f, 0.f, 0.f), VGet(0.f, 1.f, 0.f), 0.1f);
			}
		}
		//�G�t�F�N�g�̍X�V
		{
			for (size_t index = 0; index < effHndle.size(); ++index) {
				effects[index].put(effHndle[index]);
			}
		}
		/*�`��*/
		{
			//3D(��`��)
			draw->SetDraw_Screen(VGet(0, 0, 10), VGet(0, 0, 0), VGet(0, 1, 0), DX_PI_F / 4, 0.5f, 20.f);
			Effekseer_Sync3DSetting();
			{
				UpdateEffekseer3D();
				//draw3D
				DrawEffekseer3D();
			}
			//2D(UI:���[�U�[�C���^�[�t�F�[�X)
			{
				DrawPixel(320, 240, GetColor(255, 255, 255));   // �_��ł�
			}
		}
		ScreenFlip();
		//
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
			break;
		}
	}

	return 0;// �\�t�g�̏I�� 
}