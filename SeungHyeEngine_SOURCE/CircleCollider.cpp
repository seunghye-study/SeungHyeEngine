#include "CircleCollider.h"
#include "Transform.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Camera.h"

namespace Game
{
	CircleCollider::CircleCollider():Collider(eColliderType::Circle2D)
	{
	}
	CircleCollider::~CircleCollider()
	{
	}
	void CircleCollider::Initialize()
	{
	}
	void CircleCollider::Update()
	{
	}
	void CircleCollider::LateUpdate()
	{
	}
	void CircleCollider::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mainCamera)
			pos = mainCamera->CalculatePosition(pos);

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Vector2 rightBottom;
		rightBottom.x = pos.x + offset.x + 100 * GetSize().x;
		rightBottom.y = pos.y + offset.y + 100 * GetSize().y;

		Ellipse(hdc, pos.x + offset.x
			, pos.y + offset.y
			, rightBottom.x
			, rightBottom.y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(greenPen);
	}
}