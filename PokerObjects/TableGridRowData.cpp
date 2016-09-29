// TableGridRowData.cpp: implementation of the CTableGridRowData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TableGridRowData.h"
#include "SPRSCountHands.h"
#include <math.h>
#include "PlayerList.h"
#include "RS_DBQueue.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTableGridRowData::CTableGridRowData()
:   m_iSite(0),
	m_hwndWindowHandle(NULL),
	m_hwndDealerTextWindow(NULL),
	m_iVolPutMoneyInPot(0),
	m_iSawRiver(0),
	m_iRaisesNotFoldTo(0),
	m_iVariance(0)
{
	m_strTableName = "";
}

CTableGridRowData::~CTableGridRowData()
{

}

CTableGridRowData::CTableGridRowData(const CString& strTableName, HWND hwndTable, HWND hwndDealerText, int iSite)
:	m_hwndWindowHandle(hwndTable),
	m_hwndDealerTextWindow(hwndDealerText),
	m_iSite(iSite),
	m_iVolPutMoneyInPot(0),
	m_iSawRiver(0),
	m_iRaisesNotFoldTo(0),
	m_iVariance(0)
{
	m_strTableName = strTableName;
}

CTableGridRowData::CTableGridRowData(const CTableGridRowData& cTGRD)
{
	m_strTableName = cTGRD.m_strTableName;
	m_hwndWindowHandle = cTGRD.m_hwndWindowHandle;
	m_hwndDealerTextWindow = cTGRD.m_hwndDealerTextWindow;
	m_iSite = cTGRD.m_iSite;
	m_iVolPutMoneyInPot = cTGRD.m_iVolPutMoneyInPot;
	m_iSawRiver = cTGRD.m_iSawRiver;
	m_iRaisesNotFoldTo = cTGRD.m_iRaisesNotFoldTo;
	m_iVariance = cTGRD.m_iVariance;
	m_listPlayers = cTGRD.m_listPlayers;
}

CTableGridRowData& CTableGridRowData::operator=(const CTableGridRowData& cTGRD)
{
	m_strTableName = cTGRD.m_strTableName;
	m_hwndWindowHandle = cTGRD.m_hwndWindowHandle;
	m_hwndDealerTextWindow = cTGRD.m_hwndDealerTextWindow;
	m_iSite = cTGRD.m_iSite;
	m_iVolPutMoneyInPot = cTGRD.m_iVolPutMoneyInPot;
	m_iSawRiver = cTGRD.m_iSawRiver;
	m_iRaisesNotFoldTo = cTGRD.m_iRaisesNotFoldTo;
	m_iVariance = cTGRD.m_iVariance;
	m_listPlayers = cTGRD.m_listPlayers;
	return *this;
}

CTableGridRowData::CTableGridRowData(const CString& strTableName, int iSite, int iVolPutMoneyInPot, int m_iRaisesNotFoldTo, int iSawRiver, int iVariance)
:	m_iSite(iSite),
	m_hwndWindowHandle(NULL),
	m_hwndDealerTextWindow(NULL),
	m_iVolPutMoneyInPot(iVolPutMoneyInPot),
	m_iSawRiver(iSawRiver),
	m_iRaisesNotFoldTo(m_iRaisesNotFoldTo),
	m_iVariance(iVariance)
{
	m_strTableName = strTableName;
}

CString CTableGridRowData::GetTableName()  const
{
	return m_strTableName;
}

HWND CTableGridRowData::GetWindowHandle()  const
{
	return m_hwndWindowHandle;
}

HWND CTableGridRowData::GetDealerTextWindow() const
{
	return m_hwndDealerTextWindow;
}

int CTableGridRowData::GetSite()   const
{
	return m_iSite;
}
  
int CTableGridRowData::GetVolPutMoneyInPot()  const
{
	return m_iVolPutMoneyInPot;
}

int CTableGridRowData::GetSawRiver()  const
{
	return m_iSawRiver;
}

int CTableGridRowData::GetRaisesNotFoldTo()  const
{
	return m_iRaisesNotFoldTo;
}

int CTableGridRowData::GetVariance()  const
{
	return m_iVariance;
}

void CTableGridRowData::SetTableName(const CString& strName)
{					 
	m_strTableName = strName;
}
void CTableGridRowData::SetWindowHandle(HWND hwnd) 
{
	m_hwndWindowHandle = hwnd;
}
void CTableGridRowData::SetSite(int iSite) 
{
	m_iSite = iSite;
}
void CTableGridRowData::SetVolPutMoneyInPot(int iVPMIP)	
{
	m_iVolPutMoneyInPot = iVPMIP;
}	 
void CTableGridRowData::SetSawRiver(int iSR)
{
	m_iSawRiver = iSR;
}
void CTableGridRowData::SetVariance(int iVar)
{
	m_iVariance = iVar;
}

