#if !defined(HYSTORYANALYSEREXPORTS__INCLUDED_)
#define HYSTORYANALYSEREXPORTS__INCLUDED_

#include "TableGridRowData.h"

class CHistoryAnalyserDlg;

STDAPI DoModelGenericHystoryAnalyserDialog();

STDAPI DoModelHistoryAnalyserDialog(const CTableGridRowData& cTableData, CHistoryAnalyserDlg** pHistoryAnalyserDlg);

STDAPI IsTableWindowForAnalyser(HWND hwndTable, CHistoryAnalyserDlg* pHistoryAnalyserDlg);

STDAPI RefershHistoryAnalyser(const CTableGridRowData& cTableData, CHistoryAnalyserDlg* pHistoryAnalyserDlg);

#endif //HYSTORYANALYSEREXPORTS__INCLUDED_
