#include "Character.h"

_L_BEGIN
Character::Character() : pos_Original({ 0, 0 })
{
	this->implemented = ControlBaseInterface::IRenderable;
}

Character::~Character()
{
}

void Character::Render()
{
	if (!visible)
		return;

	for (list<TextureBase *>::iterator it = textures.begin(); it != textures.end(); ++it) // Go to Entity::Render for details.
	{
		if (!(*it) || !(*it)->IsAvailable())
		{
			Renderer::DrawWithoutTexture({ pos.X, pos.Y, pos.X + size.Width, pos.Y - size.Height });
			return;
		}
		if (this->displayMode == DisplayMode::Normal)
			Renderer::DrawRectangle((*it)->Get().GetIndex(), { pos.X, pos.Y, pos.X + size.Width, pos.Y - size.Height });
		else
			Renderer::DrawRectangleUpsideDown((*it)->Get().GetIndex(), { pos.X, pos.Y, pos.X + size.Width, pos.Y - size.Height });
		if (fx != FX::Normal)
			ProcessFX();
	}
}

void Character::ProcessFX()
{
	switch (fx)
	{
		case FX::Shaky:
		{
			if (fxCounter >= 360)
			{
				if (fxCounter >= 600)
				{
					fxCounter = 0;
					return;
				}
				if (fxCounter == 360)
					pos = pos_Original;
				fxCounter++;
				return;
			}
			else
				fxCounter += 20;

			pos.X += sin((double)fxCounter) / 10.0f;
			return;
		}
		case FX::Flowing:
		{
			if (fxCounter >= 250)
			{
				if (fxCounter == 250)
				{
					pos = pos_Original;
					fxCounter = 0;
				}
				return;
			}
			else
				fxCounter++;

			pos.X += sin(fxCounter / 20.0f) / 30.0f;
			size.Width += sin(fxCounter / 20.0f) / 30.0f;
			pos.Y += cos(fxCounter / 10.0f) / 15.0f;
			size.Height += cos(fxCounter / 10.0f) / 15.0f;
			return;
		}
		case FX::Abnormal:
		{
			switch (fxCounter)
			{
				case 0:
				{
					pos = { pos.X - 0.5f, pos.Y };
					fxCounter++;
					return;
				}
				case 15:
				{
					pos = { pos.X + 0.25f, pos.Y - 0.5f };
					fxCounter++;
					return;
				}
				case 30:
				{
					pos = { pos.X + 0.25f, pos.Y + 0.25f };
					fxCounter++;
					return;
				}
				case 45:
				{
					pos = { pos.X - 0.5f, pos.Y + 0.5f };
					fxCounter++;
					return;
				}
				case 60:
				{
					pos = { pos.X + 0.75, pos.Y + 0.25f };
					fxCounter++;
					return;
				}
				case 75:
				{
					pos = { pos.X + 0.5f, pos.Y - 0.25f };
					fxCounter++;
					return;
				}
				case 90:
				{
					pos = pos_Original;
					fxCounter = 0;
					return;
				}
			}
			fxCounter++;
			return;
		}
		case FX::ExAbnormal:
		{
			switch (fxCounter)
			{
				case 0:
				{
					pos = { pos.X - 0.5f, pos.Y };
					fxCounter++;
					return;
				}
				case 5:
				{
					pos = { pos.X + 0.25f, pos.Y - 0.5f };
					fxCounter++;
					return;
				}
				case 10:
				{
					pos = { pos.X + 0.25f, pos.Y + 0.25f };
					fxCounter++;
					return;
				}
				case 15:
				{
					pos = { pos.X - 0.5f, pos.Y + 0.5f };
					fxCounter++;
					return;
				}
				case 20:
				{
					pos = { pos.X + 0.75, pos.Y + 0.25f };
					fxCounter++;
					return;
				}
				case 25:
				{
					pos = { pos.X + 0.5f, pos.Y - 0.25f };
					fxCounter++;
					return;
				}
				case 30:
				{
					pos = pos_Original;
					fxCounter = 0;
					return;
				}
			}
			fxCounter++;
			return;
		}
		case FX::ExExAbnormal:
		{
			switch (fxCounter)
			{
				case 0:
				{
					pos = { pos.X - 0.5f, pos.Y };
					fxCounter++;
					return;
				}
				case 2:
				{
					pos = { pos.X + 0.25f, pos.Y - 0.5f };
					fxCounter++;
					return;
				}
				case 4:
				{
					pos = { pos.X + 0.25f, pos.Y + 0.25f };
					fxCounter++;
					return;
				}
				case 6:
				{
					pos = { pos.X - 0.5f, pos.Y + 0.5f };
					fxCounter++;
					return;
				}
				case 8:
				{
					pos = { pos.X + 0.75, pos.Y + 0.25f };
					fxCounter++;
					return;
				}
				case 10:
				{
					pos = { pos.X + 0.5f, pos.Y - 0.25f };
					fxCounter++;
					return;
				}
				case 12:
				{
					pos = pos_Original;
					fxCounter = 0;
					return;
				}
			}
			fxCounter++;
			return;
		}
	}
}
_L_END