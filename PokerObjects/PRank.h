// PRank.h: interface for the PRank class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRANK_H__1524E920_677C_4AAD_BF21_C4A8F756AC11__INCLUDED_)
#define AFX_PRANK_H__1524E920_677C_4AAD_BF21_C4A8F756AC11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PRank   
{
public:
	enum RANK
	{
		RANK_NO_RANK = 0,
		RANK_TWO,
		RANK_THREE,
		RANK_FOUR,
		RANK_FIVE,
		RANK_SIX,
		RANK_SEVEN,
		RANK_EIGHT,
		RANK_NINE,
		RANK_TEN,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		RANK_NUM_RANKS
	};
public:
	virtual CString asString() const;
	PRank(int iHashValue);
	int getHashValue() const;
	PRank(RANK eRank);
	virtual ~PRank();
	static PRank charToRank(unsigned char chRank);
	static PRank stringToRank(const CString& strRank);
	static int distance(const PRank& rRank1, const PRank& rRank2);
	bool operator!=(const PRank& sRank) const;
	bool operator==(const PRank& sRank) const;
	bool operator<(const PRank& sRank) const;
	bool operator<=(const PRank& sRank) const;
	bool operator>(const PRank& sRank) const;
	bool operator>=(const PRank& sRank) const;
	operator int() const;

	//static bool operator<(const PRank& sRank1, const PRank& sRank2);
	//static bool operator<=(const PRank& sRank1, const PRank& sRank2);
	//static bool operator>(const PRank& sRank1, const PRank& sRank2);
	//static bool operator>=(const PRank& sRank1, const PRank& sRank2);

	PRank& operator++();
	PRank& operator--();
	PRank& operator+=(int iIncrement);
	PRank& operator-=(int iDecrement);
	//PRank& operator+(int iIncrement);
	//PRank& operator-(int iDecrement);
	int operator-(const PRank& sRank) const;
	PRank& operator=(const PRank& sRank);
	void DUMP() const;
private:
	RANK m_eRank;
};


#endif // !defined(AFX_PRANK_H__1524E920_677C_4AAD_BF21_C4A8F756AC11__INCLUDED_)
