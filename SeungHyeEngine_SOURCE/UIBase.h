#pragma once
#include "Entity.h"

namespace Game
{
	class UIBase : public Entity
	{
	public:
		UIBase();
		~UIBase();

		// ui �ε�(�ʱ�ȭ)
		void Initialize();

		// ui Ȱ���� ȣ��
		void Active();

		// ui ��Ȱ���� ȣ��
		void InActive();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		// ui�� ����� �� ȣ��
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnClear();

		eUIType GetType() { return mType; }
		void SetFullScreen(bool enable) { mbFullScreen = enable; }
		bool IsFullScreen() { return mbFullScreen; }

	private:
		eUIType mType;
		bool mbFullScreen; 
		bool mbEnabled;
	};
}


