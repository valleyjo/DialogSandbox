#include <Windows.h>
#include <atlbase.h>
#include <atlwin.h>
#include <atlstr.h>
#include <atlapp.h>
#include <atlctrls.h>
#include "resource.h"


class CMyDialog : public CDialogImpl<CMyDialog>
{
public:
    BEGIN_MSG_MAP(CMyDialog)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog);
        COMMAND_ID_HANDLER(IDOK, OnOK);
        COMMAND_ID_HANDLER(IDCANCEL, OnCancel);
    END_MSG_MAP();

    BOOL OnInitDialog(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    BOOL OnCancel(WORD code, WORD id, HWND hwndControl, BOOL& handled);
    BOOL OnOK(WORD code, WORD id, HWND hwndControl, BOOL& handled);

    const static int IDD = IDD_DIALOG1;

    CMyDialog();
};


CMyDialog::CMyDialog()
{
}

BOOL CMyDialog::OnInitDialog(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    return TRUE;
}

BOOL CMyDialog::OnOK(WORD code, WORD id, HWND hwndControl, BOOL& handled)
{
    EndDialog(1);
    return TRUE;
}

BOOL CMyDialog::OnCancel(WORD code, WORD id, HWND hwndControl, BOOL& handled)
{
    EndDialog(0);
    return TRUE;
}


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdline, int nCmdShow)
{
    CoInitialize(NULL);
    InitCommonControls();

    CMyDialog dlg;
    dlg.DoModal();
    return 0;
}
