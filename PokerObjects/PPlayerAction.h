// PPlayerAction.h: interface for the PPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PPLAYERACTION_H__4CC4FDEA_AF5D_471C_8F74_C8E24BD1D829__INCLUDED_)
#define AFX_PPLAYERACTION_H__4CC4FDEA_AF5D_471C_8F74_C8E24BD1D829__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PPlayerAction  
{
public:
	enum Action
	{
		ACTION_NONE = 0,
		ACTION_POST = 1,
		ACTION_MUCK = 2,
		ACTION_FOLD = 3,
		ACTION_CHECK = 4,
		ACTION_CALL = 5,
		ACTION_BET = 6,
		ACTION_RAISE = 7,
		NUM_OF_ACTIONS
	};
	
	PPlayerAction();
	PPlayerAction(const CString& strAction);
	PPlayerAction(Action eAction);
	CString ActionDescription() const;
	static bool IsAction(const CString& strAction);
	Action GetAction() const;
	void DUMP() const;						
	PPlayerAction& operator=(const PPlayerAction& cAction);
	virtual ~PPlayerAction();
	bool operator!=(const PPlayerAction& card) const;
	bool operator==(const PPlayerAction& card) const;

private:
	static Action GetActionFromString(const CString& strAction);
	static CString GetStringFromAction(Action m_eAction);


	Action m_eAction;

};

inline PPlayerAction::Action PPlayerAction::GetActionFromString(const CString& strAction)
{
	CString strLocalAction = strAction;
	strLocalAction.TrimLeft(' ');
	strLocalAction.TrimRight(" .");
	//strLocalAction.TrimRight(' ');

	if (strLocalAction == "folds" 
		|| strLocalAction == "folds." 
		|| strLocalAction == "Fold" 
		|| strLocalAction == "folds."
		|| strLocalAction == "folded"
		|| strLocalAction == "folded.")
		return ACTION_FOLD;
	if (strLocalAction == "bets" 
		|| strLocalAction == "bets." 
		|| strLocalAction == "Bet"
		|| strLocalAction == "bet")
		return ACTION_BET;
	if (strLocalAction == "raises" 
		|| strLocalAction == "raises." 
		|| strLocalAction == "Raise" 
		|| strLocalAction == "re-raises"
		|| strLocalAction == "re-raises."
		|| strLocalAction == "raised"
		|| strLocalAction == "re-raised")
		return ACTION_RAISE;
	if (strLocalAction == "calls" 
		|| strLocalAction == "calls." 
		|| strLocalAction == "Call"
		|| strLocalAction == "called")
		return ACTION_CALL;
	if (strLocalAction == "checks" 
		|| strLocalAction == "checks." 
		|| strLocalAction == "Check" 
		|| strLocalAction == "checks."
		|| strLocalAction == "checked"
		|| strLocalAction == "checked.")
		return ACTION_CHECK;
	if (strLocalAction == "posts" 
		|| strLocalAction == "post." 
		|| strLocalAction == "Post" 
		|| strLocalAction == "Posts")
		return ACTION_POST;
	else
		return ACTION_NONE;

/*CString strLocalAction = strAction;
	strLocalAction.TrimLeft(' ');

	switch (strLocalAction[0])
	{
	case 'f':
		return ACTION_FOLD;
	case 'b':
		return ACTION_BET;
	case 'r':
		return ACTION_RAISE;
	case 'c':
		switch(strLocalAction[1])
		{
		case 'a':
			return ACTION_CALL;
		case 'h':
			return ACTION_CHECK;
		default:
			return ACTION_NONE;
		}
	case 'p':
		return ACTION_POST;
	default:
		return ACTION_NONE;
	} */
}

inline CString PPlayerAction::GetStringFromAction(Action eAction)
{
	switch (eAction)
	{
	case ACTION_NONE:
		return CString("No action");
	case ACTION_POST:
		return CString("Post");
	case ACTION_MUCK:
		return CString("Muck");
	case ACTION_FOLD:
		return CString("Fold");
	case ACTION_CHECK:
		return CString("Check");
	case ACTION_CALL:
		return CString("Call");
	case ACTION_BET:
		return CString("Bet");
	case ACTION_RAISE:
		return CString("Raise");
	default:
		ASSERT(FALSE);
		return CString("Invalid action");
	}

}

inline CString PPlayerAction::ActionDescription() const
{
 	return GetStringFromAction(m_eAction);
}

inline PPlayerAction::Action PPlayerAction::GetAction() const
{
	return  m_eAction;
}

inline bool PPlayerAction::IsAction(const CString& strAction)
{
	return	 strAction == "folds" 
			 || strAction == "folds."
			 || strAction == "bets" 
			 || strAction == "bets."
			 || strAction == "raises" 
			 || strAction == "raises."
			 || strAction == "calls" 
			 || strAction == "calls."
			 || strAction == "checks" 
			 || strAction == "checks."
			 || strAction == "posts."
			 || strAction == "post";
}


inline PPlayerAction& PPlayerAction::operator=(const PPlayerAction& cAction)
{
	m_eAction = cAction.m_eAction;
	return *this;
}

inline bool PPlayerAction::operator!=(const PPlayerAction& cAction) const
{
	return m_eAction != cAction.m_eAction;
}

inline bool PPlayerAction::operator==(const PPlayerAction& cAction) const
{
	return m_eAction == cAction.m_eAction;
}



#endif // !defined(AFX_PPLAYERACTION_H__4CC4FDEA_AF5D_471C_8F74_C8E24BD1D829__INCLUDED_)
