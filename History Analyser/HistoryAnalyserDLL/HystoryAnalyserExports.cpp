#include "stdafx.h"
#include "HystoryAnalyserExports.h"
#include "History AnalyserDlg.h"

STDAPI DoModelGenericHystoryAnalyserDialog()
{
	CHistoryAnalyserDlg dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	} 
	return nResponse;
}


STDAPI DoModelHistoryAnalyserDialog(const CTableGridRowData& cTableData, CHistoryAnalyserDlg** pHistoryAnalyserDlg)
{
	CHistoryAnalyserDlg* pDlg = new CHistoryAnalyserDlg();
	pDlg->Create(IDD_HISTORYANALYSER_DIALOG,NULL);

	CRect lpRect;
	pDlg->GetClientRect(lpRect);
	pDlg->ClientToScreen(lpRect);
    pDlg->MoveWindow(0, 0, lpRect.Width(), lpRect.Height()+20);

	pDlg->FixTable(cTableData);
	pDlg->ShowWindow(SW_SHOW);
	*pHistoryAnalyserDlg = pDlg;
	return 1;
}

STDAPI IsTableWindowForAnalyser(HWND hwndTable, CHistoryAnalyserDlg* pHistoryAnalyserDlg)
{
	return pHistoryAnalyserDlg->GetDealerTextWindowHandle() == hwndTable;
}

STDAPI RefershHistoryAnalyser(const CTableGridRowData& cTableData, CHistoryAnalyserDlg* pHistoryAnalyserDlg)
{
   if (pHistoryAnalyserDlg->m_hWnd)
   {
		//pHistoryAnalyserDlg->RefreshTableInfo(cTableData);
		return true;
   }
   else
   {
	   return false;
   }
}