bool CTableGridRowData::operator!=(const CTableGridRowData& cData) const
{
	return m_strTableName != cData.m_strTableName;
}

bool CTableGridRowData::operator==(const CTableGridRowData& cData) const
{
	return m_strTableName == cData.m_strTableName;
}

void CTableGridRowData::DUMP() const
{
	TRACE(m_strTableName);
	TRACE1("\n--- Handel = %d ---\n", (long) m_hwndWindowHandle);
	CString strTraceData;
	strTraceData.Format("Site = %d \t Vol Put money in Pot = %d \t Saw River = %d  \t RaisesCalled = %d\t Variance = %d\n",
						 m_iSite, m_iVolPutMoneyInPot, m_iSawRiver, m_iRaisesNotFoldTo, m_iVariance);

	TRACE(strTraceData);
}

StringList CTableGridRowData::GetListOfPlayers() const
{
	//if (m_listPlayers.size() == 0)
	//{
	//	m_listPlayers = CPlayerList::Get(GetDealerTextWindow(), GetSite());
	//}
	return m_listPlayers;
}

int CTableGridRowData::GetNumberOfPlayers() const
{
	
	int iNum = GetListOfPlayers().size();
	ASSERT(iNum <11);
	return 	iNum;
}


void CTableGridRowData::Calculate()
{
	int ipctSawRiver = 0;
	double fVariance = 0;
	int ipctVolPutMoneyPot = 0;
	int iNumDataEntries = 0;
	int iNumVarianceDataEntries = 0;

	int iRaiesNotCalled = 0;
	int iRaiesCalled = 0;
	int iCouldHaveCalledRaise = 0;


	const int NUM_HANDS_NEEDED_TO_INCLUDE_IN_STATS = 1;
	const double VARIANCE_OF_STATS = 0.15; //pq where p = .2 ish

	StringList listPlayers = GetListOfPlayers();

	RS_DBQueue dbQueue;
	RS_DBQueue::QueueID qId = dbQueue.WaitToUseDB(RS_DBQueue::DB_QUEUE_SPY_CONSUL_PRIORITY, "Spy Consul");
	try
	{
		for (ConstStringListIterator iter = listPlayers.begin(); iter != listPlayers.end() ; iter++ )
		{
			CString strNick = *iter;
			if (!strNick.IsEmpty())
			{
				int iNumHands = SPRSCountHands::GetValue("sp_num_get_hands", strNick, m_iSite);
				if (iNumHands >= NUM_HANDS_NEEDED_TO_INCLUDE_IN_STATS)
				{
					iNumDataEntries++;
					iNumVarianceDataEntries++;
					fVariance += VARIANCE_OF_STATS / (double) iNumHands;
					int iNumVolPutMoneyPot = SPRSCountHands::GetValue("sp_preflop_num_vol_put_money_in_Pot", strNick, m_iSite);
					ipctVolPutMoneyPot += iNumVolPutMoneyPot * 100 / iNumHands;
					//int iNumSawRiver = SPRSCountHands::GetValue("sp_river_num_seen", strNick, m_iSite);
					//ipctSawRiver += iNumSawRiver * 100 / iNumHands;

					//iRaiesCalled += SPRSCountHands::GetValue("sp_preflop_num_called_raise_outside_blinds", strNick, m_iSite);
					//iRaiesCalled += SPRSCountHands::GetValue("sp_preflop_num_reraise", strNick, m_iSite);
					//iCouldHaveCalledRaise +=  SPRSCountHands::GetValue("sp_river_num_can_call_raise", strNick, m_iSite);
					//iCouldHaveCalledRaise +=  SPRSCountHands::GetValue("sp_preflop_num_can_reraise", strNick, m_iSite);
				}
				else
				{
					fVariance += VARIANCE_OF_STATS;
					iNumVarianceDataEntries++;
				}
			}
		}
	}
	catch(...)
	{
		//??
	}
	dbQueue.FinishedUsingDB(qId);

	if (iNumDataEntries > 0)
	{
		m_iVolPutMoneyInPot = ipctVolPutMoneyPot / iNumDataEntries;
		m_iSawRiver = ipctSawRiver / iNumDataEntries;
		if (iCouldHaveCalledRaise != 0)
		{
			m_iRaisesNotFoldTo = (100 * iRaiesCalled) / iCouldHaveCalledRaise;
		}
		else
		{
			m_iRaisesNotFoldTo = -1;
		}
		fVariance /= iNumVarianceDataEntries;
		fVariance = sqrt(fVariance) * 100;
		m_iVariance	= (int) fVariance;
	}
}


void CTableGridRowData::SetPlayerList(const StringList &listPlayers)
{
	m_listPlayers =  listPlayers;
}
