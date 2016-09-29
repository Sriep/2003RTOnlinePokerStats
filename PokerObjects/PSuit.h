// PSuit.h: interface for the PSuit class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_PSUIT_H__ED62888F_1579_445D_ADD3_4FDA488BA44F__INCLUDED_)
#define AFX_PSUIT_H__ED62888F_1579_445D_ADD3_4FDA488BA44F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PSuit  
{
public:
	enum SUIT
	{
		SUIT_NO_SUIT = 0,
		SUIT_CLUBS,
		SUIT_DIAMONDS,
		SUIT_HEARTS,
		SUIT_SPADES,
		SUIT_NUM_SUITS
	};

public:
	CString asString() const;
	PSuit(int iHashValue);
	int getHashValue() const;
	PSuit(SUIT eSuit);
	virtual ~PSuit();
	static PSuit charToSuit(unsigned char chSuit);
	static PSuit stringToSuit(const CString& strSuit);
	bool operator!=(const PSuit& sSuit) const;
	bool operator==(const PSuit& sSuit) const;
	bool operator<(const PSuit& sSuit) const;
	bool operator<=(const PSuit& sSuit) const;
	bool operator>(const PSuit& sSuit) const;
	bool operator>=(const PSuit& sSuit) const;
	PSuit& operator=(const PSuit& sSuit);
	void DUMP() const;
private:
	SUIT m_eSuit;
};

#endif // !defined(AFX_PSUIT_H__ED62888F_1579_445D_ADD3_4FDA488BA44F__INCLUDED_)



