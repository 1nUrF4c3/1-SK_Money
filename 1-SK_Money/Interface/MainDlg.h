//=====================================================================================

#pragma once

#include "../Resources/Resource.h"
#include "../Interface/WinAPI/Dialog.hpp"
#include "../Interface/WinAPI/Button.hpp"
#include "../Interface/WinAPI/EditBox.hpp"
#include "../Helpers/Message.hpp"
#include "../Helpers/Memory.hpp"

//=====================================================================================

#define OFF_SQUADPOINTS 0x1445A34A0

//=====================================================================================

class cMainDlg : public cDialog
{
public:

	cMainDlg(HINSTANCE instance);
	~cMainDlg() {};

private:

	bool SetSquadPoints();

	DLG_HANDLER(OnInit);
	DLG_HANDLER(OnClose);
	DLG_HANDLER(OnSetSquadPoints);

	ctrl::cEditBox _squadPoints;
	ctrl::cButton _set;

	HINSTANCE _instance;
};

//=====================================================================================