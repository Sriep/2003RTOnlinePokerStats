// TournamentEquity.h: interface for the CTournamentEquity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOURNAMENTEQUITY_H__890001EA_D0CF_4915_B5DF_C46468E6B6A4__INCLUDED_)
#define AFX_TOURNAMENTEQUITY_H__890001EA_D0CF_4915_B5DF_C46468E6B6A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning( disable : 4786 )
#include <vector>
#include "StackSizes.h"
#include "ICMModDlg.h"


class CStackSizes;
class CPrizes;

using std::vector;
typedef std::vector<PAS_FLOAT>::iterator IterTournametEquity;
typedef std::vector<PAS_FLOAT>::const_iterator ConstIterTournametnEquity;


class CTournamentEquity  : public std::vector <PAS_FLOAT> 
{
public:					
	void DUMP();
	CTournamentEquity();
	virtual ~CTournamentEquity();

	void CalculateEquity(CStackSizes stackSizes, const CPrizes& prizes);

private:
	PAS_FLOAT GetPlayerEquity(CStackSizes stackSizes, const CPrizes& prizes,  int iTopPlace, int numPlayersLeft);

	int m_numPlayers;
	int m_totalChips;
};

#endif // !defined(AFX_TOURNAMENTEQUITY_H__890001EA_D0CF_4915_B5DF_C46468E6B6A4__INCLUDED_)
